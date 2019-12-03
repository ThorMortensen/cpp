#include <algorithm>
#include <cstdlib> /* getenv */
#include <fstream>
#include <iostream>
#include <iterator>

#include "DebugPrinter.hpp"
#include "Recollection.hpp"

namespace Manduca {

Recollection::Recollection(const std::string &fileName, size_t historyLimit)
    : fileName(fileName), historyLimit(historyLimit) {

  std::string home(getenv("HOME"));
  folder = home + "/.manduca-history";
  absPath = folder + "/" + fileName;
}

std::string Recollection::suggestNextInBounds(const std::string &suggestionSeed,
                                              bool forward) {
  if (suggestionSeed.empty()) {
    return forward ? recallNext() : recallPrev();
  }

  state = State::IN_BOUNDS;

  forward ? dataIt++ : dataIt--;

  if (dataIt->first.rfind(suggestionSeed, 1) == std::string::npos) {
    if (!forward) {
      // Add 255 char to find last occurrence of seed.
      findSuggestion(suggestionSeed + static_cast<char>(255), false);
      dataIt--;
      validDataIt = true;
    } else {
      findSuggestion(suggestionSeed, false);
    }
  }

  return validDataIt ? dataIt->first : "";
}

std::string Recollection::suggestNext(const std::string &suggestionSeed) {
  return suggestNextInBounds(suggestionSeed, true);
}
std::string Recollection::suggestPrev(const std::string &suggestionSeed) {
  return suggestNextInBounds(suggestionSeed, false);
}

std::string Recollection::recallNext() {

  if (state != State::HISTORY_CRAWL) {
    histIt = history.cbegin();
  } else {
    histIt++;
    MARKER
    if (histIt == history.cend()) {
      histIt = history.cbegin();
    }
  }
  dataIt = histIt->content;
  state = State::HISTORY_CRAWL;

  return dataIt->first;
}
std::string Recollection::recallPrev() {

  if (state != State::HISTORY_CRAWL) {
    histIt = std::prev(history.cend());
  } else {
    histIt--;
    if (histIt == history.cbegin()) {
      histIt = std::prev(history.cend());
    }
  }
  dataIt = histIt->content;
  state = State::HISTORY_CRAWL;

  return dataIt->first;
}

bool Recollection::findSuggestion(const std::string &suggestionSeed,
                                  bool useUpperBound) {
  validDataIt = false;

  if (suggestionSeed.empty()) {
    return validDataIt;
  }

  dataIt = useUpperBound ? data.upper_bound(suggestionSeed)
                         : data.lower_bound(suggestionSeed);

  if ((dataIt->first).length() < suggestionSeed.length()) {
    return validDataIt;
  }

  if ((dataIt->first).compare(0, suggestionSeed.length(), suggestionSeed) ==
      0) {
    validDataIt = true;
  }

  return validDataIt;
}

std::string Recollection::suggest(const std::string &suggestionSeed) {
  state = State::SEARCHING;
  return findSuggestion(suggestionSeed, false) ? dataIt->first : "";
}

void Recollection::load() {

  if (isLoaded){
    return;
  }

  std::ifstream df(absPath, std::ifstream::in);
  std::ifstream hf(absPath + histPrefix, std::ifstream::in);
  std::string line;

  if (df.good()) {
    while (std::getline(df, line)) {
      history.emplace_back(mhist());
      auto h = std::prev(history.end());
      auto d = data.insert(std::make_pair(std::move(line), h));
      d.first->second->content = d.first;
    }
  }

  dataIt = data.begin();
  isLoaded = true;

  loadDbgPrint();
}
void Recollection::save(const std::string &str) {

  auto d = data.insert(std::make_pair(str, history.end()));

  if(d.first->second != history.end()){
    history.erase(d.first->second);
  }

  history.emplace_front(mhist());
  auto h = history.begin();
  h->content = d.first;
  d.first->second = h;

  state = State::SEARCHING;
}

void Recollection::store() {

  //  std::ofstream df(absPath);
  //  std::ofstream hf(absPath + histPrefix);
  //
  //  if (!df.good() && !hf.good()) {
  //    std::cerr << "Open output file's at " << absPath << " failed!!\n";
  //    return;
  //  }
  //
  //  std::copy(data.begin(), data.end(),
  //            std::ostream_iterator<std::string>(df, "\n"));
  //
  //  std::copy(history.begin(), history.end(),
  //            std::ostream_iterator<int>(hf, "\n"));
}

Recollection::~Recollection() {
  //  store();
}

// ------------------------ Debug stuff -------------------------

void Recollection::dbgPrintBounds() {
  //  if (!dbgPrintIsLoaded) {
  //    loadDbgPrint();
  //    dbgPrintIsLoaded = true;
  //  }

  DBP(dbgPrintVector.size())
  //  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, dbgPrintVector,
  //                                     dbgPrintVector.begin(),
  //                                     dbgPrintVector.end());

  //
  auto d = std::upper_bound(dbgPrintVector.begin(), dbgPrintVector.end(),
                            dataIt->first);

  //  auto u = std::upper_bound(dbgPrintVector.begin(), dbgPrintVector.end(),
  //                            upperBound->first);
  //
  //  auto l = std::upper_bound(dbgPrintVector.begin(), dbgPrintVector.end(),
  //                            std::prev(lowerBound)->first);

  std::cout << "d --> " << dataIt->first << '\n';
  //  std::cout << "u --> " << upperBound->first << '\n';
  //  std::cout << "l --> " << std::prev(lowerBound)->first << '\n';

  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, dbgPrintVector, --d);
}

void Recollection::dbgPrintContent() {

  //  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, data, dataIt);
  //  ppVector<std::deque<uint32_t>>(DBG_PEEK_SIZE, history, history.begin());
}

void Recollection::dbgPrintAttr() {
  std::cout << "fileName: " << fileName << std::endl;
  std::cout << "folder: " << folder << std::endl;
  std::cout << "absPath: " << absPath << std::endl;
  std::cout << "historyLimit: " << historyLimit << std::endl;
}
void Recollection::test() {
  load();
  dbgPrintAttr();
  dbgPrintContent();
  store();
}
void Recollection::loadDbgPrint() {
  for (const auto &st : data) {
    dbgPrintVector.emplace_back(st.first);
  }
}

} // namespace Manduca

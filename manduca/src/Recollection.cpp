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

void Recollection::setBounds(const std::string &suggestionSeed) {
  lowerBound = data.lower_bound(suggestionSeed);
  upperBound = data.upper_bound(suggestionSeed);
  state = State::IN_BOUNDS;
}

std::string Recollection::suggestNext(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return recallNext();
  }

  if (state == State::IN_BOUNDS) {
    if (dataIt == lowerBound) {
      dataIt = upperBound;
    }else{
      dataIt++;
    }
  } else {
    setBounds(suggestionSeed);
    dataIt = std::next(upperBound);
  }
  return dataIt->first;
}
std::string Recollection::suggestPrev(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return recallPrev();
  }

  if (state == State::IN_BOUNDS) {
    dataIt--;
    if (dataIt == std::prev(upperBound)) {
      dataIt = std::prev(upperBound);
    }
  } else {
    setBounds(suggestionSeed);
    dataIt = std::prev(lowerBound);
  }
  return dataIt->first;
}

std::string Recollection::recallNext() {
  //  dataIt = history[histIdx++] + data.begin();
  //  histIdx %= history.size();
  return dataIt->first;
}
std::string Recollection::recallPrev() {
  //  dataIt = history[histIdx--] + data.begin();
  //  histIdx %= history.size();
  return dataIt->first;
}

std::string Recollection::suggest(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return "";
  }

  state = State::SEARCHING;

  dataIt = data.lower_bound(suggestionSeed);

  if ((dataIt->first).length() < suggestionSeed.length()) {
    validDataIt = false;
    return "";
  }

  if ((dataIt->first).compare(0, suggestionSeed.length(), suggestionSeed) ==
      0) {
    validDataIt = true;
    return dataIt->first;
  }

  validDataIt = false;

  return "";
}

void Recollection::load() {

  std::ifstream df(absPath, std::ifstream::in);
  std::ifstream hf(absPath + histPrefix, std::ifstream::in);
  std::string line;

  if (df.good()) {
    while (std::getline(df, line)) {
      auto f = data.insert(std::make_pair(std::move(line), mhist()));
      f.first->second.content = f.first;
      history.push_front(f.first->second);
    }
  }

  dataIt = data.begin();
  upperBound = data.begin();
  lowerBound = data.end();
  loadDbgPrint();
}
void Recollection::save(const std::string &str) {

  if (validDataIt) {
    //    uint32_t dataLineToAdd = dataIt - data.begin();
    //    history.push_front(dataLineToAdd);
    //    history.erase(dataToHistory[dataLineToAdd]);
    //    dataToHistory[dataLineToAdd] = 0;
  }
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

  auto u = std::upper_bound(dbgPrintVector.begin(), dbgPrintVector.end(),
                            upperBound->first);

  auto l = std::upper_bound(dbgPrintVector.begin(), dbgPrintVector.end(),
                            std::prev(lowerBound)->first);


  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, dbgPrintVector, d, u, l);
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

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

int32_t Recollection::getPos() const { return dataIt - data.begin(); }

void Recollection::setBounds(const std::string &suggestionSeed) {
  auto comp = [](const std::string &a, const std::string &b) -> bool {
    return (a.compare(0, b.length(), b) <= 0);
  };
  lowerBound = std::lower_bound(data.begin(), data.end(), suggestionSeed, comp);
  upperBound = std::lower_bound(data.begin(), data.end(), suggestionSeed);
  state = State::IN_BOUNDS;
}

std::string Recollection::suggestNext(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return recallNext();
  }

  if (state == State::IN_BOUNDS) {
    dataIt++;
    if (dataIt == lowerBound) {
      dataIt = upperBound;
    }
  } else {
    setBounds(suggestionSeed);
    dataIt = upperBound + 1;
  }
  return (*dataIt);
}
std::string Recollection::suggestPrev(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return recallPrev();
  }

  if (state == State::IN_BOUNDS) {
    dataIt--;
    if (dataIt == upperBound - 1) {
      dataIt = lowerBound - 1;
    }
  } else {
    setBounds(suggestionSeed);
    dataIt = lowerBound - 1;
  }
  return (*dataIt);
}

std::string Recollection::recallNext() {
  dataIt = history[histIdx++] + data.begin();
  histIdx %= history.size();
  return (*dataIt);
}
std::string Recollection::recallPrev() {
  dataIt = history[histIdx--] + data.begin();
  histIdx %= history.size();
  return (*dataIt);
}

std::string Recollection::suggest(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return "";
  }

  state = State::SEARCHING;

  dataIt = std::lower_bound(data.begin(), data.end(), suggestionSeed);

  if ((*dataIt).length() < suggestionSeed.length()) {
    validDataIt = false;
    return "";
  }

  if ((*dataIt).compare(0, suggestionSeed.length(), suggestionSeed) == 0) {
    validDataIt = true;
    return *dataIt;
  }

  validDataIt = false;

  return "";
}

void Recollection::load() {

  std::ifstream df(absPath, std::ifstream::in);
  std::ifstream hf(absPath + histPrefix, std::ifstream::in);
  std::string line;
  uint32_t histLine = 0;
  uint32_t histIdx = 0;

  if (df.good()) {
    data.reserve(historyLimit);
    while (std::getline(df, line)) {
      data.emplace_back(std::move(line));
    }
  }

  if (hf.good()) {
    while (std::getline(hf, line)) {
      histLine = std::stoi(line);
//      dataToHistory.at()
      history.emplace_back(histLine);
    }
  }

  dataIt = data.begin();
  upperBound = data.begin();
  lowerBound = data.end();
}
void Recollection::save(const std::string &str) {
  if (validDataIt){
    uint32_t dataLineToAdd = dataIt - data.begin();
    history.push_front(dataLineToAdd);
    history.erase(dataToHistory[dataLineToAdd]);
    dataToHistory[dataLineToAdd] = 0;
  }

}

void Recollection::store() {

  std::ofstream df(absPath);
  std::ofstream hf(absPath + histPrefix);

  if (!df.good() && !hf.good()) {
    std::cerr << "Open output file's at " << absPath << " failed!!\n";
    return;
  }

  std::copy(data.begin(), data.end(),
            std::ostream_iterator<std::string>(df, "\n"));

  std::copy(history.begin(), history.end(),
            std::ostream_iterator<int>(hf, "\n"));
}

Recollection::~Recollection() {
  //  store();
}

// ------------------------ Debug stuff -------------------------

void Recollection::dbgPrintBounds() {
  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, data, dataIt, upperBound,
                                     lowerBound);
}

void Recollection::dbgPrintContent() {
  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, data, dataIt);
  ppVector<std::deque<uint32_t>>(DBG_PEEK_SIZE, history, history.begin());
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

} // namespace Manduca

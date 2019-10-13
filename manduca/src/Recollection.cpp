#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h> /* getenv */

#include "Recollection.hpp"
#include "DebugPrinter.hpp"

namespace Manduca {

Recollection::Recollection(const std::string &fileName, size_t historyLimit)
    : fileName(fileName), historyLimit(historyLimit) {

  std::string home(getenv("HOME"));
  folder = home + "/.manduca-history";
  absPath = folder + "/" + fileName;
}

int32_t Recollection::getPos() const { return dataIt - data.begin(); } 

void Recollection::setBounds(const std::string &suggestionSeed){
  auto comp = [] (const std::string &a, const std::string &b ) -> bool { 
    return (a.compare(0,b.length(),b) <= 0 );
   };
  lowerBound = std::lower_bound(data.begin(), data.end(), suggestionSeed, comp);
  upperBound = std::lower_bound(data.begin(), data.end(), suggestionSeed);
  state = State::IN_BOUNDS;
}

std::string Recollection::suggestNext(const std::string &suggestionSeed) {

  if(state == State::IN_BOUNDS){
    dataIt++;
    if(dataIt == lowerBound){
      dataIt = upperBound;
    }
  } else{
    setBounds(suggestionSeed);
      dataIt = upperBound + 1;
  }
  return *dataIt;
}
std::string Recollection::suggestPrev(const std::string &suggestionSeed) {

  if(state == State::IN_BOUNDS){
    dataIt--;
    if(dataIt == upperBound - 1){
      dataIt = lowerBound - 1;
    }
  } else{
    setBounds(suggestionSeed);
      dataIt = lowerBound - 1;
  }
  return *dataIt;
}

std::string Recollection::recallNext() {}
std::string Recollection::recallPrev() {}

std::string Recollection::suggest(const std::string &suggestionSeed) {

  if (suggestionSeed.empty()) {
    return "";
  }

  if (suggestionSeed.length() < (*dataIt).length()) {
    dataIt = data.begin();
  }
  state = State::SEARCHING;

  dataIt = std::lower_bound(dataIt, data.end(), suggestionSeed);
  return *dataIt;
}
void Recollection::dbgPrintBounds(){
  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, data, dataIt, upperBound, lowerBound);
}

void Recollection::dbgPrintContent(){
  ppVector<std::vector<std::string>>(DBG_PEEK_SIZE, data, dataIt);
}

void Recollection::dbgPrintAttr() {
  std::cout << "fileName: " << fileName << std::endl;
  std::cout << "folder: " << folder << std::endl;
  std::cout << "absPath: " << absPath << std::endl;
  std::cout << "historyLimit: " << historyLimit << std::endl;
}

void Recollection::load() {

  // if (fs::exists(absPath)) {
  std::ifstream hf(absPath, std::ifstream::in);
  std::string line;
  data.reserve(historyLimit);
  while (std::getline(hf, line)) {
    data.emplace_back(std::move(line));
  }
  dataIt = data.begin();
  upperBound = data.begin();
  lowerBound = data.end();
  // }
}

void Recollection::store() {

  std::ofstream hf(absPath);

  if (!hf) {
    std::cerr << "Open output file at " << absPath << " failed!!\n";
    return;
  }
  std::sort(data.begin(), data.end());
  std::copy(data.begin(), data.end(),
            std::ostream_iterator<std::string>(hf, "\n"));
}

void Recollection::test() {
  load();
  dbgPrintAttr();
  dbgPrintContent();
  // store();
}

} // namespace Manduca

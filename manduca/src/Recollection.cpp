#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h> /* getenv */

#include "Recollection.hpp"

namespace Manduca {

Recollection::Recollection(const std::string &fileName, size_t historyLimit)
    : fileName(fileName), historyLimit(historyLimit) {

  std::string home(getenv("HOME"));
  folder = home + "/.manduca-history";
  absPath = folder + "/" + fileName;
}

int32_t Recollection::getPos() const{
  return dataIt - data.begin();
}


std::string Recollection::suggest(const std::string &suggestionSeed) {
  dataIt = std::lower_bound(dataIt, data.end(), suggestionSeed);
  return *dataIt;
}

void Recollection::dbgPrint() {
  std::cout << "fileName: " << fileName << std::endl;
  std::cout << "folder: " << folder << std::endl;
  std::cout << "absPath: " << absPath << std::endl;
  std::cout << "historyLimit: " << historyLimit << std::endl;

  std::cout << "data content (first " << DBG_PEEK_SIZE << " items): " << std::endl;

  int32_t peek = data.size() > DBG_PEEK_SIZE ? DBG_PEEK_SIZE : data.size();

  for (int i = 0; i < peek; i++) {
    std::cout << data[i] << '\n';
  }

  std::cout << std::endl;
  // std::cout << "fs::exists(absPath): " << fs::exists(absPath) << std::endl;
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
  dbgPrint();
  load();
  store();
}

} // namespace Manduca

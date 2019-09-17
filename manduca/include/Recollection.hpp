#pragma once

#include <string>
#include <vector>

namespace Manduca {
class Recollection {
public:
  // Recollection() = default;
  Recollection(const std::string &fileName, size_t historyLimit = 10000);
  // Recollection();

  Recollection(Recollection &&) = default;
  Recollection(const Recollection &) = default;
  Recollection &operator=(Recollection &&) = default;
  Recollection &operator=(const Recollection &) = default;
  ~Recollection() = default;

  void load();
  void store();
  void merge();
  // std::string proposeCandidate(std::string fromStr);
  
  std::string suggest(const std::string &suggestionSeed);
  std::string nextSuggestion();
  std::string prevSuggestion();


  void test();
  void dbgPrint();

private:

  std::vector<std::string>::iterator dataIt;


  std::string fileName;
  std::string folder;
  std::string absPath;
  size_t historyLimit;

  std::vector<std::string> data;
  std::vector<int32_t> history;
  std::vector<std::string> newData;
};
} // namespace Manduca

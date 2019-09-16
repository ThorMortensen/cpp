#pragma once

#include <filesystem>
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
  auto suggest(const std::string &suggestionSeed);

  void test();
  void dbgPrint();

private:

  std::string fileName;
  std::filesystem::path folder;
  std::filesystem::path absPath;
  size_t historyLimit;

  std::vector<std::string> data;
  std::vector<int32_t> history;
  std::vector<std::string> newData;
};
} // namespace Manduca

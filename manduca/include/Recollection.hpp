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
  
  std::string suggest(const std::string &suggestionSeed);
  std::string nextSuggestion();
  std::string prevSuggestion();

  void test();
  void dbgPrint();

  int32_t getPos() const;

private:

  enum class State {
    START,
    SEARCHING,

   };

  State state = State::START;
  std::string searchStr;
  std::vector<std::string>::iterator dataIt;

  constexpr static int DBG_PEEK_SIZE = 10;

  std::string fileName;
  std::string folder;
  std::string absPath;
  size_t historyLimit;

  std::vector<std::string> data;
  std::vector<int32_t> history;
  std::vector<std::string> newData;
};
} // namespace Manduca

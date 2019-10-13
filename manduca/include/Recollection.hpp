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
  std::string suggestNext(const std::string &suggestionSeed);
  std::string suggestPrev(const std::string &suggestionSeed);
  std::string recallNext();
  std::string recallPrev();

  void test();
  void dbgPrintContent();
  void dbgPrintBounds();
  void dbgPrintAttr();

  int32_t getPos() const;

private:
  void setBounds(const std::string &suggestionSeed);

  std::vector<std::string>::iterator upperBound;
  std::vector<std::string>::iterator lowerBound;

  enum class State {
    IN_BOUNDS,
    SEARCHING,

  };

  State state = State::SEARCHING;
  std::string searchStr;
  std::vector<std::string>::iterator dataIt;

  constexpr static int DBG_PEEK_SIZE = 15;

  std::string fileName;
  std::string folder;
  std::string absPath;
  size_t historyLimit;

  std::vector<std::string> data;
  std::vector<int32_t> history;
  std::vector<std::string> newData;
};
} // namespace Manduca

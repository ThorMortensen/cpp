#pragma once

#include <deque>
#include <string>
#include <vector>

namespace Manduca {
class Recollection {
public:

  Recollection(const std::string &fileName, size_t historyLimit = 10000);
  Recollection(Recollection &&) = default;
  Recollection(const Recollection &) = default;
  Recollection &operator=(Recollection &&) = default;
  Recollection &operator=(const Recollection &) = default;
  ~Recollection();

  void load();
  void store();

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
    HISTORY_CRAWL,
  };

  State state = State::SEARCHING;
  std::vector<std::string> ::iterator dataIt;

  constexpr static int DBG_PEEK_SIZE = 15;

  std::string fileName;
  std::string folder;
  std::string absPath;
  inline static const std::string histPrefix = ".histIdx";
  size_t historyLimit;

  std::deque<uint32_t > history;
  std::deque<uint32_t > dataToHistory;
  std::vector<std::string> data;
  uint32_t histIdx = 0;

  bool validDataIt = true;


  void save(const std::string &str);
};
} // namespace Manduca

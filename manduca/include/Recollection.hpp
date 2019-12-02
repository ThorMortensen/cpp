#pragma once

#include <deque>
#include <list>
#include <map>
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

  enum class State {
    IN_BOUNDS,
    SEARCHING,
    HISTORY_CRAWL,
  };

  State state = State::SEARCHING;

  constexpr static int DBG_PEEK_SIZE = 15;

  std::string fileName;
  std::string folder;
  std::string absPath;
  inline static const std::string histPrefix = ".histIdx";
  size_t historyLimit;


  struct mhist {
    std::map<std::string, mhist>::iterator content;

  };

  typedef std::map<std::string, mhist>::iterator mapIt;

  std::list<mhist> history;
  std::map<std::string, mhist> data;

  mapIt dataIt;
  mapIt upperBound;
  mapIt lowerBound;
  uint32_t histIdx = 0;

  bool validDataIt = true;

  std::vector<std::string> dbgPrintVector;
  void loadDbgPrint();
  bool dbgPrintIsLoaded = false;

  void save(const std::string &str);
};
} // namespace Manduca

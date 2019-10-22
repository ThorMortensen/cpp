#pragma once

#include <string>
#include <vector>

#include "Curser.hpp"
#include "Recollection.hpp"

namespace Manduca {

class Prompt {
public:
  // Prompt() = default;
  Prompt(const std::string &nameHistDB);
  Prompt();
  Prompt(Prompt &&) = default;
  Prompt(const Prompt &) = default;
  Prompt &operator=(Prompt &&) = default;
  Prompt &operator=(const Prompt &) = default;
  ~Prompt() = default;

  int32_t choose(const std::string &question,
                 const std::vector<std::string> &options);

  std::string ask(const std::string &question,
                  const std::string &defaultAnsw = "");

  void test();

private:
  Curser c;
  Recollection recall;
  enum class CS { APPEND, INSERT, PREPEND };

  CS curserState = CS::APPEND;

  int32_t curserOffset = 0;

  void moveCurser(KeyCode direction, std::string &inputStr,
                  const std::string_view &suggestion);
  void addToStr(std::string &inputStr, char ch);

  // std::string dbName;
};

} // namespace Manduca

#pragma once

#include <functional>
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
  std::tuple<std::string, bool>
  ask(const std::string &question, const std::string &defaultAnsw,
      const std::function<void(const std::string &)> validate);
  void save(const std::string &string);
  void save();

  void test();

private:
  Curser c;
  Recollection recall;
  enum class CS { APPEND, INSERT, PREPEND };

  CS cursorState = CS::APPEND;

  int32_t cursorOffset = 0;

  void moveCursor(KeyCode direction, std::string &inputStr,
                  const std::string_view &suggestion);
  void addToStr(std::string &inputStr, char ch);
  std::string lastInputStr;
};

} // namespace Manduca

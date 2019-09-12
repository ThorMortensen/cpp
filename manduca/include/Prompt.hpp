#pragma once

#include <string>
#include <vector>

#include "Curser.hpp"

namespace Manduca {

class Prompt {
public:
  Prompt() = default;
  Prompt(std::string nameHistDB);
  Prompt(Prompt &&) = default;
  Prompt(const Prompt &) = default;
  Prompt &operator=(Prompt &&) = default;
  Prompt &operator=(const Prompt &) = default;
  ~Prompt() = default;

  int32_t choose(const std::string &question,
                 const std::vector<std::string> &options) ;

  std::string ask(const std::string &question, std::string defaultAnsw);

private:
  Curser c;
  std::string dbName;
 
};

} // namespace Manduca

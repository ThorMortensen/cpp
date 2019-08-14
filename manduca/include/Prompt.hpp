#pragma once

#include <string>

#include "Curser.hpp"

namespace Manduca {

class Prompt {
private:
  /* data */
public:
  Prompt(/* args */);
  ~Prompt();

  std::string prompt(std::string inputStr);
};

} // namespace Manduca

#include "Prompt.hpp"

#include <iostream>

namespace Manduca {

Prompt::Prompt(/* args */) {}

Prompt::~Prompt() {}

std::string Prompt::prompt(std::string inputStr) {
  return inputStr + " foo ";
}

} // namespace Manduca
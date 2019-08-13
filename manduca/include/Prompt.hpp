#pragma once
#include <string>

namespace Manduca {

class Prompt {
private:
  /* data */
public:
  Prompt(/* args */);
  ~Prompt();

  std::string prompt(std::string inputStr);
};

} // namespace manduca

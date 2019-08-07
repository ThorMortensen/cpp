#pragma once
#include <string>

// namespace manduca {

class manduca {
private:
  /* data */
public:
  manduca(/* args */);
  ~manduca();

  void initTerminal();
  std::string prompt(std::string inputStr);
};

// } // namespace manduca

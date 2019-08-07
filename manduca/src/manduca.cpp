#include "manduca.hpp"

#include <curses.h>

// namespace manduca {

manduca::manduca(/* args */) {}

manduca::~manduca() {}

void manduca::initTerminal(){
  initscr();

  endwin();
}

std::string manduca::prompt(std::string inputStr) {
  initTerminal();
  
  addstr(inputStr.c_str);
}

// } // namespace manduca
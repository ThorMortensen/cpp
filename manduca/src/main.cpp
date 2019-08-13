#include <iostream>
#include <ncurses.h>

#include "Prompt.hpp"

int main(/* int argc, char const *argv[] */ ) {



  std::cout << "prompt test starts..." << std::endl;


  Manduca::Prompt m;

  m.prompt("Hello world!");

  std::cout << "prompt test ends..." << std::endl;

  return 0;
}

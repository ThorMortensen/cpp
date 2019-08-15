#include <iostream>
#include <ncurses.h>

#include "Curser.hpp"

#include "Manduca.hpp"

std::string foo(const std::string &s) { return s + " bla bla "; }

int main(/* int argc, char const *argv[] */) {

  std::cout << "prompt test starts..." << std::endl;

  Manduca::Curser c;

  c.move(Manduca::Curser::Direction_e::UP);
  c.print("Hello curser");

  std::cout << "prompt test ends..." << std::endl;

  return 0;
}
// Fixed color. Must find solutasdion to curser movement.
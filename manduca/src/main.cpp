#include <iostream>
#include <ncurses.h>

#include "Color.hpp"
#include "Curser.hpp"

std::string foo(const std::string &s) { return s + " bla bla "; }

int main(/* int argc, char const *argv[] */) {

  Manduca::Color color;

  std::string s = "foo";
  std::string b = "foo";

  b = foo(s);



  std::cout << color.red(b) << std::endl;

  // std::cout << "prompt test starts..." << std::endl;

  // Manduca::Curser c;

  // c.print("Hello curser");

  // std::cout << "prompt test ends..." << std::endl;

  return 0;
}

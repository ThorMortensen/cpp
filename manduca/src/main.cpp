#include <iostream>
#include <ncurses.h>

#include "Curser.hpp"

#include "Manduca.hpp"

void testStrCol() {

  Manduca::Curser c;

  c.move(Manduca::Curser::Direction_e::UP);
  c.print("Hello curser");
}

void testBound() {
  // Manduca::bound<int> f(0, 0, 10);

  // std::cout << "F is 1: [" << f.get() << "]"<< std::endl;

  // f = 123;

  // std::cout << "F is 2: [" << f.get() << "]"<< std::endl;

  // f = 5;

  // std::cout << "F is 3: [" << f.get() << "]"<< std::endl;

  // f = 5;

  // std::cout << "F is 3: [" << f.get() << "]"<< std::endl;
}

void testCurserMovement() {
  Manduca::Curser c;
  c.print("This is 0 (aka home)");

  // c.move(Manduca::Curser::Direction_e::UP, 3);
  c.print("This is 3 up");
  c.goHome();



}

int main(/* int argc, char const *argv[] */) {

  std::cout << "prompt test starts..." << std::endl;

  testCurserMovement();

  std::cout << "prompt test ends..." << std::endl;

  return 0;
}

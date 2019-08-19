#include <iostream>
#include <ncurses.h>

#include "Curser.hpp"

#include "Manduca.hpp"



void testStrCol(){


  Manduca::Curser c;

  c.move(Manduca::Curser::Direction_e::UP);
  c.print("Hello curser");
}


int main(/* int argc, char const *argv[] */) {

  std::cout << "prompt test starts..." << std::endl;

  Manduca::bound<int> f(0, 0, 10);

  std::cout << "F is 1: [" << f.get() << "]"<< std::endl;

  f.set(23);

  std::cout << "F is 2: [" << f.get() << "]"<< std::endl;

  f = 5;

  std::cout << "F is 3: [" << f.get() << "]"<< std::endl;





  std::cout << "prompt test ends..." << std::endl;

  return 0;
}

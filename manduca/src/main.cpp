#include "Curser.hpp"
#include "Manduca.hpp"
#include <iostream>
#include <unistd.h>
#include "Recollection.hpp"

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

  for (int i = 0; i < 10; i++) {
    // c.print(std::to_string(i) + "\n");
    std::cout << std::to_string(i) << std::endl;
  }
  // c.flush();

  sleep(3);

  c.jumpLinesUp(5);
  c.print("this is 5 up");

  c.jumpLinesDown(5);
  c.print("this is 5 DOWN");
  c.print("\n");

  c.flush();
}

void testPrompt() {
  std::vector<std::string> opt = {"one", "two", "three", "four"};
  Manduca::Prompt prompt;

  int32_t answ = prompt.choose("Choose one:", opt);

  std::cout << "You chose number [" << answ << "]" << std::endl;
  std::cout << "You chose opt [" << opt[answ] << "]" << std::endl;
}

void keyCodeDbg() {
  Manduca::Curser c;
  c.printDbgKeyPress();
}

void stringTests() {
  std::string ts;

  std::cout << ts.capacity() << std::endl;
  ts.clear();
  ts += 'c';
  std::cout << ts.capacity() << std::endl;
}


void recollectionTests(){
  Manduca::Recollection r("manduca-10000-test-sorted");
  r.test();
  

}

int main(/* int argc, char const *argv[] */) {

  // std::cout << "prompt test starts..." << std::endl;

  // keyCodeDbg();
  // testPrompt();
  // testCurserMovement();
  // stringTests();
  recollectionTests();

  // std::cout << "prompt test ends..." << std::endl;

  return 0;
}

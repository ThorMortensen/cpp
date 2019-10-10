#include "Curser.hpp"
#include "Manduca.hpp"
#include "Recollection.hpp"
#include <iostream>
#include <unistd.h>

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
  std::cout << "hello world";
  c.clearLine();
  std::cout << "987654321";
  c.move(Manduca::Curser::Direction_e::LEFT, 6);
  std::string foo;
  std::cin >> foo;

  return;

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

void testPromptChoose() {
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

void recollectionTests() {
  Manduca::Recollection r("manduca-10000-test-sorted");
  r.test();
}

void testPromptAsk() {
  Manduca::Prompt p("manduca-10000-test-sorted");
  p.test();
  // p.ask("Enter something ~> ");
}


void testDebugPrinter(){
  std::vector<std::string> sv{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten"
  };

  std::vector<std::string>::iterator it = sv.begin() + 0;
  std::vector<std::string>::iterator it2 = sv.begin() + 6;


  Manduca::ppVector<std::vector<std::string>>(3, sv, it, it2);

}

int main(/* int argc, char const *argv[] */) {

  testDebugPrinter();

  // testPromptAsk();
  // testCurserMovement();

  // std::cout << "prompt test starts..." << std::endl;
  // keyCodeDbg();
  // testPromptChoose();
  // stringTests();
  // recollectionTests();

  // std::cout << "prompt test ends..." << std::endl;

  return 0;
}

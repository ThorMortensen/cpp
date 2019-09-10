/**
 * @file Curser.cpp
 * @author Thor Mortensen (thor.mortensen@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-08-16
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "Curser.hpp"
#include "Manduca.hpp"

// #include <conio.h>
#include <iostream>

#include <stdio.h>

namespace Manduca {

void Curser::flush() { std::cout.flush(); }

void Curser::print(const std::string &str) {
  curserPos.x += str.length();
  std::cout << str;
}

void Curser::jumpLinesDown(int amount) {
  move(Direction_e::DOWN, amount);
  std::cout << "\r";
}

void Curser::jumpLinesUp(int amount) {
  move(Direction_e::UP, amount);
  std::cout << "\r";
}

void Curser::clearLine() {}

void Curser::clearDown() {
  curserAction(CS_D);
  flush();
}

void Curser::caretShow(bool isShowing) const {
  curserAction(isShowing ? SHOW_CURSER : HIDE_CURSER);
}

char Curser::getKeyPress() const {
  char c = 0;
  system("/bin/stty raw -echo");
  // std::cin >> c;
  c = getchar();
  system("/bin/stty sane");
  return c;
}

void Curser::printDbgKeyPress() const {
  while (true) {
    char kc = getKeyPress();
    std::cout << "KeyCode [" << std::to_string(static_cast<int32_t>(kc))
              << "], Char --> " << static_cast<char>(kc) << std::endl;
    if (static_cast<char>(kc) == 'q') {
      return;
    }
  }

  // while (true) {
  //   // KeyCode kc = getKeyPress();
  //   char str[256] = {0};
  //   std::string c;
  //   system("/bin/stty raw");
  //   // std::cin >> c;
  //   std::getline(std::cin, c);

  //   // std::cin.get(str, 256);
  //   c = getchar();
  //   system("/bin/stty cooked");
  //   // std::string c(str);

  //   std::cout << "String codes [";
  //   for (size_t i = 0; i < c.length(); i++) {
  //     std::cout << std::to_string(static_cast<int32_t>(c[i])) << ", ";
  //   }

  //   std::cout << " Str [" << c << "]" << std::endl;
  //   if (c == "q") {
  //     return;
  //   }
  // }
}

void Curser::curserAction(const std::string_view &cmd) const {
  std::cout << ESC_START << cmd;
}

void Curser::move(const Direction_e d) { move(d, 1); }

void Curser::goHome() {
  curserAction(GHOME);
  curserPos = {0};
}

void Curser::move(const Direction_e d, int amount) {
  switch (d) {
  case Direction_e::LEFT:
    curserAction(std::to_string(amount) + LEFT);
    curserPos.x -= amount;
    break;
  case Direction_e::RIGHT:
    curserAction(std::to_string(amount) + RIGHT);
    curserPos.x += amount;
    break;
  case Direction_e::UP:
    curserAction(std::to_string(amount) + UP);
    curserPos.y += amount;
    break;
  case Direction_e::DOWN:
    curserAction(std::to_string(amount) + DOWN);
    curserPos.y -= amount;
    break;
  default:
    std::cout << "Defaulted in move" << std::endl;
  }
}

} // namespace Manduca

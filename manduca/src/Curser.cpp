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

namespace Manduca {

void Curser::print(const std::string &str) {
  curserPos.x += str.length();
  std::cout << str;
}

void Curser::move(const Direction_e d) { move(d, 1); }

void Curser::goHome() { std::cout << "\e[H"; }



void Curser::clearLine() {

}
void Curser::printMenu() {

}

void Curser::move(const Direction_e d, int amount) {
  std::cout << "\e[";
  switch (d) {
  case Direction_e::LEFT:
    std::cout << amount << "D";
    curserPos.x -= amount;
    break;
  case Direction_e::RIGHT:
    std::cout << amount << "C";
    curserPos.x += amount;
    break;
  case Direction_e::UP:
    std::cout << amount << "A";
    curserPos.y += amount;
    break;
  case Direction_e::DOWN:
    std::cout << amount << "B";
    curserPos.y -= amount;
    break;
  default:
    std::cout << "Defaulted in move" << std::endl;
  }
}

} // namespace Manduca

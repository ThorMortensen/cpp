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
  std::cout << str << std::endl;
}

// Esc[ValueA	Move cursor up n lines	CUU

void Curser::move(const Direction_e d) { move(d, 1); }

void Curser::move(const Direction_e d, int amount) {
  switch (d) {
  case Direction_e::LEFT:
    // "\e[30m"+str+"\e[0m"
    curserPos.x -= amount;
    break;
  case Direction_e::RIGHT:
    curserPos.x += amount;
    break;
  case Direction_e::UP:
    // Esc[2J
    std::cout << "\e[3A" << std::endl;
    curserPos.y += amount;
    break;
  case Direction_e::DOWN:
    curserPos.y -= amount;
    break;
  default:
    std::cout << "Defaulted in move" << std::endl;
  }
}

} // namespace Manduca

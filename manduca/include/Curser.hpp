/**
 * @file Curser.hpp
 * @author Thor Mortensen (thor.mortensen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-08-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include <cstdint>
#include <iostream>

#include "Color.hpp"

namespace Manduca {

class Curser {
public:
  Curser() = default;
  Curser(Curser &&) = default;
  Curser(const Curser &) = default;
  Curser &operator=(Curser &&) = default;
  Curser &operator=(const Curser &) = default;
  ~Curser() = default;

  enum class Direction_e { UP, DOWN, LEFT, RIGHT };


  struct Coordinate_s {
    int x = 0;
    int y = 0;
  };

  void move(const Direction_e d, int amount);
  void move(const Direction_e d);
  void print(const std::string &str);

private:
  Coordinate_s curserPos = {0};
};

} // namespace Manduca

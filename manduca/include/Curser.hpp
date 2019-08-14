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

  void print(std::string str);

private:
  int curserPos = 0;
  Color color = {};

  enum class Direction { UP, DOWN, LEFT, RIGHT };

  void move(Direction d);
};

} // namespace Manduca

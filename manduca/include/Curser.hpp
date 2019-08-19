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

template <class T> class bound {

private:
  T val;
  T lMin;
  T lMax;

  T limit(T value) {
    if (value > lMax) {
      return lMax;
    } else if (value < lMin) {
      return lMin;
    } else {
      return value;
    }
  }

public:
  bound(T value, T limitMin, T limitMax)
      : val(value), lMin(limitMin), lMax(limitMax) {}

  T get() { return val; }
  T set(T value) {
    val = limit(value);
    return get();
  }

  void operator=(T value) { set(value); }

}; // namespace Manduca

// template <class T>
// class bound {
//    private:
//       vector<T> elems;    // elements

//    public:
//       void push(T const&);  // push element
//       void pop();               // pop element
//       T top() const;            // return top element

//       bool empty() const {      // return true if empty.
//          return elems.empty();
//       }
// };

} // namespace Manduca

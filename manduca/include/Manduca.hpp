/**
 * @file Manduca.hpp
 * @author Thor Mortensen (thor.mortensen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-08-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once 

#include "Color.hpp"
#include "Prompt.hpp"

namespace mDye = Manduca::Color;


template <class T> class bound {
private:
  T val;
  T lMin;
  T lMax;

  T limit(T value) {
    if (value > lMax) {
      val = lMax;
    } else if (value < lMin) {
      val = lMin;
    }
    return val;
  }

public:
  bound(T value, T limitMin, T limitMax)
      : val(value), lMin(limitMin), lMax(limitMax) {}

  T operator=(T value) { return limit(value); }

  T operator++() { return limit(val++); }
  T operator++(int) {
    T tmp = val;  // copy
    operator++(); // pre-increment
    return tmp;   // return old value
  }

  T get(){
    return val;
  }

  // std::ostream &operator<<(std::ostream &os, const T& obj) {
  //   // write obj to stream
  //   os << obj.val;
  //   return os;
  // }
  // std::istream &operator>>(std::istream &is, T value) {
  //   // read obj from stream
  //   if (/* T could not be constructed */)
  //     is.setstate(std::ios::failbit);
  //   return is;
  // }

};
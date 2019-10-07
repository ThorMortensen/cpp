#pragma once

#include <iostream>
#include <optional>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Color.hpp"

namespace Manduca {

#define DBP(...)                                                               \
  std::cout << __FUNCTION__ << "( " << __LINE__ << "): {" #__VA_ARGS__ "}-->[" \
            << __VA_ARGS__ << "]\n";
// https://en.wikipedia.org/wiki/Variadic_macro
// #define dbgprintf(...) realdbgprintf (__FILE__, __LINE__, __VA_ARGS__)

template <typename T, typename... iteratorList>
void ppVector(int32_t lines, const T &printebleVector,
              iteratorList... iterators) {

  static const std::size_t itCount = sizeof...(iterators);

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int32_t colWidth = w.ws_col;

  if (itCount < 0) {
    colWidth = w.ws_col / itCount;
  }

  if (lines <= 0) {
    lines = w.ws_row;
  }

  for (size_t i = 0; i < lines; i++) {
    for (const auto it : {iterators...}) {
      
    }
  }

  printf("itCount %d\n", itCount);
  printf("lines %d\n", w.ws_row);
  printf("columns %d\n", w.ws_col);
}

// template<class... Args>
// void print(Args... args)
// {
//     (std::cout << ... << args) << "\n";
// }
// print(1, ':', " Hello", ',', " ", "World!");
// And another with enforced type match for all arguments:

// #include <type_traits> // enable_if, conjuction

// template<class Head, class... Tail>
// using are_same = std::conjunction<std::is_same<Head, Tail>...>;

// template<class Head, class... Tail, class = std::enable_if_t<are_same<Head,
// Tail...>::value, void>> void print_same_type(Head head, Tail... tail)
// {
//     std::cout << head;
//     (std::cout << ... << tail) << "\n";
// }
// print_same_type("2: ", "Hello, ", "World!");   // OK
// print_same_type(3, ": ", "Hello, ", "World!"); // no matching function for
// call to 'print_same_type(int, const char [3], const char [8], const char
// [7])'
//                                                // print_same_type(3, ": ",
//                                                "Hello, ", "World!");

} // namespace Manduca

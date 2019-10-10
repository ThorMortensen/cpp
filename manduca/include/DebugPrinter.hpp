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
  int32_t vSize = static_cast<int32_t>(printebleVector.size());

  if (vSize == 0) {
    std::cout << Color::brown("Vector is empty...\n");
    return;
  }

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int32_t colWidth = w.ws_col;

  if (itCount < 0) {
    colWidth = w.ws_col / itCount;
  }

  if (lines <= 0) {
    lines = w.ws_row;
  }

  if (vSize < lines) {
    lines = vSize;
  }

  for (const auto it : {iterators...}) {
    

    int32_t itPos = it - printebleVector.begin();
    int32_t start = itPos - (lines / 2);
    int32_t end = itPos + (lines / 2);

    if (itPos < 0 || itPos > vSize) {
      std::cout << Color::brown("Invalid iterator pos...\n");
      continue;
    }

    if (start < 0) {
      end += start * (-1);
      start = 0;
    }

    if (end >= vSize) {
      start += vSize - end - 1;
      end = vSize - 1;
    }

    int32_t digitLength = std::to_string(end).length();
    std::string fs("[%" + std::to_string(digitLength) + "d] ");
    std::string fsItPos(
        Color::bold(Color::green("‣[%" + std::to_string(digitLength) + "d] ")));

    DBP(std::min(lines, end))
    DBP(start)

    for (int32_t i = 0; i < lines; i++) {
      if ((start + i) == itPos) {
        printf(fsItPos.c_str(), start + i);
        std::cout << Color::bold(Color::green(printebleVector[start + i]))
                  << "\n";
      } else {
        printf(fs.c_str(), start + i);
        std::cout << printebleVector[start + i] << "\n";
      }
    }
  }

  // for (size_t i = 0; i < lines; i++) {
  //   std::cout << printebleVector <<
  // }

  // printf("itCount %d\n", itCount);
  // printf("lines %d\n", w.ws_row);
  // printf("columns %d\n", w.ws_col);
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

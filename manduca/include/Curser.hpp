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
#include <sstream>

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

  void goHome();

  void clearLine();
  void printMenu();

  void curserAction(std::string cmd);

private:
  Coordinate_s curserPos = {0};
  inline static const std::string ESC_START = "\e[";
  // Movement
  inline static const std::string UP = "A";
  inline static const std::string DOWN = "B";
  inline static const std::string LEFT = "D";
  inline static const std::string RIGHT = "C";
  // Misc
  inline static const std::string SAVE = "s";
  inline static const std::string LOAD = "u";
  // Line clear
  inline static const std::string CL_R = "K";    // Clear line from cursor right	EL0
  inline static const std::string CL_L = "1K";   // Clear line from cursor left	EL1
  inline static const std::string CL_ALL = "2K"; // Clear entire line	EL2
  // Screen clear
  inline static const std::string CS_D = "J";    // Clear screen from cursor down	ED0
  inline static const std::string CS_U = "1J";   // Clear screen from cursor up	ED1
  inline static const std::string CS_ALL = "2J"; // Clear entire screen	ED2

  // #define CURSER_COMMANDS(CURSER_COMMAND)                                        \
//   /*             name ,   value      */                                        \
//   CURSER_COMMAND(CLEAR_LINE, "[H")                                             \
//   CURSER_COMMAND(SAVE, "[s")                                                   \
//   CURSER_COMMAND(LOAD, "[u")

  // #define GENERATE_ENUM(name, val) name##_e,
  // #define GENERATE_STRING(name, val) val,

  //   enum CurserCmd { CURSER_COMMANDS(GENERATE_ENUM) CMD_COUNT };
  //   std::string curserCmdStrings[CMD_COUNT] = {
  //   CURSER_COMMANDS(GENERATE_STRING)};
};

} // namespace Manduca

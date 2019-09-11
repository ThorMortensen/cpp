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
#include "KeyCodes.hpp"

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
  void clearDown();
  void flush();

  void jumpLinesDown(int amount);
  void jumpLinesUp(int amount);

  KeyCode getKeyPress();

  void caretShow(bool isShowing) const;

  void printDbgKeyPress() const;

  std::string inputStr;


private:
  Coordinate_s curserPos = {0};
  void curserAction(const std::string_view& cmd) const;
  void setRawTerminal(bool isRaw) const;

  constexpr static const char ESC_START[] = "\e[";
  // Movement
  constexpr static const char UP[] = "A";
  constexpr static const char DOWN[] = "B";
  constexpr static const char LEFT[] = "D";
  constexpr static const char RIGHT[] = "C";
  // Misc
  constexpr static const char SAVE[] = "s";
  constexpr static const char LOAD[] = "u";
  constexpr static const char GHOME[] = "H"; // Go home
  constexpr static const char HIDE_CURSER[] = "?25l"; // Go home
  constexpr static const char SHOW_CURSER[] = "?25h"; // Go home
  
  // Line clear
  constexpr static const char CL_R[] = "K";    // Clear line from cursor right	EL0
  constexpr static const char CL_L[] = "1K";   // Clear line from cursor left	EL1
  constexpr static const char CL_ALL[] = "2K"; // Clear entire line	EL2
  // Screen clear
  constexpr static const char CS_D[] = "J";    // Clear screen from cursor down	ED0
  constexpr static const char CS_U[] = "1J";   // Clear screen from cursor up	ED1
  constexpr static const char CS_ALL[] = "2J"; // Clear entire screen	ED2


  // #define CURSER_COMMANDS(CURSER_COMMAND)                                        
//   /*             name ,   value      */                                        
//   CURSER_COMMAND(CLEAR_LINE, "[H")                                             
//   CURSER_COMMAND(SAVE, "[s")                                                   
//   CURSER_COMMAND(LOAD, "[u")

  // #define GENERATE_ENUM(name, val) name##_e,
  // #define GENERATE_STRING(name, val) val,

  //   enum CurserCmd { CURSER_COMMANDS(GENERATE_ENUM) CMD_COUNT };
  //   std::string curserCmdStrings[CMD_COUNT] = {
  //   CURSER_COMMANDS(GENERATE_STRING)};
};

} // namespace Manduca

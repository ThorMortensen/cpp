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
#include <csignal>
#include <iostream>
#include <cstdio>

namespace Manduca {

void Curser::flush() const { std::cout.flush(); }

void Curser::print(const std::string &str) const {
  std::cout << str;
}

void Curser::jumpLinesDown(int amount) const {
  move(Direction_e::DOWN, amount);
  std::cout << "\r";
}

void Curser::jumpLinesUp(int amount) const {
  move(Direction_e::UP, amount);
  std::cout << "\r";
}

void Curser::clearLine() const {
  curserAction(CL_ALL);
  std::cout << "\r";
}

void Curser::clearDown() const {
  curserAction(CS_D);
  std::cout << "\r";
}

void Curser::caretShow(bool isShowing) const {
  curserAction(isShowing ? SHOW_CURSER : HIDE_CURSER);
}

void Curser::setRawTerminal(bool isRaw) const {
  if (isRaw) {
    system("/bin/stty raw -echo");
  } else {
    system("/bin/stty sane");
  }
}

KeyCode Curser::getKeyPress() {
  int c = 0;
  bool readingInput = true;
  KeyCode state = KeyCode::NOP;
  KeyCode nextState = KeyCode::NOP;

  inputStr.clear();

  setRawTerminal(true);

  while (readingInput) {
    c = getchar();

    nextState = static_cast<KeyCode>(c);

    if (nextState == KeyCode::SIGINT_KEY) { // 3
      setRawTerminal(false);
      std::raise(SIGINT);
    }

    inputStr.push_back(c);

    switch (state) {
    case KeyCode::NOP: // 0
      if (nextState != KeyCode::FUNC_START) {
        readingInput = false;
      }
      state = nextState;
      break;
    case KeyCode::FUNC_START: // 27
      if (nextState == KeyCode::FUNC_CONF) {
        state = nextState;
      } else {
        state = KeyCode::NOP;
        readingInput = false;
      }
      break;
    case KeyCode::FUNC_CONF: // 91
      state = nextState;
      if (nextState == KeyCode::DEL_START) {
        state = nextState;
      } else {
        readingInput = false;
      }
      break;

    default:
      state = nextState;
      readingInput = false;
      break;
    }
  }
  setRawTerminal(false);
  return state;
}

void Curser::printDbgKeyPress() const {
  while (true) {

    setRawTerminal(true);
    char kc = getchar();
    setRawTerminal(false);

    std::cout << "KeyCode [" << std::to_string(static_cast<int32_t>(kc))
              << "], Char --> " << static_cast<char>(kc) << std::endl;
    if (static_cast<char>(kc) == 'q') {
      return;
    }
  }
}

void Curser::curserAction(const std::string_view &cmd) const {
  std::cout << ESC_START << cmd;
}

void Curser::move(const Direction_e d) const { move(d, 1); }

void Curser::goHome() const {
  curserAction(GHOME);
}

void Curser::move(const Direction_e d, int amount) const {
  if (amount == 0) {
    return;
  }
  switch (d) {
  case Direction_e::LEFT:
    curserAction(std::to_string(amount) + LEFT);
    break;
  case Direction_e::RIGHT:
    curserAction(std::to_string(amount) + RIGHT);
    break;
  case Direction_e::UP:
    curserAction(std::to_string(amount) + UP);
    break;
  case Direction_e::DOWN:
    curserAction(std::to_string(amount) + DOWN);
    break;
  default:
    DEFAULT_ERR_MSG
  }
}

} // namespace Manduca

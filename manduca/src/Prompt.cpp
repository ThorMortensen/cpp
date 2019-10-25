#include "Prompt.hpp"
#include "Manduca.hpp"

namespace Manduca {

Prompt::Prompt(const std::string &nameHistDB) : recall(nameHistDB) {}

Prompt::Prompt() : recall("") {}

void Prompt::test() { recall.test(); }

void Prompt::moveCurser(KeyCode direction, std::string &inputStr,
                        const std::string_view &suggestion) {

  int32_t isl = static_cast<int32_t>(inputStr.length());
  if (isl == 0) {
    return;
  }

  switch (curserState) {
  case CS::APPEND:
    if (direction == KeyCode::LEFT) {
      curserOffset++;
      curserState = (curserOffset == isl - 1) ? CS::PREPEND : CS::INSERT;
    } else {
      if (suggestion.length() > inputStr.length()) {
        inputStr.push_back(suggestion.at(isl));
      }
    }
    break;
  case CS::PREPEND:
    if (direction == KeyCode::RIGHT) {
      curserOffset--;
      curserState = (curserOffset == 0) ? CS::APPEND : CS::INSERT;
    }
    break;
  case CS::INSERT:

    if (direction == KeyCode::LEFT) {
      curserOffset++;
      if (curserOffset == isl) {
        curserState = CS::PREPEND;
      }
    } else {
      curserOffset--;
      if (curserOffset == 0) {
        curserState = CS::APPEND;
      }
    }
    break;
  default:
    DEFAULT_ERR_MSG
    break;
  }
}

std::string Prompt::ask(const std::string &question,
                        const std::string &defaultAnsw) {
  bool done = false;
  KeyCode kIn = KeyCode::NOP;
  std::string suggestion = defaultAnsw;
  std::string inputStr;
  std::string ppStr;

  recall.load();
  recall.dbgPrintAttr();

  // c.caretShow(true);

  std::cout << question << mDye::gray(suggestion);

  while (!done) {
    kIn = c.getKeyPress();

    switch (kIn) {
    case KeyCode::UP:
      suggestion = recall.suggestNext(inputStr);
      break;
    case KeyCode::DOWN:
      suggestion = recall.suggestPrev(inputStr);
      break;
    case KeyCode::RIGHT:
    case KeyCode::LEFT:
      moveCurser(kIn, inputStr, suggestion);
      break;
    case KeyCode::ENTER:
      done = true;
      break;
    case KeyCode::NOP:
      break;
    case KeyCode::HOME:
      curserOffset = inputStr.length();
      break;
    case KeyCode::END:
      curserOffset = 0;
      break;
    case KeyCode::DEL:
      if (!inputStr.empty() && curserState != CS::APPEND) {
        if (curserState == CS::INSERT) {
          inputStr.erase(inputStr.length() - curserOffset,
                         1); // remove 1 char
          if (curserOffset == 0) {
            curserState = CS::APPEND;
          }
        } else {
          inputStr.erase(0, 1);
        }
        curserOffset--;
        suggestion = recall.suggest(inputStr);
      }
      break;
    case KeyCode::TAB:
      if (suggestion.length() > 0) {
        inputStr = suggestion;
        curserOffset = 0;
      }
      break;
    case KeyCode::BACK_SPACE:
      if (!inputStr.empty() && curserState != CS::PREPEND) {
        if (curserState == CS::INSERT) {
          inputStr.erase(inputStr.length() - curserOffset - 1,
                         1); // remove 1 char
          if (curserOffset == static_cast<int32_t>(inputStr.length())) {
            curserState = CS::PREPEND;
          }
        } else {
          inputStr.pop_back();
        }
        suggestion = recall.suggest(inputStr);
      }
      break;
    default:
      char ch = static_cast<char>(kIn);
      if (curserState == CS::APPEND) {
        inputStr.push_back(ch);
      } else {
        inputStr.insert(inputStr.length() - curserOffset, 1,
                        ch); // 1 copy of ch
      }
      suggestion = recall.suggest(inputStr);
      break;
    }
    NL;
    recall.dbgPrintBounds();
    NL;
    c.clearLine();
    int32_t dif = suggestion.length() - inputStr.length();
    if (dif > 0) {
      std::string pp =
          inputStr +
          mDye::dim(mDye::gray(suggestion.substr(inputStr.length(), dif)));
      std::cout << question << pp;
    } else {
      dif = 0;
      std::cout << question << inputStr;
    }
    c.move(Curser::Direction_e::LEFT, dif + curserOffset);
  }

  return inputStr;
}

int32_t Prompt::choose(const std::string &question,
                       const std::vector<std::string> &options) {
  int32_t optCount = static_cast<int>(options.size()) - 1;
  int32_t selection = 0;
  bool done = false;
  KeyCode kIn = KeyCode::NOP;

  std::cout << question << std::endl;
  c.caretShow(false);

  while (!done) {

    for (int32_t i = 0; i <= optCount; i++) {
      if (i == selection) {
        std::cout << mDye::green("‣ " + mDye::bold(options[i]));
      } else {
        std::cout << "  " << options[i];
      }
      if (i < optCount) {
        std::cout << "\n";
      }
    }

    kIn = c.getKeyPress();

    switch (kIn) {
    case KeyCode::UP:
      selection--;
      break;
    case KeyCode::DOWN:
      selection++;
      break;
    case KeyCode::ENTER:
      done = true;
      break;
    default:
      break;
    }

    if (selection > optCount) {
      selection = optCount;
    } else if (selection < 0) {
      selection = 0;
    }

    c.jumpLinesUp(optCount);
    c.flush();
  }

  c.caretShow(true);

  return selection;
}

} // namespace Manduca
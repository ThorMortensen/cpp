#include "Prompt.hpp"
#include "Manduca.hpp"

namespace Manduca {

Prompt::Prompt(const std::string &nameHistDB) : recall(nameHistDB) {}

Prompt::Prompt() : recall("") {}

std::string Prompt::ask(const std::string &question, std::string &defaultAnsw) {
  bool done = false;
  KeyCode kIn = KeyCode::NOP;
  std::string suggestion = defaultAnsw;
  std::string inputStr;
  // string suggestion;
  

  std::cout << question << mDye::gray(suggestion);

  while (!done) {
    kIn = c.getKeyPress();

    switch (kIn) {
    case KeyCode::UP:
      break;
    case KeyCode::DOWN:
      break;
    case KeyCode::ENTER:
      done = true;
      break;
    default:
      inputStr += static_cast<char>(kIn);
      suggestion = recall.suggest(inputStr);
      break;
    }
  }
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
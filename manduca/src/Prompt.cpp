#include "Prompt.hpp"
#include "Manduca.hpp"

namespace Manduca {

int32_t Prompt::choose(const std::string &question,
                       const std::vector<std::string> &options) {
  int32_t optCount = static_cast<int>(options.size());
  int32_t selection = 0;
  bool done = false;
  KeyCode kIn = KeyCode::NOP;

  std::cout << question << std::endl;

  while (!done) {

    for (int32_t i = 0; i < optCount; i++) {
      if (i == selection) {
        std::cout << mDye::green("‣ ") << mDye::green(options[i]);
      } else {
        std::cout << "  " << options[i];
      }
      if (i < optCount - 1) {
        std::cout << "\n";
      }
    }
    
    c.jumpLinesUp(optCount);
    c.caretShow(false);
    c.flush();

    kIn = c.getKeyPress();

    switch (kIn) {
    case KeyCode::UP:
      selection--;
      break;
    case KeyCode::DOWN:
      if (selection < static_cast<int>(options.size())) {
        selection++;
      }
      break;
    case KeyCode::ENTER:
      done = true;
      break;
    default:
      break;
    }
  }

  return selection;
}

} // namespace Manduca
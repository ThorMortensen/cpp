#include "Prompt.hpp"
#include "Manduca.hpp"

namespace Manduca {

void Prompt::paintChooseMenu(int32_t select,
                             const std::vector<std::string> &options)  {

  int32_t optCount = static_cast<int>(options.size());

  c.jumpLinesUp(optCount-2);
  c.clearDown();


  for (int32_t i = 0; i < optCount; i++) {
    if (i == select) {
      std::cout << mDye::green("‣ ") << mDye::green(options[i]);
    } else {
      std::cout << "  " << options[i];
    }
    if (i < optCount-1){
      std::cout << "\n";
    }
  }
}

int32_t Prompt::choose(const std::string &question,
                       const std::vector<std::string> &options)  {
  int32_t selection = 0;
  bool done = false;
  KeyCode kIn = KeyCode::NOP;

  std::cout << question << std::endl;

  while (!done) {
    paintChooseMenu(selection, options);
    kIn = c.getKeyPress();
    switch (kIn) {
    case KeyCode::Up:
      selection--;
      break;
    case KeyCode::Down:
      if (selection < static_cast<int>(options.size())) {
        selection++;
      }
      break;
    case KeyCode::KP_Enter:
    case KeyCode::Enter:
      done = true;
      break;
    default:
      std::cerr << "Defaulted in choose select";
      break;
    }
  }

  return selection;
}

} // namespace Manduca
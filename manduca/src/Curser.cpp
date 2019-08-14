#include "Curser.hpp"

namespace Manduca {



void Curser::print(std::string str) {

  std::cout << color.red(str) << "foo" << std::endl;


}

void Curser::move(Direction d) {
  switch (d) {
  case Direction::LEFT:
    std::cout << "Defaulted in move" << std::endl;
    curserPos++;
  default:
    std::cout << "Defaulted in move" << std::endl;
  }
}

} // namespace Manduca

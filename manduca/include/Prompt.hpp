#pragma once

#include <string>
#include <vector>

#include "Curser.hpp"

namespace Manduca {

class Prompt {
public:
  Prompt() = default;
  Prompt(Prompt &&) = default;
  Prompt(const Prompt &) = default;
  Prompt &operator=(Prompt &&) = default;
  Prompt &operator=(const Prompt &) = default;
  ~Prompt() = default;

  int32_t choose(const std::string &question,
                 const std::vector<std::string> &options) ;

private:
  Curser c;
  void paintChooseMenu(int32_t select,
                       const std::vector<std::string> &options) ;
};

} // namespace Manduca

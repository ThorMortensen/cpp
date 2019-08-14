#pragma once

#include <string>

namespace Manduca {

class Color {
public:
  Color() = default;
  Color(Color &&) = default;
  Color(const Color &) = default;
  Color &operator=(Color &&) = default;
  Color &operator=(const Color &) = default;
  ~Color() = default;

  std::string white(const std::string &str) const;
  std::string black(const std::string &str) const;
  std::string red(const std::string &str) const;
  std::string green(const std::string &str) const;
  std::string greenLight(const std::string &str) const;
  std::string brown(const std::string &str) const;
  std::string blue(const std::string &str) const;
  std::string magenta(const std::string &str) const;
  std::string cyan(const std::string &str) const;
  std::string gray(const std::string &str) const;
  std::string yellow(const std::string &str) const;
  std::string bg_black(const std::string &str) const;
  std::string bg_red(const std::string &str) const;
  std::string bg_green(const std::string &str) const;
  std::string bg_yell(const std::string &str) const;
  std::string bg_brown(const std::string &str) const;
  std::string bg_blue(const std::string &str) const;
  std::string bg_magenta(const std::string &str) const;
  std::string bg_cyan(const std::string &str) const;
  std::string bg_gray(const std::string &str) const;
  std::string bold(const std::string &str) const;
  std::string dim(const std::string &str) const;
  std::string italic(const std::string &str) const;
  std::string underline(const std::string &str) const;
  std::string blink(const std::string &str) const;
  std::string reverse_color(const std::string &str) const;

  std::string removeColor(const std::string &str) const;

private:
};

} // namespace Manduca

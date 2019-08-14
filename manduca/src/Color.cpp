#include "Color.hpp"


namespace Manduca
{
  
  std::string Color::white(const std::string &str) const {         return "\e[30m"+str+"\e[0m" ;}
  std::string Color::black(const std::string &str) const {         return "\e[30m"+str+"\e[0m" ;}
  std::string Color::red(const std::string &str) const {           return "\e[31m"+str+"\e[0m" ;}
  std::string Color::green(const std::string &str) const {         return "\e[32m"+str+"\e[0m" ;}
  std::string Color::greenLight(const std::string &str) const {    return "\e[92m"+str+"\e[0m" ;}
  std::string Color::brown(const std::string &str) const {         return "\e[33m"+str+"\e[0m" ;}
  std::string Color::blue(const std::string &str) const {          return "\e[34m"+str+"\e[0m" ;}
  std::string Color::magenta(const std::string &str) const {       return "\e[35m"+str+"\e[0m" ;}
  std::string Color::cyan(const std::string &str) const {          return "\e[36m"+str+"\e[0m" ;}
  std::string Color::gray(const std::string &str) const {          return "\e[37m"+str+"\e[0m" ;}
  std::string Color::yellow(const std::string &str) const {        return "\e[43m"+str+"\e[0m" ;}

  std::string Color::bg_black(const std::string &str) const {      return "\e[40m"+str+"\e[0m" ;}
  std::string Color::bg_red(const std::string &str) const {        return "\e[41m"+str+"\e[0m" ;}
  std::string Color::bg_green(const std::string &str) const {      return "\e[42m"+str+"\e[0m" ;}
  std::string Color::bg_yell(const std::string &str) const {       return "\e[103m"+str+"\e[0m";}
  std::string Color::bg_brown(const std::string &str) const {      return "\e[43m"+str+"\e[0m" ;}
  std::string Color::bg_blue(const std::string &str) const {       return "\e[44m"+str+"\e[0m" ;}
  std::string Color::bg_magenta(const std::string &str) const {    return "\e[45m"+str+"\e[0m" ;}
  std::string Color::bg_cyan(const std::string &str) const {       return "\e[46m"+str+"\e[0m" ;}
  std::string Color::bg_gray(const std::string &str) const {       return "\e[47m"+str+"\e[0m" ;}

  std::string Color::bold(const std::string &str) const {          return "\e[1m"+str+"\e[22m" ;}
  std::string Color::dim(const std::string &str) const {           return "\e[2m"+str+"\e[22m" ;}
  std::string Color::italic(const std::string &str) const {        return "\e[3m"+str+"\e[23m" ;}
  std::string Color::underline(const std::string &str) const {     return "\e[4m"+str+"\e[24m" ;}
  std::string Color::blink(const std::string &str) const {         return "\e[5m"+str+"\e[25m" ;}
  std::string Color::reverse_color(const std::string &str) const { return "\e[7m"+str+"\e[27m" ;}


  std::string Color::removeColor(const std::string &str) const {
    
  };


} // namespace Manduca



  

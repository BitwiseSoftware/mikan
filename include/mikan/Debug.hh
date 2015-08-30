#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

namespace Mikan {

class Debug {
public:
  Debug();
  static void print_log(std::string line);
  static void print_screen(std::string line);

private:
  static std::string string_time();

  static sf::Font font;
  static sf::Text text;
};

} // namespace Mikan


#include "Debug.hh"

#include <ctime>
#include "Engine.hh"

namespace Mikan {

// Initialize static variables
sf::Font Debug::font;
sf::Text Debug::text;

Debug::Debug() {
  font.loadFromFile(Engine::ROOT_DIR + "Resources/Fonts/OpenSans-Regular.ttf");
  text.setPosition(sf::Vector2f(10, 10));
  text.setFont(font);
  text.setCharacterSize(24);
  text.setColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold);
}

void Debug::print_log(const std::string line) {
  std::ofstream log_file(
    Mikan::Engine::ROOT_DIR + "Debug/log.txt",
    std::fstream::out | std::ios::app
  );

  std::string final_line;
  final_line.append(1, '[')
            .append(string_time())
            .append(1, ']')
            .append(1, ' ')
            .append(line);

  log_file << final_line << std::endl;
  log_file.close();
}

void Debug::print_screen(const std::string line) {
  text.setStyle(sf::Text::Bold);
  text.setString(line);
  Engine::ui_layer.draw(text);
}

std::string Debug::string_time() {
  std::time_t rawtime;
  std::tm* timeinfo;
  char buffer[30];

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

  return std::string(buffer);
}

} // namespace Mikan


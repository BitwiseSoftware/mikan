#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Mikan {

class Engine {
public:
  Engine();

  static std::unique_ptr<sf::RenderWindow> window;

  // layers
  static sf::RenderTexture terrain_layer;
  static sf::RenderTexture ui_layer;

  sf::View camera;

  void run();

  static const std::string ROOT_DIR;

private:
  void init_window();
  void init_layers();

  void control_keyboard_actions(float delta_seconds);
  void control_window(float delta_seconds);

  bool paused;

  std::vector<std::pair<std::vector<sf::Keyboard::Key>,
                        std::function<void(double)>>> keyboard_actions;

  void add_keyboard_action(std::vector<sf::Keyboard::Key> keys,
                           std::function<void(double)> callback) {
    keyboard_actions.push_back(std::make_pair(keys, callback));
  }
};

} // namespace Mikan

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

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

  void control_camera(float delta_seconds);
  void control_window(float delta_seconds);

  bool paused;
};

} // namespace Mikan


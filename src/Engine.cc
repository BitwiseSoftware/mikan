#include "Engine.hh"

#include "Debug.hh"
#include "Entity.hh"

namespace Mikan {

// Initialize static variables
std::unique_ptr<sf::RenderWindow> Engine::window;
sf::RenderTexture Engine::terrain_layer;
sf::RenderTexture Engine::ui_layer;
const std::string Engine::ROOT_DIR = "../";

Engine::Engine() : paused(false) {
  init_window();
  init_layers();

  Debug();

  camera.zoom(.1);
  camera.setCenter(0, 0);

  add_keyboard_action({sf::Keyboard::W, sf::Keyboard::Up},
                      [this](double delta_seconds) {
                        camera.move(sf::Vector2f(0, -100 * delta_seconds));
                      });

  add_keyboard_action({sf::Keyboard::A, sf::Keyboard::Left},
                      [this](double delta_seconds) {
                        camera.move(sf::Vector2f(-100 * delta_seconds, 0));
                      });
  add_keyboard_action({sf::Keyboard::S, sf::Keyboard::Down},
                      [this](double delta_seconds) {
                        camera.move(sf::Vector2f(0, 100 * delta_seconds));
                      });
  add_keyboard_action({sf::Keyboard::D, sf::Keyboard::Right},
                      [this](double delta_seconds) {
                        camera.move(sf::Vector2f(100 * delta_seconds, 0));
                      });
}

void Engine::run() {
  sf::Clock delta_clock;

  while (window->isOpen()) {
    const float delta_seconds = delta_clock.restart().asSeconds();

    control_window(delta_seconds);
    if (paused) {
      continue;
    }
    control_keyboard_actions(delta_seconds);

    // Needs to keep tranparency
    terrain_layer.clear(sf::Color(0, 0, 0, 0));
    ui_layer.clear(sf::Color(0, 0, 0, 0));
    window->clear(sf::Color::Black);

    for (auto entity : Entity::entities) {
      entity->tick(delta_seconds);
      entity->render();
    }

    window->setView(camera);
    terrain_layer.display();
    const sf::Sprite terrain_sprite(terrain_layer.getTexture());
    window->draw(terrain_sprite);

    window->setView(window->getDefaultView());
    ui_layer.display();
    const sf::Sprite ui_sprite(ui_layer.getTexture());
    window->draw(ui_sprite);

    window->display();
  }
}

void Engine::init_window() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 16;

  window.reset(new sf::RenderWindow(sf::VideoMode(1024, 768), "Pax Atlas",
                                    sf::Style::Default, settings));
  window->setFramerateLimit(60);
}

void Engine::init_layers() {
  terrain_layer.create(1000, 1000);
  ui_layer.create(1000, 1000);
}

void Engine::control_keyboard_actions(const float delta_seconds) {
  for (auto keyboard_action : keyboard_actions) {
    for (auto key : keyboard_action.first) {
      if (sf::Keyboard::isKeyPressed(key)) {
        keyboard_action.second(delta_seconds);
      }
    }
  }
}

void Engine::control_window(const float delta_seconds) {
  sf::Event event;
  while (window->pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      window->close();
      break;
    case sf::Event::LostFocus:
      paused = true;
      break;
    case sf::Event::GainedFocus:
      paused = false;
      break;
    // camera zoom
    case sf::Event::MouseWheelMoved:
      if (event.mouseWheel.delta > 0) {
        camera.zoom(0.9f);
      } else {
        camera.zoom(1.1f);
      }
      break;
    default:
      break;
    }
  }
}

} // namespace Mikan

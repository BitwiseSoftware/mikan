#include "Entity.hh"

#include <algorithm>
#include "Engine.hh"

namespace Mikan {

// Initialize static variables
std::vector<Entity*> Entity::entities;

Entity::Entity() {
  entities.push_back(this);
}

Entity::~Entity() {
  const auto position = std::find(entities.begin(), entities.end(), this);
  entities.erase(position);
}

void Entity::render() {
  get_layer().draw(shape);
}

sf::ConvexShape Entity::get_shape() {
  return shape;
}

sf::RenderTexture& Entity::get_layer() {
  return Mikan::Engine::terrain_layer;
}

} // namespace Mikan


#pragma once

#include "../json/json.h"

namespace Mikan {

class EntityLoader {
public:
  EntityLoader();

protected:
  Json::Value root;

  void load_json(std::string file_location);
};

} // namespace Mikan


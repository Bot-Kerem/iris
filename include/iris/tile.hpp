#pragma once

#include <memory>
#include "texture.hpp"

class Tile {
 public:
   std::shared_ptr<const Texture> texture;
  Tile(std::shared_ptr<const Texture> texture) : texture(texture) {}
};

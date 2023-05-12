#pragma once

#include <cstddef>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mesh.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "tile.hpp"

constexpr float tile_size = 100.0f;

class Tilemap : public Mesh {
 private:
  std::shared_ptr<Shader> tile_shader;
  std::map<std::string, std::unique_ptr<Texture>> textures;
  std::vector<std::vector<std::unique_ptr<Tile>>> tiles;

 public:
  Tilemap(std::shared_ptr<Shader> shader) noexcept;

  void set_tile(std::unique_ptr<Tile>& tile,
                std::pair<size_t, size_t> position);

  void draw() override;
};

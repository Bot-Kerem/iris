#pragma once

#include <memory>
#include "mesh.hpp"
#include "shader.hpp"
#include "texture.hpp"

constexpr float tile_size = 100.0f;

class Tilemap : public Mesh {
 private:
  Texture tex;

  std::shared_ptr<Shader> tile_shader;
 public:
  Tilemap(std::shared_ptr<Shader> shader) noexcept;

  void draw() override;
};

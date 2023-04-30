#pragma once

#include "iris/shader.hpp"
#include "mesh.hpp"

constexpr float tile_size = 0.1f;

class Tilemap : Mesh {
  private:
  public:
    Tilemap() noexcept;
    
    void draw(const Shader& shader) override;
};

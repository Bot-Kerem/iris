#pragma once

#include "iris/shader.hpp"
#include "mesh.hpp"

constexpr float tile_size = 800.0f;

class Tilemap : public Mesh {
  private:
  public:
    Tilemap() noexcept;
    
    void draw(const std::unique_ptr<Shader>& shader) override;
};

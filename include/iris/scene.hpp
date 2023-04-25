#pragma once

#include <glm/ext/vector_float3.hpp>

class Scene {
 private:
  glm::vec3 clear_color = glm::vec3{0.52f};

 public:
  Scene() = default;

  void draw() const noexcept;
  void set_clear_color(const glm::vec3& color) noexcept;
};

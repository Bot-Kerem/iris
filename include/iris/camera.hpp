#pragma once

#include <glm/ext/vector_float2.hpp>

/* Basic 2D Camera class */
class Camera {
 protected:
 public:
  Camera() = default;
  glm::vec2* position;
};

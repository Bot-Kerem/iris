#include "iris/mesh.hpp"

#include <glad/glad.h>

void Mesh::draw_arrays(const int num_points,
                       const PrimitiveType type) noexcept {
  glDrawArrays(static_cast<unsigned int>(type), 0, num_points);
}

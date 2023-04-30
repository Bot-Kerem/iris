#include "iris/tilemap.hpp"

#include <glm/ext/vector_float2.hpp>

struct TileVertex {
  glm::vec2 position;
};

Tilemap::Tilemap() noexcept {
  const TileVertex vertices[] = {
      {{-tile_size / 2.0f, tile_size / 2.0f}},
      {{-tile_size / 2.0f, -tile_size / 2.0f}},
      {{tile_size / 2.0f, -tile_size / 2.0f}},

      {{-tile_size / 2.0f, tile_size / 2.0f}},
      {{tile_size / 2.0f, -tile_size / 2.0f}},
      {{tile_size / 2.0f, tile_size / 2.0f}},
  };

  m_vertex_array.bind();
  m_vertex_buffer.bind();
  m_vertex_buffer.buffer_data(vertices, sizeof(vertices));
  m_vertex_array.vertex_attrib_pointer(0, 2, sizeof(TileVertex), 0);
}

void Tilemap::draw([[maybe_unused]] const Shader& shader) {
  draw_arrays(6, PrimitiveType::Triangle);
}


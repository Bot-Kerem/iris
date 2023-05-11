#include "iris/tilemap.hpp"

#include <cstddef>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_int2_sized.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "iris/texture.hpp"

struct TileVertex {
  glm::vec2 position;
  glm::vec2 uv;
};

Tilemap::Tilemap(std::shared_ptr<Shader> shader) noexcept
    : tile_shader(shader) {
  const TileVertex vertices[] = {
      {{-tile_size / 2.0f, tile_size / 2.0f}, {0.0f, 1.0f}},
      {{-tile_size / 2.0f, -tile_size / 2.0f}, {0.0f, 0.0f}},
      {{tile_size / 2.0f, -tile_size / 2.0f}, {1.0f, 0.0f}},

      {{-tile_size / 2.0f, tile_size / 2.0f}, {0.0f, 1.0f}},
      {{tile_size / 2.0f, -tile_size / 2.0f}, {1.0f, 0.0f}},
      {{tile_size / 2.0f, tile_size / 2.0f}, {1.0f, 1.0f}},
  };

  m_vertex_array.bind();
  m_vertex_buffer.bind();
  m_vertex_buffer.buffer_data(vertices, sizeof(vertices));
  m_vertex_array.vertex_attrib_pointer(0, 2, sizeof(TileVertex),
                                       offsetof(TileVertex, position));
  m_vertex_array.vertex_attrib_pointer(1, 2, sizeof(TileVertex),
                                       offsetof(TileVertex, uv));

  tex.load_from_file("res/luffy.jpg", Texture::Format::RGB);
}

void Tilemap::draw() {
  const glm::i32vec2 tile_map_size{4, 3};

  tex.bind(0);
  tile_shader->use();
  for (int y = 0; y < tile_map_size.y; y++) {
    for (int x = 0; x < tile_map_size.x; x++) {
      tile_shader->set_mat4(
          "model", glm::translate(glm::mat4(1.0f),
                                  glm::vec3(400.0f + (x * tile_size),
                                            300.0f + (y * tile_size), 0.0)));
      draw_arrays(6, PrimitiveType::Triangle);
    }
  }
}

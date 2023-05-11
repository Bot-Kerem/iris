#pragma once

#include <memory>
#include "vertex_array.hpp"
#include "vertex_buffer.hpp"

class Mesh {
 protected:
  enum class PrimitiveType : unsigned int {
    Point = 0x000,
    Line = 0x0001,
    LineLoop = 0x002,
    LineStrip = 0x003,
    Triangle = 0x004,
    TriangleStrip = 0x005,
    TriangleFan = 0x006,
    Quad = 0x007,
    QuadStrip = 0x008,
  };

  static void draw_arrays(
      const int num_points,
      const PrimitiveType type = PrimitiveType::Triangle) noexcept;

  VertexBuffer m_vertex_buffer;
  VertexArray m_vertex_array;

 public:
  Mesh() = default;
  virtual ~Mesh() = default;

  virtual void draw() = 0;
};

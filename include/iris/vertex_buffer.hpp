#pragma once

#include <limits>
#include <cstddef>

class VertexBuffer {
 private:
  unsigned int m_vertex_buffer = std::numeric_limits<unsigned int>::max();
 public:
  VertexBuffer() noexcept;
  ~VertexBuffer() noexcept;

  void bind() const noexcept;
  void buffer_data(const void* data, const size_t size) const noexcept;

  VertexBuffer(VertexBuffer&&) = delete;
  VertexBuffer(const VertexBuffer&) = delete;
  VertexBuffer& operator=(VertexBuffer&&) = delete;
  VertexBuffer& operator=(const VertexBuffer&) = delete;
};

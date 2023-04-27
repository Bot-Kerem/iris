#pragma once

#include <cstddef>
#include <limits>

class VertexArray {
 private:
  unsigned int m_vertex_array = std::numeric_limits<unsigned int>::max();

 public:
  VertexArray() noexcept;
  ~VertexArray() noexcept;

  void bind() const noexcept;
  void vertex_attrib_pointer(unsigned int index, int size, size_t stride,
                             size_t pointer) const noexcept;

  VertexArray(VertexArray&&) = delete;
  VertexArray(const VertexArray&) = delete;
  VertexArray& operator=(VertexArray&&) = delete;
  VertexArray& operator=(const VertexArray&) = delete;
};

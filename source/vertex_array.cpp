#include "iris/vertex_array.hpp"

#include <glad/glad.h>

void VertexArray::vertex_attrib_pointer(unsigned int index, int size,
                                        size_t stride,
                                        size_t pointer) const noexcept {
  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride,
                        reinterpret_cast<void*>(pointer));
}

void VertexArray::bind() const noexcept { glBindVertexArray(m_vertex_array); }

VertexArray::VertexArray() noexcept {
  glGenVertexArrays(1, &m_vertex_array);
}
VertexArray::~VertexArray() noexcept {
  glDeleteVertexArrays(1, &m_vertex_array);
}

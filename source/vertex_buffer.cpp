#include "iris/vertex_buffer.hpp"

#include <glad/glad.h>

void VertexBuffer::buffer_data(const void *data,
                               const size_t size) const noexcept {
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::bind() const noexcept {
  glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer);
}

VertexBuffer::VertexBuffer() noexcept { glGenBuffers(1, &m_vertex_buffer); }
VertexBuffer::~VertexBuffer() noexcept { glDeleteBuffers(1, &m_vertex_buffer); }

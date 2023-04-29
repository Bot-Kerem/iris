#include "iris/texture.hpp"
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <stb/stb_image.h>

void Texture::bind(unsigned int level) const noexcept {
  glActiveTexture(GL_TEXTURE0 + level);
  glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Texture::load_from_file(const std::string_view file_path, Format format) {
  stbi_set_flip_vertically_on_load(true);
  int desired_format = 0;
  switch (format) {
    case Format::RGB:
      desired_format = 3;
      break;
    case Format::RGBA:
      desired_format = 4;
      break;
    default:
      throw std::runtime_error("Unknown format");
  }
  int width, height, nr_channels = 0;
  unsigned char* data = stbi_load(file_path.data(), &width, &height,
                                  &nr_channels, desired_format);
  load(data, width, height, format);
}

void Texture::load(const void* data, size_t width, size_t height,
                   Format format) noexcept {
  glGenTextures(1, &m_texture);
  glBindTexture(GL_TEXTURE_2D, m_texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(GL_TEXTURE_2D, 0, static_cast<unsigned int>(format), width,
               height, 0, static_cast<unsigned int>(format), GL_UNSIGNED_BYTE,
               data);
}

Texture::Texture(const void* data, size_t width, size_t height,
                 Format format) noexcept {
  load(data, width, height, format);
}

Texture::Texture(const std::string_view file_path, Format format) {
  load_from_file(file_path, format);
}

Texture::~Texture() noexcept { glDeleteTextures(1, &m_texture); }

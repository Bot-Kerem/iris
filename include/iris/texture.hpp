#pragma once

#include <limits>
#include <cstddef>
#include <string_view>

class Texture {
 private:
  unsigned int m_texture = std::numeric_limits<unsigned int>::max();

 public:
  enum class Format {
    RGB = 0x1907,
    RGBA = 0x1908,
  };

  Texture() = default;
  Texture(const void* data, size_t width, size_t height, Format format) noexcept;
  Texture(const std::string_view file_path, Format format);
  ~Texture() noexcept;

  void load(const void* data, size_t width, size_t height, Format format) noexcept;
  void load_from_file(const std::string_view file_path, Format format);

  void bind(unsigned int level) const noexcept;

};

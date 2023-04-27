#pragma once

#include <limits>
#include <map>
#include <string>
#include <string_view>

class Shader {
 public:
  enum class Type : unsigned int {
    Fragment = 0x8b30,
    Vertex = 0x8b31,
  };

 private:
  unsigned int m_program = std::numeric_limits<unsigned int>::max();
  static inline std::map<std::string, unsigned int> shaders;
  static unsigned int create_shader(const std::string_view source, Type type);

  int get_location(const std::string_view uniform) const noexcept;

 public:
  Shader(const std::string_view vertex_shader_source,
         const std::string_view fragment_shader_source) noexcept;
  Shader() = default;
  ~Shader() noexcept;

  void use() const noexcept;
  static void register_shader(const std::string& shader_name,
                              const std::string_view shader_source,
                              Type type) noexcept;
  static unsigned int get_register(const std::string& shader_name);

  void load(const std::string_view vertex_shader_source,
            const std::string_view fragment_shader_source) noexcept;

  void set_vec2(const std::string_view uniform, const auto& val) const noexcept;
  void set_vec3(const std::string_view uniform, const auto& val) const noexcept;
  void set_vec4(const std::string_view uniform, const auto& val) const noexcept;

  void set_mat3(const std::string_view uniform, const auto& val) const noexcept;
  void set_mat4(const std::string_view uniform, const auto& val) const noexcept;

  Shader(Shader&&) = delete;
  Shader(const Shader&) = delete;
  Shader& operator=(Shader&&) = delete;
  Shader& operator=(const Shader&) = delete;
};

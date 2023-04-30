#include "iris/shader.hpp"

#include <glad/glad.h>

#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

unsigned int Shader::get_register(const std::string& shader_name) {
  return shaders.at(shader_name);
}

void Shader::register_shader(const std::string& shader_name,
                             const std::string_view shader_source,
                             Type type) noexcept {
  unsigned int shader = create_shader(shader_source, type);

  shaders.insert(std::make_pair(shader_name, shader));
}

void Shader::load(const std::string_view vertex_shader_source,
                  const std::string_view fragment_shader_source) {
  unsigned int vertex_shader =
      create_shader(vertex_shader_source, Type::Vertex);
  unsigned int fragment_shader =
      create_shader(fragment_shader_source, Type::Fragment);

  load(vertex_shader, fragment_shader);
}

void Shader::load(const unsigned int vertex_shader,
                  const unsigned int fragment_shader) {
  m_program = glCreateProgram();

  glAttachShader(m_program, vertex_shader);
  glAttachShader(m_program, fragment_shader);

  /* Link and check errors */
  glLinkProgram(m_program);

  int link_status = 0;
  glGetProgramiv(m_program, GL_LINK_STATUS, &link_status);
  if (!link_status) {
    int log_length = 0;
    glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &log_length);

    std::vector<char> info_log(log_length);
    glGetProgramInfoLog(m_program, log_length, nullptr, info_log.data());

    throw std::runtime_error(std::string(info_log.data(), log_length));
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

int Shader::get_location(const std::string_view uniform) const noexcept {
  return glGetUniformLocation(m_program, uniform.data());
}

unsigned int Shader::create_shader(const std::string_view source, Type type) {
  unsigned int shader = glCreateShader(static_cast<unsigned int>(type));

  /* Set shader data and compile */
  const auto data = source.data();
  glShaderSource(shader, 1, &data, nullptr);

  glCompileShader(shader);

  /* Check errors */
  int compile_status = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
  if (!compile_status) {
    /* Get log length */
    int log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

    /* Write log to the buffer */
    std::vector<char> info_log(log_length);
    glGetShaderInfoLog(shader, log_length, nullptr, info_log.data());

    throw std::runtime_error(std::string(info_log.data(), log_length));

    glDeleteShader(shader);
  }

  return shader;
}

void Shader::use() const noexcept { glUseProgram(m_program); }

Shader::Shader(const std::string_view vertex_shader_source,
               const std::string_view fragment_shader_source) noexcept {
  load(vertex_shader_source, fragment_shader_source);
}

Shader::Shader(const unsigned int vertex_shader,
               const unsigned int fragment_shader) noexcept {
  load(vertex_shader, fragment_shader);
}

Shader::~Shader() noexcept { glDeleteProgram(m_program); }

void Shader::set_mat4(const std::string_view uniform, const glm::mat4& val) const noexcept {
  glUniformMatrix4fv(get_location(uniform), 1, GL_FALSE, reinterpret_cast<const float*>(&val));
}


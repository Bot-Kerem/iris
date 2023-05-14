#pragma once

#include <glm/ext/vector_float3.hpp>
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "mesh.hpp"
#include "shader.hpp"

class Scene {
 protected:
  glm::vec3 clear_color = glm::vec3{0.52f};
  bool activated = false;

  std::vector<std::unique_ptr<Mesh>> scene_elements;
  std::map<std::string, std::shared_ptr<Shader>> shaders;

 public:
  Scene() = default;

  virtual std::string load(const std::string_view scene_data) = 0;

  void draw() const noexcept;
  void activate() noexcept;
  void deactivate() noexcept;
  void set_clear_color(const glm::vec3& color) noexcept;

  std::shared_ptr<Shader> get_shader(const std::string& shader_name) const;

  void add_shader(std::shared_ptr<Shader> shader,
                  const std::string& shader_name);

  void add_mesh(auto& mesh) {
    scene_elements.push_back(std::move(mesh));
  }

};

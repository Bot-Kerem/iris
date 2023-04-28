#pragma once

#include <glm/ext/vector_float3.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mesh.hpp"
#include "shader.hpp"

class Scene {
 private:
  glm::vec3 clear_color = glm::vec3{0.52f};
  bool activated = false;

  std::map<std::string,
           std::pair<std::unique_ptr<Shader>,
           std::vector<std::unique_ptr<Mesh>>>> scene_elements;

 public:
  Scene() = default;

  void draw() const noexcept;
  void activate() noexcept;
  void deactivate() noexcept;
  void set_clear_color(const glm::vec3& color) noexcept;
};

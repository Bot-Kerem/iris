#include "iris/scene.hpp"

#include <glad/glad.h>

#include <glm/ext/matrix_float4x4.hpp>
#include <memory>
#include <utility>

void Scene::draw() const noexcept {
  glClear(GL_COLOR_BUFFER_BIT);

  /* Draw scene */
  for (auto& mesh : scene_elements) {
    mesh->draw();
  }
}

void Scene::activate() noexcept {
  activated = true;

  extern const glm::mat4 view_matrix;
  for (auto& shader: shaders) {
    shader.second->use();
    shader.second->set_mat4("view", view_matrix);
  }

  glClearColor(clear_color.r, clear_color.g, clear_color.b, 1.0f);
}

void Scene::deactivate() noexcept { activated = false; }

void Scene::set_clear_color(const glm::vec3& color) noexcept {
  if (activated) glClearColor(color.r, color.g, color.b, 1.0f);
  clear_color = color;
}

std::shared_ptr<Shader> Scene::get_shader(const std::string& shader_name) const {
  return shaders.at(shader_name);
}

void Scene::add_shader(std::shared_ptr<Shader> shader,
                       const std::string& shader_name) {
  shaders.emplace(shader_name, shader);
}

void Scene::add_mesh(std::unique_ptr<Mesh>& mesh) {
  scene_elements.push_back(std::move(mesh));
}

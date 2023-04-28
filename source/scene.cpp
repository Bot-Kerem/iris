#include "iris/scene.hpp"

#include <glad/glad.h>

#include <memory>
#include <utility>

void Scene::draw() const noexcept {
  glClear(GL_COLOR_BUFFER_BIT);

  /* Draw scene */
  for ([[maybe_unused]] auto& [_, shader_scene] : scene_elements) {
    shader_scene.first->use();
    for (auto& mesh : shader_scene.second) {
      mesh->draw();
    }
  }
}

void Scene::activate() noexcept {
  activated = true;
  glClearColor(clear_color.r, clear_color.g, clear_color.b, 1.0f);
}

void Scene::deactivate() noexcept { activated = false; }

void Scene::set_clear_color(const glm::vec3& color) noexcept {
  if (activated) glClearColor(color.r, color.g, color.b, 1.0f);
  clear_color = color;
}

void Scene::add_shader(std::unique_ptr<Shader>& shader,
                       const std::string& shader_name) {
  scene_elements.insert(std::make_pair(
      shader_name,
      std::make_pair(std::move(shader), std::vector<std::unique_ptr<Mesh>>())));
}

void Scene::add_mesh(std::unique_ptr<Mesh>& mesh,
                     const std::string& shader_name) {
  scene_elements.at(shader_name).second.push_back(std::move(mesh));
}

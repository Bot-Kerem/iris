#include "iris/scene.hpp"

#include <glad/glad.h>

void Scene::draw() const noexcept {
  glClear(GL_COLOR_BUFFER_BIT);

  /* Draw scene */
  for ([[maybe_unused]] auto& [_, shader_scene]: scene_elements) {
    shader_scene.first->use();
    for (auto& mesh: shader_scene.second) {
      mesh->draw();
    }
  }
}

void Scene::activate() noexcept {
  activated = true;
  glClearColor(clear_color.r, clear_color.g, clear_color.b, 1.0f);
}

void Scene::deactivate() noexcept {
  activated = false;
}

void Scene::set_clear_color(const glm::vec3 &color) noexcept {
  if (activated)
    glClearColor(color.r, color.g, color.b, 1.0f);
  clear_color = color;
}


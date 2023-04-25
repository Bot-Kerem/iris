#include "iris/scene.hpp"

#include <glad/glad.h>

void Scene::draw() const noexcept {
  glClear(GL_COLOR_BUFFER_BIT);
}

void Scene::activate() const noexcept {
  glClearColor(clear_color.r, clear_color.g, clear_color.b, 1.0f);
}

void Scene::set_clear_color(const glm::vec3 &color) noexcept {
  glClearColor(color.r, color.g, color.b, 1.0f);
  clear_color = color;
}


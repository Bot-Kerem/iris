#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <algorithm>
#include <glm/ext/matrix_clip_space.hpp>
#include <utility>

#include "iris/application.hpp"

glm::mat4 view_matrix;

void Application::main_loop() {
  while (!window.close_requested()) {
    window.poll_events();

    render();

    window.swap_buffers();
  }
}

void Application::render() {
  /* Draw the main scene */
  current_scene->draw();
}

void Application::build_app() {
  /* Load OpenGL */
  spdlog::info("Loading OpenGL");
  gladLoadGLLoader(reinterpret_cast<GLADloadproc>(Window::get_proc_address));

  /* Set view matrix */
  auto window_size = window.get_window_size();
  view_matrix = glm::ortho(0.0f, static_cast<float>(std::get<0>(window_size)), 0.0f, static_cast<float>(std::get<1>(window_size)));

  auto [scene, scene_name] = build();
  scenes.insert(std::make_pair(scene_name, std::move(scene)));

  spdlog::info("Active scene: \"{}\"", scene_name);
  current_scene = scenes.at(scene_name).get();
  current_scene->activate();
}

Application::Application(const WindowCreateInfo& info_window)
    : window(info_window.title, info_window.width, info_window.height) {}

int Application::exec() {
  spdlog::info("Executing application");

  spdlog::info("Building the application");
  build_app();
  spdlog::info("Entering the main loop");
  main_loop();
  return 0;
}

void framebuffer_size_callback(const size_t w, const size_t h) {
  view_matrix = glm::ortho(0.0f, static_cast<float>(w), 0.0f, static_cast<float>(h));
}

#include <glad/glad.h>

#include "iris/application.hpp"

void Application::main_loop() {
  while (!window.close_requested()) {
    window.poll_events();

    render();

    window.swap_buffers();
  }
}

void Application::render() {
  /* Draw the main scene */
  main_scene.draw();
}

void Application::build_app() {
  /* Load OpenGL */
  spdlog::info("Loading OpenGL");
  gladLoadGLLoader(reinterpret_cast<GLADloadproc>(Window::get_proc_address));

  spdlog::info("Active scene: \"Main Scene\"");
  main_scene.activate();
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

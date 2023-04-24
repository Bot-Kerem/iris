#include <glad/glad.h>

#include "iris/application.hpp"

void Application::main_loop() {
  while (!window.close_requested()) {
    window.poll_events();

    window.swap_buffers();
  }
}

void Application::build_app() {
  /* Load OpenGL */
  spdlog::info("Loading OpenGL");
  gladLoadGLLoader(reinterpret_cast<GLADloadproc>(Window::get_proc_address));
}

Application::Application(const WindowCreateInfo& info_window)
    : window(info_window.title, info_window.width, info_window.height) {}

int Application::exec() {
  spdlog::info("Executing application");

  spdlog::info("Building the application");
  void build_app();
  spdlog::info("Entering the main loop");
  main_loop();
  return 0;
}

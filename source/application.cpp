#include "iris/application.hpp"

#include "iris/window.hpp"

void Application::main_loop() {
  while (!window.close_requested()) {
    window.poll_events();

    window.swap_buffers();
  }
}

Application::Application(const WindowCreateInfo& info_window)
    : window(info_window.title, info_window.width, info_window.height) {}

int Application::exec() {
  spdlog::info("Executing application");
  spdlog::info("Entering the main loop");
  main_loop();
  return 0;
}

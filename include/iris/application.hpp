#pragma once

#include <string_view>

#include "config.hpp"
#include "window.hpp"
#include "scene.hpp"

class Application {
 protected:
  struct WindowCreateInfo {
    std::string_view title;
    unsigned int width;
    unsigned int height;
  };
  Window window;
  Scene main_scene;

  Application(const WindowCreateInfo& info_window);
  ~Application() = default;

 private:
  void main_loop();
  void build_app();
  void render();

 public:
  int exec();
};

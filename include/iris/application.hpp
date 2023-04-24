#pragma once

#include <string_view>

#include "config.hpp"
#include "window.hpp"

class Application {
 protected:
  struct WindowCreateInfo {
    std::string_view title;
    unsigned int width;
    unsigned int height;
  };
  Window window;

  Application(const WindowCreateInfo& info_window);
  ~Application() = default;

 private:
  void main_loop();
  void build_app();

 public:
  int exec();
};

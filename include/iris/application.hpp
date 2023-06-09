#pragma once

#include <cstddef>
#include <glm/ext/matrix_float4x4.hpp>
#include <map>
#include <memory>
#include <string_view>
#include <utility>

#include "config.hpp"
#include "scene.hpp"
#include "window.hpp"

class Application {
 protected:
  struct WindowCreateInfo {
    std::string_view title;
    unsigned int width;
    unsigned int height;
  };

  Window window;
  Scene* current_scene;

  Application(const WindowCreateInfo& info_window);
  ~Application() = default;

 private:
  void main_loop();
  void build_app();
  void render();
  void framebuffer_size_callback(const size_t w, const size_t h);

  virtual std::pair<std::unique_ptr<Scene>, std::string> build() = 0;

  std::map<std::string, std::unique_ptr<Scene>> scenes;

 public:
  int exec();
};

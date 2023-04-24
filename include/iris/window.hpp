#pragma once

#include <GLFW/glfw3.h>

#include <string_view>
#include <tuple>

#include "config.hpp"

enum class MouseButton : int {
  Left = GLFW_MOUSE_BUTTON_LEFT,
  Right = GLFW_MOUSE_BUTTON_RIGHT,
  Middle = GLFW_MOUSE_BUTTON_MIDDLE
};

enum class KeyState {
  Pressed = GLFW_PRESS,
  Released = GLFW_RELEASE,
  NotInitialized = GLFW_NOT_INITIALIZED,
  InvalidEnum = GLFW_INVALID_ENUM,
};

enum class Key {
  W = GLFW_KEY_W,
  A = GLFW_KEY_A,
  S = GLFW_KEY_S,
  D = GLFW_KEY_D,
};

enum class Cursor { Arrow, Hand };

class Window {
 private:
  GLFWwindow* window;
  GLFWcursor* cursor_arrow;
  GLFWcursor* cursor_hand;

  std::tuple<double, double> mouse_position;

 public:
  Window(const std::string_view title, int width, int height) noexcept;
  ~Window() noexcept;

  [[nodiscard]] bool close_requested() const noexcept;
  void poll_events() noexcept;
  void swap_buffers() const noexcept;
  [[nodiscard]] GLFWwindow* get_window() const noexcept;
  [[nodiscard]] std::tuple<double, double> get_mouse_position() const noexcept;
  [[maybe_unused]] void set_mouse_position(double x, double y) noexcept;

  [[nodiscard]] KeyState get_mouse_button(MouseButton button) const noexcept;
  [[nodiscard]] KeyState get_key(Key key) const noexcept;

  void set_cursor(Cursor cursor) const noexcept;
};

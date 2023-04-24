#include "iris/window.hpp"

#include <type_traits>

Window::Window(const std::string_view title, int width, int height) noexcept {
  /* Initialize glfw */
  glfwInit();

  /* Set OpenGL Context 3.3 Compatibility Profile */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

  /* Set window unresizeable */
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  /* Create window */
  window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

  /* Create cursors */
  cursor_arrow = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
  cursor_hand = glfwCreateStandardCursor(GLFW_HAND_CURSOR);

  /* Make context current */
  glfwMakeContextCurrent(window);

  /* Enable VSync */
  glfwSwapInterval(1);

  /* Load OpenGL */
  // gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
}

Window::~Window() noexcept {
  /* Destroy Cursors*/
  glfwDestroyCursor(cursor_arrow);
  glfwDestroyCursor(cursor_hand);
  /* Destroy window */
  glfwDestroyWindow(window);
  /* Terminate library */
  glfwTerminate();
}

void Window::swap_buffers() const noexcept { glfwSwapBuffers(window); }

bool Window::close_requested() const noexcept {
  return glfwWindowShouldClose(window);
}

void Window::poll_events() noexcept {
  glfwPollEvents();
  glfwGetCursorPos(window, &std::get<0>(mouse_position),
                   &std::get<1>(mouse_position));
}

GLFWwindow* Window::get_window() const noexcept { return window; }

std::tuple<double, double> Window::get_mouse_position() const noexcept {
  return mouse_position;
}

void Window::set_mouse_position(double x, double y) noexcept {
  mouse_position = std::make_tuple(x, y);
  glfwSetCursorPos(window, x, y);
}

KeyState Window::get_mouse_button(MouseButton button) const noexcept {
  return static_cast<KeyState>(
      glfwGetMouseButton(window, static_cast<int>(button)));
}

KeyState Window::get_key(Key key) const noexcept {
  return static_cast<KeyState>(glfwGetKey(window, static_cast<int>(key)));
}

void Window::set_cursor(Cursor cursor) const noexcept {
  switch (cursor) {
    case Cursor::Arrow:
      glfwSetCursor(window, cursor_arrow);
      break;
    case Cursor::Hand:
      glfwSetCursor(window, cursor_hand);
      break;
  }
}

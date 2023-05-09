#include "iris/window.hpp"

#include <functional>
#include <type_traits>

Window::Window(const std::string_view title, int width, int height) noexcept {
  /* Initialize glfw */
  spdlog::info("Initializing glfw");
  glfwInit();

  /* Set OpenGL Context 4.6 Compatibility Profile */
  const int version_major = 4;
  const int version_minor = 6;
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version_major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version_minor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
  spdlog::info("Graphics API: OpenGL {}.{} {} Profile", version_major,
               version_minor, "Compatibility");

  /* Set window unresizeable */
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  /* Create window */
  spdlog::info("Creating window: {}", title);
  window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

  /* Create cursors */
  cursor_arrow = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
  cursor_hand = glfwCreateStandardCursor(GLFW_HAND_CURSOR);

  /* Make context current */
  glfwMakeContextCurrent(window);

  /* Enable VSync */
  spdlog::info("VSync: ENABLED");
  glfwSwapInterval(1);
}

Window::~Window() noexcept {
  /* Destroy Cursors*/
  spdlog::info("Destroying cursors");
  glfwDestroyCursor(cursor_arrow);
  glfwDestroyCursor(cursor_hand);
  /* Destroy window */
  spdlog::info("Destroying windows");
  glfwDestroyWindow(window);
  /* Terminate library */
  spdlog::info("Terminating glfw");
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

void Window::set_framebuffer_size_callback(
    std::function<void(size_t w, size_t h)>) noexcept {
}

KeyState Window::get_mouse_button(MouseButton button) const noexcept {
  return static_cast<KeyState>(
      glfwGetMouseButton(window, static_cast<int>(button)));
}

KeyState Window::get_key(Key key) const noexcept {
  return static_cast<KeyState>(glfwGetKey(window, static_cast<int>(key)));
}

GLFWglproc Window::get_proc_address(const char* procname) noexcept {
  return glfwGetProcAddress(procname);
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

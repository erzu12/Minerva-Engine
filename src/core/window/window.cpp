#include "Window.h"

bool Window::framebufferResized = false;

GLFWwindow* Window::InitWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	window = glfwCreateWindow(1400, 1000, "Minerva", nullptr, nullptr);
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

	glfwSetKeyCallback(window, [](GLFWwindow* c_window, int key, int scancode, int action, int mods) {

	});

	return window;
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
	app->framebufferResized = true;
}


#include "window.h"
#include "events.h"
#include "inputEvents.h"
#include "appEvents.h"
#include <iostream>

bool Window::framebufferResized = false;

GLFWwindow* Window::InitWindow() {
	std::cout << "initWidow" << std::endl;

	glfwInit();
	
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	GLFWwidow = glfwCreateWindow(1400, 1000, "Minerva", nullptr, nullptr);
	glfwSetWindowUserPointer(GLFWwidow, this);

	//GLFW event callbaks
	glfwSetFramebufferSizeCallback(GLFWwidow, [](GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
	});

	glfwSetMouseButtonCallback(GLFWwidow, [](GLFWwindow* window, int button, int action, int mods) {

	});
	
	glfwSetKeyCallback(GLFWwidow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		if(action == GLFW_PRESS)
			EventBus::Get().publish(new KeyDownEvent(key));
		if(action == GLFW_RELEASE)
			EventBus::Get().publish(new KeyUpEvent(key));
	});

	glfwSetWindowCloseCallback(GLFWwidow, [](GLFWwindow* window) {
		EventBus::Get().publish(new WindowCloseEvent(window));
	});
	
	return GLFWwidow;
}




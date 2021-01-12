#pragma once

#include <GLFW/glfw3.h>

class Window {
	static bool framebufferResized;
public:
	GLFWwindow* InitWindow();
	GLFWwindow* window;

};
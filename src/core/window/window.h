#pragma once

#include <GLFW/glfw3.h>

class Window {
	static bool framebufferResized;
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
public:
	GLFWwindow* InitWindow();
	GLFWwindow* window;

};
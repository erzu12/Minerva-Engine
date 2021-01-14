#include "minerva.h"
#include <GLFW/glfw3.h>
#include "vulkan.h"
#include "window/window.h"

void MvUpdate() {
	glfwPollEvents();
	Vulkan::Get().drawFrame();
}

bool MvShouldWindowClose(Window w) {
	return glfwWindowShouldClose(w.window);
}
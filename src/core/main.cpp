#include <iostream>
#include <log.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vulkan.h>
#include "window/Window.h"
#include <events.h>

int main()
{	
	//init
	Window w;
	w.InitWindow();

	Vulkan::Get().initVulkan(w.window);

	//main Loop
	while (!glfwWindowShouldClose(w.window)) {
		glfwPollEvents();
		Vulkan::Get().drawFrame();
	}
	vkDeviceWaitIdle(Vulkan::Get().device);

	//cleanup
	Vulkan::Get().cleanup();

	return EXIT_SUCCESS;
}

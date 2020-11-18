#include <iostream>
#include <log.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vulkan.h>
#include "window/Window.h"


int main()
{	
	//init
	Window w;
	w.InitWindow();
	Vulkan vulkan;
	vulkan.initVulkan(w.window);
	
	//main Loop
	while (!glfwWindowShouldClose(w.window)) {
		glfwPollEvents();
		vulkan.drawFrame();
	}
	vkDeviceWaitIdle(vulkan.device);

	//cleanup
	vulkan.cleanup();

	return EXIT_SUCCESS;
}
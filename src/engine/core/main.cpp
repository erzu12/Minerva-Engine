#include <iostream>
#include <log.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vulkan.h>
#include "window/window.h"
#include <events.h>
#include "appEvents.h"
#include "minerva.h"

extern Core* GameInit();

int main()
{	
	//init
	Window w;
	Log log;
	w.InitWindow();

	Vulkan::Get().initVulkan(w.window);

	GameInit();
	EventBus::Get().publish(new StartEvent());
	//main Loop
	while (!glfwWindowShouldClose(w.window)) {
		glfwPollEvents();
		Vulkan::Get().drawFrame();
		EventBus::Get().publish(new UpdateEvent());
		log.Fps();
	}
	vkDeviceWaitIdle(Vulkan::Get().device);

	//cleanup
	Vulkan::Get().cleanup();

	return EXIT_SUCCESS;
}

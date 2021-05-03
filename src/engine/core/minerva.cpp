#include "minerva.h"


void Minerva::Init() {

	//init
	window.InitWindow();

	Vulkan::Get().initVulkan(window.GLFWwidow);
}

void Minerva::Update() {
	glfwPollEvents();
	Vulkan::Get().drawFrame();
}

bool Minerva::ShouldWindowClose(Window window) {
	return glfwWindowShouldClose(window.GLFWwidow);
}

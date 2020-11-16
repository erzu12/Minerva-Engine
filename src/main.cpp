#include <iostream>
#include <log.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vulkan.h>

int main()
{
	Vulkan app;

	try {
		app.Run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
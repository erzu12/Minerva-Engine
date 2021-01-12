#include "minerva.h"
#include "window/Window.h"
#include <vulkan.h>


Window MvInit() {

	//init
	Window w;
	w.InitWindow();

	Vulkan::Get().initVulkan(w.window);

	return w;
}

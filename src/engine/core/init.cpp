#include "minerva.h"
#include "window/window.h"
#include <vulkan.h>


void MvInit() {

	//init
	Window w;
	w.InitWindow();

	Vulkan::Get().initVulkan(w.window);
}

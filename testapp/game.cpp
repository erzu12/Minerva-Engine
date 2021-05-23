#include "minerva.h"
#include <iostream>
#include <vector>
#include <memory>


int main() {
    Log log;
    Minerva minerva;
    log.Message("Test");

    Scene scene;

    scene.Load("../src/editor/test.scene");

    minerva.Init();

    Vulkan vk;

    vk.initVulkan(minerva.window.GLFWwidow, &scene);

    while(!minerva.ShouldWindowClose(minerva.window)){
        minerva.Update();
        vk.drawFrame();
        log.Fps();
    }
    vkDeviceWaitIdle(vk.device);

    vk.cleanup();

	return EXIT_SUCCESS;
}
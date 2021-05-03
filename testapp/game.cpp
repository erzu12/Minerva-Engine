#include "minerva.h"
#include <iostream>
#include <vector>


int main() {
    Log log;
    Minerva minerva;
    log.Message("Test");

    SceneSaver ss;
    Test tst;
    tst.setTestdat();
    ss.SaveScene(tst);

    SceneLoader sl;
    Test test1 = sl.LoadScene("test.bin");

    for(auto & i : test1.testdata)
    {
		std::cout << "data = " << i << std::endl;
    }



    minerva.Init();
    while(!minerva.ShouldWindowClose(minerva.window)){
        minerva.Update();
        log.Fps();
    }
    vkDeviceWaitIdle(Vulkan::Get().device);

    Vulkan::Get().cleanup();

	return EXIT_SUCCESS;
}
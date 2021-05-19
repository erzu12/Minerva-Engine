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

    //Test tst;
    //for (int i = 0; i < 100; i++) {
    //    Test test;
    //    for (int i = 0; i < 5; i++) {
    //        Test test2;
    //        test2.testval = 6;
    //        test.setTestdat(test2, 2);
    //    }
    //    tst.setTestdat(test, 3);
    //}
    //tst.Save();

    //Test test1;

    //test1.Load("test.bin");

    //std::cout << test1.testdata[0].test << std::endl;

    //minerva.Init();
    //while(!minerva.ShouldWindowClose(minerva.window)){
    //    minerva.Update();
    //    log.Fps();
    //}
    //vkDeviceWaitIdle(Vulkan::Get().device);

    //Vulkan::Get().cleanup();

	return EXIT_SUCCESS;
}
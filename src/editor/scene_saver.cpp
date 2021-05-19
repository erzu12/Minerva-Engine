#include "scene_saver.h"
#include <fstream>

void SceneSaver::SaveScene(Scene scene){

    std::fstream File("test.bin", std::ios::out);
    File.seekp(0);
    File.write((char*)&scene, sizeof (Scene));
    File.close();
}

#include "sceneloader.h"
#include <iostream>
#include <fstream>

void SceneSaver::SaveScene(Test test){

    std::fstream File("test.bin", std::ios::out);
    File.seekp(0);
    File.write((char*)&test, sizeof (Test));
    File.close();
}

Test SceneLoader::LoadScene(const char* file){
    test = new Test;
    std::fstream File (file, std::ios::in);
    File.seekg (0);
    File.read ((char*)test, sizeof (Test));
    if(!File){
        std::cout << "ups" << std::endl;
    }
    return *test;
}
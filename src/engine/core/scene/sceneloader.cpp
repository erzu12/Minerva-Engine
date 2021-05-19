#include "sceneloader.h"

void SceneSaver::SaveScene(Test test){

    std::fstream File("test.bin", std::ios::out);
    File.seekp(0);
    File.write((char*)&test, sizeof(Test));
    std::cout << sizeof(test) << "  " << sizeof(test.testdata) << std::endl;
    File.close();
}

Test SceneLoader::LoadScene(const char* file){
    test = new Test;
    std::fstream File (file, std::ios::in);
    if(!File){
        std::cout << "ups" << std::endl;
    }
    File.seekg (0);
    File.read ((char*)test, sizeof (Test));
    return *test;
}
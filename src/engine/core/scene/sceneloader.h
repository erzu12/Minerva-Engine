#pragma once
#include <vector>

class Test {
public:
    std::vector<float> testdata;
    void setTestdat(){
        testdata.assign(10, 34);
    }
};

class SceneLoader {
    Test *test;
public:
    Test LoadScene(const char* file);
};

class SceneSaver {
public:
    void SaveScene(Test test);
};
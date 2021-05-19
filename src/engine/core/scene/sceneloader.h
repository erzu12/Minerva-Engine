#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

class Test2 {
public:
	int test = 0;
    Test2(int tst) {
        test = tst;
    }
};

class Test {
public:
    std::vector<Test> testdata;
    int testval;
    void setTestdat(Test tst, int tstval){
        testdata.push_back(tst);
        testval = tstval;
    }
    
    void Save() {
        std::fstream file("test.bin", std::ios::out);
		file.seekp(0);
        Write(file);
		file.close();
    }

    void Write(std::fstream &file) {
        int datalength = testdata.size();
        file.write((char*)&datalength, sizeof(int));
        file.write((char*)&testval, sizeof(int));
        if (datalength == 0) {
            return;
        }
        for (Test test : testdata) {
            test.Write(file);
        }
    }

    void Load(const char* filename) {
		std::fstream file (filename, std::ios::in);
		if(!file){
			std::cout << "error: faild to load: " << filename << std::endl;
            return;
		}
		file.seekg (0);
        Read(file);
    }

    void Read(std::fstream& file) {
        int datalength;
        file.read((char*)&datalength, sizeof(int));
        file.read((char*)&testval, sizeof(int));
        if (datalength == 0) {
            return;
        }
        testdata.resize(datalength);
        for (auto it = std::begin(testdata); it != std::end(testdata); ++it) {
            it->Read(file);
        }
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
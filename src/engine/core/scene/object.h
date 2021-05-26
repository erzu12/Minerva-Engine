#pragma once
#include <vector>
#include <iostream>
#include <fstream>

#include "module.h"

class Object : public Module {
public:
	std::vector < std::shared_ptr<Module>> modules;
    std::vector<Object> objects;

	Object* AddObject(Object* newObject);

	int GetModuleIndex() override;

	void AddModule(std::shared_ptr<Module> newModule);

	void Write(std::ofstream &file) override;
	void Read(std::ifstream &file) override;
};
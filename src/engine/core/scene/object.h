#pragma once
#include <vector>
#include <iostream>
#include <fstream>

#include "module.h"

class Object : public Module {
public:
    std::vector<Module> modules;
    std::vector<Object> objects;

	Object* AddObject(Object* newObject);

	Module *AddModule(Module *newModule);

	void Write(std::fstream &file);
	void Read(std::fstream &file);
};
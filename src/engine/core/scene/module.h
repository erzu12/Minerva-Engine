#pragma once

#include <string>

class Module {
public:
	Module *parent;
	std::string name;

	virtual int GetModuleIndex() = 0;

	virtual void Write(std::ofstream &file) = 0;
	virtual void Read(std::ifstream &file) = 0;
};

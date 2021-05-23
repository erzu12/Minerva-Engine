#pragma once

#include <string>

class Module {
public:
	Module *parent;
	std::string name;

	virtual void Write(std::ofstream &file) = 0;
	virtual void Read(std::ifstream &file) = 0;
};

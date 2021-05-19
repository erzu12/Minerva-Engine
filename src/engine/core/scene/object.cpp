#include "object.h"

Object *Object::AddObject(Object *newObject) {
	objects.push_back(*newObject);
	return &objects.back();
}

Module *Object::AddModule(Module *newModule) {
	modules.push_back(*newModule);
	return &modules.back();
}

void Object::Write(std::fstream &file) {
	int datalength = objects.size();
	int namelength = name.length();
	file.write((char*)&datalength, sizeof(int));
	file.write((char*)&namelength, sizeof(int));
	file.write(name.data(), name.length() * sizeof(char));
	if (datalength == 0) {
		return;
	}
	for (Object test : objects) {
		test.Write(file);
	}
}

void Object::Read(std::fstream &file) {
	int datalength;
	int namelength;
	file.read((char*)&datalength, sizeof(int));
	file.read((char*)&namelength, sizeof(int));
	name.resize(namelength);
	file.read((char*)name.data(), namelength * sizeof(char));
	if (datalength == 0) {
		return;
	}
	objects.resize(datalength);
	for (auto it = std::begin(objects); it != std::end(objects); ++it) {
		it->Read(file);
	}
}

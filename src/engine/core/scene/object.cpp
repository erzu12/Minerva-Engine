#include "object.h"
#include "modules.h"

Object *Object::AddObject(Object *newObject) {
	objects.push_back(*newObject);
	return &objects.back();
}

void Object::AddModule(std::shared_ptr<Module> newModule) {
	modules.push_back(std::move(newModule));
}

void Object::Write(std::ofstream &file) {
	int namelength = name.length();
	int datalength = objects.size();
	int modulelength = modules.size();

	file.write((char*)&namelength, sizeof(int));
	file.write(name.data(), name.length() * sizeof(char));

	file.write((char*)&modulelength, sizeof(int));
	file.write((char*)&datalength, sizeof(int));

	if (modulelength != 0) {
		for (auto mod : modules) {
			mod->Write(file);
		}
	}
	if (datalength != 0) {
		for (Object obj : objects) {
			obj.Write(file);
		}
	}
}

void Object::Read(std::ifstream &file) {
	Modules mods;

	int datalength;
	int namelength;
	int modulelength;
	int moduleIndex;

	file.read((char*)&namelength, sizeof(int));
	name.resize(namelength);
	file.read((char*)name.data(), namelength * sizeof(char));
	
	file.read((char*)&modulelength, sizeof(int));
	file.read((char*)&datalength, sizeof(int));

	if (modulelength != 0) {
		modules.resize(modulelength);
		for (rsize_t i = 0; i < modules.size(); ++i) {
			file.read((char*)&moduleIndex, sizeof(int));
			mods.modules[moduleIndex](modules[i], file);
		}
	}
	if (datalength != 0) {
		objects.resize(datalength);
		for (auto it = std::begin(objects); it != std::end(objects); ++it) {
			it->Read(file);
		}
	}
}

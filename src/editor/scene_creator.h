#pragma once

#include <sstream>

#include "scene/scene.h"
#include "scene/object.h"
#include "modules.h"

class SceneCreator {
private:
	Modules modules;
	std::stringstream strStream;
	std::string tp;
	std::string moduleType;
	std::string moduleName;
	std::string argType;
	std::string argValue;
	std::vector<std::pair<std::string, std::string> > args;
	bool isLeft;
	bool isArgs;
public:
	void CreateScene(const char* file);
	void AddModule(bool isParent);
	Scene scene;

	Object *currentObject;
};
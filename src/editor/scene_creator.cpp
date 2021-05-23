#include "scene_creator.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <memory>

#include "scene/mesh.h"


void SceneCreator::CreateScene(const char* file) {

	currentObject = &scene;
	scene.parent = nullptr;

	scene.name = "scene";

	std::fstream newfile;
	newfile.open(file, std::ios::in); 
	if (!newfile.is_open()){
		std::cout << "error failed to open file: " << file << std::endl;
		return;
	}

	strStream << newfile.rdbuf();
	tp = strStream.str();

	isArgs = false;
	isLeft = true;

	for (auto& i : tp) {
		if (i == '\n' || i == ' ' || i == '\v' || i == '\t') {
			continue;
		}
		switch (i)
		{
			case '{' :
				AddModule(true);
				break;
			case '}' :
				currentObject = (Object*)currentObject->parent;
				break;
			case '(' :
				isLeft = false;
				break;
			case ')' :
				isLeft = true;
				break;
			case ',' :
				args.push_back(std::pair < std::string, std::string >(argType, argValue));
				argType.clear();
				argValue.clear();
				isLeft = false;
				break;
			case ':' :
				isArgs = true;

				break;
			case ';' :
				AddModule(false);
				break;
			case '=' :
				isLeft = false;
				break;
			default:
				if (isArgs) {
					if (isLeft) {
						argType += i;
					}
					else {
						argValue += i;
					}
				}
				else {
					if (isLeft) {
						moduleType += i;
					}
					else
					{
						moduleName += i;
					}
				}
				break;
		}
		
	newfile.close();
	}

	scene.Save("test.scene");
}

void SceneCreator::AddModule(bool isParent) {
	isArgs = false;
	args.push_back(std::pair < std::string, std::string >(argType, argValue));
	if (moduleType == "object") {
		Object object;
		object.name = moduleName;
		object.parent = currentObject;
		if (isParent) {
			currentObject = currentObject->AddObject(&object);
		}
		else
		{
			currentObject->AddObject(&object);
		}
	}
	else {
		auto a = modules.modules.find(moduleType);
		if (a == modules.modules.end()) {
			std::cout << "module not found: " << moduleType << std::endl;
		}
		auto func = a->second;
		func(currentObject, moduleName, args);
	}
	std::cout << moduleName << "   " << moduleType << std::endl;
	moduleName.clear();
	moduleType.clear();
	argType.clear();
	argValue.clear();
	args.clear();
}


#include "scene_creator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>


#define COMPONENT(name, mod) 	modules.insert(std::pair<std::string, fptr>(name, [](Object *oc) {mod a; a.parent = oc; return oc->AddModule(&a);}));

typedef Module *(*fptr)(Object *co);

void SceneCreator::CreateScene(const char* file) {
	std::unordered_map<std::string, fptr> modules;

	currentObject = &scene;
	scene.parent = nullptr;

	scene.name = "scene";

	std::fstream newfile;
	newfile.open(file, std::ios::in); 
	if (newfile.is_open()){
		std::stringstream strStream;
		strStream << newfile.rdbuf();
		std::string tp = strStream.str();
		std::string moduleType;
		std::string moduleName;
		bool args = false;
		for (auto& i : tp) {
			if (i == '\n' || i == ' ' || i == '\v' || i == '\t') {}
			else if (i == '{') {
				if (moduleType == "object") {
					Object object;
					object.name = moduleName;
					object.parent = currentObject;
					currentObject = currentObject->AddObject(&object);
					std::cout << moduleName << "   " << moduleType << std::endl;
				}
				else
				{
					std::cout << "error: expected ',' found '{'. Only objects support children" << std::endl;
				}
				moduleName.clear();
				moduleType.clear();
			}
			else if(i == '}') {
				if (moduleType == "object") {
					Object object;
					object.name = moduleName;
					object.parent = currentObject;
					currentObject->AddObject(&object);
					std::cout << moduleName << "   " << moduleType << std::endl;
				}
				currentObject = (Object*)currentObject->parent;
				moduleName.clear();
				moduleType.clear();
			}
			else if (i == '(') {
				args = true;
			}
			else if (i == ')') {
				args = false;
			}
			else if (i == ',') {
				if (moduleType == "object") {
					Object object;
					object.name = moduleName;
					object.parent = currentObject;
					currentObject->AddObject(&object);
				}
				std::cout << moduleName << "   " << moduleType << std::endl;
				moduleName.clear();
				moduleType.clear();
			}
			else {
				if (args) {
					moduleName += i;
				}
				else {
					moduleType += i;
				}
			}
		}
		newfile.close();
	}
	else
	{
		std::cout << "error failed to open file: " << file << std::endl;
	}

	scene.Save("test.scene");
}


#include "scene_creator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

#include "scene/mesh.h"
#include "modules.h"


#define COMPONENT(modName, mod) 	modules.insert(std::pair<std::string, fptr>(modName, [](Object *co, std::string *name) { \
										std::shared_ptr<Module> a(new mod()); \
										a->parent = co; \
										a->name = *name; \
										co->AddModule(std::move(a)); \
									}));

typedef void (*fptr)(Object *co, std::string *name);

void SceneCreator::CreateScene(const char* file) {
	//std::unordered_map<std::string, fptr> modules;
	//COMPONENT("mesh", Mesh);

	Modules modules;

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
				else {
					auto a = modules.modules.find(moduleType);
					if (a == modules.modules.end()) {
						std::cout << "module not found: " << moduleType << std::endl;
					}
					auto func = a->second;
					func(currentObject, moduleName, std::string());
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
				else {
					auto a = modules.modules.find(moduleType);
					if (a == modules.modules.end()) {
						std::cout << "module not found: " << moduleType << std::endl;
					}
					auto func = a->second;
					func(currentObject, moduleName, std::string());
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


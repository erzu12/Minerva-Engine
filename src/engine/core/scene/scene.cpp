#include "scene.h"

void Scene::Save(const char* filename) {
	std::fstream file(filename, std::ios::out);
	file.seekp(0);
	Write(file);
	file.close();
}

void Scene::Load(const char* filename) {
	std::fstream file (filename, std::ios::in);
	if(!file){
		std::cout << "error: faild to load: " << filename << std::endl;
		return;
	}
	file.seekg (0);
	Read(file);
}

#include "scene.h"

void Scene::Save(const char* filename) {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	file.seekp(0);
	Write(file);
	file.close();
}

void Scene::Load(const char* filename) {
	std::ifstream file (filename, std::ios::in | std::ios::binary);
	if(!file){
		std::cout << "error: faild to load: " << filename << std::endl;
		return;
	}
	file.seekg (0);
	Read(file);
}

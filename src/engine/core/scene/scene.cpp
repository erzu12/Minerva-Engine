#include "scene.h"

Scene Scene::Get() {
	static Scene scene;
	return scene;
}


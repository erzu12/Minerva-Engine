#pragma once
#include "scene/scene.h"
#include "scene/object.h"

class SceneCreator {
public:
	void CreateScene(const char* file);
	Scene scene;

	Object *currentObject;
};
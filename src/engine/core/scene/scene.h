#pragma once

#include <vector>

#include "object.h"

class Scene : public Object
{
public:
	Scene() {}

	void Save(const char* filename);
	void Load(const char* filename);
};
#pragma once

#include <unordered_map>
#include <functional>
#include <memory>

#include "config.h"
#include "scene/mesh.h"
#include "scene/object.h"
#include "mesh_loader.h"

class Modules {
public:

	std::unordered_map < std::string, std::function<void(Object*, std::string, std::string) > > modules{
		{"mesh",[](Object *co, std::string &name, std::string &args) {
			Meshloader ml;
			auto mesh = std::make_shared<Mesh>();
			mesh->name = name;
			mesh->parent = co;
			ml.LoadMesh(ASSETS_PATH"/models/test.obj", mesh);
			co->AddModule(std::move(mesh));
		}}
	};
};

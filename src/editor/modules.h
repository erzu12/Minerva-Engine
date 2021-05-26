#pragma once

#include <unordered_map>
#include <functional>
#include <memory>
//#include <sstream>

#include "config.h"
#include "scene/mesh.h"
#include "scene/object.h"
#include "mesh_loader.h"

class Modules {
public:

	std::unordered_map < std::string, std::function<void(Object*, std::string&, std::vector<std::pair<std::string, std::string> >&) > > modules {
		{"mesh",[=](Object *co, std::string &name, std::vector<std::pair<std::string, std::string> > &args) {
			auto mesh = std::make_shared<Mesh>();
			mesh->name = name;
			mesh->parent = co;
			for (auto& arg : args) {
				auto a = meshArgs.find(arg.first);
				if (a == meshArgs.end()) {
					std::cout << "error: no such argument for Mesh: " << arg.first << std::endl;
				}
				else
				{
					a->second(mesh, arg.second);
				}
			}
			co->AddModule(std::move(mesh));
		}}
	};

	std::unordered_map < std::string, std::function<void(std::shared_ptr<Mesh>, std::string&) > > meshArgs{
		{"path",[](std::shared_ptr<Mesh> mod, std::string& arg) {
			Meshloader ml;
			ml.LoadMesh(ASSETS_PATH + arg, mod);
		}},
		{"position",[](std::shared_ptr<Mesh> mod, std::string& arg) {
			int x, y, z;
			std::stringstream ss(arg);
			ss >> x;
			ss >> y;
			ss >> z;
			mod->pos = {x, y, z};
		}}
	};
};

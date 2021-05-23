#pragma once

#include <vector>
#include <functional>
#include <fstream>

#include "mesh.h"


class Modules {
public:
	std::vector<std::function<void(std::shared_ptr<Module>&, std::ifstream&)> > modules{
		[](std::shared_ptr<Module> &mod, std::ifstream &file) {
			auto mesh = std::make_shared<Mesh>();
			mesh->Read(file);
			mod = std::dynamic_pointer_cast<Module>(mesh);
		}
	};
};
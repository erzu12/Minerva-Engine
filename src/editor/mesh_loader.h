#pragma once

#include <string>
#include <memory>

#include "scene/mesh.h"

class Meshloader
{
public:
    void LoadMesh(std::string path, std::shared_ptr<Mesh> mesh);
private:
};



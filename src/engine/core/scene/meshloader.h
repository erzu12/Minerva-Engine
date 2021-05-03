#pragma once

#include "mesh.h"
#include <string>

class Meshloader
{
public:
    static Meshloader& Get();
    void LoadMesh(std::string path, Mesh* mesh);
private:
    Meshloader(){}
};



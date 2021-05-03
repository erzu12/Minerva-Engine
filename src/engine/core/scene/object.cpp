#include "object.h"
#include "meshloader.h"
#include "config.h"

Object::Object(){
    Meshloader::Get().LoadMesh(ASSETS_PATH"/models/plane.obj", &mesh);
}
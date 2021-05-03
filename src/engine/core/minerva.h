#pragma once
#include "window/window.h"
#include "log.h"
#include "vulkan.h"
#include "scene/sceneloader.h"

class Minerva {
public:
    Minerva(){
    }

    Window window;
    
    void Init();

    void Update();

    bool ShouldWindowClose(Window w);
};
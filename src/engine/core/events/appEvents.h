#pragma once
#include "events/events.h"
#include "window/window.h"

struct WindowCloseEvent : public Event {
    WindowCloseEvent(GLFWwindow* window) : window{ window } {}
    Window window;
};

struct UpdateEvent : public Event 
{
    UpdateEvent(){}
};

struct StartEvent : public Event
{
    StartEvent(){}
};

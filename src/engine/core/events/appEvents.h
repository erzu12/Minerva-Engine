#include "events/events.h"
#include "window/window.h"

struct WindowCloseEvent : public Event {
    WindowCloseEvent(GLFWwindow* window) : window{ window } {}
    Window window;
};
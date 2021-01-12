#include "events.h"

struct KeyDownEvent : public Event {
    KeyDownEvent(int key) : key{ key } {}
    int key;
};

struct KeyUpEvent : public Event {
    KeyUpEvent(int key) : key{ key } {}
    int key;
};


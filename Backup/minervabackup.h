#pragma once
#include "window/window.h"
#include "log.h"
#include "events.h"
#include "appEvents.h"
#include <iostream>

void MvInit();

void MvUpdate();

bool MvShouldWindowClose(Window w);

class Core
{
public:
    Core()
    {
		EventBus::Get().subscribe(this, &Core::Update);
		EventBus::Get().subscribe(this, &Core::Start);
    }
    ~Core()
    {
    }

	virtual void Update(UpdateEvent* updateEvent){}
	virtual void Start(StartEvent* startEvent){}
};
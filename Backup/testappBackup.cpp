#include "minerva.h"
#include <iostream>

class Testapp : public Core
{
public:
	Testapp()
	{
	}

	~Testapp()
	{
	}

	Log log;

	void Update(UpdateEvent* updateEvent) override
	{
	}

	// void Start(StartEvent* startEvent) override
	// {
	// }
};

Core* GameInit(){
	return new Testapp();
}
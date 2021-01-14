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

	void Update(UpdateEvent* updateEvent) override 
	{
		log("update");
	}

	void Start(StartEvent* startEvent) override 
	{
		log("start");
	}
};

Core* GameInit(){
	return new Testapp();
}
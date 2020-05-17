#include "Application.h"

#include "Minerva/Events/AppEvent.h"
#include "Minerva/Log.h"

namespace Minerva
{

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MV_INFO(e);


		while (true);
	}

}
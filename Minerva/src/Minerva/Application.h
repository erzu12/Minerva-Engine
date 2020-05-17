#pragma once
#include "core.h"
#include "Events/Event.h"

namespace Minerva
{
	class MINERVA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in CLIENT
	Application* CreateApplication();

}


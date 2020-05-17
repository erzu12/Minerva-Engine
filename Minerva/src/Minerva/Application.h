#pragma once
#include "core.h"

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


#pragma once
#include "core.h"
#include "Events/Event.h"
#include "Minerva/Events/AppEvent.h"

#include "Window.h"

namespace Minerva
{
	class MINERVA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;;
	};


	// To be defined in CLIENT
	Application* CreateApplication();

}


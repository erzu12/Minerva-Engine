#include "mvpch.h"
#include "Application.h"
#include "Minerva/Log.h"

namespace Minerva
{

#define BINDE_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BINDE_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BINDE_EVENT_FN(OnWindowClose));

		MV_CORE_TRACE("{0}", e);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		while (m_Running)
		{
			m_Window->Update();
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
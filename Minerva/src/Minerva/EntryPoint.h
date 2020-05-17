#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Minerva::Application* Minerva::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Minerva::CreateApplication();
	app->Run();
	delete app;
}

#endif

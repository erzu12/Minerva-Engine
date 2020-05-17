#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Minerva::Application* Minerva::CreateApplication();

void main(int argc, char** argv)
{
	Minerva::Log::Init();
	MV_CORE_WARN("warning");
	int a = 5;
	MV_INFO("hello Var={0}", a);

	auto app = Minerva::CreateApplication();
	app->Run();
	delete app;
}

#endif

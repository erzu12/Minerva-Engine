#include <Minerva.h>


class Test : public Minerva::Application
{
public:
	Test()
	{

	}

	~Test()
	{

	}
};

Minerva::Application* Minerva::CreateApplication()
{
	return new Test();
}
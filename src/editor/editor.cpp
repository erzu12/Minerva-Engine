#include "scene_creator.h"

#include "minerva.h"


class B {
public:
	virtual void Out() {
		std::cout << "base\n";
	}
};

class D : public B {
public:
	void Out() override {
		std::cout << "Derived\n";
	}
};


int main() 
{
//	std::vector<std::unique_ptr<B>> objs;
//
//std::unique_ptr<B>d(new D());
//
//	objs.push_back(std::move(d));
//	objs.push_back(std::make_unique<B>());
//
//	objs[0]->Out();
//	objs[1]->Out();

	SceneCreator sc;
	sc.CreateScene("test.txt");
}
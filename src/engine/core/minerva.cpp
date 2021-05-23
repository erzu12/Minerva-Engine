#include "minerva.h"


void Minerva::Init() {

	//init
	window.InitWindow();

}

void Minerva::Update() {
	glfwPollEvents();
}

bool Minerva::ShouldWindowClose(Window window) {
	return glfwWindowShouldClose(window.GLFWwidow);
}

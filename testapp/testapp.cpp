#include "minerva.h"
#include <iostream>

int main() {
	Window window = MvInit();

	while (!MvShouldWindowClose(window)) {
		MvUpdate();
	}
}
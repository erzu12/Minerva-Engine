#include <iostream>
#include "log.h"

Log::Log(){
	start = std::chrono::steady_clock::now();
	count = 0;
}

void Log::Message(const char* output) {
	std::cout << output << std::endl;
}

void Log::Fps() {
	count++;

	if(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() >= 1000000){
		start = std::chrono::steady_clock::now();
		std::cout << "Fps: " << count << std::endl;
		count = 0;
	}

	
}

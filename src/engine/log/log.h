#pragma once
#include <chrono>

class Log {
public:
    Log();
    void Message(const char* output);
    void Fps();
private:
    int count;
    std::chrono::steady_clock::time_point start;
};


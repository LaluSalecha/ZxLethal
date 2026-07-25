#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time
{
public:

    Time();

    void Update();

    float GetDeltaTime() const;

private:

    std::chrono::high_resolution_clock::time_point lastTime;

    float deltaTime;
};

#endif

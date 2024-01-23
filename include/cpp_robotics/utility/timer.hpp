#pragma once

#include <chrono>

namespace cpp_robotics
{

class Timer
{
public:
    void start()
    {
        start_ = std::chrono::system_clock::now();
    }

    void stop()
    {
        end_ = std::chrono::system_clock::now();
    }

    double second()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() * 1e-3;
    }

    double millisecond()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count();
    }

    template<class Second>
    int count()
    {
        return std::chrono::duration_cast<Second>(end_-start_).count();
    }

private:
    std::chrono::system_clock::time_point start_, end_; 
};

}
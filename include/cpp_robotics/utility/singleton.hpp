#pragma once

#include <memory>

namespace cpp_robotics
{

template<class T>
class Singleton
{
private:
    Singleton() = default;

public:
    static std::shared_ptr<T> get_instance()
    {
        static std::shared_ptr<T> instance = std::make_shared<T>();
        return instance;
    }
};

}
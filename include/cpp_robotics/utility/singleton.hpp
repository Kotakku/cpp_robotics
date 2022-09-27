#pragma once

#include <memory>

namespace cpp_robotics
{

/**
 * @brief シングルトンなオブジェクトを生成する
 * 
 * @tparam T シングルトンで生成したいオブジェクトの型
 */
template<class T>
class Singleton
{
private:
    Singleton() = default;

public:
    using class_t = T;
    using shared_t = std::shared_ptr<class_t>;

    /**
     * @brief シングルトンなオブジェクトをstd::shared_ptrで返す
     * 
     * @return shared_t オブジェクトのshared_ptr
     */
    static shared_t get_shared_instance()
    {
        static shared_t instance = std::make_shared<class_t>();
        return instance;
    }
};

}
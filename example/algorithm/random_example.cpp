#include <iostream>
#include <cpp_robotics/algorithm.hpp>

double random_std()
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    // 平均0.0、標準偏差1.0で分布させる
    std::normal_distribution<> dist(0.0, 1.0);

    return dist(engine);
}

double random_cpp_robotics()
{
    // 平均0.0、標準偏差1.0で分布させる
    cpp_robotics::NormalRandomEngine dist_engine(0.0, 1.0);
    return dist_engine.value();
}

int main()
{
    // random_std関数とrandom_cpp_robotics関数はどちらも平均0.0, 標準偏差1.0の正規分布に従う乱数を返す関数です
    // random_cpp_robotics関数ではインスタンスの生成は1つだけです
    
    std::cout << "random_std:          " << random_std() << std::endl;
    std::cout << "random_cpp_robotics: " << random_cpp_robotics() << std::endl;
}
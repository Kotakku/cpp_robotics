---
title: example/optimize/optimize_rosenbrock.cpp

---

# example/optimize/optimize_rosenbrock.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/optimize__rosenbrock_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/optimize.hpp>

int main()
{
    namespace cr = cpp_robotics;

    // 2変数 Rosenbrock関数
    // 最適解は x = (1, 1)
    auto f = [](Eigen::VectorXd x) -> double
    {
        return 100*( std::pow( (x(0) - std::pow(x(1),2)), 2) ) + std::pow(1 - x(1), 2);
    };

    auto g = [&](const Eigen::VectorXd &x)
    {
        return cr::derivative(f, x);
    };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    {
        auto [ret, rx, rcnt] = cr::quasi_newton_method(f, g, x_init);
        std::cout << "optimize Rosenbrock function with quasi newton method" << std::endl;
        std::cout << "ans: " << rx.transpose() << std::endl;
        std::cout << "itr: " << rcnt << std::endl;
    }
}
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900

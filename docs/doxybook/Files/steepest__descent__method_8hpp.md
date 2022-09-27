---
title: include/cpp_robotics/optimize/steepest_descent_method.hpp

---

# include/cpp_robotics/optimize/steepest_descent_method.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <tuple>
#include <functional>
#include <Eigen/Dense>
#include "bracketing_serach.hpp"

namespace cpp_robotics
{

// 最急降下法
static std::tuple<bool, Eigen::VectorXd, size_t> steepest_descent_method(std::function<double(const Eigen::VectorXd &)> f, std::function<Eigen::VectorXd(const Eigen::VectorXd &)> grad, Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
{
    Eigen::VectorXd x = x_init;
    Eigen::VectorXd s;

    for(size_t i = 0; i < max_iter; i++)
    {
        s = -grad(x);

        if(s.norm() < tol)
        {
            return {true, x, i};
        }

        // 直線探索
        double a = bracketing_serach(f, grad, x, s);
        x += a*s;
    }

    return {false, x, max_iter};
}

}
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900
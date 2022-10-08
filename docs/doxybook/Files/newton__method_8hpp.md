---
title: include/cpp_robotics/optimize/newton_method.hpp

---

# include/cpp_robotics/optimize/newton_method.hpp



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

static std::tuple<bool, Eigen::VectorXd, size_t> newton_method(std::function<Eigen::VectorXd(const Eigen::VectorXd &)> grad, std::function<Eigen::MatrixXd(const Eigen::VectorXd &)> hesse, Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
{
    Eigen::VectorXd x = x_init;
    Eigen::VectorXd dx;

    for(size_t i = 0; i < max_iter; i++)
    {
        dx = grad(x);

        if(dx.norm() < tol)
        {
            return {true, x, i};
        }

        x -= (hesse(x).inverse() * dx);
    }

    return {false, x, max_iter};
}

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

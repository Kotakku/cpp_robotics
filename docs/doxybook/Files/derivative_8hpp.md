---
title: include/cpp_robotics/optimize/derivative.hpp

---

# include/cpp_robotics/optimize/derivative.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <limits>
#include <functional>
#include <Eigen/Dense>

namespace cpp_robotics
{

static double derivative(std::function<double(double)> f, double x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    // 中央差分
    return ( f(x + eps) - f(x - eps) ) / (2.0*eps);
}

static Eigen::VectorXd derivative(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::VectorXd der(x.rows());
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        Eigen::VectorXd diff = Eigen::VectorXd::Zero(x.rows());
        diff(i) = eps;
        // 中央差分
        der(i) = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
    }
    return der;
}

static Eigen::MatrixXd derivative(std::function<Eigen::VectorXd(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::MatrixXd der;
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        Eigen::VectorXd diff = Eigen::VectorXd::Zero(x.rows());
        diff(i) = eps;
        // 中央差分
        Eigen::VectorXd der_col = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
        if(i == 0)
        {
            der = Eigen::MatrixXd::Zero(der_col.size(), x.rows());
        }
        der.col(i) = der_col;
    }
    return der;
}

static double second_derivative(std::function<double(double)> f, double x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    // 中央2階差分
    return ( f(x + eps) - 2*f(x) + f(x - eps) ) / std::pow(eps,2);
}

static Eigen::MatrixXd approx_hessian(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    auto j = derivative(f, x, eps);
    return j * j.transpose();
}

}
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900

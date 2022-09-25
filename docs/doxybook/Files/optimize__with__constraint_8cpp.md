---
title: example/optimize/optimize_with_constraint.cpp

---

# example/optimize/optimize_with_constraint.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/optimize__with__constraint_8cpp/#function-main)**() |


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
    using namespace cpp_robotics;

    std::cout << "test" << std::endl;

    auto f = [](Eigen::VectorXd x)
    {
        return std::pow(x(0)-2,2) + std::pow(x(1),2);
    };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);

    ConstraintArray con;
    con.push_back({
        Constraint::Type::Ineq,
        [](Eigen::VectorXd x)
        {
            return (std::pow(x(0), 2) + std::pow(x(1), 2)) - 1;
        }
    });

    {
        x_init(0) = 0.4;
        x_init(1) = 0.5;
        auto [ret, rx, rcnt] = penalty_method(f, con, x_init);
        std::cout << rx.transpose() << "(norm: " << rx.norm() << "), " << rcnt << std::endl;
    }

    {
        x_init(0) = 0.4;
        x_init(1) = 0.5;
        auto [ret, rx, rcnt] = barrier_method(f, con, x_init);
        std::cout << rx.transpose() << "(norm: " << rx.norm() << "), " << rcnt << std::endl;
    }
}
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900

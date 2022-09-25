---
title: example/optimize/sqp_example.cpp

---

# example/optimize/sqp_example.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics_core/doxybook/Files/sqp__example_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <cpp_robotics/algorithm/algorithm.hpp>
#include <cpp_robotics/optimize/sqp.hpp>
#include "cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h"

using namespace cpp_robotics;

int main()
{
    SQP solver;
    SQP::Problem prob;

    prob.func = [](Eigen::VectorXd x)
    {
        return std::pow(x(0)+3, 2) + std::pow(x(1),2);
    };

    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            return (x.squaredNorm() - 3*3);
        },
    });

    Eigen::Vector2d cx(2.0, 0.0);
    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [=](Eigen::VectorXd x)
    //     {
    //         x -= cx;
    //         return (x.squaredNorm() - 3*3);
    //     },
    // });
    // prob.con.push_back({
    //     Constraint::Eq,
    //     [](Eigen::VectorXd x)
    //     {
    //         return (x(0) - 1);
    //     },
    // });
    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [](Eigen::VectorXd x)
    //     {
    //         x(0) -= 1.5;
    //         return x.squaredNorm() - 1;
    //     },
    // });

    Eigen::VectorXd x0(2);
    x0 << 0, 0.5;

    std::vector<double> x_, y_;

    auto result = solver.solve(prob, x0, [&](auto x){ x_.push_back(x(0)); y_.push_back(x(1)); });

    std::cout << "min (x(0))^2 + x(1)^2" << std::endl;
    std::cout << "s.t. x(0)^2 + x(1)^2 <= 1" << std::endl;

    if(result.is_solved)
    {
        std::cout << "解けた" << std::endl;
    }
    else
    {
        std::cout << "解けなかった" << std::endl;
    }

    std::cout << "optimal x =" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "x norm = " << result.x.norm() << std::endl;
    
    std::cout << "x norm = " << (result.x-cx).norm() << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;
    std::cout << "size: " << x_.size() << ", " << y_.size() << std::endl;

    for(size_t i = 0; i < x_.size(); i++)
    {
        std::cout << x_[i] << ",  " << y_[i] << std::endl;
    }
    

    namespace plt = matplotlibcpp;
    plt::plot(x_, y_, "o--");
    plt::xlim(-4, 4);
    plt::ylim(-4, 4);
    
    plt::show();


}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

---
title: example/algorithm/icp_sample.cpp

---

# example/algorithm/icp_sample.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics_core/doxybook/Files/icp__sample_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <cpp_robotics/algorithm/algorithm.hpp>
#include <cpp_robotics/vector/vector2.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>

int main()
{
    namespace cr = cpp_robotics;

    {
        std::vector<Eigen::Vector2d> fixed = {
            {0,9},
            {0,7},
            {0,5},
            {0,3},
            {2,1},
            {4,1},
            {6,1},
            {8,3},
            {8,5},
            {8,9},
        };

        std::vector<Eigen::Vector2d> p2 = fixed;
        for(size_t i = 0; i < fixed.size(); i++)
        {
            // p2[i][0] = fixed[i][1] + 1;
            // p2[i][1] = -fixed[i][0];
            p2[i][0] += 3.0; //fixed[i][0];
            p2[i][1] += 1.0; //fixed[i][1];
        }
        auto [R, T] = cr::calcu_transformatoin<2>(p2, fixed);

        std::cout << "R = " << std::endl;
        std::cout << R << std::endl;
        std::cout << "T = " << std::endl;
        std::cout << T << std::endl;

        std::cout << "///// check /////" << std::endl;

        for(size_t i = 0; i < p2.size(); i++)
        {
            auto moved_p = R*p2[i] + T;

            std::cout << moved_p.transpose() << ", err = " << (moved_p-fixed[i]).transpose() << std::endl;
        }
    }

    {
        std::vector<Eigen::Vector2d> p1 = {
            {0,8},
            {0,7},
            {0,5},
            {0,3},
            {2,1},
            {4,1},
            {6,1},
            {8,3},
            {8,5},
            {8,9},
        };

        std::vector<Eigen::Vector2d> p2 = p1;
        for(auto &v : p2)
            v += Eigen::Vector2d(3, 0);

        auto [points, cnt] = cr::icp<2>(p2, p1, 50);

        auto gen = [](std::vector<Eigen::Vector2d> ps)
        {
            std::vector<double> x_(ps.size()), y_(ps.size());

            for(size_t i = 0; i < (ps.size()); i++)
            {
                x_[i] = ps[i][0];
                y_[i] = ps[i][1];
            }

            return std::tuple<std::vector<double>, std::vector<double>>(x_, y_);
        };

        auto [x, y] = gen(p1);
        matplotlibcpp::plot(x, y);
        auto [x2, y2] = gen(points);
        matplotlibcpp::plot(x2, y2);
        matplotlibcpp::show();

    }
}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

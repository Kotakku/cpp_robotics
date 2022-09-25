---
title: example/system/state_space_system.cpp

---

# example/system/state_space_system.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/state__space__system_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <cpp_robotics/system/system.hpp>
#include <cpp_robotics/controller/controller.hpp>

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    Eigen::Matrix2d A;
    Eigen::Matrix<double, 2, 1> B;
    Eigen::Matrix<double, 1, 2> C;

    A << 0, 1, 1, 0.5;
    B << 0, 0.5;
    C << 1, 0;
    const double dt = 0.01;

    cr::StateSpaceSystem sys(A, B, C, dt);

    std::cout << cr::is_controllable(A, B) << std::endl;
    std::cout << cr::is_observable(A, C) << std::endl;
}
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900

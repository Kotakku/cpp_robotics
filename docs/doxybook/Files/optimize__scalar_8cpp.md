---
title: example/optimize/optimize_scalar.cpp

---

# example/optimize/optimize_scalar.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/optimize__scalar_8cpp/#function-main)**() |


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

    std::cout << "optimize_scalar" << std::endl;

    std::cout << "min x => (x+1)^2 = " << cr::golden_search([](double x){ return std::pow(x+1, 2); }, -10, 10) << std::endl;

    std::cout << "sin'(0) = cos(0) = " << cr::derivative([](double x){ return std::sin(x); }, 0) << std::endl;
}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900

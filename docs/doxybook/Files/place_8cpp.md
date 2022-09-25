---
title: example/controller/place.cpp

---

# example/controller/place.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics_core/doxybook/Files/place_8cpp/#function-main)**() |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[PRINT_MAT](/cpp_robotics_core/doxybook/Files/place_8cpp/#define-print-mat)**(MAT)  |


## Functions Documentation

### function main

```cpp
int main()
```




## Macros Documentation

### define PRINT_MAT

```cpp
#define PRINT_MAT(
    MAT
)
    std::cout << #MAT << std::endl;\
    std::cout << MAT << std::endl << std::endl;
```


## Source code

```cpp
#include <iostream>
#include <iomanip>
#include <cpp_robotics/system/system.hpp>
#include <cpp_robotics/controller/controller.hpp>

#define PRINT_MAT(MAT) \
    std::cout << #MAT << std::endl;\
    std::cout << MAT << std::endl << std::endl;

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    // http://arduinopid.web.fc2.com/O7.html
    Eigen::MatrixXd A(2,2);
    Eigen::MatrixXd B(2,1);
    Eigen::MatrixXd C(1,2);
    Eigen::MatrixXd D(1,1);

    A << 
        -10, -10,
        5, 0;
    B << 10, 0;
    C << 0, 1;
    D << 0;

    const double dt = 0.01;
    cr::StateSpaceSystem sys(A, B, C, D, dt);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "pole place" << std::endl;
    std::vector<double> pole = {-6, -6};
    auto K = cr::place(sys, pole);
    
    PRINT_MAT(K);
}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

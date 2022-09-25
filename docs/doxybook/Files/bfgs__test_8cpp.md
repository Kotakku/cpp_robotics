---
title: example/optimize/bfgs_test.cpp

---

# example/optimize/bfgs_test.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Mat \> <br>bool | **[is_posdef](/cpp_robotics_core/doxybook/Files/bfgs__test_8cpp/#function-is-posdef)**(Mat H) |
| int | **[main](/cpp_robotics_core/doxybook/Files/bfgs__test_8cpp/#function-main)**() |


## Functions Documentation

### function is_posdef

```cpp
template <typename Mat >
bool is_posdef(
    Mat H
)
```


### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <cpp_robotics/algorithm/algorithm.hpp>
#include <cpp_robotics/optimize/sqp.hpp>

template <typename Mat>
bool is_posdef(Mat H)
{
    Eigen::EigenSolver<Mat> eigensolver(H);
    for (int i = 0; i < eigensolver.eigenvalues().rows(); i++) {
        double v = eigensolver.eigenvalues()(i).real();
        if (v <= 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    using namespace cpp_robotics;

    {
        Eigen::VectorXd step(2), delta_grad(2);
        Eigen::MatrixXd H(2,2); // true constant hessian;
        H << 2, 0,
            0, 1;
        Eigen::MatrixXd B = Eigen::MatrixXd::Identity(2,2);

        for (int i = 0; i < 10; i++) {
            // do some random steps
            step << sin(i), cos(i);

            delta_grad = H*step;
            powells_modified_bfgs_step(B, step, delta_grad);

            assert(is_posdef(B));
        }

        assert(B.isApprox(H, 1e-3));

        std::cout << "test 1 done!" << std::endl;
    }

    {
        Eigen::VectorXd step(2), delta_grad(2);
        Eigen::MatrixXd H(2,2); // true constant hessian;
        H << 2, 0,
            0, -1;
        Eigen::MatrixXd B = Eigen::MatrixXd::Identity(2,2);

        for (int i = 0; i < 10; i++) {
            // do some random steps
            step << sin(i), cos(i);

            delta_grad = H*step;
            powells_modified_bfgs_step(B, step, delta_grad);

            assert(is_posdef(B));
        }

        std::cout << "test 2 done!" << std::endl;
    }

}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

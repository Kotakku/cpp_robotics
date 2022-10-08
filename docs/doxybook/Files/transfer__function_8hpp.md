---
title: include/cpp_robotics/system/transfer_function.hpp

---

# include/cpp_robotics/system/transfer_function.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)** <br>伝達関数モデル  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>
#include "state_space_system.hpp"

#include <iostream>

namespace cpp_robotics
{

class TransferFunction : public StateSpaceSystem
{
public:
    static TransferFunction make_first_order_system(const double T, const double Ts)
    {
        return TransferFunction({1}, {T, 1}, Ts);
    }

    static TransferFunction make_second_order_system(const double omega, const double zeta, const double Ts)
    {
        return TransferFunction({omega*omega}, {1.0, 2.0*zeta*omega, omega*omega}, Ts);
    }

    TransferFunction():
        StateSpaceSystem() {}
    
    TransferFunction(std::vector<double> num, std::vector<double> den, const double Ts):
        num_array_(num), den_array_(den)
    {
        // 伝達関数を可制御正準系に変換して保存
        const size_t num_size = num_array_.size();
        const size_t den_size = den_array_.size();
        const size_t state_size = den_deg();

        Eigen::MatrixXd A = Eigen::MatrixXd::Zero(state_size, state_size);
        // 対角要素の1個右隣を1埋め
        for(size_t i = 0; i < state_size-1; i++)
        {
            A(i, i+1) = 1;
        }
        // 一番下の行を伝達関数の要素で埋め
        for(size_t i = 0; i < state_size; i++)
        {
            A(state_size-1, i) = -den_array_[state_size - i] / den_array_[0];
        }

        Eigen::MatrixXd B = Eigen::VectorXd::Zero(state_size);
        B(state_size-1) = 1;

        Eigen::MatrixXd C = Eigen::RowVectorXd::Zero(state_size);
        for(size_t i = 0; i <= num_size; i++)
        {
            C(i) = num_array_[i] / den_array_[0];
        }

        set_continuous(A, B, C, Ts);
    }

    size_t num_deg(size_t num_idx = 0) const
    {
        return num_array_.size()-1 - num_idx;
    }

    size_t den_deg(size_t num_idx = 0) const
    {
        return den_array_.size()-1 - num_idx;
    }

    std::vector<double> num_array() const { return num_array_; }
    std::vector<double> den_array() const { return den_array_; }

private:
    std::vector<double> num_array_;
    std::vector<double> den_array_;
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

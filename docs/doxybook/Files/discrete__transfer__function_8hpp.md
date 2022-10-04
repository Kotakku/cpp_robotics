---
title: include/cpp_robotics/system/discrete_transfer_function.hpp

---

# include/cpp_robotics/system/discrete_transfer_function.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)** <br>z空間の伝達関数  |




## Source code

```cpp
#pragma once

#include <vector>

namespace cpp_robotics
{

class DiscreteTransferFunction
{
public:
    DiscreteTransferFunction() = default;
    DiscreteTransferFunction(std::vector<double> num_disc, std::vector<double> den_disc, const double dt)
    {
        set_discrite(num_disc, den_disc, dt);
    }

    // z領域の伝達関数の分子と分母を降べきの準に与える
    void set_discrite(std::vector<double> num_disc, std::vector<double> den_disc, const double dt)
    {
        assert(num_disc.size() > 0);
        assert(den_disc.size() > 0);
        
        num_ = num_disc;
        den_ = den_disc;

        u_.resize(num_.size());
        y_.resize(den_.size()-1);

        dt_ = dt;
    }

    double Ts() const { return dt_; }

    virtual void reset(double state = 0)
    {
        (void) state;

        for(auto &u : u_)
            u = 0;
        for(auto &y : y_)
            y = 0;
    }

    double responce(double u)
    {
        double y = 0;
        u_.pop_back();
        u_.insert(u_.begin(), u);

        for(size_t i = 0; i < num_.size(); i++)
        {
            y += num_[i]*u_[u_.size()-1-i];
        }

        for(size_t i = 0; i < den_.size()-1; i++)
        {
            y -= den_[i]*y_[y_.size()-1-i];
        }

        y /= den_.back();

        y_.pop_back();
        y_.insert(y_.begin(), y);

        return y;
    }

private:
    std::vector<double> num_;
    std::vector<double> den_;
    std::vector<double> u_;
    std::vector<double> y_;
    double dt_;
};

}
```


-------------------------------

Updated on 2022-10-05 at 01:02:07 +0900

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
#include <cpp_robotics/system/discret.hpp>

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

    void set_continuous(std::vector<double> num, std::vector<double> den, const double dt)
    {
        auto [num_disc, den_disc] = DiscretTransferFunction::discritize(num, den, dt);
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

        reset();
    }
    
    double Ts() const { return dt_; }

    virtual void reset(double state = 0)
    {
        for(auto &u : u_)
            u = 0;
        for(auto &y : y_)
            y = state;
        u_.reset_position();
        y_.reset_position();
    }

    double responce(double u)
    {
        double y = 0;
        u_.insert_front(u);

        for(size_t i = 0; i < num_.size(); i++)
        {
            y += num_[i]*u_.at_circular(i);
        }

        for(size_t i = 0; i < den_.size()-1; i++)
        {
            y -= den_[i+1]*y_.at_circular(i);
        }
        y /= den_[0];

        y_.insert_front(y);
        return y;
    }

private:
    template<typename T>
    class CircularBuffer : public std::vector<T>
    {
    public:
        void reset_position()
        {
            i = 0;
        }

        T& at_circular(size_t idx)
        {
            idx += i;
            if(this->size() <= idx)
                idx-=this->size();
            return this->at(idx);
        }

        void insert_front(T val)
        {
            i += this->size()-1;
            if(this->size() <= i)
                i-=this->size();
            this->at(i) = val;
        }

    private:
        size_t i = 0;
    };
    std::vector<double> num_;
    std::vector<double> den_;
    CircularBuffer<double> u_;
    CircularBuffer<double> y_;
    double dt_;
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

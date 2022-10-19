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
#include <cpp_robotics/system/discret.hpp>

namespace cpp_robotics
{

class TransferFunction
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

    TransferFunction() = default;
    
    TransferFunction(std::vector<double> num, std::vector<double> den, const double Ts):
        num_array_(num), den_array_(den)
    {
        set_continuous(num_array_, den_array_, Ts);
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

Updated on 2022-10-19 at 13:20:53 +0900

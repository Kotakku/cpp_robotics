---
title: include/cpp_robotics/system/time_responce.hpp

---

# include/cpp_robotics/system/time_responce.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <tuple>
#include "./transfer_function.hpp"
#include "./discrete_transfer_function.hpp"


namespace cpp_robotics
{

static std::tuple<std::vector<double>, std::vector<double>> impluse(TransferFunction &sys, double time)
{
    std::vector<double> t = arrange(0, time, sys.Ts());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce( i == 0 ? 1.0/sys.Ts() : 0.0);
    }

    return {t, res};
}

static std::tuple<std::vector<double>, std::vector<double>> step(const std::function<double(double)> &sys, double dt, double time, const double gain = 1.0)
{
    std::vector<double> t = arrange(0, time, dt);
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys(gain);
    }

    return {t, res};
}

static std::tuple<std::vector<double>, std::vector<double>> step(TransferFunction &sys, double time, const double gain = 1.0)
{
    return step([&](double u){ return sys.responce(u); }, sys.Ts(), time, gain);
}

static std::tuple<std::vector<double>, std::vector<double>> step(DiscreteTransferFunction &sys, double time, const double gain = 1.0)
{
    return step([&](double u){ return sys.responce(u); }, sys.Ts(), time, gain);
}

static std::tuple<std::vector<double>, std::vector<double>> lsim(TransferFunction &sys, std::vector<double> input)
{
    std::vector<double> t = linspace(0, sys.Ts()*input.size(), input.size());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce(input[i]);
    }

    return {t, res};
}

}
```


-------------------------------

Updated on 2022-09-28 at 23:12:44 +0900

---
title: include/cpp_robotics/filter/velocity_limit_filter.hpp

---

# include/cpp_robotics/filter/velocity_limit_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::VelocityLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <optional>
#include <tuple>
#include <algorithm>
#include "integrator.hpp"

namespace cpp_robotics
{

namespace internal
{

// diff = s / (gpd*s + 1)
// pass = 1 / (gpd*s + 1)
class DiffPair
{
public:
    DiffPair(double Ts_, double gpd_): Ts(Ts_), gpd(gpd_) {}

    void reset()
    {
        reset(0.0f);
    }

    void reset(double u)
    {
        u1 = u;
        y1diff = 0;
        y1pass = 0;
    }
        
    std::tuple<double, double> filtering(double u)
    {
        double diff = ( 2.0*gpd*(u-u1) + (2.0-Ts*gpd)*y1diff )/(2.0+Ts*gpd);
        double pass = ( gpd*Ts*(u+u1) + (2.0-gpd*Ts)*y1pass )/(2.0+Ts*gpd);
        
        u1 = u;
        y1diff = diff;
        y1pass = pass;

        return {diff, pass};
    }

private:    
    double Ts, gpd;
    double u1 = 0, y1diff = 0, y1pass = 0;
};

}

// 速度制限フィルタ
// 熊本大学の岡島研究室の文献を参考にした
class VelocityLimitFilter
{
public:
    VelocityLimitFilter(double v_max_, double Ts_):
        VelocityLimitFilter(v_max_, Ts_, 1.0/Ts_, 0.5/Ts_){}

    VelocityLimitFilter(double v_max_, double Ts_, std::pair<double, double> limit):
        VelocityLimitFilter(v_max_, Ts_, 1.0/Ts_, 0.5/Ts_, limit){}
    
    VelocityLimitFilter(double v_max_, double Ts_, double gpd_, double fb_gain, std::optional<std::pair<double, double>> limit = std::nullopt): 
        Ts(Ts_), v_max(v_max_), gpd(gpd_), Cfb(fb_gain), dp(Ts, gpd), intr(Ts), limit_(limit)
    {
        reset();
    }

    virtual void reset() 
    {
        reset(0);
    }
    void reset(double u)
    {
        u1 = u;
        y1 = u;
        dp.reset(u);
        intr.reset(u);
    }

    virtual double filtering(double u) 
    {
        if(limit_)
        {
            u = std::clamp(u, limit_.value().first, limit_.value().second);
        }
        auto[diff, pass] = dp.filtering(u);
        double v = diff - (Cfb*(y1-pass));
        v = std::clamp(v, -v_max, v_max);
        prev_v_ = v;
        double y = intr.filtering(v);
        if(limit_)
        {
            y = std::clamp(y, limit_.value().first, limit_.value().second);
        }
        
        u1 = u;
        y1 = y;
        return y;
    }

    double prev_v_;

private:
    double Ts, v_max, gpd, Cfb;
    internal::DiffPair dp;
    Integrator intr;
    double u1 = 0, y1 = 0;

    std::optional<std::pair<double, double>> limit_;
};

}
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900

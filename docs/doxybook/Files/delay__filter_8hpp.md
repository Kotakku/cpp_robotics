---
title: include/cpp_robotics/filter/delay_filter.hpp

---

# include/cpp_robotics/filter/delay_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::DelayFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DelayFilter/)** <br>遅延フィルタ  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <vector>

namespace cpp_robotics
{

class DelayFilter
{
public:
    DelayFilter(double delay_time, double Ts)
    {
        delay_sample_cnt_ = std::floor(delay_time/Ts);
        delay_table_.resize(delay_sample_cnt_);
    }

    virtual void reset()
    {
        for(auto &val : delay_table_)
        {
            val = 0;
        }
    }

    virtual double filtering(double u)
    {
        if(delay_table_.size() == 0)
            return u;
        
        for(int i = delay_table_.size() - 2; i >= 0; i--)
        {
            delay_table_[i+1] = delay_table_[i];
        }
        delay_table_[0] = u;
        return delay_table_.back();
    }

private:
    size_t delay_sample_cnt_;
    std::vector<double> delay_table_;
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

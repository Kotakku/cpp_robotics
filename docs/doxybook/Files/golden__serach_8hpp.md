---
title: include/cpp_robotics/optimize/golden_serach.hpp

---

# include/cpp_robotics/optimize/golden_serach.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <functional>
#include <cmath>

namespace cpp_robotics 
{

// 黄金探索
static double golden_search(std::function<double(double)> f, double low, double high, const double tol = 1e-6, const size_t max_iter = 100)
{
    constexpr double r = (-1.0 + std::sqrt(5)) / 2.0;
    double a1 = low + (1.0 - r) * (high - low);
    double a2 = low + (r) * (high - low);
    double f1 = f(a1);
    double f2 = f(a2);
    
    for(size_t i = 0; i < max_iter; i++)
    {
        if(std::abs(high - low) < tol)
            return 0.5 * (low + high);

        if(f1 < f2)
        {
            high = a2;
            a2 = a1;
            a1 = low + (1.0 - r) * (high - low);
            f2 = f1;
            f1 = f(a1);
        }
        else
        {
            low = a1;
            a1 = a2;
            a2 = low + (r) * (high - low);
            f1 = f2;
            f2 = f(a2);
        }
    }
    return 0.5 * (low + high);
}

}
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900
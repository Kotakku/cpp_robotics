---
title: include/cpp_robotics/filter/butterworth_filter.hpp

---

# include/cpp_robotics/filter/butterworth_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::ButterworthFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/)** <br>バターワースフィルタ  |




## Source code

```cpp
#pragma once

#include <cpp_robotics/system/transfer_function.hpp>
#include "cpp_robotics/system/polynomial.hpp"

namespace cpp_robotics
{

class ButterworthFilter : public TransferFunction
{
public:
    ButterworthFilter(double omega, size_t n, double dt):
        omega_(omega), n_(n)
    {
        Polynomial den_poly({1});
        if(n % 2)
        {
            den_poly *= Polynomial{1/omega_, 1};
            // nが奇数
            for(size_t k = 1; k <= (n-1)/2; k++)
            {
                int num = 2*k + n - 1;
                int den = 2*n;
                const double k1 = -2.0*std::cos((double)(num) / (double)(den) * M_PI);
                den_poly *= Polynomial{1/omega_/omega_, k1/omega, 1};
            }
        }
        else
        {
            // nが偶数
            for(size_t k = 1; k <= n/2; k++)
            {
                int num = 2*k + n - 1;
                int den = 2*n;
                const double k1 = -2.0*std::cos((double)(num) / (double)(den) * M_PI);
                den_poly *= Polynomial{1/omega_/omega_, k1/omega, 1};
            }
        }

        std::cout << den_poly << std::endl;
        TransferFunction::set_continuous({1}, den_poly.coeff(), dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }

    size_t n() const { return n_; }

private:
    const double omega_;
    const size_t n_;
};

}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900

---
title: include/cpp_robotics/filter/notch_filter.hpp

---

# include/cpp_robotics/filter/notch_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/)** <br>ノッチフィルタ  |




## Source code

```cpp
#pragma once

#include "cpp_robotics/system/discrete_transfer_function.hpp"

namespace cpp_robotics
{

//         s^2 + d*2*zeta*omega + omega^2
// G(s) = -------------------------------- を双一次変換
//          s^2 + 2*zeta*omega + omega^2
class NotchFilter
{
public:
    NotchFilter(double w, double zeta, double d, double dt):
        w_(w), zeta_(zeta), d_(d), dt_(dt)
    {
        const double ww = w*w;
        const double dtdt = dt*dt;

        tf_.set_discrite(
            {(4+d*(4*dt*zeta*w)+dtdt*ww), (-8+2*dtdt*ww), (4-d*(4*dt*zeta*w)+dtdt*ww)},
            {(4+  (4*dt*zeta*w)+dtdt*ww), (-8+2*dtdt*ww), (4-  (4*dt*zeta*w)+dtdt*ww)},
            dt
        );
    }

    void reset()
    {
        tf_.reset();
    }
    
    double filtering(double u)
    {
        return tf_.responce(u);
    }

    double w() const { return w_; }
    double zeta() const { return zeta_; }
    double d() const { return d_; }
    double dt() const {return dt_; }
private:
    const double w_;
    const double zeta_;
    const double d_;
    const double dt_;
    DiscreteTransferFunction tf_;
};

}
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900

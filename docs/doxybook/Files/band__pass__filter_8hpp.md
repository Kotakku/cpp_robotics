---
title: include/cpp_robotics/filter/band_pass_filter.hpp

---

# include/cpp_robotics/filter/band_pass_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/)** <br>バンドパスフィルタ  |




## Source code

```cpp
#pragma once

namespace cpp_robotics
{

//               2*zeta*omega
// G(s) = ------------------------------ を双一次変換
//         s^2 + 2*zeta*omega + omega^2
class BandPassFilter
{
public:
    BandPassFilter(double w, double zeta, double dt):
        w_(w), zeta_(zeta), dt_(dt)
    {
        const double ww = w*w;
        const double dtdt = dt*dt;

        tf_.set_discrite(
            {     (4*dt*zeta*w),                0,            (-4*dt*zeta*w)},
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
    double dt() const {return dt_; }
private:
    const double w_;
    const double zeta_;
    const double dt_;
    DiscreteTransferFunction tf_;
};

}
```


-------------------------------

Updated on 2022-09-28 at 23:12:44 +0900

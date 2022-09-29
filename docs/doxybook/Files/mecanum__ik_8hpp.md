---
title: include/cpp_robotics/chassis/mecanum_ik.hpp

---

# include/cpp_robotics/chassis/mecanum_ik.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::MecanumIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/)** <br>メカナムの逆運動学モデル  |
| struct | **[cpp_robotics::MecanumIk::Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1MecanumIk_1_1Config/)**  |




## Source code

```cpp
#pragma once

#include <array>
#include <Eigen/Dense>
#include "cpp_robotics/vector/transform.hpp"

namespace cpp_robotics
{

class MecanumIk
{
public:
    struct Config
    {
        double width;
        double length;
    };
    
    MecanumIk(double width, double length):
        MecanumIk(Config{width, length}) {}
    
    MecanumIk(Config config):
        config_(config)
    {
        const double norm = (config_.width + config_.length)/2.0;
        conv_mat_ << 
            -1,  1, norm,
            -1, -1, norm,
             1, -1, norm,
             1,  1, norm;
    }

    std::array<double, 4> calculate(Transformd velocity)
    {
        std::array<double, 4> wv;
        Eigen::Map<Eigen::Vector4d> wv_vec(wv.data());
        Eigen::Vector3d v(velocity.x, velocity.y, velocity.theta);
        wv_vec = conv_mat_ * v;
        return wv;
    }

    Config config() const { return config_; }

private:
    Config config_;
    Eigen::Matrix<double, 4, 3> conv_mat_;
};
}
```


-------------------------------

Updated on 2022-09-30 at 00:12:50 +0900

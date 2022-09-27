---
title: include/cpp_robotics/chassis/omni_ik.hpp

---

# include/cpp_robotics/chassis/omni_ik.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::Omni3Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/)** <br>3輪オムニの逆運動学モデル  |
| struct | **[cpp_robotics::Omni3Ik::Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni3Ik_1_1Config/)**  |
| class | **[cpp_robotics::Omni4Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/)** <br>4輪オムニの逆運動学モデル  |
| struct | **[cpp_robotics::Omni4Ik::Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni4Ik_1_1Config/)**  |




## Source code

```cpp
#pragma once

#include <array>
#include <Eigen/Dense>
#include "cpp_robotics/vector/transform.hpp"

namespace cpp_robotics
{

class Omni3Ik
{
public:
    struct Config
    {
        double radius;
        double first_wheel_angle = M_PI/6;
    };
    
    Omni3Ik(double radius, double first_wheel_angle = M_PI/6):
        Omni3Ik(Config{radius, first_wheel_angle}) {}
    
    Omni3Ik(Config config):
        config_(config)
    {
        for(size_t i = 0; i < 3; i++)
        {
            const double wheel_angle = config_.first_wheel_angle + (i* 2*M_PI/3);
            conv_mat_(i, 0) = -std::sin(wheel_angle);
            conv_mat_(i, 1) =  std::cos(wheel_angle);
            conv_mat_(i, 2) = config_.radius;
            
        }
    }

    std::array<double, 3> calculate(Transformd velocity)
    {
        std::array<double, 3> wv;
        Eigen::Map<Eigen::Vector3d> wv_vec(wv.data());
        Eigen::Vector3d v(velocity.x, velocity.y, velocity.theta);
        wv_vec = conv_mat_ * v;
        return wv;
    }

    Config config() const { return config_; }

private:
    Config config_;
    Eigen::Matrix<double, 3, 3> conv_mat_;
};

class Omni4Ik
{
public:
    struct Config
    {
        double radius;
        double first_wheel_angle = M_PI/4;
    };
    
    Omni4Ik(double radius, double first_wheel_angle = M_PI/4):
        Omni4Ik(Config{radius, first_wheel_angle}) {}
    
    Omni4Ik(Config config):
        config_(config)
    {
        for(size_t i = 0; i < 4; i++)
        {
            const double wheel_angle = config_.first_wheel_angle + (i* M_PI/2);
            conv_mat_(i, 0) = -std::sin(wheel_angle);
            conv_mat_(i, 1) =  std::cos(wheel_angle);
            conv_mat_(i, 2) = config_.radius;
            
        }
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

Updated on 2022-09-28 at 01:12:56 +0900

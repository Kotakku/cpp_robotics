---
title: include/cpp_robotics/path_planning/minimum_jerk_model.hpp

---

# include/cpp_robotics/path_planning/minimum_jerk_model.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

namespace cpp_robotics
{

static double normalized_mjm_position(double t)
{
    double t3 = t * t * t;
    return ( ((6.0*t - 15.0)*t + 10.0)*t3 );
}

static double normalized_mjm_velocity(double t)
{
    double t2 = t * t;
    return ( ((30.0*t - 60.0)*t + 30.0)*t2 );
}

static double normalized_mjm_acceleration(double t)
{
    return ( ((120.0*t - 180.0)*t + 60.0)*t );
}

static double normalized_mjm_jerk(double t)
{
    return (360.0*t - 360.0)*t + 60.0;
}

}
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900

---
title: include/cpp_robotics/algorithm/mahalanobis.hpp

---

# include/cpp_robotics/algorithm/mahalanobis.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <Eigen/Dense>

namespace cpp_robotics
{

double mahalanobis(const Eigen::VectorXd &a, const Eigen::VectorXd &b, const Eigen::MatrixXd cov_inv)
{
    auto diff = a-b;
    return std::sqrt( diff.dot( cov_inv*diff ) );
}

}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

---
title: include/cpp_robotics/optimize/bfgs.hpp

---

# include/cpp_robotics/optimize/bfgs.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

static void bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y)
{
    double sy, sBs;
    Eigen::VectorXd Bs;

    Bs.noalias() = hess * s;
    sBs = s.dot(Bs);
    sy = s.dot(y);

    hess += -( Bs * Bs.transpose() )/sBs + ( y*y.transpose() )/( sy );
}

static void powells_modified_bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y, double gamma = 0.2)
{
    // y_tilde
    if(s.transpose()*y < gamma * s.transpose()*hess*s)
    {
        double sy, sBs;
        Eigen::VectorXd Bs;

        Bs.noalias() = hess * s;
        sBs = s.dot(Bs);
        sy = s.dot(y);

        double beta = (1-gamma)*sBs / ( sBs - sy );
        y = beta*y + (1-beta)*hess*s;
    }
    
    bfgs_step(hess, s, y);
}

}
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900

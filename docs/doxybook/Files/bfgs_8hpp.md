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

// BFGS公式
// hess: B行列
// s   : x_k+1 - x_k
// y   : \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k)
static void bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y)
{
    double sy, sBs;
    Eigen::VectorXd Bs;

    Bs.noalias() = hess * s;
    sBs = s.dot(Bs);
    sy = s.dot(y);

    hess += -( Bs * Bs.transpose() )/sBs + ( y*y.transpose() )/( sy );
}

// パウエルの修正BFGS公式
// hess  : B行列
// s     : x_k+1 - x_k
// y     : \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k)
// gamma : 
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

Updated on 2022-09-27 at 01:12:56 +0900

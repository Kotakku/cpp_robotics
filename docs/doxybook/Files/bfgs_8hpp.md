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

static void powells_modified_bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y, Eigen::VectorXd dgg, double gamma = 0.2)
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

    // 0 < syになるまでyを修正
    const double lnrm = 1e-12;
    double w = 1e-6;
    int i = 0;
    if(s.dot(y) < lnrm)
    {
        Eigen::VectorXd v(y.size());
        while(s.dot(y) < lnrm)
        {
            for(int i = 0; i < y.size(); i++)
            {
                if(y(i)*w < lnrm && y(i)*s(i) < lnrm)
                    v(i) = dgg(i);
                else
                    v(i) = 0;
            }
            y += w*v;
            w*= 1.1;

            if(1000 < ++i)
            {
                break;
            }
        }
    }

    bfgs_step(hess, s, y);
}

static void powells_modified_bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y, double gamma = 0.2)
{
    powells_modified_bfgs_step(hess, s, y, Eigen::VectorXd::Zero(y.size()), gamma);
}

}
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900

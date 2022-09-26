---
title: include/cpp_robotics/optimize/constraint.hpp

---

# include/cpp_robotics/optimize/constraint.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/)**  |
| class | **[cpp_robotics::ConstraintArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <functional>
#include <vector>
#include <optional>
#include <numeric>
#include <Eigen/Dense>
#include "derivative.hpp"

namespace cpp_robotics
{

struct Constraint
{
    using func_type = std::function<double(Eigen::VectorXd)>;
    using grad_func_type = std::function<Eigen::VectorXd(Eigen::VectorXd)>;
    using hessian_func_type = std::function<Eigen::MatrixXd(Eigen::VectorXd)>;
    
    enum Type : uint8_t
    {
        // g(x) = 0
        Eq,

        // g(x) <= 0
        Ineq
    };
    
    Type type;
    func_type con_f;
    std::optional<grad_func_type> con_grad_f;
    std::optional<hessian_func_type> con_hessian_f;

    Constraint(Type type_, func_type con_):
        type(type_), con_f(con_) {}

    double eval(const Eigen::VectorXd &x) const
    {
        return con_f(x);
    }

    bool satisfy(const Eigen::VectorXd &x, const double tol) const
    {
        const double val = eval(x);
        std::cout << "eval: " << val << std::endl;
        if(type == Type::Eq)
        {
            return std::abs(val) < tol;
        }
        else
        {
            return val < tol;
        }
    }

    Eigen::VectorXd grad(Eigen::VectorXd x)
    {
        if(con_grad_f)
            return con_grad_f.value()(x);
        
        return derivative(con_f, x);
    }

    Eigen::MatrixXd hessian(Eigen::VectorXd x)
    {
        if(con_hessian_f)
            return con_hessian_f.value()(x);
        
        return approx_hessian(con_f, x);
    }
};

class ConstraintArray : public std::vector<Constraint>
{
public:
    // std::vector<Constraint>::size_type size() const
    // {
    //     return this->size();
    // }

    std::vector<double> eval(const Eigen::VectorXd &x) const
    {
        std::vector<double> val(this->size());
        for(size_t i = 0; i < this->size(); i++)
        {
            
            val[i] = this->at(i).eval(x);
        }
        return val;
    }

    double eval_sum(const Eigen::VectorXd &x) const
    {
        auto val = eval(x);
        return std::accumulate(val.begin(), val.end(), 0.0);
    }

    bool all_satisfy(const Eigen::VectorXd &x, const double tol) const
    {
        bool satisfy = true;

        for(auto & con : *this)
        {
            if(not con.satisfy(x, tol))
            {
                std::cout << "not satisfy" << std::endl;
                satisfy = false;
            }
            else
            {
                std::cout << "satisfy" << std::endl;
                
            }
        }
        return satisfy;
    }

    std::vector<Constraint>::size_type eq_constraint_size() const
    {
        std::vector<Constraint>::size_type num = 0;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Eq)
                num++;
        }
        return num;
    }

    std::vector<Constraint>::size_type ineq_constraint_size() const
    {
        std::vector<Constraint>::size_type num = 0;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Ineq)
                num++;
        }
        return num;
    }

    std::vector<Constraint> gen_eq_constraint_list() const
    {
        std::vector<Constraint> ret;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Eq)
                ret.push_back(con);
        }
        return ret;
    }

    std::vector<Constraint> gen_ineq_constraint_list() const
    {
        std::vector<Constraint> ret;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Ineq)
                ret.push_back(con);
        }
        return ret;
    }
};

}
```


-------------------------------

Updated on 2022-09-26 at 11:58:18 +0900

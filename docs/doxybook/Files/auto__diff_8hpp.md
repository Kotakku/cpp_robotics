---
title: include/cpp_robotics/algorithm/auto_diff.hpp

---

# include/cpp_robotics/algorithm/auto_diff.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::AutoDiffAdaptor](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/)** <br>自動微分でヤコビアンを求めるクラス  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
#include <functional>
#include <optional>

namespace cpp_robotics
{

template<class DerType>
using AutoDiffScalar = Eigen::AutoDiffScalar<DerType>;

template<class DerType, int NX=Eigen::Dynamic>
using AutoDiffVector = Eigen::Matrix<AutoDiffScalar<DerType>, NX, 1>;

template<class DerType>
static auto make_auto_diff_vector(const size_t &dim, const std::optional<DerType> &x = std::nullopt)
{
    AutoDiffVector<DerType> ax(dim);
    for(size_t i = 0; i < dim; i++)
    {
        if(x.has_value())
            ax(i).value() = x.value()(i);
        else
            ax(i).value() = 0;
        ax(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
    }
    return ax;
}

template<class Functor, class DerType = Eigen::VectorXd, typename Scalar = double, int NX=Eigen::Dynamic, int NY=Eigen::Dynamic>
class AutoDiffAdaptor
{
public:
    using InputVector = Eigen::Matrix<Scalar, NX, 1>;
    using ValueVector = Eigen::Matrix<Scalar, NY, 1>;
    using JacobianMatrix = Eigen::Matrix<Scalar, NY, NX>;
    using HessianMatrix = Eigen::Matrix<Scalar, NX, NX>;
    enum {
        InputsAtCompileTime = NX,
        ValuesAtCompileTime = NY
    };

    AutoDiffAdaptor(Functor &functor): 
        functor_(functor), input_size_(NX), value_size_(NY) {}

    AutoDiffAdaptor(Functor &functor, const size_t input_size, const size_t value_size):
        functor_(functor), input_size_(input_size), value_size_(value_size) {}

    void evalute(const InputVector &x, ValueVector &y)
    {
        return functor_.eval_func(x, y);
    }

    ValueVector evalute(const InputVector &x)
    {
        ValueVector y;
        if constexpr(ValueVector::SizeAtCompileTime == Eigen::Dynamic)
            y.resize(value_size_);
        evalute(x, y);
        return y;
    }

    std::function<ValueVector(InputVector)> evalute_func()
    {
        return [this](InputVector x) { return evalute(x); };
    }

    std::function<double(InputVector)> evalute_func_scalar()
    {
        assert(value_size_ == 1);
        return [this](InputVector x) { return evalute(x)(0); };
    }

    void jacobian(const InputVector &x, JacobianMatrix &jac)
    {
        using ADScalar = AutoDiffScalar<DerType>;
        using ADInput = AutoDiffVector<DerType, NX>;
        using ADValue = AutoDiffVector<DerType, NY>;
        
        ADInput ax = x.template cast<ADScalar>();
        ADValue ay(jac.rows());

        if constexpr(InputsAtCompileTime==Eigen::Dynamic)
        for (Eigen::Index j=0; j<jac.rows(); j++)
            ay[j].derivatives().resize(x.rows());

        for (Eigen::Index i=0; i<jac.cols(); i++)
            ax[i].derivatives() = DerType::Unit(x.rows(),i);

        functor_.eval_func(ax, ay);

        for (Eigen::Index i=0; i<jac.rows(); i++)
        {
            jac.row(i) = ay[i].derivatives();
        }
    }

    JacobianMatrix jacobian(const InputVector &x)
    {
        JacobianMatrix jac;
        if constexpr(JacobianMatrix::SizeAtCompileTime == Eigen::Dynamic)
            jac.resize(value_size_, input_size_);
        
        jacobian(x, jac);
        return jac;
    }

    std::function<JacobianMatrix(InputVector)> jacobian_func()
    {
        return [this](InputVector x) { return jacobian(x); };
    }

    std::function<Eigen::Matrix<Scalar, NX, 1>(InputVector)> jacobian_func_row_vector()
    {
        assert(value_size_ == 1);
        return [this](InputVector x) { return jacobian(x).transpose().col(0).eval(); };
    }

    // void hessian(const EigenVectorType &x, HessianMatrix &hess)
    // {
    //     assert(value_size_ == 1);
    // }
    
    // HessianMatrix hessian(const InputVector &x)
    // {
    //     HessianMatrix hess;
    //     if constexpr(HessianMatrix::SizeAtCompileTime == Eigen::Dynamic)
    //         hess.resize(input_size_, input_size_);
    //     hessian(x, hess);
    //     return hess;
    // }

private:
    Functor &functor_;
    const size_t input_size_;
    const size_t value_size_;
};

}
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900

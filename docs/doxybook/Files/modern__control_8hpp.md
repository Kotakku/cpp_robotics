---
title: include/cpp_robotics/controller/modern_control.hpp

---

# include/cpp_robotics/controller/modern_control.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <array>
#include <Eigen/Dense>
#include "../system/state_space_system.hpp"
#include "../system/polynomial.hpp"

namespace cpp_robotics
{
    // 可制御性行列
    static Eigen::MatrixXd controllability_matrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& B)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == B.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uc(dim, dim);
        Eigen::VectorXd colv = B;

        for(int i = 0; i < dim; i++)
        {
            Uc.col(i) = colv;
            colv = A * colv;
        }

        return Uc;
    }

    // 可制御性の判別
    static bool is_controllable(const Eigen::MatrixXd& A, const Eigen::VectorXd& B)
    {
        const int dim = A.rows();
        Eigen::FullPivLU<Eigen::MatrixXd> lu(controllability_matrix(A, B));
        return (lu.rank() == dim);
    }
    
    static bool is_controllable(const StateSpaceSystem& sys)
    {
        return is_controllable(sys.A().value(), sys.B().value());
    }


    // 可観測性行列
    static Eigen::MatrixXd observability_matrix(const Eigen::MatrixXd& A, const Eigen::RowVectorXd& C)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == C.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uo(dim, dim);
        Eigen::RowVectorXd colv = C;

        for(int i = 0; i < dim; i++)
        {
            Uo.row(i) = colv;
            colv = colv * A;
        }

        return Uo;
    }

    // 可観測性の判別
    static bool is_observable(const Eigen::MatrixXd& A, const Eigen::RowVectorXd& C)
    {
        const int dim = A.rows();
        Eigen::FullPivLU<Eigen::MatrixXd> lu(observability_matrix(A, C));
        return (lu.rank() == dim);
    }

    static bool is_observable(const StateSpaceSystem& sys)
    {
        return is_observable(sys.A().value(), sys.C());
    }

    enum class CanonicalizeMode
    {
        // MODEL,
        COMPANION,
        OBSERBAVLE,
        CONTROLLABLE
    };

    // 同値変換による可制御正準形への変換
    // https://www.mathworks.com/help/control/ug/canonical-state-space-realizations.html
    static std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> canonicalize_system(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& C, const Eigen::MatrixXd& D, CanonicalizeMode mode = CanonicalizeMode::COMPANION)
    {
        // if(mode == MODEL)
        // else
        if(mode == CanonicalizeMode::CONTROLLABLE || mode == CanonicalizeMode::COMPANION || mode == CanonicalizeMode::OBSERBAVLE)
        {
            
            Eigen::MatrixXd Uc = controllability_matrix(A, B);
            Eigen::MatrixXd Ucinv = Uc.inverse();

            if(mode == CanonicalizeMode::CONTROLLABLE)
            {
                auto [A_tilda, B_tilda, C_tilda, D_tilda] = canonicalize_system(A, B, C, D, CanonicalizeMode::COMPANION);
                return {
                    A_tilda.transpose(),
                    C_tilda.transpose(),
                    B_tilda.transpose(),
                    D_tilda
                };
            }
            else
            {
                return {
                    Ucinv*A*Uc,
                    Ucinv*B,
                    C*Uc,
                    D
                };
            }
        }

        return canonicalize_system(A, B, C, D, CanonicalizeMode::COMPANION);
    }

    static std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> canonicalize_system(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& C, CanonicalizeMode mode = CanonicalizeMode::COMPANION)
    {
        const size_t input_size = B.cols();
        const size_t output_size = C.rows();

        return canonicalize_system(A, B, C, Eigen::MatrixXd::Zero(output_size, input_size), mode);
    }

    static std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> canonicalize_system(const StateSpaceSystem& sys, CanonicalizeMode mode = CanonicalizeMode::COMPANION)
    {
        return canonicalize_system(sys.A().value(), sys.B().value(), sys.C(), sys.D(), mode);
    }

    // SISOモデルに対してのアッカーマン法
    // https://ossyaritoori.hatenablog.com/entry/2018/05/16/%E6%A5%B5%E9%85%8D%E7%BD%AE%E3%81%AE%E5%AE%9F%E8%A3%85%EF%BC%9A%E3%82%A2%E3%83%83%E3%82%AB%E3%83%BC%E3%83%9E%E3%83%B3%E6%B3%95%E3%81%AEMATLAB%E5%AE%9F%E8%A3%85#Outline
    static Eigen::VectorXd place(const StateSpaceSystem& sys, std::vector<double> poles)
    {
        assert(sys.state_size() == poles.size());
        assert(sys.is_siso_model());

        auto pole_poly = Polynomial::expand(poles);

        auto Uc = controllability_matrix(sys.A().value(), sys.B().value());

        Eigen::MatrixXd tmp = Eigen::MatrixXd::Zero(sys.state_size(), sys.state_size());
        Eigen::MatrixXd An = Eigen::MatrixXd::Identity(sys.state_size(), sys.state_size());

        for(size_t i = 0; i < sys.state_size(); i++)
        {
            tmp += pole_poly.at_degree(i)*An;
            An *= sys.A().value();
        }
        tmp += An;

        return (Uc.inverse() * tmp).row(sys.state_size()-1);
    }

    // 可制御正準形の\tilda{A}の係数比較により極配置を行う
    // https://www.youtube.com/watch?v=yiFgI6Oos88
//     static Eigen::VectorXd place(const StateSpaceSystem& sys, std::vector<double> poles)
//     {

//     }
}
```


-------------------------------

Updated on 2022-09-25 at 23:50:01 +0900

---
title: include/cpp_robotics/system/discret.hpp

---

# include/cpp_robotics/system/discret.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::Discret](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Discret/)** <br>状態空間モデルを双一次変換で離散化する  |
| class | **[cpp_robotics::DiscretTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscretTransferFunction/)**  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>
#include <tuple>
#include "./polynomial.hpp"

namespace cpp_robotics
{

class Discret
{
private:
    template<typename Derived>
    static auto expm(const Eigen::MatrixBase<Derived> &A)
    {
        assert(A.cols() == A.rows());
        return A.exp();
    }

    template<typename Derived>
    static auto integral_expm(const Eigen::MatrixBase<Derived> &A, const float &Ts, size_t hdiv = 1000)
    {
        assert(A.cols() == A.rows());

        // シンプソン法で積分
        const double h = Ts / (double)(hdiv);
        Derived S = expm(A*0) + expm(A*Ts);
        
        for(size_t i = 1; i < hdiv; i += 2)
        {
            S += 4 * expm(A*h*i);
        }

        for(size_t i = 2; i < hdiv; i += 2)
        {
            S += 2 * expm(A*h*i);
        }
        S *= h/3;
        return S;
    }

public:
    template<typename Derived>
    static auto discretize_a(const Eigen::MatrixBase<Derived> &A, const float Ts)
    {
        assert(A.cols() == A.rows());
        return static_cast<Derived>((A*Ts).exp());
    }

    template<typename Derived1, typename Derived2>
    static auto discretize_b(const Eigen::MatrixBase<Derived1> &A, const Eigen::MatrixBase<Derived2> &B, const float &Ts, size_t hdiv = 1000)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == B.rows());

        Eigen::FullPivLU<Derived1> lu_decomp(A);
        auto rank = lu_decomp.rank();

        if(rank == A.rows())
        {
            if constexpr (Derived1::SizeAtCompileTime==Eigen::Dynamic)
            {
                Derived1 I = Derived1::Identity(A.rows(), A.cols());
                return static_cast<Derived2>(A.inverse() * (expm(A*Ts) - I) * B);
            }
            else
            {
                return static_cast<Derived2>(A.inverse() * (expm(A*Ts) - Derived1::Identity()) * B);
            }
        }

        return static_cast<Derived2>(integral_expm(A, Ts, hdiv)*B);
    }

    template<typename Derived1, typename Derived2>
    static auto discritize(const Eigen::MatrixBase<Derived1> &A, const Eigen::MatrixBase<Derived2> &B, const float &Ts, size_t hdiv = 1000)
    {
        return std::tuple{
            discretize_a(A, Ts),
            discretize_b(A, B, Ts, hdiv)
        };
    }
};

class DiscretTransferFunction
{
private:

public:
    static std::tuple<std::vector<double>, std::vector<double>> discritize(const std::vector<double> &num, const std::vector<double> &den, const double Ts)
    {
        assert(num.size() < den.size()); // 厳密にプロパー

        size_t dim = den.size();
        Polynomial num_poly, den_poly;
        auto z_poly = [&](size_t num_size, size_t den_size)
        {
            std::vector<double> roots(num_size+den_size, -1);
            for(size_t i = 0; i < num_size; i++)
            {
                roots[i] = +1;
            }

            // std::cout << num_size << ", " << den_size << " -> ";
            // for(auto &c : roots)
            //     std::cout << c << ", ";
            // std::cout << std::endl;

            return std::pow(2.0, num_size)*std::pow(Ts, den_size) * Polynomial::expand(roots);
        };

        for(size_t i = 0; i < den.size(); i++)
        {
            den_poly += den[i] * z_poly(den.size()-1-i, i);
        }

        for(size_t i = 0; i < num.size(); i++)
        {
            num_poly += num[i] * z_poly(num.size()-1-i, i+(den.size()-num.size()));
        }

        return {num_poly.coeff(), den_poly.coeff()};
    }
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

#pragma once

#include <cpp_robotics/system/transfer_function.hpp>
#include "cpp_robotics/system/polynomial.hpp"

namespace cpp_robotics
{

/// バターワースフィルタ
class ButterworthFilter : public TransferFunction
{
public:
    /**
     * @brief Construct a new Butterworth Filter object
     * 
     * @param omega 折れ点周波数[rad/s]
     * @param n フィルタの次数
     * @param dt サンプリング周期
     */
    ButterworthFilter(double omega, size_t n, double dt):
        omega_(omega), n_(n)
    {
        Polynomial den_poly({1});
        if(n % 2)
        {
            den_poly *= Polynomial{1/omega_, 1};
            // nが奇数
            for(size_t k = 1; k <= (n-1)/2; k++)
            {
                int num = 2*k + n - 1;
                int den = 2*n;
                const double k1 = -2.0*std::cos((double)(num) / (double)(den) * M_PI);
                den_poly *= Polynomial{1/omega_/omega_, k1/omega, 1};
            }
        }
        else
        {
            // nが偶数
            for(size_t k = 1; k <= n/2; k++)
            {
                int num = 2*k + n - 1;
                int den = 2*n;
                const double k1 = -2.0*std::cos((double)(num) / (double)(den) * M_PI);
                den_poly *= Polynomial{1/omega_/omega_, k1/omega, 1};
            }
        }

        std::cout << den_poly << std::endl;
        TransferFunction::set_continuous({1}, den_poly.coeff(), dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 

    /**
     * @brief 時定数の取得
     * 
     * @return double 
     */
    double omega() const { return omega_; }

    /**
     * @brief フィルタの次数
     * 
     * @return size_t 
     */
    size_t n() const { return n_; }

private:
    const double omega_;
    const size_t n_;
};

}
#pragma once

#include <cmath>
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

/**
 * @brief 疑似微分器
 * 
 */
/// G(s) = omega*s / (s + omega)
/// 双一次変換で離散化したもの
class Differentiator : public TransferFunction
{
public:
    /**
     * @brief Construct a new Differentiator object
     * 
     * @param omega 折れ点周波数[rad/s]
     * @param dt サンプリング周期
     */
	Differentiator(double omega, double dt): 
        omega_(omega)
    {
        TransferFunction::set_continuous({omega_, 0}, {1, omega_}, dt);
    }

    virtual void reset(double state = 0) override
    {
        for(auto &u : u_)
            u = 0;
        for(auto &y : y_)
            y = state;
        u_.reset_position();
        y_.reset_position();
        reset_request = true;
    }

    void reset_test(double state = 0, double input = 0)
    {
        for(auto &u : u_)
            u = input;
        for(auto &y : y_)
            y = state;
        u_.reset_position();
        y_.reset_position();
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) 
    {
        if(reset_request)
        {
            reset_test(0, u);
            reset_request = false;
        }
        return responce(u);
    } 

    /**
     * @brief 時定数の取得
     * 
     * @return double 
     */
    double omega() const { return omega_; }
private:
    const double omega_;
    bool reset_request = true;
};

}
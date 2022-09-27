#pragma once

#include <cmath>
#include <functional>
#include <Eigen/Dense>

namespace cpp_robotics
{

/**
 * @brief アルミホ条件を満たすステップ幅を求める囲い込み法
 * 
 * @param func 
 * @param grad 
 * @param x 
 * @param d 
 * @param gamma 
 * @param tau 
 * @param max_iter 
 * @return double 
 */
static double bracketing_serach(std::function<double(Eigen::VectorXd)> func, std::function<Eigen::VectorXd(Eigen::VectorXd)> grad, const Eigen::VectorXd &x, const Eigen::VectorXd &d, double gamma = 0.3, double tau = 0.9, const size_t max_iter = 1000)
{
    auto line_func = [&](double v){ return func(x + v*d); };

    double a = 1;
    double b = grad(x).dot(d);
    double lf0 = line_func(0);
    for(size_t i = 0; i < max_iter; i++){
        if(line_func(a) <= lf0 + gamma * a * b){
            return a;
        }
        a = tau * a;
    }
    return a;
}

/**
 * @brief 囲い込み法
 * 
 * @param func 
 * @param init 
 * @param beta 
 * @param max_iter 
 * @return double 
 */
static double bracketing_serach(std::function<double(double)> func, const double init = 1.0, const double beta = 0.9, const size_t max_iter = 1000)
{
    double a = init;
    double fval = func(a);
    double new_fval;

    for(size_t i = 0; i < max_iter; i++)
    {
        new_fval = func(a*beta);

        if(new_fval > fval)
            return a;
        a *= beta;
        fval = new_fval;
    }

    return a;
}

}
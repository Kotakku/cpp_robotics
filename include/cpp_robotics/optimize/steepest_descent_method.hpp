#pragma once

#include <tuple>
#include <functional>
#include <Eigen/Dense>
#include "bracketing_serach.hpp"

namespace cpp_robotics
{

/**
 * @brief 最急降下法
 * 
 * @param f 
 * @param grad 
 * @param x_init 
 * @param tol 
 * @param max_iter 
 * @return std::tuple<bool, Eigen::VectorXd, size_t> 
 */
static std::tuple<bool, Eigen::VectorXd, size_t> steepest_descent_method(std::function<double(const Eigen::VectorXd &)> f, std::function<Eigen::VectorXd(const Eigen::VectorXd &)> grad, Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
{
    Eigen::VectorXd x = x_init;
    Eigen::VectorXd s;

    for(size_t i = 0; i < max_iter; i++)
    {
        s = -grad(x);

        if(s.norm() < tol)
        {
            return {true, x, i};
        }

        // 直線探索
        double a = bracketing_serach(f, grad, x, s);
        x += a*s;
    }

    return {false, x, max_iter};
}

}
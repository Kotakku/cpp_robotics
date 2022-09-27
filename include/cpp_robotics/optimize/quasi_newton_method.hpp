#pragma once

#include <Eigen/Dense>
#include "./bfgs.hpp"
#include "./bracketing_serach.hpp"

namespace cpp_robotics
{

/**
 * @brief 準ニュートン法
 * 
 * @param f 
 * @param grad 
 * @param x_init 
 * @param tol 
 * @param max_iter 
 * @return std::tuple<bool, Eigen::VectorXd, size_t> 
 */
static std::tuple<bool, Eigen::VectorXd, size_t> quasi_newton_method(std::function<double(const Eigen::VectorXd &)> f, std::function<Eigen::VectorXd(const Eigen::VectorXd &)> grad, Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
{
    size_t n = x_init.rows();
    Eigen::VectorXd x = x_init;
    Eigen::VectorXd dx, gx, y;
    Eigen::MatrixXd B = Eigen::MatrixXd::Identity(n, n);
    
    gx = grad(x);
    for(size_t i = 0; i < max_iter; i++)
    {
        dx = - B.inverse() * grad(x);

        if(dx.norm() < tol)
        {
            return {true, x, i};
        }

        // 疑似ヘッセ行列の更新
        // BFGS法
        double a = bracketing_serach([&](double v){ return f(x + v*dx); }); // 直線探索
        x += a * dx;
        y = -gx;
        gx = grad(x);
        y += gx;
        powells_modified_bfgs_step(B, a*dx, y);
    }

    return {false, x, max_iter};
}

}
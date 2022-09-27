#pragma once

#include <tuple>
#include <functional>
#include <Eigen/Dense>
#include "bracketing_serach.hpp"

namespace cpp_robotics
{

/**
 * @brief ニュートン法
 * 
 * @param grad 
 * @param hesse 
 * @param x_init 
 * @param tol 
 * @param max_iter 
 * @return std::tuple<bool, Eigen::VectorXd, size_t> 
 */
static std::tuple<bool, Eigen::VectorXd, size_t> newton_method(std::function<Eigen::VectorXd(const Eigen::VectorXd &)> grad, std::function<Eigen::MatrixXd(const Eigen::VectorXd &)> hesse, Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
{
    Eigen::VectorXd x = x_init;
    Eigen::VectorXd dx;

    for(size_t i = 0; i < max_iter; i++)
    {
        dx = grad(x);

        if(dx.norm() < tol)
        {
            return {true, x, i};
        }

        x -= (hesse(x).inverse() * dx);
    }

    return {false, x, max_iter};
}

}
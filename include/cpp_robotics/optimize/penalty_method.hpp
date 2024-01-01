#pragma once

#include <cmath>
#include <functional>
#include <Eigen/Dense>
#include "constraint.hpp"
#include "derivative.hpp"
#include "quasi_newton_method.hpp"

namespace cpp_robotics
{

/**
 * @brief ペナルティ法
 * 
 * @param f 
 * @param constraint 
 * @param x_init 
 * @param r_init 
 * @param tol 
 * @param max_iter 
 * @return std::tuple<bool, Eigen::VectorXd, size_t> 
 */
static std::tuple<bool, Eigen::VectorXd, size_t> penalty_method(std::function<double(const Eigen::VectorXd &)> f, ConstraintArray constraint, Eigen::VectorXd x_init, const double r_init = 1.0, const double tol = 1e-3, const size_t max_iter = 1000)
{
    Eigen::VectorXd x = x_init;
    double r = r_init;
    std::function<double(const Eigen::VectorXd &)> ext_f = 
    [&](const Eigen::VectorXd & x)
    {
        double y = f(x);

        for(auto & con : constraint)
        {
            switch(con.type)
            {
                case Constraint::Type::Eq:
                    y += r*std::pow(con.con_f(x), 2);
                    break;
                case Constraint::Type::Ineq:
                    y += r*std::pow(std::max(0.0, con.con_f(x)), 2);
                    break;
                default:
                    break;
            }
        }

        return y;
    };

    auto ext_grad = [&](Eigen::VectorXd x)
    {
        return derivative(ext_f, x);
    };

    for(size_t i = 0; i < max_iter; i++)
    {
        auto [step_result, new_x, sub_itr_cnt] = quasi_newton_method(ext_f, ext_grad, x, tol, 1);
        if(std::abs(r * constraint.eval_sum(new_x)) < tol)
            return {true, new_x, i};

        x = new_x;
        r += 1;
    }
    return {false, x, max_iter};
}

}
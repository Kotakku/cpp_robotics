#pragma once

#include <cmath>
#include <functional>
#include <Eigen/Dense>
#include "constraint.hpp"
#include "derivative.hpp"
#include "quasi_newton_method.hpp"

namespace cpp_robotics
{

/// バリア法
// 制約の境界で目的関数が発散するため等式制約は使用することが出来ない
// また不等式制約でもg(x)=0の境界をまたぐことは出来ないのでx_initが実行可能領域内である必要がある
static std::tuple<bool, Eigen::VectorXd, size_t> barrier_method(std::function<double(const Eigen::VectorXd &)> f, ConstraintArray constraint, Eigen::VectorXd x_init, const double r_init = 10.0, const double tol = 1e-3, const size_t max_iter = 1000)
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
                    // 無視
                    break;
                case Constraint::Type::Ineq:
                    y += r * std::log(std::abs(con.con_f(x))); // / std::pow(, 2);
                    break;
                default:
                    break;
            }
        }

        return y;
    };

    auto grad = [&](Eigen::VectorXd x)
    {
        return derivative(ext_f, x);
    };

    for(size_t i = 0; i < max_iter; i++)
    {
        auto [step_result, new_x, sub_itr_cnt] = quasi_newton_method(ext_f, grad, x, tol, 1);
        if(std::abs(r * constraint.eval_sum(new_x)) < tol)
            return {true, new_x, i};

        x = new_x;
        r *= 1.5;
    }
    return {false, x, max_iter};
}

}
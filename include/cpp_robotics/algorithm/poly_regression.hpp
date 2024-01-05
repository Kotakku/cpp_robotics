#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/system/polynomial.hpp"

namespace cpp_robotics
{

/**
 * @brief 回帰曲線
 * 
 * @param x 
 * @param y 
 * @param degree 回帰曲線の次元
 * @return Polynomial 
 */
Polynomial poly_regression(const std::vector<double> &x, const std::vector<double> &y, const size_t degree)
{
    Eigen::MatrixXd XT, Y;

    assert(x.size() == y.size());
    const size_t data_num = x.size();
    XT.resize(degree + 1, data_num);
    Y.resize(data_num, 1);

    for (size_t j = 0; j < x.size(); j++)
    {
        XT(0, j) = 1;
        for (size_t i = 0; i < degree; i++)
        {
            XT(i + 1, j) = XT(i, j) * x[j];
        }
    }

    for (size_t i = 0; i < y.size(); i++)
    {
        Y(i) = y[i];
    }

    std::vector<double> coeff(degree + 1);
    Eigen::Map<Eigen::VectorXd> coeff_vec(coeff.data(), degree + 1);
    coeff_vec = (XT * XT.transpose()).inverse() * (XT * Y);
    return Polynomial(coeff);
}

}
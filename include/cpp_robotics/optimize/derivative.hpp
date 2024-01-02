#pragma once

#include <cmath>
#include <limits>
#include <functional>
#include <Eigen/Dense>

namespace cpp_robotics
{

/**
 * @brief R -> Rの数値微分
 * 
 * @param f 
 * @param x 
 * @param eps 
 * @return double 
 */
static double derivative(std::function<double(double)> f, double x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    // 中央差分
    return ( f(x + eps) - f(x - eps) ) / (2.0*eps);
}

/**
 * @brief R^n -> Rの数値微分
 * 
 * @param f 
 * @param x 
 * @param eps 
 * @return Eigen::VectorXd 
 */
static Eigen::VectorXd derivative(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::VectorXd der(x.rows());
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        Eigen::VectorXd diff = Eigen::VectorXd::Zero(x.rows());
        diff(i) = eps;
        // 中央差分
        der(i) = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
    }
    return der;
}

/**
 * @brief R^n -> R^mの数値微分
 * 
 * @param f 
 * @param x 
 * @param eps 
 * @return Eigen::MatrixXd 
 */
static Eigen::MatrixXd derivative(std::function<Eigen::VectorXd(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::MatrixXd der;
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        Eigen::VectorXd diff = Eigen::VectorXd::Zero(x.rows());
        diff(i) = eps;
        // 中央差分
        Eigen::VectorXd der_col = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
        if(i == 0)
        {
            der = Eigen::MatrixXd::Zero(der_col.size(), x.rows());
        }
        der.col(i) = der_col;
    }
    return der;
}

/**
 * @brief R -> Rの2回数値微分
 * 
 * @param f 
 * @param x 
 * @param eps 
 * @return double 
 */
static double second_derivative(std::function<double(double)> f, double x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    // 中央2階差分
    return ( f(x + eps) - 2*f(x) + f(x - eps) ) / std::pow(eps,2);
}

/**
 * @brief R^n -> Rの2回数値微分
 * 
 * @param f
 * @param x
 * @param eps
 * @return Eigen::MatrixXd
*/
static Eigen::MatrixXd second_derivative(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    int n = x.size();
    Eigen::MatrixXd H(n, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Eigen::VectorXd e_i = Eigen::VectorXd::Zero(n);
            Eigen::VectorXd e_j = Eigen::VectorXd::Zero(n);
            e_i[i] = eps;
            e_j[j] = eps;
            
            double f_ij = f(x + e_i + e_j) - f(x + e_i - e_j) - f(x - e_i + e_j) + f(x - e_i - e_j);
            H(i, j) = f_ij / (4 * eps * eps);
        }
    }

    return H;
}

/**
 * @brief 
 * 
 * @param f 
 * @param x 
 * @param eps 
 * @return Eigen::MatrixXd 
 */
static Eigen::MatrixXd approx_hessian(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    auto j = derivative(f, x, eps);
    return j * j.transpose();
}

}
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
 * @param J ヤコビアン(あらかじめ確保しておくこと)
 * @param eps
*/
static void derivative(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, Eigen::VectorXd &J, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::VectorXd diff(x.rows());
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        diff.setZero();
        diff(i) = eps;
        // 中央差分
        J(i) = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
    }
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
    Eigen::VectorXd J(x.rows());
    derivative(f, x, J, eps);
    return J;
}

/**
 * @brief R^n -> R^mの数値微分
 * 
 * @param f
 * @param x
 * @param J ヤコビアン(あらかじめ確保しておくこと)
 * @param eps
*/
static void derivative(std::function<Eigen::VectorXd(Eigen::VectorXd)> f, Eigen::VectorXd x, Eigen::MatrixXd &J, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    Eigen::VectorXd J_col;
    Eigen::VectorXd diff(x.rows());
    for(Eigen::VectorXd::Index i = 0; i < x.rows(); i++)
    {
        diff.setZero();
        diff(i) = eps;
        // 中央差分
        J_col = ( f(x + diff) - f(x - diff) ) / (2.0*eps);
        J.col(i) = J_col;
    }
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
    Eigen::MatrixXd J;
    derivative(f, x, J, eps);
    return J;
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
 * @param H ヘッセ行列(あらかじめ確保しておくこと)
 * @param eps
*/
static void second_derivative(std::function<double(Eigen::VectorXd)> f, Eigen::VectorXd x, Eigen::MatrixXd &H, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    int n = x.size();
    Eigen::VectorXd e_i(n);
    Eigen::VectorXd e_j(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            e_i.setZero();
            e_j.setZero();
            e_i[i] = eps;
            e_j[j] = eps;
            
            double f_ij = f(x + e_i + e_j) - f(x + e_i - e_j) - f(x - e_i + e_j) + f(x - e_i - e_j);
            H(i, j) = f_ij / (4 * eps * eps);
        }
    }
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
    second_derivative(f, x, H, eps);
    return H;
}

/**
 * @brief R^(n, m) -> Rのn,mでの偏微分
 * 
 * @param f
 * @param x
 * @param H (あらかじめ確保しておくこと)
 * @param eps
*/
static void mixed_derivative(std::function<double(Eigen::VectorXd, Eigen::VectorXd)> f, Eigen::VectorXd x, Eigen::VectorXd y, Eigen::MatrixXd &H, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    int n = x.size();
    int m = y.size();
    Eigen::VectorXd e_i(n);
    Eigen::VectorXd e_j(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            e_i.setZero();
            e_j.setZero();
            e_i[i] = eps;
            e_j[j] = eps;
            
            double f_ij = f(x + e_i, y + e_j) - f(x + e_i, y - e_j) - f(x - e_i, y + e_j) + f(x - e_i, y - e_j);
            H(i, j) = f_ij / (4 * eps * eps);
        }
    }
}


/**
 * @brief R^(n, m) -> Rのn,mでの偏微分
 * 
 * @param f
 * @param x
 * @param eps
 * @return Eigen::MatrixXd
*/
static Eigen::MatrixXd mixed_derivative(std::function<double(Eigen::VectorXd, Eigen::VectorXd)> f, Eigen::VectorXd x, Eigen::VectorXd y, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5))
{
    int n = x.size();
    int m = y.size();
    Eigen::MatrixXd H(n, m);
    mixed_derivative(f, x, y, H, eps);
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
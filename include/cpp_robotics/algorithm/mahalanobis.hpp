#pragma once

#include <cmath>
#include <Eigen/Dense>

namespace cpp_robotics
{

/**
 * @brief マハラノビス距離の計算
 * 
 * @param a 
 * @param b 
 * @param cov_inv 分散の逆行列
 * @return double マハラノビス距離
 */
double mahalanobis(const Eigen::VectorXd &a, const Eigen::VectorXd &b, const Eigen::MatrixXd cov_inv)
{
    auto diff = a-b;
    return std::sqrt( diff.dot( cov_inv*diff ) );
}

}



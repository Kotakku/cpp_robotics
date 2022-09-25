#pragma once

#include <cmath>
#include <Eigen/Dense>

namespace cpp_robotics
{

double mahalanobis(const Eigen::VectorXd &a, const Eigen::VectorXd &b, const Eigen::MatrixXd cov_inv)
{
    auto diff = a-b;
    return std::sqrt( diff.dot( cov_inv*diff ) );
}

}



#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

// min || Ax - b ||^2
//  x
Eigen::VectorXd leastsq(const Eigen::MatrixXd &A, const Eigen::VectorXd &b)
{
    return (A.transpose()*A).partialPivLu().solve(A.transpose()*b);
}

}
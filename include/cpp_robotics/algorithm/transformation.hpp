#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

static Eigen::MatrixXd homogeneous(const Eigen::MatrixXd &R, const Eigen::VectorXd &T)
{
    assert(R.rows() == R.cols());
    assert(R.cols() == T.rows());
    const int dim = T.rows();
    Eigen::MatrixXd H(dim+1, dim+1);
    H.block(0,0, dim, dim) = R;
    H.block(0, dim, dim, 1) = T;
    H(dim, dim) = 1;
    return H;
}

static Eigen::VectorXd transform_by_homogeneous(const Eigen::MatrixXd &H, const Eigen::VectorXd &x)
{
    assert(H.rows() == H.cols());
    assert(H.cols() == x.rows()+1);
    const int dim = x.rows();

    Eigen::VectorXd xt = H.block(0,0, dim, dim)*x + H.block(0, dim, dim, 1);
    return xt;
}

}
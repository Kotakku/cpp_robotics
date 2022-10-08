#include <gtest/gtest.h>

#include <cpp_robotics/optimize/bfgs.hpp>

template <typename Mat>
bool is_posdef(Mat H)
{
    Eigen::EigenSolver<Mat> eigensolver(H);
    for (int i = 0; i < eigensolver.eigenvalues().rows(); i++) {
        double v = eigensolver.eigenvalues()(i).real();
        if (v <= 0) {
            return false;
        }
    }
    return true;
}

TEST(bfgs, is_posdef1) {
    using namespace cpp_robotics;

    Eigen::VectorXd step(2), delta_grad(2);
    Eigen::MatrixXd H(2,2); // true constant hessian;
    H << 2, 0,
        0, 1;
    Eigen::MatrixXd B = Eigen::MatrixXd::Identity(2,2);

    for (int i = 0; i < 10; i++) {
        // do some random steps
        step << sin(i), cos(i);

        delta_grad = H*step;
        powells_modified_bfgs_step(B, step, delta_grad);

        EXPECT_TRUE(is_posdef(B));
    }

    EXPECT_TRUE(B.isApprox(H, 1e-3));
}

TEST(bfgs, is_posdef2) {
    using namespace cpp_robotics;

    Eigen::VectorXd step(2), delta_grad(2);
    Eigen::MatrixXd H(2,2); // true constant hessian;
    H << 2, 0,
        0, -1;
    Eigen::MatrixXd B = Eigen::MatrixXd::Identity(2,2);

    for (int i = 0; i < 10; i++) {
        // do some random steps
        step << sin(i), cos(i);

        delta_grad = H*step;
        powells_modified_bfgs_step(B, step, delta_grad);

        EXPECT_TRUE(is_posdef(B));
    }
}
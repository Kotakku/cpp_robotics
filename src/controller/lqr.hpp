#pragma once

#include <Eigen/Dense>
#include <optional>

namespace cpp_robotics
{

static std::optional<Eigen::MatrixXd> solve_riccati_arimoto_potter(const Eigen::MatrixXd &A,
                                const Eigen::MatrixXd &B,
                                const Eigen::MatrixXd &Q,
                                const Eigen::MatrixXd &R) {
    const uint dim_x = A.rows();
    const uint dim_u = B.cols();
    // set Hamilton matrix
    Eigen::MatrixXd Ham = Eigen::MatrixXd::Zero(2 * dim_x, 2 * dim_x);
    Ham << A, -B * R.inverse() * B.transpose(), -Q, -A.transpose();
    // calc eigenvalues and eigenvectors
    Eigen::EigenSolver<Eigen::MatrixXd> Eigs(Ham);
    // check eigen values
    // std::cout << "eigen values：\n" << Eigs.eigenvalues() << std::endl;
    // std::cout << "eigen vectors：\n" << Eigs.eigenvectors() << std::endl;
    // extract stable eigenvectors into 'eigvec'
    Eigen::MatrixXcd eigvec = Eigen::MatrixXcd::Zero(2 * dim_x, dim_x);
    int j = 0;
    for (size_t i = 0; i < 2 * dim_x; ++i) {
        if (Eigs.eigenvalues()[i].real() < 0.) {
        eigvec.col(j) = Eigs.eigenvectors().block(0, i, 2 * dim_x, 1);
        ++j;
        }
    }
    // calc P with stable eigen vector matrix
    Eigen::MatrixXcd Vs_1, Vs_2;
    Vs_1 = eigvec.block(0, 0, dim_x, dim_x);
    Vs_2 = eigvec.block(dim_x, 0, dim_x, dim_x);
    return (Vs_2 * Vs_1.inverse()).real();
}

static Eigen::MatrixXd lqr(const Eigen::MatrixXd &A,
                    const Eigen::MatrixXd &B,
                    const Eigen::MatrixXd &Q,
                    const Eigen::MatrixXd &R)
{
    auto P = solve_riccati_arimoto_potter(A, B, Q, R);
    return R.inverse() * B.transpose() * P.value();
}

}
#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

// 行列が正定値かどうか
template<typename MatrixType>
bool isPositiveDefinite(const MatrixType& matrix) {
    Eigen::LLT<MatrixType> llt(matrix);
    if(llt.info() == Eigen::NumericalIssue) {
        return false;
    }
    return true;
}

// 疑似逆行列
template<typename MatrixType>
MatrixType pseudo_inverse(const MatrixType &a, double epsilon = std::numeric_limits<double>::epsilon()) //, Eigen::MatrixXd W = Eigen::MatrixXd())
{
    unsigned int svd_option;
    if (a.rows() == a.cols())
    {
        svd_option = Eigen::ComputeFullU | Eigen::ComputeFullV; // for square matrix
    }
    else
    {
        svd_option = Eigen::ComputeThinU | Eigen::ComputeThinV; // for non-square matrix
    }

	Eigen::JacobiSVD< MatrixType > svd(a ,svd_option);
    double tolerance = epsilon * std::max(a.cols(), a.rows()) *svd.singularValues().array().abs()(0);
	return svd.matrixV() *  (svd.singularValues().array().abs() > tolerance).select(svd.singularValues().array().inverse(), 0).matrix().asDiagonal() * svd.matrixU().adjoint();
}

// Singularity-Robust Inverse SR逆行列
template<typename MatrixType>
MatrixType sr_inverse(const MatrixType &a, double w0 = 1e-2, Eigen::MatrixXd W = Eigen::MatrixXd())
{
    auto r = a.rows();
    auto c = a.cols();
    if(W.rows() != c|| W.cols() != c)
    {
        W = Eigen::MatrixXd::Identity(c,c);
    }

    double w = std::sqrt((a*(a.transpose())).determinant());

    double lambda = 0;
    if(w < w0)
        lambda = std::pow((1-w/w0),2);

    auto a1 = (a*W*(a.transpose()) + lambda * Eigen::MatrixXd::Identity(r,r)).inverse();
    Eigen::MatrixXd a_sr = W*a.transpose()*a1;

    return a_sr;
}

}
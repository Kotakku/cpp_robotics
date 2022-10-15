#pragma once

namespace cpp_robotics
{

// min || Cx + d ||_2^2 
//  to
// min 1/2 x^TQx + c^Tx
// https://jp.mathworks.com/help/optim/ug/least-squares-model-fitting-algorithms.html#buc5ri4
std::tuple<Eigen::MatrixXd, Eigen::VectorXd> lsi2qp(const Eigen::MatrixXd &C, const Eigen::VectorXd &d)
{
    return {2*C.transpose()*C, (2*C.transpose()*d)};
}

}
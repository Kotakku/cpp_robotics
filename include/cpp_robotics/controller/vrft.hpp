#pragma once

#include <cpp_robotics/system.hpp>
#include <cpp_robotics/optimize/least_squares_method.hpp>

namespace cpp_robotics
{

Eigen::VectorXd vrft_leastsq(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, TransferFunction ref_model, std::vector<TransferFunction> &control_base, std::optional<TransferFunction> prefilter)
{
    (void) Ts;

    Eigen::VectorXd uf, ef;
    if(prefilter)
    {
        uf = lsim_y(prefilter.value(), u);
        ef = lsim_y(prefilter.value()*(ref_model.inv()-1.0), y);
    }
    else
    {
        uf = u;
        ef = lsim_y((ref_model.inv()-1.0), y);
    }

    Eigen::MatrixXd phi(ef.size(), control_base.size());
    for(size_t i = 0; i < control_base.size(); ++i)
    {
        phi.col(i) = lsim_y(control_base[i], ef);
    }

    return leastsq(phi, uf);
}

Eigen::VectorXd vrft_pid(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, TransferFunction ref_model, std::optional<TransferFunction> prefilter, double Td = 0.01)
{
    std::vector<TransferFunction> control_base = {
        TransferFunction({1.0}, {1.0}, Ts),         // P
        TransferFunction({1.0}, {1.0, 0.0}, Ts),    // I
        TransferFunction({1.0, 0.0}, {Td, 1.0}, Ts) // D
    };

    return vrft_leastsq(u, y, Ts, ref_model, control_base, prefilter);
}

Eigen::VectorXd vrft_p(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, TransferFunction ref_model, std::optional<TransferFunction> prefilter)
{
    std::vector<TransferFunction> control_base = {
        TransferFunction({1.0}, {1.0}, Ts)
    };

    return vrft_leastsq(u, y, Ts, ref_model, control_base, prefilter);
}

Eigen::VectorXd vrft_pi(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, TransferFunction ref_model, std::optional<TransferFunction> prefilter)
{
    std::vector<TransferFunction> control_base = {
        TransferFunction({1.0}, {1.0}, Ts),
        TransferFunction({1.0}, {1.0, 0.0}, Ts)
    };

    return vrft_leastsq(u, y, Ts, ref_model, control_base, prefilter);
}

Eigen::VectorXd vrft_pd(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, TransferFunction ref_model, std::optional<TransferFunction> prefilter, double Td = 0.01)
{
    std::vector<TransferFunction> control_base = {
        TransferFunction({1.0}, {1.0}, Ts),
        TransferFunction({1.0, 0.0}, {Td, 1.0}, Ts)
    };

    return vrft_leastsq(u, y, Ts, ref_model, control_base, prefilter);
}

}
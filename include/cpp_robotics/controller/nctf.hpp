#pragma once

#include <functional>
#include "./pid.hpp"
#include "../filter/differentiator.hpp"

namespace cpp_robotics
{

class NctfController
{
public:
    static std::function<double(double)> make_simple_nct(double max_velocity, double slope)
    {
        return [=](double e){ return -max_velocity*std::tanh(e*slope/max_velocity); };
    }

    NctfController(double max_velocity, double nct_slope, PIDController::pid_param_t pid_param, double dt):
        NctfController(make_simple_nct(max_velocity, nct_slope), pid_param, dt)
    {

    }

    NctfController(std::function<double(double)> nct, PIDController::pid_param_t pid_param, double dt):
        nct_(nct),
        diff_(0.5/dt, dt),
        pid_(pid_param)
    {

    }

    void reset()
    {
        diff_.reset();
        pid_.reset();
    }

    double control(double target, double state) { return control(target-state); }
    double control(double e)
    {
        double state_e_dot = diff_.filtering(e);
        double nct_e_dot = nct_(e);

        // e_.push_back(e);
        // e_dot_.push_back(state_e_dot);
        // target_e_dot_.push_back(nct_e_dot);

        return pid_.calculate(-(nct_e_dot - state_e_dot));
    }

    std::function<double(double)> nct() const
    {
        return nct_;
    }

    // std::vector<double> e_, e_dot_, target_e_dot_;

private:
    std::function<double(double)> nct_;
    Differentiator diff_;
    PIDController pid_;
};

}
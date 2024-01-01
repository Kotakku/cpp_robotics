#pragma once

#include <functional>
#include "./pid.hpp"
#include "../filter/differentiator.hpp"
#include "../filter/integrator.hpp"

namespace cpp_robotics
{

/**
 * @brief NCTF制御器
 * 
 */
class NctfController
{
public:
    static std::function<double(double)> make_simple_nct(double max_velocity, double slope)
    {
        return [=](double e){ return -max_velocity*std::tanh(e*slope/max_velocity); };
    }

    NctfController(double max_velocity, double nct_slope, PID::pid_param_t pid_param, double dt):
        NctfController(make_simple_nct(max_velocity, nct_slope), pid_param, dt)
    {

    }

    NctfController(std::function<double(double)> nct, PID::pid_param_t pid_param, double dt):
        nct_(nct),
        diff_(pid_param.gpd, dt),
        pid_(pid_param),
        itg_(dt),
        pid_param_(pid_param)
    {

    }

    void reset()
    {
        diff_.reset();
        pid_.reset();
    }

    double nct_error = 0;
    double control(double target, double state) { return control(target-state); }
    double control(double e)
    {
        double state_e_dot = diff_.filtering(e);
        double nct_e_dot = nct_(e);
        nct_error = -(nct_e_dot - state_e_dot);
        return pid_.calculate(nct_error);
    }

    std::function<double(double)> nct() const
    {
        return nct_;
    }

private:
    std::function<double(double)> nct_;
    Differentiator diff_;
    PID pid_;
    Integrator itg_;
    PID::pid_param_t pid_param_;
};

}
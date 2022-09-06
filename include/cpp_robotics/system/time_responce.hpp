#pragma once

#include <tuple>
#include "./transfer_function.hpp"

namespace cpp_robotics
{

static std::tuple<std::vector<double>, std::vector<double>> impluse(TransferFunction &sys, double time)
{
    std::vector<double> t = arrange(0, time, sys.Ts());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce( i == 0 ? 1.0/sys.Ts() : 0.0);
    }

    return {t, res};
}

static std::tuple<std::vector<double>, std::vector<double>> step(TransferFunction &sys, double time, const double gain = 1.0)
{
    std::vector<double> t = arrange(0, time, sys.Ts());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce(gain);
    }

    return {t, res};
}

static std::tuple<std::vector<double>, std::vector<double>> lsim(TransferFunction &sys, std::vector<double> input)
{
    std::vector<double> t = linspace(0, sys.Ts()*input.size(), input.size());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce(input[i]);
    }

    return {t, res};
}

}
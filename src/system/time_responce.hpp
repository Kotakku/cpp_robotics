#pragma once

#include <tuple>
#include "./transfer_function.hpp"

namespace cpp_robotics
{

template<size_t NUM, size_t DEN>
static std::tuple<std::vector<double>, std::vector<double>> impluse(TransferFunction<NUM, DEN> &sys, double time)
{
    std::vector<double> t = arrange(0, time, sys.Ts);
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce( i == 0 ? 1.0/sys.Ts : 0.0);
    }

    return {t, res};
}

template<size_t NUM, size_t DEN>
static std::tuple<std::vector<double>, std::vector<double>> step(TransferFunction<NUM, DEN> &sys, double time)
{
    std::vector<double> t = arrange(0, time, sys.Ts);
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce(1.0);
    }

    return {t, res};
}

}
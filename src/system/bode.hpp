#pragma once

#include "./transfer_function.hpp"
#include "../external_lib/matplotlibcpp.h"
#include "../utility/space.hpp"

namespace cpp_robotics
{

template<size_t NUM, size_t DEN>
static void bode_plot(TransferFunction<NUM, DEN> &tf, size_t n = 100)
{
    namespace plt = matplotlibcpp;
    auto f = logspace(-2, 2, n);
    std::vector<double> gain_db(n);

    for(size_t i = 0; i < n; i++)
    {
        double gain = 1 / std::sqrt(1 + std::pow(f[i], 2)); // G(s) = 1 / (s + 1)の決め打ち
        gain_db[i] = 20 * std::log(gain);
    }
    plt::semilogx(f, gain_db);
    plt::xlim(std::pow(10,-2), std::pow(10,2));
    plt::ylim(-50, 10);
    plt::show();
}

}
#pragma once

#include <vector>
#include <tuple>
#include "./transfer_function.hpp"
#ifdef CR_USE_MATPLOTLIB
#include "../third_party/matplotlib-cpp/matplotlibcpp.h"
#endif
#include "../utility/space.hpp"
#include "../vector/vector2.hpp"
#include "../utility/math_utils.hpp"
#include "./bode.hpp"

namespace cpp_robotics
{

/**
 * @brief ナイキスト線図の応答を計算する
 * 
 * @param tf 
 * @param omegas 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> nyquist(TransferFunction &tf, const std::vector<double> &omegas = logspace(-2, 2, 500))
{
    size_t n = omegas.size();
    std::vector<double> Re(n), Im(n);
    auto [g, ph] = bode(tf, omegas, false, false);

    Vector2d tmp;
    for(size_t i = 0; i < n; i++)
    {
        tmp.x = g[i];
        tmp.y = 0;
        tmp.rotate(ph[i]);
        Re[i] = tmp.x;
        Im[i] = tmp.y;
    }

    return {Re, Im};
}

#ifdef CR_USE_MATPLOTLIB
/**
 * @brief ナイキスト線図を表示する(matplotlibが必要)
 * 
 * @param tf 
 * @param omegas 
 */
static void nyquist_plot(TransferFunction &tf, const std::vector<double> &omegas = logspace(-2, 2, 500))
{
    namespace plt = matplotlibcpp;
    auto [Re, Im] = nyquist(tf, omegas);

    plt::plot(Re, Im);
    plt::set_aspect(1.0);
    plt::xlabel("Re");
    plt::ylabel("Im");
    plt::xlim(-1.3*Re[0], 1.3*Re[0]);
    plt::ylim(-1.3*Re[0], 1.3*Re[0]);
    plt::grid(true, "both");

    plt::show();
}
#endif

}
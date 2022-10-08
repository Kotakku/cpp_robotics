#define CR_USE_MATPLOTLIB
#include <iostream>
#include <cpp_robotics/system/time_responce.hpp>
#include <cpp_robotics/filter/low_pass_filter.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>

int main()
{
    namespace cr = cpp_robotics;

    const double dt = 1e-3;
    const double f = 1; // [Hz]
    const double omega = 2*M_PI*f; // [rad/s]
    const double tau = 1/omega; //[s]
    cr::LowPassFilter lpf(tau, dt);

    const double gain = 1.0;
    auto [t, res] = cr::step([&](double u){return lpf.filtering(u); }, dt, 3.0);

    namespace plt = matplotlibcpp;
    plt::plot(t, res);

    plt::show();
}
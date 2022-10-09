#define CR_USE_MATPLOTLIB
#include <iostream>
#include <cpp_robotics/system/time_responce.hpp>
#include <cpp_robotics/filter/velocity_limit_filter.hpp>
#include <cpp_robotics/filter/acceleration_limit_filter.hpp>
#include <cpp_robotics/filter/differentiator.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;

    const double dt = 1e-3;

    {
        // 速度制限フィルタ
        cr::VelocityLimitFilter vel_filter(1.0, dt);
        auto [t, res] = cr::step(vel_filter, 1.5);
        plt::plot(t, res);
        plt::show();
    }

    {
        // 加速度制限フィルタ
        cr::AccelerationLimitFilter acc_filter(4.0, dt);
        auto [t, res] = cr::step(acc_filter, 1.5);
        plt::plot(t, res);
        plt::show();

        // acc_filterの出力の速度を調べる
        cr::Differentiator diff(1/dt, dt);
        auto [t2, dres] = cr::lsim(diff, res);
        plt::plot(t2, dres);
        plt::show();
    }
}
#include <gtest/gtest.h>

#include <cpp_robotics/system/time_responce.hpp>
#include <cpp_robotics/filter/low_pass_filter.hpp>

class MyAllPassSystem
{
public:
    double responce(double u)
    {
        return u;
    }

    double Ts() const { return 1e-3; }
};

class MyAllPassFilter
{
public:
    double filtering(double u)
    {
        return u;
    }

    double Ts() const { return 1e-3; }
};

TEST(time_responce, impluce) {
    namespace cr = cpp_robotics;

    {
        MyAllPassSystem system;
        auto [t, res] = cr::impulse(system, 1.0);
    }

    {
        MyAllPassFilter filter;
        auto [t, res] = cr::impulse(filter, 1.0);
    }

    {
        cr::LowPassFilter filter(10*2*M_PI, 1e-3);
        auto [t, res] = cr::impulse(filter, 1.0);
    }
}

TEST(time_responce, step) {
    namespace cr = cpp_robotics;

    {
        MyAllPassSystem system;
        auto [t, res] = cr::step(system, 1.0);
    }

    {
        MyAllPassFilter filter;
        auto [t, res] = cr::step(filter, 1.0);
    }

    {
        cr::LowPassFilter filter(10*2*M_PI, 1e-3);
        auto [t, res] = cr::step(filter, 1.0);
    }
}

TEST(time_responce, lsim) {
    namespace cr = cpp_robotics;

    {
        MyAllPassSystem system;
        auto [t, res] = cr::lsim(system, cr::arrange(0, 3.0, system.Ts()));
    }

    {
        MyAllPassFilter filter;
        auto [t, res] = cr::lsim(filter, cr::linspace(0, 3.0, filter.Ts()));
    }

    {
        cr::LowPassFilter filter(10*2*M_PI, 1e-3);
        auto [t, res] = cr::lsim(filter, cr::linspace(0, 3.0, filter.Ts()));
    }
}
#include <gtest/gtest.h>

#include <cpp_robotics/controller/pid.hpp>

TEST(pid, test) {
    namespace cr = cpp_robotics;

    const double dt = 0.001;
    const double max_output = 24;

    //////////////////// PID ////////////////////
    cr::PID::pid_param_t pid_param = 
    {
        dt,
        100*2*M_PI,
        6.0,
        0.0,
        0.2,
        std::pair(-max_output, max_output)
    };
    cr::PID pid(pid_param);

    EXPECT_TRUE(0.0 < pid.calculate(1.0));
}
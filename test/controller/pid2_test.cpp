#include <gtest/gtest.h>

#include <cpp_robotics/controller/pid2.hpp>

TEST(pid2, test) {
    namespace cr = cpp_robotics;

    const double dt = 0.001;
    const double max_output = 24;

    //////////////////// PID ////////////////////
    cr::PID2::pid_param_t pid_param = 
    {
        dt,
        100*2*M_PI,
        6.0,
        0.0,
        0.2,
        1,
        1,
        std::pair(-max_output, max_output)
    };
    cr::PID2 pid(pid_param);

    double u = pid.calculate(1.0, 0.0);
    std::cout << "u = " << u << std::endl;
    EXPECT_TRUE(0.0 < u);
}
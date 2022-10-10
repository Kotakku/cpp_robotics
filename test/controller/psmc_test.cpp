#include <gtest/gtest.h>

#include <cpp_robotics/controller/psmc.hpp>

TEST(psmc, test) {
    namespace cr = cpp_robotics;

    const double dt = 0.001;
    const double max_output = 24;

    //////////////////// PID ////////////////////
    cr::PSMC::param_t psmc_param = 
    {
        dt,
        6.0,
        0.0,
        0.1,
        std::pair(-max_output, max_output)
    };
    cr::PSMC psmc(psmc_param);

    EXPECT_TRUE(0.0 < psmc.calculate(1.0, 0.0));
}
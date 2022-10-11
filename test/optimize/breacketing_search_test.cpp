#include <gtest/gtest.h>


#include "cpp_robotics/optimize/bracketing_serach.hpp"

TEST(breaketing_search, test) {
    using namespace cpp_robotics;

    EXPECT_NEAR(bracketing_serach([](double a){ return std::pow(a-0.5, 2); }, 1, 0.99), 0.5, 1e-2);
}
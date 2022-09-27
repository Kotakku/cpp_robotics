#include <gtest/gtest.h>

#include <cpp_robotics/chassis/mecanum_ik.hpp>

constexpr double eps = 1e-6;

TEST(mecanum_ik, test) {
    namespace cr = cpp_robotics;

    cr::MecanumIk ik(1.0, 1.0);

    auto wv = ik.calculate(cr::Transformd(1.0, 0.0, 0.0));
    EXPECT_NEAR(wv[0], -1, eps);
    EXPECT_NEAR(wv[1], -1, eps);
    EXPECT_NEAR(wv[2], 1, eps);
    EXPECT_NEAR(wv[3], 1, eps);

    wv = ik.calculate(cr::Transformd(0.0, 1.0, 0.0));
    EXPECT_NEAR(wv[0], 1, eps);
    EXPECT_NEAR(wv[1], -1, eps);
    EXPECT_NEAR(wv[2], -1, eps);
    EXPECT_NEAR(wv[3], 1, eps);

    wv = ik.calculate(cr::Transformd(0.0, 0.0, 1.0));
    EXPECT_NEAR(wv[0], 1, eps);
    EXPECT_NEAR(wv[1], 1, eps);
    EXPECT_NEAR(wv[2], 1, eps);
    EXPECT_NEAR(wv[3], 1, eps);
}
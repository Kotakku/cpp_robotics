#include <gtest/gtest.h>

#include <cpp_robotics/chassis/swerve_ik.hpp>

constexpr double eps = 1e-6;

TEST(swerve_test, test) {
    namespace cr = cpp_robotics;

    cr::SwerveIk ik(0.5, 0.5);

    auto wv = ik.calculate(cr::Transformd(1.0, 0.0, 0.0));
    const cr::Vector2d xvec(1, 0);
    EXPECT_EQ(wv[0], xvec);
    EXPECT_EQ(wv[1], xvec);
    EXPECT_EQ(wv[2], xvec);
    EXPECT_EQ(wv[3], xvec);

    wv = ik.calculate(cr::Transformd(0.0, 1.0, 0.0));
    const cr::Vector2d yvec(0, 1);
    EXPECT_EQ(wv[0], yvec);
    EXPECT_EQ(wv[1], yvec);
    EXPECT_EQ(wv[2], yvec);
    EXPECT_EQ(wv[3], yvec);

    wv = ik.calculate(cr::Transformd(0.0, 0.0, 1.0));
    const cr::Vector2d thetavec(-0.25, 0.25);
    EXPECT_NEAR((wv[0] - thetavec.get_rotated(0)       ).norm(), 0.0, eps);
    EXPECT_NEAR((wv[1] - thetavec.get_rotated(M_PI/2)  ).norm(), 0.0, eps);
    EXPECT_NEAR((wv[2] - thetavec.get_rotated(M_PI)    ).norm(), 0.0, eps);
    EXPECT_NEAR((wv[3] - thetavec.get_rotated(3*M_PI/2)).norm(), 0.0, eps);
}
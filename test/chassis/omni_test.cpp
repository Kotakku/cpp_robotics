#include <gtest/gtest.h>

#include <cpp_robotics/chassis/omni_ik.hpp>

constexpr double eps = 1e-6;

TEST(omni_ik, omni3_test) {
    namespace cr = cpp_robotics;

    cr::Omni3Ik ik(0.3);

    auto wv = ik.calculate(cr::Transformd(1.0, 0.0, 0.0));
    EXPECT_NEAR(wv[0], -std::sin(M_PI/6), eps);
    EXPECT_NEAR(wv[1], -std::sin(M_PI/6), eps);
    EXPECT_NEAR(wv[2], 1, eps);
    

    wv = ik.calculate(cr::Transformd(0.0, 1.0, 0.0));
    EXPECT_NEAR(wv[0], std::cos(M_PI/6), eps);
    EXPECT_NEAR(wv[1], -std::cos(M_PI/6), eps);
    EXPECT_NEAR(wv[2], 0, eps);

    wv = ik.calculate(cr::Transformd(0.0, 0.0, 1.0));
    EXPECT_NEAR(wv[0], 0.3, eps);
    EXPECT_NEAR(wv[1], 0.3, eps);
    EXPECT_NEAR(wv[2], 0.3, eps);
}

TEST(omni_ik, omni4_test) {
    namespace cr = cpp_robotics;

    cr::Omni4Ik ik(0.3);

    auto wv = ik.calculate(cr::Transformd(1.0, 0.0, 0.0));
    const double norm = 1.0 / std::sqrt(2.0);
    EXPECT_NEAR(wv[0], -norm, eps);
    EXPECT_NEAR(wv[1], -norm, eps);
    EXPECT_NEAR(wv[2], norm, eps);
    EXPECT_NEAR(wv[3], norm, eps);
    

    wv = ik.calculate(cr::Transformd(0.0, 1.0, 0.0));
    EXPECT_NEAR(wv[0], norm, eps);
    EXPECT_NEAR(wv[1], -norm, eps);
    EXPECT_NEAR(wv[2], -norm, eps);
    EXPECT_NEAR(wv[3], norm, eps);

    wv = ik.calculate(cr::Transformd(0.0, 0.0, 1.0));
    EXPECT_NEAR(wv[0], 0.3, eps);
    EXPECT_NEAR(wv[1], 0.3, eps);
    EXPECT_NEAR(wv[2], 0.3, eps);
    EXPECT_NEAR(wv[3], 0.3, eps);
}
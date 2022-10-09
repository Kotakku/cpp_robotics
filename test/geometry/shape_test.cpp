#include <gtest/gtest.h>

#include <cpp_robotics/geometry/shape.hpp>

TEST(shape, construct_and_area) {
    namespace cr = cpp_robotics;

    cr::Line line({0,0}, {1,1});
    cr::Rect rect({0.5, 1}, {1, 2});
    cr::Quad quad({0, 0}, {1, 0}, {1, 1}, {0, 1});
    cr::Triangle triangle({0,0}, {1,0}, {0.5, 1});
    cr::Circle circle({1,1}, 1);

    EXPECT_NEAR(line.length(), std::sqrt(2.0), 1e-5);
    EXPECT_NEAR(line.angle(), M_PI/4, 1e-5);
    EXPECT_TRUE(line.lerp(0.5) == cr::Vector2d(0.5, 0.5));

    EXPECT_NEAR(rect.area(), 2.0, 1e-5);
    EXPECT_NEAR(quad.area(), 1.0, 1e-5);
    EXPECT_NEAR(triangle.area(), 0.5, 1e-5);
    EXPECT_NEAR(circle.area(), M_PI, 1e-5);
}

TEST(shape, as_quad) {
    namespace cr = cpp_robotics;

    cr::Rect rect({0.5, 1}, {1, 2});
    cr::Quad quad1 = rect.as_quad();
    cr::Quad quad2 = rect.get_rotated(M_PI/6);

    EXPECT_NEAR(rect.area(), quad1.area(), 1e-5);
    EXPECT_NEAR(rect.area(), quad2.area(), 1e-5);
}
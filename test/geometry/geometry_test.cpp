#include <gtest/gtest.h>

#include <cpp_robotics/geometry/geometry.hpp>

TEST(geometry, intersect) {
    namespace cr = cpp_robotics;

    // cr::Line line({0,0}, {1,1});
    cr::Vector2d p(1,1);
    cr::Rect rect({1, 1}, {1, 2});

    EXPECT_TRUE(cr::intersect(p, rect));
    EXPECT_TRUE(cr::intersect(rect, p));
    
    p.set(0,1);
    EXPECT_FALSE(cr::intersect(p, rect));
    EXPECT_FALSE(cr::intersect(rect, p));

    
}

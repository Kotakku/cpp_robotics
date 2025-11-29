#include <gtest/gtest.h>

#include <cpp_robotics/geometry.hpp>

TEST(geometry, intersect) {
    namespace cr = cpp_robotics;

    auto expect_sym = [](const auto &a, const auto &b, bool expected, const char *label) {
        SCOPED_TRACE(label);
        EXPECT_EQ(cr::intersect(a, b), expected);
        EXPECT_EQ(cr::intersect(b, a), expected);
    };

    const cr::Vector2d p_inside_rect(0, 0);
    const cr::Vector2d p_outside(5, 5);
    const cr::Vector2d p_on_line(1, 0);
    const cr::Vector2d p_off_line(4, 0);
    const cr::Vector2d p_in_triangle(0.5, 0.5);
    const cr::Vector2d p_out_triangle(3, 3);
    const cr::Vector2d p_in_circle(1, 1);
    const cr::Vector2d p_out_circle(3, 0);

    const cr::Line line_hit({-3, 0}, {3, 0});
    const cr::Line line_cross({-3, -3}, {3, 3});
    const cr::Line line_far({5, 5}, {7, 7});

    const cr::Rect rect_a({0, 0}, {4, 4});
    const cr::Rect rect_b({6, 6}, {2, 2});
    const cr::Rect rect_c({1, 1}, {2, 2});

    const cr::Circle circle_a({0, 0}, 2.0);
    const cr::Circle circle_b({5, 0}, 1.0);
    const cr::Circle circle_c({1, 0}, 1.5);

    const cr::Triangle tri_a({0, 0}, {3, 0}, {0, 3});
    const cr::Triangle tri_b({5, 5}, {6, 5}, {5, 6});
    const cr::Triangle tri_c({1, 1}, {2, 1}, {1, 2});

    const cr::Quad quad_a({{-1, -1}, {1, -1}, {1, 1}, {-1, 1}});
    const cr::Quad quad_b({{5, 5}, {7, 5}, {7, 7}, {5, 7}});
    const cr::Quad quad_c({{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}});

    // Point vs others
    EXPECT_TRUE(cr::intersect(p_inside_rect, p_inside_rect));
    EXPECT_FALSE(cr::intersect(p_inside_rect, p_outside));
    expect_sym(p_inside_rect, rect_a, true, "point-rect true");
    expect_sym(p_outside, rect_a, false, "point-rect false");
    expect_sym(p_in_triangle, tri_a, true, "point-triangle true");
    expect_sym(p_out_triangle, tri_a, false, "point-triangle false");
    expect_sym(p_in_circle, circle_a, true, "point-circle true");
    expect_sym(p_out_circle, circle_a, false, "point-circle false");
    expect_sym(p_inside_rect, quad_a, true, "point-quad true");
    expect_sym(p_outside, quad_a, false, "point-quad false");
    expect_sym(p_on_line, line_hit, true, "point-line true");
    expect_sym(p_off_line, line_hit, false, "point-line false");

    // Line vs others
    expect_sym(line_hit, line_cross, true, "line-line true");
    expect_sym(line_hit, line_far, false, "line-line false");
    expect_sym(line_hit, rect_a, true, "line-rect true");
    expect_sym(line_far, rect_a, false, "line-rect false");
    expect_sym(line_hit, circle_a, true, "line-circle true");
    expect_sym(line_far, circle_a, false, "line-circle false");
    expect_sym(line_hit, tri_a, true, "line-triangle true");
    expect_sym(line_far, tri_a, false, "line-triangle false");
    expect_sym(line_hit, quad_a, true, "line-quad true");
    expect_sym(line_far, quad_a, false, "line-quad false");

    // Triangle vs others
    EXPECT_TRUE(cr::intersect(tri_a, tri_c));
    EXPECT_FALSE(cr::intersect(tri_a, tri_b));
    expect_sym(tri_a, rect_a, true, "triangle-rect true");
    expect_sym(tri_b, rect_a, false, "triangle-rect false");
    expect_sym(tri_a, quad_a, true, "triangle-quad true");
    expect_sym(tri_b, quad_a, false, "triangle-quad false");
    expect_sym(tri_a, circle_a, true, "triangle-circle true");
    expect_sym(tri_b, circle_b, false, "triangle-circle false");

    // Quad vs others
    EXPECT_TRUE(cr::intersect(quad_a, quad_c));
    EXPECT_FALSE(cr::intersect(quad_a, quad_b));
    expect_sym(quad_a, rect_a, true, "quad-rect true");
    expect_sym(quad_b, rect_a, false, "quad-rect false");
    expect_sym(quad_a, circle_a, true, "quad-circle true");
    expect_sym(quad_b, circle_b, false, "quad-circle false");

    // Rect vs Rect / Circle
    EXPECT_TRUE(cr::intersect(rect_a, rect_c));
    EXPECT_FALSE(cr::intersect(rect_a, rect_b));
    expect_sym(rect_a, circle_a, true, "rect-circle true");
    expect_sym(rect_a, circle_b, false, "rect-circle false");

    // Circle vs Circle
    EXPECT_TRUE(cr::intersect(circle_a, circle_c));
    EXPECT_FALSE(cr::intersect(circle_a, circle_b));
}

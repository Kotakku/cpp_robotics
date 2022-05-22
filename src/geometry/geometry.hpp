#pragma once

#include <vector>
#include "./shape.hpp"

namespace cpp_robotics
{
////////////////////////////// intersect //////////////////////////////
// Vector2d vs
bool intersect(const Vector2d& a, const Vector2d& b);
bool intersect(const Vector2d& a, const Line& b);
bool intersect(const Vector2d& a, const Rect& b);
bool intersect(const Vector2d& a, const Circle& b);

// Line vs
bool intersect(const Line& a, const Vector2d& b);
bool intersect(const Line& a, const Line& b);
bool intersect(const Line& a, const Circle& b);

// Rect vs
bool intersect(const Rect& a, const Vector2d& b);

// Ciecle vs
bool intersect(const Circle& a, const Vector2d& b);
bool intersect(const Circle& a, const Line& b);

////////////////////////////// intersect_at //////////////////////////////
// Vector2d vs
std::vector<Vector2d> intersect_at(const Vector2d& a, const Vector2d& b);
std::vector<Vector2d> intersect_at(const Vector2d& a, const Line& b);
std::vector<Vector2d> intersect_at(const Vector2d& a, const Rect& b);
std::vector<Vector2d> intersect_at(const Vector2d& a, const Circle& b);

// Line vs
std::vector<Vector2d> intersect_at(const Line& a, const Vector2d& b);
std::vector<Vector2d> intersect_at(const Line& a, const Line& b);
std::vector<Vector2d> intersect_at(const Line& a, const Circle& b);

// Rect vs
std::vector<Vector2d> intersect_at(const Rect& a, const Vector2d& b);

// Ciecle vs
std::vector<Vector2d> intersect_at(const Circle& a, const Vector2d& b);
std::vector<Vector2d> intersect_at(const Circle& a, const Line& b);

////////////////////////////// contain //////////////////////////////
bool contain(const Vector2d &range, const Vector2d &target);
bool contain(const Rect &range, const Vector2d &target);
}
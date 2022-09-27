#pragma once

#include <array>
#include "../vector/vector2.hpp"

namespace cpp_robotics
{
    struct Line;
    struct Rect;
    struct Quad;
    struct Triangle;
    struct Circle;

    /**
     * @brief 直線クラス
     */
    struct Line
    {
        Vector2d p0, p1;

        Line() = default;
        constexpr Line(const Vector2d& p0, const Vector2d& p1): p0(p0), p1(p1) {}

        void set(const Vector2d& p0_, const Vector2d& p1_) {p0 = p0_; p1 = p1_;}

        constexpr float length() const { return (p1-p0).norm(); }
        
        constexpr float angle() const { return (p1-p0).angle(); }
        
        constexpr Vector2d lerp(const float t) const { return Vector2d::lerp(p0, p1, t); }
    };

    /**
     * @brief 長方形クラス(回転は考えない)
     */
    struct Rect
    {
        Vector2d pos; // 原点側の頂点座標
        Vector2d size;
        
        Rect() = default;
        constexpr Rect(const Vector2d& pos, const Vector2d& size): pos(pos), size(size) {}
        static constexpr Rect gen_center(const Vector2d& center_pos, const Vector2d& size)
        {
            return Rect(center_pos-size/2, size);
        }

        void set(const Vector2d& pos_, const Vector2d& size_) { pos = pos_; size = size_; }
        void set_center(const Vector2d& pos_, const Vector2d& size_) 
        { 
            pos = pos_ - size_/2; 
            size = size_; 
        }

        constexpr Vector2d center() const { return pos + 0.5f*size; }

        constexpr bool has_area() const
        {
            return !approx_zero(area());
        }

        constexpr float area() const
        {
            return size.x*size.y;
        }

        constexpr std::array<Vector2d, 4> vertex() const
        {
            Vector2d tv(size.x/2, size.y/2);
            return {
                center() + tv,
                center() + tv.nxy(),
                center() - tv,
                center() + tv.xny()
            };
        }

        constexpr std::array<Line, 4> outline() const
        {
            const auto vtx = vertex();
            return {
                Line{vtx[0], vtx[1]},
                Line{vtx[1], vtx[2]},
                Line{vtx[2], vtx[3]},
                Line{vtx[3], vtx[0]}
            };
        }

        constexpr Quad as_quad() const;
        constexpr Quad get_rotated(float angle) const;
    };

    /**
     * @brief 四角形クラス
     */
    struct Quad
    {
        Vector2d p0, p1, p2, p3;

        Quad() = default;
        constexpr Quad(const std::array<Vector2d, 4> &points): p0(points[0]), p1(points[1]), p2(points[2]), p3(points[3]) {}
        constexpr Quad(const Vector2d &p0, const Vector2d &p1, const Vector2d &p2, const Vector2d &p3): p0(p0), p1(p1), p2(p2), p3(p3) {} 

        void set(const Vector2d &p0_, const Vector2d &p1_, const Vector2d &p2_, const Vector2d &p3_)
        {
            p0 = p0_;
            p1 = p1_;
            p2 = p2_;
            p3 = p3_;
        }

        constexpr bool has_area() const
        {
            return !approx_zero(area());
        }

        constexpr float area() const
        {
            // 三角形の面積2個
            // 01 02
            const float a1 = std::abs((p2.x - p0.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y));

            // 31 32
            const float a2 = std::abs((p2.x - p3.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p2.y - p3.y));
            return 0.5*(a1 + a2);
        }
        
        constexpr std::array<Vector2d, 4> vertex() const
        {
            return {p0, p1, p2, p3};
        }

        constexpr std::array<Line, 4> outline() const
        {
            const auto vtx = vertex();
            return {
                Line{vtx[0], vtx[1]},
                Line{vtx[1], vtx[2]},
                Line{vtx[2], vtx[3]},
                Line{vtx[3], vtx[0]}
            };
        }
    };

    /**
     * @brief 三角形クラス
     */
    struct Triangle
    {
        Vector2d p0, p1, p2;

        Triangle() = default;
        // constexpr Triangle(const std::array<Vector2d, 3> &points): points(points) {}
        constexpr Triangle(const Vector2d &p0, const Vector2d &p1, const Vector2d &p2): p0(p0), p1(p1), p2(p2) {} 

        void set(const Vector2d &p0_, const Vector2d &p1_, const Vector2d &p2_)
        {
            p0 = p0_;
            p1 = p1_;
            p2 = p2_;
        }

        constexpr bool has_area() const
        {
            return !approx_zero(area());
        }

        constexpr float area() const
        {
            return std::abs((p2.x - p0.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y)) * 0.5;
        }
        
        constexpr std::array<Vector2d, 3> vertex() const
        {
            return {p0, p1, p2};
        }

        constexpr std::array<Line, 3> outline() const
        {
            const auto vtx = vertex();
            return {
                Line{vtx[0], vtx[1]},
                Line{vtx[1], vtx[2]},
                Line{vtx[2], vtx[0]}
            };
        }
    };

    /**
     * @brief 円クラス
     */
    struct Circle
    {
        Vector2d center;
        float r;

        Circle() = default;
        constexpr Circle(const Vector2d& center, const float r): center(center), r(r) {}

        constexpr bool has_area() const
        {
            return !approx_zero(area());
        }

        constexpr float area() const
        {
            return square(r)*PI;
        }
        
        constexpr Vector2d angle_pos(const float theta) const {
            return center + Vector2d(r*std::cos(theta), r*std::sin(theta));
        }
    };
}

#include "./shape.ipp"
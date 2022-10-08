---
title: include/cpp_robotics/path_planning/spline.hpp

---

# include/cpp_robotics/path_planning/spline.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |
| **[cpp_robotics::spline](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/)** <br>スプライン曲線用関数郡  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::spline::spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/)**  |
| class | **[cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)** <br>2次元のスプライン曲線のインターフェイスクラス  |
| class | **[cpp_robotics::CatumullRom2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CatumullRom2D/)** <br>Catumull曲線  |
| class | **[cpp_robotics::CubicSpline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CubicSpline/)** <br>3次スプライン曲線  |




## Source code

```cpp
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

#include <cmath>
#include <vector>

#include "../utility/math_utils.hpp"
#include "../vector/vector2.hpp"
#include "../vector/vector4.hpp"

namespace cpp_robotics
{

namespace spline
{
    struct spline_c
    {
        Vector4d xb, yb;
    };

    spline_c bezier_spline(const Vector2d &p0, const Vector2d &p1, const Vector2d &p2, const Vector2d &p3)
    {
        return {
            Vector4d{p0.x, p1.x, p2.x, p3.x},
            Vector4d{p0.y, p1.y, p2.y, p3.y}};
    }

    spline_c hermite_spline(const Vector2d &p0, const Vector2d &p1, const Vector2d &v0, const Vector2d &v1)
    {
        Vector2d bp1 = p0 + (1.0 / 3.0) * v0;
        Vector2d bp2 = p1 - (1.0 / 3.0) * v1;

        return bezier_spline(p0, bp1, bp2, p1);
    }

    spline_c catumull_spline(const Vector2d &p0, const Vector2d &p1, const Vector2d &p2, const Vector2d &p3)
    {
        Vector2d bp1 = p1 + (1.0 / 6.0) * (p2 - p0);
        Vector2d bp2 = p2 - (1.0 / 6.0) * (p3 - p1);

        return bezier_spline(p1, bp1, bp2, p2);
    }

    // f(t) = a t^3 + b t^2 + c t + d -> bezier
    spline_c cubic_function_to_bezier(const Vector2d &a, const Vector2d &b, const Vector2d &c, const Vector2d &d)
    {
        Vector2d bp1 = d + (1.0 / 3.0) * c;
        Vector2d bp2 = (1.0 / 3.0) * b + (2.0 / 3.0) * c + d;
        Vector2d bp3 = a + b + c + d;

        return bezier_spline(d, bp1, bp2, bp3);
    }

    Vector4d bezier_weight(const double t)
    {
        double s = 1.0 - t;

        double t2 = t * t;
        double t3 = t2 * t;

        double s2 = s * s;
        double s3 = s2 * s;

        return Vector4d(s3, 3.0 * s2 * t, 3.0 * s * t2, t3);
    }

    Vector4d bezier_weight(const Vector4d t)
    {
        return Vector4d(
            t.x - 3.0 * t.y + 3.0 * t.z - t.w,
            3.0 * t.y - 6.0 * t.z + 3.0 * t.w,
            3.0 * t.z - 3.0 * t.w,
            t.w);
    }

    inline Vector2d evaluate(const spline_c &spline, const Vector4d &w)
    {
        return {
            Vector4d::dot(spline.xb, w),
            Vector4d::dot(spline.yb, w)};
    }

    Vector2d position(const spline_c &spline, double t)
    {
        return evaluate(spline, bezier_weight(t));
    }

    Vector2d velocity(const spline_c &spline, double t)
    {
        Vector4d dt(0.0, 1.0, 2.0 * t, 3.0 * t * t);
        return evaluate(spline, bezier_weight(dt));
    }

    Vector2d acceleration(const spline_c &spline, double t)
    {
        Vector4d dt(0.0, 0.0, 2.0, 6.0 * t);
        return evaluate(spline, bezier_weight(t));
    }

    inline void split(const Vector4d &spline, Vector4d &spline0, Vector4d &spline1, double t)
    {
        // assumption: seg = (P0, P1, P2, P3)
        double q0 = lerp(spline.x, spline.y, t);
        double q1 = lerp(spline.y, spline.z, t);
        double q2 = lerp(spline.z, spline.w, t);

        double r0 = lerp(q0, q1, t);
        double r1 = lerp(q1, q2, t);

        double s0 = lerp(r0, r1, t);

        double sx = spline.x; // support aliasing
        double sw = spline.w;

        spline0 = Vector4d(sx, q0, r0, s0);
        spline1 = Vector4d(s0, r1, q2, sw);
    }

    // Optimised for t=0.5
    inline void split(const Vector4d &spline, Vector4d &spline0, Vector4d &spline1)
    {
        double q0 = (spline.x + spline.y) * 0.5; // x + y / 2
        double q1 = (spline.y + spline.z) * 0.5; // y + z / 2
        double q2 = (spline.z + spline.w) * 0.5; // z + w / 2

        double r0 = (q0 + q1) * 0.5; // x + 2y + z / 4
        double r1 = (q1 + q2) * 0.5; // y + 2z + w / 4

        double s0 = (r0 + r1) * 0.5; // q0 + 2q1 + q2 / 4 = x+y + 2(y+z) + z+w / 8 = x + 3y + 3z + w

        double sx = spline.x; // support aliasing
        double sw = spline.w;

        spline0 = Vector4d(sx, q0, r0, s0);
        spline1 = Vector4d(s0, r1, q2, sw);
    }

    void split(const spline_c& spline, spline_c& spline0, spline_c& spline1)
    {
        split(spline.xb, spline0.xb, spline1.xb);
        split(spline.yb, spline0.yb, spline1.yb);
    }

    void split(const spline_c& spline, spline_c& spline0, spline_c& spline1, double t)
    {
        split(spline.xb, spline0.xb, spline1.xb, t);
        split(spline.yb, spline0.yb, spline1.yb, t);
    }

    double length_estimate(const spline_c &s, double *error)
    {
        // Our convex hull is p0, p1, p2, p3, so p0_p3 is our minimum possible length, and p0_p1 + p1_p2 + p2_p3 our maximum.
        double d03 = square(s.xb.x - s.xb.w) + square(s.yb.x - s.yb.w);

        double d01 = square(s.xb.x - s.xb.y) + square(s.yb.x - s.yb.y);
        double d12 = square(s.xb.y - s.xb.z) + square(s.yb.y - s.yb.z);
        double d23 = square(s.xb.z - s.xb.w) + square(s.yb.z - s.yb.w);

        double minLength = std::sqrt(d03);
        double maxLength = std::sqrt(d01) + std::sqrt(d12) + std::sqrt(d23);

        minLength *= 0.5;
        maxLength *= 0.5;

        *error = maxLength - minLength;
        return minLength + maxLength;
    }

    double length(const spline_c &s, double maxError)
    {
        double error;
        double len = length_estimate(s, &error);

        if (error > maxError)
        {
            spline_c s0;
            spline_c s1;

            split(s, s0, s1);

            return length(s0, maxError) + length(s1, maxError);
        }

        return len;
    }

    double length(const spline_c &s, double t0, double t1, double maxError)
    {
        assert(t0 >= 0.0 && t0 < 1.0);
        assert(t1 >= 0.0 && t1 <= 1.0);
        assert(t0 <= t1);

        spline_c s0, s1;

        if (t0 == 0.0)
        {
            if (t1 == 1.0)
                return length(s, maxError);

            split(s, s0, s1, t1);
            return length(s0, maxError);
        }
        else
        {
            split(s, s0, s1, t0);

            if (t1 == 1.0)
                return length(s1, maxError);

            split(s1, s0, s1, (t1 - t0) / (1.0 - t0));
            return length(s0, maxError);
        }
    }

    double curvature(const spline_c &spline, double t)
    {
        Vector2d v = velocity(spline, t);
        Vector2d a = acceleration(spline, t);

        double avCrossLen = std::abs(v.x * a.y - v.y * a.x);
        double vLen = v.norm();

        if (vLen == 0.0)
            return 1e10;

        return avCrossLen / (vLen * vLen * vLen);
    }
} // namespace spline

class Spline2D
{
public:
    Spline2D() = default;
    
    bool is_empty()
    {
        return _is_empty;
    }

    size_t size()
    {
        return _size;
    }

    size_t point_num()
    {
        return size()+1;
    }

    double length()
    {
        return _all_length;
    }

    double length(size_t i)
    {
        if(i >= size())
            return 0;
        
        return _spline[i].length;
    }

    Vector2d position(double t)
    {
        assert(_is_empty == false);
        assert(t >= 0);
        assert(t <= static_cast<double>(size()));
        
        segment_info_t segment = get_segmet_idx(t);
        return spline::position(_spline[segment.i].coeff, segment.t);
    }

    Vector2d velocity(double t)
    {
        assert(_is_empty == false);
        assert(t >= 0);
        assert(t <= static_cast<double>(size()));
        
        size_t i = std::floor(t);
        t -= static_cast<double>(i);
        return spline::velocity(_spline[i].coeff, t);
    }

    Vector2d acceleration(double t)
    {
        assert(_is_empty == false);
        assert(t >= 0);
        assert(t <= static_cast<double>(size()));
        
        size_t i = std::floor(t);
        t -= static_cast<double>(i);
        return spline::acceleration(_spline[i].coeff, t);
    }

protected:
    struct segment_t
    {
        spline::spline_c coeff;
        double length;
    };
    
    struct segment_info_t
    {
        size_t i;
        double t;
    };
    
    segment_info_t get_segmet_idx(const double t)
    {
        segment_info_t result;
        result.i = std::min(static_cast<size_t>(std::floor(t)), size()-1);
        result.t = t - static_cast<double>(result.i);
        return result;
    }

    std::vector<segment_t> _spline;
    bool _is_empty;
    size_t _size;
    double _all_length;
};

class CatumullRom2D : public Spline2D
{
public:
    CatumullRom2D(std::vector<Vector2d>& points, const double error = 0.1)
    {
        const size_t p_size = points.size();
        
        _is_empty = false;
        switch (p_size)
        {
            case 0:
                _is_empty = true;
                return;
            case 1:
                {
                    Vector2d& p0 = points[0];
                    _spline.push_back({spline::catumull_spline(p0, p0, p0, p0), 0});
                    return;
                }
            case 2:
                _size = 1;
                _spline.resize(_size);
                calcu_segment(_spline[0], points, error, 0, 0, 0, 1, 1);
                _all_length = _spline[0].length;
                return;
        }

        _size = p_size - 1;
        _spline.resize(_size);
        
        calcu_segment(_spline[0], points, error, 0, 0, 0, 1, 2);
        for (size_t i = 0; i < p_size - 3; i++)
        {
            calcu_segment(_spline[i+1], points, error, i, 0, 1, 2, 3);
        }

        calcu_segment(_spline[_size-1], points, error, p_size-3, 0, 1, 2, 2);

        _all_length = 0;
        for(auto& seg : _spline)
        {
            _all_length += seg.length;
        }
    }

private:
    void calcu_segment(segment_t& seg, std::vector<Vector2d>& points, const double error, const size_t start, const size_t i0 = 0, const size_t i1 = 1, const size_t i2 = 2, const size_t i3 = 3)
    {
        Vector2d &p0 = points[start + i0];
        Vector2d &p1 = points[start + i1];
        Vector2d &p2 = points[start + i2];
        Vector2d &p3 = points[start + i3];
        
        seg.coeff = spline::catumull_spline(p0, p1, p2, p3);
        seg.length = spline::length(seg.coeff, error);
    }
};

class CubicSpline : public Spline2D
{
public:
    CubicSpline(std::vector<Vector2d>& points, const double error = 0.1)
    {
        const size_t p_size = points.size();
        std::vector<double> w;

        _is_empty = false;
        if(p_size < 2)
        {
            _is_empty = true;
            return;
        }

        _size = p_size - 1;
        _spline.resize(p_size);
        w.resize(p_size);

        for(size_t xy = 0; xy < 2; xy++)
        {            
            // 0次の係数
            for(size_t i = 0; i <= _size; i++)
            {
                spline(i, xy).x = p(points, i, xy);
            }
            
            // 2次の係数
            spline(0, xy).z = spline(_size, xy).z = 0.0;
            for(size_t i = 1; i < _size; i++)
            {
                spline(i, xy).z = 3.0 * (spline(i-1, xy).x - 2.0 * spline(i, xy).x + spline(i+1, xy).x);
            }
            // 左下消去
            w[0] = 0.0;
            for(size_t i = 1; i < _size; i++)
            {
                double temp = 4.0 - w[i-1];
                spline(i, xy).z = (spline(i, xy).z - spline(i-1, xy).z)/temp;
                w[i] = 1.0 / temp;
            }
                
            // 右下消去
            for(size_t i = _size-1; i > 0; i--) {
                spline(i, xy).z = spline(i, xy).z - spline(i+1, xy).z * w[i];
            }
                
            // 1次と3次の係数
            spline(_size, xy).y = spline(_size, xy).w = 0.0;
            for(size_t i = 0; i < _size; i++)
            {
                spline(i, xy).w = ( spline(i+1, xy).z - spline(i, xy).z) / 3.0;
                spline(i, xy).y = spline(i+1, xy).x - spline(i, xy).x - spline(i, xy).z - spline(i, xy).w;
            }
        }
        // 最後のセグメントは最後の制御点一点ようなので消しておく
        _spline.erase(_spline.begin()+_spline.size()-1);

        _all_length = 0;
        for(auto& seg : _spline)
        {
            auto c = seg.coeff;
            seg.coeff = spline::cubic_function_to_bezier(
                Vector2d(c.xb.w, c.yb.w),
                Vector2d(c.xb.z, c.yb.z),
                Vector2d(c.xb.y, c.yb.y),
                Vector2d(c.xb.x, c.yb.x)
            );
            seg.length = spline::length(seg.coeff, error);
            _all_length += seg.length;
        }
    }

private:
    Vector4d& spline(size_t i, size_t xy)
    {
        if (xy == 0)
            return _spline[i].coeff.xb;
        else
            return _spline[i].coeff.yb;
    }

    double& p(std::vector<Vector2d>& points, size_t i, size_t xy)
    {
        if (xy == 0)
            return points[i].x;
        else
            return points[i].y;
    }
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900

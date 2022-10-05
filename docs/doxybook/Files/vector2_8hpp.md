---
title: include/cpp_robotics/vector/vector2.hpp

---

# include/cpp_robotics/vector/vector2.hpp

 [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)** <br>2次元のベクトル  |
| struct | **[cpp_robotics::Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)** <br>2次元のベクトル  |

## Detailed Description


**Author**: Takumi Odashima ([Kotakkucu@gmail.com](mailto:Kotakkucu@gmail.com)) 

**Date**: 2021-01-25

**Copyright**: Copyright (c) 2021 



## Source code

```cpp

#pragma once

#include <cmath>
#include <cassert>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{
    template<typename FLOATING_TYPE>
    struct Vector2;
    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;

    template<typename FLOATING_TYPE>
    struct Vector2
    {
        using value_type = FLOATING_TYPE;
        value_type x, y;

        Vector2() = default;

        constexpr Vector2(value_type vx, value_type vy) : x(vx), y(vy) {}

        constexpr Vector2(const Vector2&) = default;

        constexpr void set(const value_type vx, const value_type vy)
        {
            x = vx;
            y = vy;
        }

        void set_polar(const value_type radius, const value_type theta)
        {
            x = radius * std::cos(theta);
            y = radius * std::sin(theta);
        }

        constexpr value_type dot(const Vector2 &v) const
        {
            return (x * v.x + y * v.y);
        }

        constexpr value_type cross(const Vector2 &v) const
        {
            return (x * v.y - y * v.x);
        }
        
        constexpr value_type norm_sq() const
        {
            return dot(*this);
        }

        constexpr value_type norm() const { return std::sqrt(norm_sq()); }

        void normalize() { *this /= norm(); }
        

        
        constexpr value_type angle() const { return std::atan2(y, x); }
        
        constexpr Vector2 get_normalized()
        {
            Vector2 v = *this;
            v /= v.norm();
            return v;
        }
        
        void rotate(const value_type theta)
        {
            Vector2 v = *this;
            x = v.x * std::cos(theta) - v.y * std::sin(theta);
            y = v.x * std::sin(theta) + v.y * std::cos(theta);
        }

        constexpr Vector2 get_rotated(const value_type theta) const
        {
            Vector2 v = {
                x * std::cos(theta) - y * std::sin(theta),
                x * std::sin(theta) + y * std::cos(theta)
            };

            return v;
        }

        constexpr bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y);
        }

        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y);
        }

        constexpr Vector2 yx() const
        {
            return {y, x};
        }

        constexpr Vector2 nyx() const
        {
            return {-y, x};
        }

        constexpr Vector2 ynx() const
        {
            return {y, -x};
        }

        constexpr Vector2 nxy() const
        {
            return {-x, y};
        }

        constexpr Vector2 xny() const
        {
            return {x, -y};
        }

        static constexpr value_type dot(const Vector2 &a, const Vector2 &b)
        {
            return a.dot(b);
        }

        static constexpr value_type angle(const Vector2 &a, const Vector2 &b)
        {
            value_type value = a.dot(b) / (a.norm() * b.norm());
            return std::acos(value);
        }

        static constexpr value_type distance(const Vector2 &a, const Vector2 &b)
        {
            return (b-a).norm();
        }

        static constexpr Vector2 lerp(const Vector2 &a, const Vector2 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t),
                    cpp_robotics::lerp(a.y, b.y, t)};
        }

        constexpr Vector2 lerp(const Vector2 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }
        
        // constatnt vector
        static constexpr Vector2 zero()
        {
            return {0, 0};
        }

        static constexpr Vector2 up()
        {
            return {0, 1};
        }
        
        static constexpr Vector2 down()
        {
            return {0, -1};
        }
        
        static constexpr Vector2 right()
        {
            return {1, 0};
        }
        
        static constexpr Vector2 left()
        {
            return {-1, 0};
        }
        
        constexpr Vector2 operator + () const
        {
            return *this;
        }

        constexpr Vector2 operator - () const
        {
            return {-x, -y};
        }

        constexpr bool operator == (const Vector2& v) const
        {
            return (x == v.x) && (y == v.y);
        }
        
        constexpr bool operator != (const Vector2& v) const
        {
            return !((x == v.x) && (y == v.y));
        }

        constexpr Vector2 operator + (const Vector2& v) const
        {
            return {x + v.x, y + v.y};
        }

        constexpr Vector2 operator - (const Vector2& v) const
        {
            return {x - v.x, y - v.y};
        }
        
        friend constexpr Vector2 operator / (const Vector2& v, const value_type value)
        {
            return {v.x / value, v.y / value};
        }
        
        constexpr Vector2& operator += (const Vector2& v)
        {
            x += v.x;
            y += v.y;
            
            return *this;
        }
        
        constexpr Vector2& operator -= (const Vector2& v)
        {
            x -= v.x;
            y -= v.y;
            
            return *this;
        }
        
        constexpr Vector2& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            
            return *this;
        }
        
        constexpr Vector2& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            
            return *this;
        }
        
        value_type &operator [] (const size_t index)
        {
            assert(index < 2);
            if(index == 0) 
                return x;
            return y;
        }

        constexpr value_type operator [] (const size_t index) const
        {
            assert(index < 2);
            if(index == 0) 
                return x;
            return y;
        }

        template<typename Scaler>
        friend constexpr Vector2 operator *(const Vector2& v, const Scaler s) noexcept
        {
            return {v.x * static_cast<value_type>(s), 
                    v.y * static_cast<value_type>(s)};
        }

        template<typename Scaler>
        friend constexpr Vector2 operator *(const Scaler s, const Vector2& v) noexcept
        {
            return (v * static_cast<value_type>(s));
        }
    };
}
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900

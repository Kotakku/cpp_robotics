---
title: include/cpp_robotics/vector/vector4.hpp

---

# include/cpp_robotics/vector/vector4.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::Vector4](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector4/)** <br>4次元のベクトル  |
| struct | **[cpp_robotics::Vector4](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector4/)** <br>4次元のベクトル  |




## Source code

```cpp

#pragma once

#include <cmath>
#include <cassert>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{   
    template<typename FLOATING_TYPE>
    struct Vector4;
    using Vector4f = Vector4<float>;
    using Vector4d = Vector4<double>;

    template<typename FLOATING_TYPE>
    struct Vector4
    {
        using value_type = FLOATING_TYPE;
        value_type x, y, z, w;

        Vector4() = default;

        constexpr Vector4(value_type vx, value_type vy, value_type vz, value_type vw) : x(vx), y(vy), z(vz), w(vw) {}

        Vector4(const Vector4 &v) = default;

        // function
        void set(value_type vx, value_type vy, value_type vz, value_type vw)
        {
            x = vx;
            y = vy;
            z = vz;
            w = vw;
        }

        constexpr value_type dot(const Vector4 &v) const
        {
            return (x * v.x + y * v.y + z * v.z + w * v.w);
        }

        constexpr value_type norm_sq() const
        {
            return dot(*this);
        }

        value_type norm() { return std::sqrt(norm_sq()); }

        void normalize() { *this /= norm(); }
        
        Vector4 get_normalized()
        {
            Vector4 v = *this;
            v /= v.norm();
            return v;
        }

        constexpr bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y) && approx_zero(z) && approx_zero(w);
        }

        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(z) || std::isnan(w);
        }

        static constexpr value_type dot(const Vector4 &a, const Vector4 &b)
        {
            return a.dot(b);
        }

        static value_type distance(const Vector4 &a, const Vector4 &b)
        {
            return (b-a).norm();
        }

        static constexpr Vector4 lerp(const Vector4 &a, const Vector4 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t), 
                    cpp_robotics::lerp(a.y, b.y, t),
                    cpp_robotics::lerp(a.z, b.z, t),
                    cpp_robotics::lerp(a.w, b.w, t)};
        }

        constexpr Vector4 lerp(const Vector4 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }

        // constant vector

        static constexpr Vector4 zero()
        {
            return {0, 0, 0, 0};
        }

        constexpr Vector4 operator + () const
        {
            return *this;
        }

        constexpr Vector4 operator - () const
        {
            return {-x, -y, -z, -w};
        }
        
        bool operator == (const Vector4& v) const
        {
            return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
        }
        
        bool operator != (const Vector4& v) const
        {
            return !((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w));
        }
        
        constexpr Vector4 operator + (const Vector4& v) const
        {
            return {x + v.x, y + v.y, z + v.z, w + v.w};
        }
        
        constexpr Vector4 operator - (const Vector4& v) const
        {
            return {x - v.x, y - v.y, z - v.z, w - v.w};
        }
        
        constexpr Vector4 operator * (const value_type value) const
        {
            return {x * value, y * value, z * value, w * value};
        }
        
        constexpr Vector4 operator / (const value_type value) const
        {
            return {x / value, y / value, z / value, w / value};
        }
        
        constexpr Vector4& operator += (const Vector4& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            
            return *this;
        }
        
        constexpr Vector4& operator -= (const Vector4& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            
            return *this;
        }
        
        constexpr Vector4& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            z *= value;
            w *= value;
            
            return *this;
        }
        
        constexpr Vector4& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            z /= value;
            w /= value;
            
            return *this;
        }
        
        value_type &operator [](const int index)
        {
            assert(0 <= index && index < 4);
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            return w;
        }

        constexpr value_type operator [](const int index) const
        {
            assert(0 <= index && index < 4);
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            return w;
        }
        
        template<typename Scaler>
        friend constexpr Vector4 operator *(Scaler s, Vector4 v) noexcept
        {
            return (v * static_cast<value_type>(s));
        }
    };
}
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

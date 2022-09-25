---
title: include/cpp_robotics/vector/vector3.hpp

---

# include/cpp_robotics/vector/vector3.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::Vector3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector3/)** <br>3次元のベクトル  |
| struct | **[cpp_robotics::Vector3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector3/)** <br>3次元のベクトル  |




## Source code

```cpp

#pragma once

#include <cmath>
#include <cassert>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{   
    template<typename FLOATING_TYPE>
    struct Vector3;
    using Vector3f = Vector3<float>;
    using Vector3d = Vector3<double>;

    template<typename FLOATING_TYPE>
    struct Vector3
    {
        using value_type = FLOATING_TYPE;
        value_type x, y, z;

        Vector3() = default;

        constexpr Vector3(value_type vx, value_type vy, value_type vz) : x(vx), y(vy), z(vz) {}

        Vector3(const Vector3 &v) = default;

        // function
        void set(value_type vx, value_type vy, value_type vz)
        {
            x = vx;
            y = vy;
            z = vz;
        }

        constexpr value_type dot(const Vector3 &v) const
        {
            return (x * v.x + y * v.y + z * v.z);
        }

        constexpr Vector3 cross(const Vector3 &v) const
        {
            return {(y * v.z) - (z * v.y), z * v.x - x * v.z, x * v.y - y * v.x};
        }

        constexpr value_type norm_sq() const
        {
            return dot(*this);
        }

        value_type norm() { return std::sqrt(norm_sq()); }

        void normalize() { *this /= norm(); }
        
        Vector3 get_normalized()
        {
            Vector3 v = *this;
            v /= v.norm();
            return v;
        }

        constexpr bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y) && approx_zero(z);
        }

        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(z);
        }
        
        static constexpr value_type dot(const Vector3 &a, const Vector3 &b)
        {
            return a.dot(b);
        }

        static value_type distance(const Vector3 &a, const Vector3 &b)
        {
            return (b-a).norm();
        }

        static constexpr Vector3 lerp(const Vector3 &a, const Vector3 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t), 
                    cpp_robotics::lerp(a.y, b.y, t),
                    cpp_robotics::lerp(a.z, b.z, t)};
        }

        constexpr Vector3 lerp(const Vector3 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }

        // constant vector
        static constexpr Vector3 zero()
        {
            return {0, 0, 0};
        }
        
        static constexpr Vector3 forward()
        {
            return {0, 0, 1};
        }
        
        static constexpr Vector3 back()
        {
            return {0, 0, -1};
        }
        
        static constexpr Vector3 up()
        {
            return {0, 1, 0};
        }
        
        static constexpr Vector3 down()
        {
            return {0, -1, 0};
        }
        
        static constexpr Vector3 right()
        {
            return {1, 0, 0};
        }
        
        static constexpr Vector3 left()
        {
            return {-1, 0, 0};
        }
        
        constexpr Vector3 operator + () const
        {
            return *this;
        }

        constexpr Vector3 operator - () const
        {
            return {-x, -y, -z};
        }
        
        bool operator == (const Vector3& v) const
        {
            return (x == v.x) && (y == v.y) && (z == v.z);
        }
        
        bool operator != (const Vector3& v) const
        {
            return !((x == v.x) && (y == v.y) && (z == v.z));
        }
        
        constexpr Vector3 operator + (const Vector3& v) const
        {
            return {x + v.x, y + v.y, z + v.z};
        }
        
        constexpr Vector3 operator - (const Vector3& v) const
        {
            return {x - v.x, y - v.y, z - v.z};
        }
        
        friend constexpr Vector3 operator / (const Vector3& v, const value_type value)
        {
            return {v.x / value, v.y / value, v.z / value};
        }
        
        constexpr Vector3& operator += (const Vector3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            
            return *this;
        }
        
        constexpr Vector3& operator -= (const Vector3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            
            return *this;
        }
        
        constexpr Vector3& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            z *= value;
            
            return *this;
        }
        
        constexpr Vector3& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            z /= value;
            
            return *this;
        }
        
        value_type &operator [](const int index)
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return z;
        }

        constexpr value_type operator [](const int index) const
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return z;
        }

        template<typename Scaler>
        friend constexpr Vector3 operator *(const Vector3& v, const Scaler s) noexcept
        {
            return {v.x * static_cast<value_type>(s), 
                    v.y * static_cast<value_type>(s),
                    v.z * static_cast<value_type>(s)};
        }
        
        template<typename Scaler>
        friend constexpr Vector3 operator *(const Scaler s, const Vector3& v) noexcept
        {
            return (v * static_cast<value_type>(s));
        }
    };
}
```


-------------------------------

Updated on 2022-09-25 at 23:50:01 +0900

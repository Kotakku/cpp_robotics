---
title: include/cpp_robotics/vector/transform.hpp

---

# include/cpp_robotics/vector/transform.hpp

 [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)** <br>2次元のロボットの座標を扱うクラス  |
| struct | **[cpp_robotics::Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)** <br>2次元のロボットの座標を扱うクラス  |

## Detailed Description


**Author**: Takumi Odashima ([Kotakkucu@gmail.com](mailto:Kotakkucu@gmail.com)) 

**Date**: 2021-01-25

**Copyright**: Copyright (c) 2021 



## Source code

```cpp

#pragma once

#include "./vector2.hpp"

namespace cpp_robotics
{
    template<typename FLOATING_TYPE>
    struct Transform;
    using Transformf = Transform<float>;
    using Transformd = Transform<double>;

    template<typename FLOATING_TYPE>
    struct Transform //
    {
        using value_type = FLOATING_TYPE;
        using vector_type = Vector2<value_type>;
        value_type x, y, theta;

        // コンストラクタ
        Transform() = default;

        constexpr Transform(const value_type _x, const value_type _y, const value_type _theta) : x(_x), y(_y), theta(_theta) {}

        constexpr Transform(const vector_type& _xy, const value_type _theta) : x(_xy.x), y(_xy.y), theta(_theta) {}
        
        constexpr Transform(const Transform &) = default;

        constexpr vector_type make_vector2() const
        {
            return vector_type(x, y);
        }

        constexpr void set(value_type vx, value_type vy, value_type vtheta) 
        {
            x = vx;
            y = vy;
            theta = vtheta;
        }
        
        // origin-xy距離
        value_type distance() const
        {
            return vector_type(x, y).norm();
        }
        
        // 回転
        void rotate(const value_type theta)
        {
            rotate(vector_type::zero(), theta);
        }
        
        void rotate(const value_type rotX, const value_type rotY, const value_type theta)
        {
            rotate(vector_type(rotX, rotY), theta); 
        }

        void rotate(vector_type rotPos, const value_type theta) 
        { 
            vector_type p = make_vector2() - rotPos;
            p.rotate(theta);
            x = p.x + rotPos.x;
            y = p.y + rotPos.y;
        }
        
        // 極座標指定
        void set_polar(const value_type radius, const value_type angle, const value_type robotTheta)
        {
            x = radius * std::cos(angle);
            y = radius * std::sin(angle);
            theta = robotTheta;
        }

        bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y) && approx_zero(theta);
        }

        bool is_zero_pos() const
        {
            return x == 0.0 && y == 0.0;
        }

        bool is_zero_angle() const
        {
            return theta == 0.0;
        }

        bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(theta);
        }
        
        static constexpr value_type get_angle(Transform &a, Transform &b) { return b.theta - a.theta; };
        
        static value_type get_distance(Transform &a, Transform &b)
        {
            return (b-a).distance();
        }

        static Transform get_lerp(Transform &a, Transform &b, const value_type t)
        {
            return {lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.theta, b.theta, t)};
        }
        
        // constatnt vector
        static constexpr Transform origin() 
        {
            return {0.0, 0.0, 0.0};
        }
        
        constexpr bool operator == (const Transform v) const
        {
            return (x == v.x) && (y == v.y) && (theta == v.theta);
        }
        
        constexpr bool operator != (const Transform& v) const
        {
            return !((x == v.x) && (y == v.y) && (theta == v.theta));
        }
        
        constexpr Transform operator + (const Transform& v) const 
        {
            return {x + v.x, y + v.y, theta + v.theta};
        }
        
        constexpr Transform operator - (const Transform& v) const
        {
            return {x - v.x, y - v.y, theta - v.theta};
        }
        
        constexpr Transform& operator += (const Transform& v)
        {
            x += v.x;
            y += v.y;
            theta += v.theta;
            
            return *this;
        }
        
        constexpr Transform& operator -= (const Transform& v)
        {
            x -= v.x;
            y -= v.y;
            theta -= v.theta;
            
            return *this;
        }
        
        // xy
        constexpr Transform operator + (const vector_type& v) const
        {
            return {x + v.x, y + v.y, theta};
        }
        
        constexpr Transform operator - (const vector_type& v) const
        {
            return {x - v.x, y - v.y, theta};
        }
        
        // theta

        constexpr Transform operator + (const value_type angle) const
        {
            return {x, y, theta + angle};
        }
        
        constexpr Transform operator - (const value_type angle) const
        {
            return {x, y, theta - angle};
        }
        
        // xy
        constexpr Transform& operator += (const vector_type& v)
        {
            x += v.x;
            y += v.y;
            
            return *this;
        }
        
        constexpr Transform& operator -= (const vector_type& v)
        {
            x -= v.x;
            y -= v.y;
            
            return *this;
        }

        // theta
        constexpr Transform& operator += (const value_type angle)
        {
            theta += angle;
            
            return *this;
        }
        
        constexpr Transform& operator -= (const value_type angle)
        {
            theta -= angle;
            
            return *this;
        }
        
        constexpr Transform operator * (const value_type value) const
        {
            return {x * value, y * value, theta * value};
        }
        
        constexpr Transform operator / (const value_type value) const
        {
            return {x / value, y / value, theta / value};
        }
        
        constexpr Transform& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            theta *= value;
            
            return *this;
        }
        
        constexpr Transform& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            theta /= value;
            
            return *this;
        }
        
        // index
        value_type &operator [] (const int index)
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return theta;
        }

        constexpr value_type operator [] (const int index) const
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return theta;
        }
    };
}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900

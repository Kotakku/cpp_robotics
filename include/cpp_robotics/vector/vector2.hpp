/**
 * @file vector2.hpp
 * @author Takumi Odashima (Kotakkucu@gmail.com)
 * @brief 
 * @date 2021-01-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <cmath>
#include <cassert>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{
    /**
     * @brief 2次元のベクトル
     * 
     */

    template<typename FLOATING_TYPE>
    struct Vector2;
    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;

    template<typename FLOATING_TYPE>
    struct Vector2
    {
        using value_type = FLOATING_TYPE;
        value_type x, y;

        /**
         * @brief Construct a new Vector 2 object
         * 
         */
        Vector2() = default;

        /**
         * @brief Construct a new Vector 2 object
         * 
         * @param vx 
         * @param vy 
         */
        constexpr Vector2(value_type vx, value_type vy) : x(vx), y(vy) {}

        /**
         * @brief Construct a new Vector 2 object
         * 
         * @param v 
         */
        constexpr Vector2(const Vector2&) = default;

        /**
         * @brief 値の代入
         * 
         * @param vx value_type
         * @param vy 
         */
        constexpr void set(const value_type vx, const value_type vy)
        {
            x = vx;
            y = vy;
        }

        /**
         * @brief 極形式での値の代入
         * 
         * @param radius 半径
         * @param theta 角度[rad]
         */
        void set_polar(const value_type radius, const value_type theta)
        {
            x = radius * std::cos(theta);
            y = radius * std::sin(theta);
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return constexpr value_type 
         */
        constexpr value_type dot(const Vector2 &v) const
        {
            return (x * v.x + y * v.y);
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return constexpr value_type 
         */
        constexpr value_type cross(const Vector2 &v) const
        {
            return (x * v.y - y * v.x);
        }
        
        /**
         * @brief 
         * 
         * @return constexpr value_type 
         */
        constexpr value_type norm_sq() const
        {
            return dot(*this);
        }

        /**
         * @brief ベクトルの大きさを返す
         * 
         * @return value_type 
         */
        constexpr value_type norm() const { return std::sqrt(norm_sq()); }

        /**
         * @brief 単位ベクトル化
         * 
         */
        void normalize() { *this /= norm(); }
        

        
        /**
         * @brief ベクトルの角度を返す
         * 
         * @return value_type 
         */
        constexpr value_type angle() const { return std::atan2(y, x); }
        
        /**
         * @brief 単位ベクトル化したベクトルを返す
         * 
         * @return Vector2 
         */
        constexpr Vector2 get_normalized()
        {
            Vector2 v = *this;
            v /= v.norm();
            return v;
        }
        
        /**
         * @brief 原点中心に回転
         * 
         * @param theta [rad]
         */
        void rotate(const value_type theta)
        {
            Vector2 v = *this;
            x = v.x * std::cos(theta) - v.y * std::sin(theta);
            y = v.x * std::sin(theta) + v.y * std::cos(theta);
        }

        /**
         * @brief 原点中心に回転させたベクトルを返す
         * 
         * @param theta 
         * @return Vector2 
         */
        constexpr Vector2 get_rotated(const value_type theta) const
        {
            Vector2 v = {
                x * std::cos(theta) - y * std::sin(theta),
                x * std::sin(theta) + y * std::cos(theta)
            };

            return v;
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        constexpr bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y);
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y);
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector2 
         */
        constexpr Vector2 yx() const
        {
            return {y, x};
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector2 
         */
        constexpr Vector2 nyx() const
        {
            return {-y, x};
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector2 
         */
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

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @return constexpr value_type 
         */
        static constexpr value_type dot(const Vector2 &a, const Vector2 &b)
        {
            return a.dot(b);
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @return value_type 
         */
        static constexpr value_type angle(const Vector2 &a, const Vector2 &b)
        {
            value_type value = a.dot(b) / (a.norm() * b.norm());
            return std::acos(value);
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @return value_type 
         */
        static constexpr value_type distance(const Vector2 &a, const Vector2 &b)
        {
            return (b-a).norm();
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @param t 
         * @return constexpr Vector2 
         */
        static constexpr Vector2 lerp(const Vector2 &a, const Vector2 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t),
                    cpp_robotics::lerp(a.y, b.y, t)};
        }

        /**
         * @brief 
         * 
         * @param b 
         * @param t 
         * @return constexpr Vector2 
         */
        constexpr Vector2 lerp(const Vector2 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }
        
        // constatnt vector
        /**
         * @brief 
         * 
         * @return const Vector2 
         */
        static constexpr Vector2 zero()
        {
            return {0, 0};
        }

        /**
         * @brief 
         * 
         * @return const Vector2 
         */
        static constexpr Vector2 up()
        {
            return {0, 1};
        }
        
        /**
         * @brief 
         * 
         * @return const Vector2 
         */
        static constexpr Vector2 down()
        {
            return {0, -1};
        }
        
        /**
         * @brief 
         * 
         * @return const Vector2 
         */
        static constexpr Vector2 right()
        {
            return {1, 0};
        }
        
        /**
         * @brief 
         * 
         * @return const Vector2 
         */
        static constexpr Vector2 left()
        {
            return {-1, 0};
        }
        
        /**
         * @brief 
         * 
         * @return constexpr Vector2 
         */
        constexpr Vector2 operator + () const
        {
            return *this;
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector2 
         */
        constexpr Vector2 operator - () const
        {
            return {-x, -y};
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        constexpr bool operator == (const Vector2& v) const
        {
            return (x == v.x) && (y == v.y);
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        constexpr bool operator != (const Vector2& v) const
        {
            return !((x == v.x) && (y == v.y));
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return Vector2 
         */
        constexpr Vector2 operator + (const Vector2& v) const
        {
            return {x + v.x, y + v.y};
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return Vector2 
         */
        constexpr Vector2 operator - (const Vector2& v) const
        {
            return {x - v.x, y - v.y};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector2 
         */

        friend constexpr Vector2 operator / (const Vector2& v, const value_type value)
        {
            return {v.x / value, v.y / value};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector2& 
         */
        constexpr Vector2& operator += (const Vector2& v)
        {
            x += v.x;
            y += v.y;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector2& 
         */
        constexpr Vector2& operator -= (const Vector2& v)
        {
            x -= v.x;
            y -= v.y;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector2& 
         */
        constexpr Vector2& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector2& 
         */
        constexpr Vector2& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param index 
         * @return value_type& 
         */
        value_type &operator [] (const size_t index)
        {
            assert(index < 2);
            if(index == 0) 
                return x;
            return y;
        }

        /**
         * @brief 
         * 
         * @param index 
         * @return constexpr value_type 
         */
        constexpr value_type operator [] (const size_t index) const
        {
            assert(index < 2);
            if(index == 0) 
                return x;
            return y;
        }

        /**
         * @brief 
         * 
         * @tparam Scaler 
         * @param v 
         * @param s 
         * @return constexpr Vector2 
         */
        template<typename Scaler>
		friend constexpr Vector2 operator *(const Vector2& v, const Scaler s) noexcept
		{
			return {v.x * static_cast<value_type>(s), 
                    v.y * static_cast<value_type>(s)};
		}

        /**
         * @brief 
         * 
         * @tparam Scaler 
         * @param s 
         * @param v 
         * @return constexpr Vector2 
         */
        template<typename Scaler>
		friend constexpr Vector2 operator *(const Scaler s, const Vector2& v) noexcept
		{
			return (v * static_cast<value_type>(s));
		}
    };
}

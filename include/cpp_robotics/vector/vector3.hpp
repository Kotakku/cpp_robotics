/**
 * @file Vector3.hpp
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
     * @brief 3次元のベクトル
     *
     */

    template<typename FLOATING_TYPE>
    struct Vector3;
    using Vector3f = Vector3<float>;
    using Vector3d = Vector3<double>;

    template<typename FLOATING_TYPE>
    struct Vector3
    {
        using value_type = FLOATING_TYPE;
        value_type x, y, z;

        /**
         * @brief Construct a new Vector 3 object
         * 
         */
        Vector3() = default;

        /**
         * @brief Construct a new Vector 3 object
         * 
         * @param vx 
         * @param vy 
         * @param vz 
         */
        constexpr Vector3(value_type vx, value_type vy, value_type vz) : x(vx), y(vy), z(vz) {}

        /**
         * @brief Construct a new Vector 3 object
         * 
         * @param v 
         */
        Vector3(const Vector3 &v) = default;

        // function
        /**
         * @brief 
         * 
         * @param vx 
         * @param vy 
         * @param vz 
         */
        void set(value_type vx, value_type vy, value_type vz)
        {
            x = vx;
            y = vy;
            z = vz;
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return constexpr value_type 
         */
        constexpr value_type dot(const Vector3 &v) const
        {
            return (x * v.x + y * v.y + z * v.z);
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return constexpr Vector3 
         */
        constexpr Vector3 cross(const Vector3 &v) const
        {
            return {(y * v.z) - (z * v.y), z * v.x - x * v.z, x * v.y - y * v.x};
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
         * @brief Get the Magnitude object
         * 
         * @return value_type 
         */
        value_type norm() { return std::sqrt(norm_sq()); }

        /**
         * @brief 単位ベクトル化
         * 
         */
        void normalize() { *this /= norm(); }
        
        /**
         * @brief Get the Normalized object
         * 
         * @return Vector3 
         */
        Vector3 get_normalized()
        {
            Vector3 v = *this;
            v /= v.norm();
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
            return approx_zero(x) && approx_zero(y) && approx_zero(z);
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(z);
        }
        
        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @return constexpr value_type 
         */
        static constexpr value_type dot(const Vector3 &a, const Vector3 &b)
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
        static value_type distance(const Vector3 &a, const Vector3 &b)
        {
            return (b-a).norm();
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @param t 
         * @return constexpr Vector3 
         */
        static constexpr Vector3 lerp(const Vector3 &a, const Vector3 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t), 
                    cpp_robotics::lerp(a.y, b.y, t),
                    cpp_robotics::lerp(a.z, b.z, t)};
        }

        /**
         * @brief 
         * 
         * @param b 
         * @param t 
         * @return constexpr Vector3 
         */
        constexpr Vector3 lerp(const Vector3 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }

        // constant vector
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 zero()
        {
            return {0, 0, 0};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 forward()
        {
            return {0, 0, 1};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 back()
        {
            return {0, 0, -1};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 up()
        {
            return {0, 1, 0};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 down()
        {
            return {0, -1, 0};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 right()
        {
            return {1, 0, 0};
        }
        
        /**
         * @brief 
         * 
         * @return Vector3 
         */
        static constexpr Vector3 left()
        {
            return {-1, 0, 0};
        }
        
        /**
         * @brief 
         * 
         * @return constexpr Vector3 
         */
        constexpr Vector3 operator + () const
        {
            return *this;
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector3 
         */
        constexpr Vector3 operator - () const
        {
            return {-x, -y, -z};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        bool operator == (const Vector3& v) const
        {
            return (x == v.x) && (y == v.y) && (z == v.z);
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        bool operator != (const Vector3& v) const
        {
            return !((x == v.x) && (y == v.y) && (z == v.z));
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector3 
         */
        constexpr Vector3 operator + (const Vector3& v) const
        {
            return {x + v.x, y + v.y, z + v.z};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector3 
         */
        constexpr Vector3 operator - (const Vector3& v) const
        {
            return {x - v.x, y - v.y, z - v.z};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector3 
         */
        friend constexpr Vector3 operator / (const Vector3& v, const value_type value)
        {
            return {v.x / value, v.y / value, v.z / value};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector3& 
         */
        constexpr Vector3& operator += (const Vector3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector3& 
         */
        constexpr Vector3& operator -= (const Vector3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector3& 
         */
        constexpr Vector3& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            z *= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector3& 
         */
        constexpr Vector3& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            z /= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param index 
         * @return value_type& 
         */
        value_type &operator [](const int index)
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return z;
        }

        /**
         * @brief 
         * 
         * @param index 
         * @return constexpr value_type 
         */
        constexpr value_type operator [](const int index) const
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return z;
        }

        /**
         * @brief 
         * 
         * @tparam Scaler 
         * @param v 
         * @param s 
         * @return constexpr Vector3 
         */
        template<typename Scaler>
		friend constexpr Vector3 operator *(const Vector3& v, const Scaler s) noexcept
		{
			return {v.x * static_cast<value_type>(s), 
                    v.y * static_cast<value_type>(s),
                    v.z * static_cast<value_type>(s)};
		}
        
        /**
         * @brief 
         * 
         * @tparam Scaler 
         * @param s 
         * @param v 
         * @return constexpr Vector3 
         */
        template<typename Scaler>
		friend constexpr Vector3 operator *(const Scaler s, const Vector3& v) noexcept
		{
			return (v * static_cast<value_type>(s));
		}
    };
}
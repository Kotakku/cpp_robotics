/**
 * @file Vector4.hpp
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
     * @brief 4次元のベクトル
     *
     */

    template<typename FLOATING_TYPE>
    struct Vector4;
    using Vector4f = Vector4<float>;
    using Vector4d = Vector4<double>;

    template<typename FLOATING_TYPE>
    struct Vector4
    {
        using value_type = FLOATING_TYPE;
        value_type x, y, z, w;

        /**
         * @brief Construct a new Vector 4 object
         * 
         */
        Vector4() = default;

        /**
         * @brief Construct a new Vector 4 object
         * 
         * @param vx 
         * @param vy 
         * @param vz 
         * @param vw
         */
        constexpr Vector4(value_type vx, value_type vy, value_type vz, value_type vw) : x(vx), y(vy), z(vz), w(vw) {}

        /**
         * @brief Construct a new Vector 4 object
         * 
         * @param v 
         */
        Vector4(const Vector4 &v) = default;

        // function
        /**
         * @brief 
         * 
         * @param vx 
         * @param vy 
         * @param vz 
         * @param vw
         * 
         */
        void set(value_type vx, value_type vy, value_type vz, value_type vw)
        {
            x = vx;
            y = vy;
            z = vz;
            w = vw;
        }

        /**
         * @brief 
         * 
         * @param v 
         * @return constexpr value_type 
         */
        constexpr value_type dot(const Vector4 &v) const
        {
            return (x * v.x + y * v.y + z * v.z + w * v.w);
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
         * @return Vector4 
         */
        Vector4 get_normalized()
        {
            Vector4 v = *this;
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
            return approx_zero(x) && approx_zero(y) && approx_zero(z) && approx_zero(w);
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        constexpr bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(z) || std::isnan(w);
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @return constexpr value_type 
         */
        static constexpr value_type dot(const Vector4 &a, const Vector4 &b)
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
        static value_type distance(const Vector4 &a, const Vector4 &b)
        {
            return (b-a).norm();
        }

        /**
         * @brief 
         * 
         * @param a 
         * @param b 
         * @param t 
         * @return constexpr Vector4 
         */
        static constexpr Vector4 lerp(const Vector4 &a, const Vector4 &b, const value_type t)
        {
            return {cpp_robotics::lerp(a.x, b.x, t), 
                    cpp_robotics::lerp(a.y, b.y, t),
                    cpp_robotics::lerp(a.z, b.z, t),
                    cpp_robotics::lerp(a.w, b.w, t)};
        }

        /**
         * @brief 
         * 
         * @param b 
         * @param t 
         * @return constexpr Vector4 
         */
        constexpr Vector4 lerp(const Vector4 &b, const value_type t) const
        {
            return lerp(*this, b, t);
        }

        // constant vector

        /**
         * @brief 
         * 
         * @return Vector4 
         */
        static constexpr Vector4 zero()
        {
            return {0, 0, 0, 0};
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector4 
         */
        constexpr Vector4 operator + () const
        {
            return *this;
        }

        /**
         * @brief 
         * 
         * @return constexpr Vector4 
         */
        constexpr Vector4 operator - () const
        {
            return {-x, -y, -z, -w};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        bool operator == (const Vector4& v) const
        {
            return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        bool operator != (const Vector4& v) const
        {
            return !((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w));
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector4 
         */
        constexpr Vector4 operator + (const Vector4& v) const
        {
            return {x + v.x, y + v.y, z + v.z, w + v.w};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector4 
         */
        constexpr Vector4 operator - (const Vector4& v) const
        {
            return {x - v.x, y - v.y, z - v.z, w - v.w};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector4 
         */
        constexpr Vector4 operator * (const value_type value) const
        {
            return {x * value, y * value, z * value, w * value};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector4 
         */
        constexpr Vector4 operator / (const value_type value) const
        {
            return {x / value, y / value, z / value, w / value};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector4& 
         */
        constexpr Vector4& operator += (const Vector4& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Vector4& 
         */
        constexpr Vector4& operator -= (const Vector4& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector4& 
         */
        constexpr Vector4& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            z *= value;
            w *= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Vector4& 
         */
        constexpr Vector4& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            z /= value;
            w /= value;
            
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
            assert(0 <= index && index < 4);
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            return w;
        }

        /**
         * @brief 
         * 
         * @param index 
         * @return constexpr value_type 
         */
        constexpr value_type operator [](const int index) const
        {
            assert(0 <= index && index < 4);
            if (index == 0) return x;
            if (index == 1) return y;
            if (index == 2) return z;
            return w;
        }
        
        /**
         * @brief 
         * 
         * @tparam Scaler 
         * @param s 
         * @param v 
         * @return constexpr Vector4 
         */
        template<typename Scaler>
		friend constexpr Vector4 operator *(Scaler s, Vector4 v) noexcept
		{
			return (v * static_cast<value_type>(s));
		}
    };
}
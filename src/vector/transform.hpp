/**
 * @file transform.hpp
 * @author Takumi Odashima (Kotakkucu@gmail.com)
 * @brief 
 * @date 2021-01-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "./vector2.hpp"

namespace cpp_robotics
{
    /**
     * @brief 2次元のロボットの座標を扱うクラス
     * 
     */

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
        /**
         * @brief Construct a new Field Vector 2 object
         * 
         */
        Transform() = default;

        /**
         * @brief Construct a new Field Vector 2 object
         * 
         * @param x 
         * @param y 
         * @param theta 
         */
        constexpr Transform(const value_type _x, const value_type _y, const value_type _theta) : x(_x), y(_y), theta(_theta) {}

        /**
         * @brief Construct a new Field Vector 2 object
         * 
         */
        constexpr Transform(const vector_type& _xy, const value_type _theta) : x(_xy.x), y(_xy.y), theta(_theta) {}
        
        /**
         * @brief Construct a new Field Vector 2 object
         * 
         * @param v 
         */
        constexpr Transform(const Transform &) = default;

        /**
         * @brief  xy成分のVector2を生成
         * 
         */
        constexpr vector_type make_vector2() const
        {
            return vector_type(x, y);
        }

        /**
         * @brief 
         * 
         * @param vx 
         * @param vy 
         * @param vtheta 
         */
        constexpr void set(value_type vx, value_type vy, value_type vtheta) 
        {
            x = vx;
            y = vy;
            theta = vtheta;
        }
        
        // origin-xy距離
        /**
         * @brief 原点からxy座標までの距離を返す
         * 
         * @return value_type 
         */
        value_type distance() const
        {
            return vector_type(x, y).norm();
        }
        
        // 回転
        /**
         * @brief 原点中心に回転
         * 
         * @param theta 
         */
        void rotate(const value_type theta)
        {
            rotate(vector_type::zero(), theta);
        }
        
        /**
         * @brief 指定座標中心に回転
         * 
         * @param rotX 
         * @param rotY 
         * @param theta 
         */
        void rotate(const value_type rotX, const value_type rotY, const value_type theta)
        {
            rotate(vector_type(rotX, rotY), theta); 
        }

        /**
         * @brief 指定座標中心に回転
         * 
         * @param rotPos 
         * @param theta 
         */
        void rotate(vector_type rotPos, const value_type theta) 
        { 
            vector_type p = make_vector2() - rotPos;
            p.rotate(theta);
            x = p.x + rotPos.x;
            y = p.y + rotPos.y;
        }
        
        // 極座標指定
        /**
         * @brief 極座標指定
         * 
         * @param radius 
         * @param angle 
         * @param robotTheta 
         */
        void set_polar(const value_type radius, const value_type angle, const value_type robotTheta)
        {
            x = radius * std::cos(angle);
            y = radius * std::sin(angle);
            theta = robotTheta;
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool is_zero() const
        {
            return approx_zero(x) && approx_zero(y) && approx_zero(theta);
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool is_zero_pos() const
        {
            return x == 0.0 && y == 0.0;
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool is_zero_angle() const
        {
            return theta == 0.0;
        }

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool has_nan() const
        {
            return std::isnan(x) || std::isnan(y) || std::isnan(theta);
        }
        
        /**
         * @brief Get the Angle object
         * 
         * @param a 
         * @param b 
         * @return value_type 
         */
        static constexpr value_type get_angle(Transform &a, Transform &b) { return b.theta - a.theta; };
        
        /**
         * @brief Get the Distance object
         * 
         * @param a 
         * @param b 
         * @return value_type 
         */
        static value_type get_distance(Transform &a, Transform &b)
        {
            return (b-a).distance();
        }

        /**
         * @brief lerp function
         * 
         * @param a 
         * @param b 
         * @param t 
         * @return Transform 
         */
        static Transform get_lerp(Transform &a, Transform &b, const value_type t)
        {
            return {lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.theta, b.theta, t)};
        }
        
        // constatnt vector
        /**
         * @brief 
         * 
         * @return Transform 
         */
        static constexpr Transform origin() 
        {
            return {0.0, 0.0, 0.0};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        constexpr bool operator == (const Transform v) const
        {
            return (x == v.x) && (y == v.y) && (theta == v.theta);
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return true 
         * @return false 
         */
        constexpr bool operator != (const Transform& v) const
        {
            return !((x == v.x) && (y == v.y) && (theta == v.theta));
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform 
         */
        constexpr Transform operator + (const Transform& v) const 
        {
            return {x + v.x, y + v.y, theta + v.theta};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform 
         */
        constexpr Transform operator - (const Transform& v) const
        {
            return {x - v.x, y - v.y, theta - v.theta};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform& 
         */
        constexpr Transform& operator += (const Transform& v)
        {
            x += v.x;
            y += v.y;
            theta += v.theta;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform& 
         */
        constexpr Transform& operator -= (const Transform& v)
        {
            x -= v.x;
            y -= v.y;
            theta -= v.theta;
            
            return *this;
        }
        
        // xy
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform 
         */
        constexpr Transform operator + (const vector_type& v) const
        {
            return {x + v.x, y + v.y, theta};
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform 
         */
        constexpr Transform operator - (const vector_type& v) const
        {
            return {x - v.x, y - v.y, theta};
        }
        
        // theta

        /**
         * @brief 
         * 
         * @param angle 
         * @return Transform 
         */
        constexpr Transform operator + (const value_type angle) const
        {
            return {x, y, theta + angle};
        }
        
        /**
         * @brief 
         * 
         * @param angle 
         * @return Transform 
         */
        constexpr Transform operator - (const value_type angle) const
        {
            return {x, y, theta - angle};
        }
        
        // xy
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform& 
         */
        constexpr Transform& operator += (const vector_type& v)
        {
            x += v.x;
            y += v.y;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param v 
         * @return Transform& 
         */
        constexpr Transform& operator -= (const vector_type& v)
        {
            x -= v.x;
            y -= v.y;
            
            return *this;
        }

        // theta
        /**
         * @brief 
         * 
         * @param angle 
         * @return Transform& 
         */
        constexpr Transform& operator += (const value_type angle)
        {
            theta += angle;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param angle 
         * @return Transform& 
         */
        constexpr Transform& operator -= (const value_type angle)
        {
            theta -= angle;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Transform 
         */
        constexpr Transform operator * (const value_type value) const
        {
            return {x * value, y * value, theta * value};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Transform 
         */
        constexpr Transform operator / (const value_type value) const
        {
            return {x / value, y / value, theta / value};
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Transform& 
         */
        constexpr Transform& operator *= (const value_type value)
        {
            x *= value;
            y *= value;
            theta *= value;
            
            return *this;
        }
        
        /**
         * @brief 
         * 
         * @param value 
         * @return Transform& 
         */
        constexpr Transform& operator /= (const value_type value)
        {
            x /= value;
            y /= value;
            theta /= value;
            
            return *this;
        }
        
        // index
        /**
         * @brief 
         * 
         * @param index 
         * @return value_type& 
         */
        value_type &operator [] (const int index)
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return theta;
        }

        /**
         * @brief 
         * 
         * @param index 
         * @return constexpr value_type 
         */
        constexpr value_type operator [] (const int index) const
        {
            assert(0 <= index && index < 3);
            if (index == 0) return x;
            if (index == 1) return y;
            return theta;
        }
    };
}
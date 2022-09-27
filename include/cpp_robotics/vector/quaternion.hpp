/**
 * @file quaternion.hpp
 * @author Takumi Odashima (Kotakkucu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "./vector3.hpp"

namespace cpp_robotics
{

template<typename FLOATING_TYPE>
struct Quaternion;
using Quaternionf = Quaternion<float>;
using Quaterniond = Quaternion<double>;

/**
 * @brief クォータニオンクラス
 * 
 * @tparam FLOATING_TYPE 
 */
template<typename FLOATING_TYPE>
class Quaternion
{
public:
    using value_type = FLOATING_TYPE;
    value_type x;
    value_type y;
    value_type z;
    value_type w;

    constexpr Quaternion():
		x(0.0f), y(0.0f), z(0.0f), w(1.0f)
    {
    }

    constexpr Quaternion(value_type nx, value_type ny, value_type nz, value_type nw):
		x(nx), y(ny), z(nz), w(nw)
    {
    }

    Quaternion get_product(Quaternion q)
    {
        return Quaternion(w * q.w - x * q.x - y * q.y - z * q.z,   // new w
                          w * q.x + x * q.w + y * q.z - z * q.y,   // new x
                          w * q.y - x * q.z + y * q.w + z * q.x,   // new y
                          w * q.z + x * q.y - y * q.x + z * q.w);  // new z
    }

    constexpr Quaternion conjugate() const { return Quaternion(w, -x, -y, -z); }

    constexpr value_type norm() const { return sqrt(w * w + x * x + y * y + z * z); }

    constexpr void normalize()
    {
        value_type m = norm();
        w /= m;
        x /= m;
        y /= m;
        z /= m;
    }

    constexpr Quaternion get_normalized() const
    {
        Quaternion r(w, x, y, z);
        r.normalize();
        return r;
    }

    constexpr void set_rpy(value_type roll, value_type pitch, value_type yaw)
    {
        double cos_roll = cos(roll / 2.0);
        double sin_roll = sin(roll / 2.0);
        double cos_pitch = cos(pitch / 2.0);
        double sin_pitch = sin(pitch / 2.0);
        double cos_yaw = cos(yaw / 2.0);
        double sin_yaw = sin(yaw / 2.0);

        w = cos_roll * cos_pitch * cos_yaw + sin_roll * sin_pitch * sin_yaw;
        x = sin_roll * cos_pitch * cos_yaw - cos_roll * sin_pitch * sin_yaw;
        y = cos_roll * sin_pitch * cos_yaw + sin_roll * cos_pitch * sin_yaw;
        z = cos_roll * cos_pitch * sin_yaw - sin_roll * sin_pitch * cos_yaw;
    }

    constexpr Vector3d get_rpy() const
    {
        value_type xx = x * x;
        value_type xy = x * y;
        value_type xz = x * z;
        value_type xw = x * w;
        value_type yy = y * y;
        value_type yz = y * z;
        value_type yw = y * w;
        value_type zz = z * z;
        value_type zw = z * w;
        value_type ww = w * w;
        return Vector3d{std::atan2(2.0f * (zw + xy), xx - yy - zz + ww),
                std::asin(2.0f * (xz - yw)),
                std::atan2(2.0f * (yz + xw), xx + yy - zz - ww)};
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
};
}

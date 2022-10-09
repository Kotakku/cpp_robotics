#pragma once
#include <cmath>
#include <cassert>

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279
#endif 

namespace cpp_robotics
{
    /**
     * @brief 数学・物理定数
     * 
     */
    inline namespace constants
    {
        /// 円周率
        constexpr double PI         = 3.1415926535897932384626433832795;
        
        /// 円周率 / 2
        constexpr double HALF_PI    = PI / 2.0;
        
        /// 円周率 * 2
        constexpr double TWO_PI     = PI * 2.0;
        
        /// degree -> radians
        constexpr double DEG_TO_RAD = PI / 180.0;
        
        /// radian -> degree
        constexpr double RAD_TO_DEG = 180.0 / PI;
        
        /// ネイピア数
        constexpr double EULER      = 2.718281828459045235360287471352;

        /// 重力
        constexpr double GRAVITY    = 9.807;
        
        /// 
        constexpr double Nm2gfm     = (1/GRAVITY);
        
        /// 
        constexpr double gfm2Nm     = GRAVITY;

        /// 
        constexpr double mNm2gfcm   = (Nm2gfm * 100);
        
        /// 
        constexpr double gfcm2mNm   = (gfm2Nm / 100);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param x 
     * @param min 
     * @param max 
     * @return true 
     * @return false 
     */
    template<typename T>
    static constexpr bool in_range_open(T x, T min, T max) 
    {
        return ((min < x && x < max) ? true : false);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param x 
     * @param min 
     * @param max 
     * @return true 
     * @return false 
     */
    template<typename T>
    static constexpr bool in_range(T x, T min, T max) 
    {
        return ((min <= x && x <= max) ? true : false);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param x 
     * @return constexpr int 
     */
    template<typename T>
    static constexpr int sgn(T x) 
    {
        return (x > 0 ? 1 : x < 0 ? -1 : 0);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param deg 
     * @return constexpr double 
     */
    template<typename T>
    static constexpr double radians(T deg) 
    {
        return (deg*DEG_TO_RAD);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param rad 
     * @return constexpr double 
     */
    template<typename T>
    static constexpr double degrees(T rad)
    {
        return (rad*RAD_TO_DEG);
    }

    /**
     * @brief 
     * 
     * @param angle 
     * @return double 
     */
    static inline double normalize_angle_positive(double angle)
    {
        return std::fmod(std::fmod(angle, TWO_PI) + TWO_PI, TWO_PI);
    }

    /**
     * @brief 
     * 
     * @param angle 
     * @return double 
     */
    static inline double normalize_angle(double angle)
    {
        double a = normalize_angle_positive(angle);
        if (a > PI)
            a -= TWO_PI;
        return a;
    }

    /**
     * @brief 
     * 
     * @param from 
     * @param to 
     * @return double 
     */
    static inline double shortest_angular_distance(double from, double to)
    {
        return normalize_angle(to-from);
    }

    static inline double nearest_angle(double from, double to)
    {
        return from + normalize_angle(to-from);
    }


constexpr inline double square(const double x) { return x*x; }
constexpr inline double cubic(const double x) { return x*x*x; }
constexpr inline double lerp(const double a, const double b, const double t) { return a + (b-a)*t; }
constexpr inline double approx_eq(const double a, const double b) { return (std::abs(a-b) < 1e-12); }
constexpr inline double approx_zero(const double a) { return (std::abs(a) < 1e-12); }

}

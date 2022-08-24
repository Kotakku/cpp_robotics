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
        constexpr float PI         = 3.1415926535897932384626433832795;
        
        /// 円周率 / 2
        constexpr float HALF_PI    = PI / 2.0;
        
        /// 円周率 * 2
        constexpr float TWO_PI     = PI * 2.0;
        
        /// degree -> radians
        constexpr float DEG_TO_RAD = PI / 180.0;
        
        /// radian -> degree
        constexpr float RAD_TO_DEG = 180.0 / PI;
        
        /// ネイピア数
        constexpr float EULER      = 2.718281828459045235360287471352;

        /// 重力
        constexpr float GRAVITY    = 9.807;
        
        /// 
        constexpr float Nm2gfm     = (1/GRAVITY);
        
        /// 
        constexpr float gfm2Nm     = GRAVITY;

        /// 
        constexpr float mNm2gfcm   = (Nm2gfm * 100);
        
        /// 
        constexpr float gfcm2mNm   = (gfm2Nm / 100);
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
     * @return constexpr float 
     */
    template<typename T>
    static constexpr float radians(T deg) 
    {
        return (deg*DEG_TO_RAD);
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param rad 
     * @return constexpr float 
     */
    template<typename T>
    static constexpr float degrees(T rad)
    {
        return (rad*RAD_TO_DEG);
    }

    /**
     * @brief 
     * 
     * @param angle 
     * @return float 
     */
    static inline float normalize_angle_positive(float angle)
    {
        return std::fmod(std::fmod(angle, TWO_PI) + TWO_PI, TWO_PI);
    }

    /**
     * @brief 
     * 
     * @param angle 
     * @return float 
     */
    static inline float normalize_angle(float angle)
    {
        float a = normalize_angle_positive(angle);
        if (a > PI)
            a -= TWO_PI;
        return a;
    }

    /**
     * @brief 
     * 
     * @param from 
     * @param to 
     * @return float 
     */
    static inline float shortest_angular_distance(float from, float to)
    {
        return normalize_angle(to-from);
    }

    static inline float nearest_angle(float from, float to)
    {
        return from + normalize_angle(to-from);
    }


constexpr inline float square(const float x) { return x*x; }
constexpr inline float cubic(const float x) { return x*x*x; }
constexpr inline float lerp(const float a, const float b, const float t) { return a + (b-a)*t; }
constexpr inline float approx_eq(const float a, const float b) { return (std::abs(a-b) < 1e-12); }
constexpr inline float approx_zero(const float a) { return (std::abs(a) < 1e-12); }

}

#pragma once

#include "./dc_motor_param.hpp"

namespace cpp_robotics
{

inline constexpr DCMotorParam RZ_735VA_9517 = generate_mabuchi_motor_param(
    18_V,
    20400_rpm,
    2.8_A,
    1265_mmNm,
    156_A,
    7.088e-5_H,
    2.46e-5 // 適当
);

inline constexpr DCMotorParam RS_775_8513 = generate_mabuchi_motor_param(
    18_V,
    18400_rpm,
    2.7_A,
    1216_mmNm, 
    130_A,
    5.872e-5_H,
    2.46e-5 // 適当
);

inline constexpr DCMotorParam RS_555VC_5524 = generate_mabuchi_motor_param(
    12_V,
    9100_rpm,
    0.8_A,
    450_mmNm, 
    36_A,
    1.820e-4_H,
    2.46e-5 // 適当
);

// inline constexpr DCMotorParam RS_540SH_6527	
// {
//     1.658e+0_ohm, 
//     7.371e-5_H, 
//     3.899e-3_Nm_per_A, 
//     6.239e-3_Nm, 
//     3.745e-2_Vs_per_rad
// };

inline constexpr DCMotorParam RS_380PH_4045 = generate_mabuchi_motor_param(
    6_V,
    12500_rpm,
    0.56_A,
    77.5_mmNm, 
    18_A,
    1.521e-4_H,
    2.46e-5 // 適当
);

inline constexpr DCMotorParam RS_385PH_2465 = generate_mabuchi_motor_param(
    18_V,
    17500_rpm,
    0.23_A,
    76.9_mmNm, 
    7.91_A,
    1.521e-4_H,
    2.46e-5 // 適当
);

// inline constexpr DCMotorParam RS_385PH_2465	
// {
//     3.067e+1_ohm, 
//     1.128e-3_H, 
//     1.189e-2_Nm_per_A, 
//     3.219e-3_Nm, 
//     1.330e-1_Vs_per_rad
// };

inline constexpr DCMotorParam RE_65_250_18 = generate_maxon_brush_motor_param(
    18_V,
    3520_rpm,
    755_mA,
    0.0609_ohm,
    0.0226_mH,
    46e-3_Nm_per_A,
    1.38
);  

// http://suzakugiken.jp/goods/30144/catalog-IG32.pdf
// http://suzakugiken.jp/goods/30335/catalog-IG36P.pdf
// http://suzakugiken.jp/goods/30045/catalog-IG42C.pdf

inline constexpr GearHeadParam IG42C_4  = { 1/4.0f, 0.8f };
inline constexpr GearHeadParam IG42C_14 = { 1/14.0f, 0.7f };
inline constexpr GearHeadParam IG42C_17 = { 1/17.0f, 0.7f };
inline constexpr GearHeadParam IG32_27  = { 1/27.0f, 0.7f };
inline constexpr GearHeadParam IG32_71  = { 1/71.0f, 0.6f };
inline constexpr GearHeadParam IG32_100 = { 1/100.0f, 0.6f };

}
---
title: include/cpp_robotics/chassis/omni_ik.hpp

---

# include/cpp_robotics/chassis/omni_ik.hpp






## Source code

```cpp
// #pragma once

// #include "../_Interface/IDriveIK.hpp"
// #include "../../Common/SCLMath.hpp"
// #include <array>

// namespace STB
// {
//     template<size_t WHEEL_NUM>
//     class OmniIK;

//     using Omni3IK = OmniIK<3>;
//     using Omni4IK = OmniIK<4>;

//     /**
//      * @brief オムニの逆運動学モデル
//      * 
//      * @tparam WHEEL_NUM 
//      */
//     template<size_t WHEEL_NUM>
//     class OmniIK : public IDriveIK<float>
//     {
//     public:
//         /**
//          * @brief Construct a new Omni I K object
//          * 
//          * @param config 
//          * @param specification 
//          */
//         OmniIK(DriveIKContents::omniConfig_t config, DriveIKContents::specification_t specification) :
//             _config(config), _specification(specification)
//         {
//             setDefaultRateMatrix();
//         }
        
//         /**
//          * @brief 
//          * 
//          * @return size_t 
//          */
//         virtual size_t wheel_num() { return WHEEL_NUM; }
        
//         /**
//          * @brief 
//          * 
//          * @param velocityVector 
//          * @param angle 
//          * @return true 
//          * @return false 
//          */
//         virtual bool calculate(FieldVec2F velocityVector, const float angle)
//         {
//             for(size_t element = 0; element < 2; element++)
//             {
//                 velocityVector[element] = clamp<float>(velocityVector[element], -_specification.maxLinearInput, _specification.maxLinearInput);
                    
//                 if(abs(velocityVector[element]) < _specification.minLinearInput)
//                     velocityVector[element] = 0;
//             }
//             velocityVector[2] = clamp<float>(velocityVector[2], -_specification.maxAngularInput, _specification.maxAngularInput);
//             if(abs(velocityVector[2]) < _specification.minAngularInput)
//                 velocityVector[2] = 0;

//             velocityVector.rotate(-angle);

//             float maxValue = 0;
//             int wheel;

//             for(wheel = 0; wheel < WHEEL_NUM; wheel++)
//             {
//                 v[wheel] = 0;
//                 for(size_t element = 0; element < 3; element++) {
//                     v[wheel] += _rateMatrix[wheel][element] * velocityVector[element];
//                 }

//                 if(abs(v[wheel]) > maxValue)
//                     maxValue = abs(v[wheel]);
//             }

//             for(size_t wheel = 0; wheel < WHEEL_NUM; wheel++)
//             {
//                 if(maxValue > _specification.maxOutput)
//                     v[wheel] = map<float>(v[wheel], -maxValue, maxValue, -_specification.maxOutput, _specification.maxOutput);
                    
//                 if(abs(v[wheel]) < _specification.minOutput)
//                     v[wheel] = 0;
//             }
            
//             return (velocityVector == FieldVec2F::origin());
//         }
        
//         /**
//          * @brief 
//          * 
//          * @param num 
//          * @return float 
//          */
//         virtual float wheel_vel(const size_t num) { return v[num]; }

//         /**
//          * @brief 
//          * 
//          * @return std::array<float, WHEEL_NUM> 
//          */
//         std::array<float, WHEEL_NUM> wheel_vel() { return v; }

//         /**
//          * @brief 
//          * 
//          * @return DriveIKContents::omniConfig_t& 
//          */
//         DriveIKContents::omniConfig_t    &config()        { return _config; }

//         /**
//          * @brief 
//          * 
//          * @return DriveIKContents::specification_t& 
//          */
//         DriveIKContents::specification_t &specification() { return _specification; }

//         /**
//          * @brief 
//          * 
//          * @param num 
//          * @return float 
//          */
//         float operator [](const int num)
//         {
//             return wheel_vel(num);
//         }
        
//     protected:
//         void setDefaultRateMatrix() 
//         {
//             float fwa = _config.theta;
//             float angleStep = 2*PI / WHEEL_NUM;
            
//             for(size_t wheel = 0; wheel < WHEEL_NUM; wheel++)
//             {
//                 _rateMatrix[wheel][0] = -sin(fwa + (angleStep * wheel));
//                 _rateMatrix[wheel][1] =  cos(fwa + (angleStep * wheel));
//                 _rateMatrix[wheel][2] = _config.radius;
//             }
//         }
        
//     protected:
//         DriveIKContents::omniConfig_t _config;
//         DriveIKContents::specification_t _specification;
//         std::array<std::array<float, 3>, WHEEL_NUM> _rateMatrix;
//         std::array<float, WHEEL_NUM> v;
//     };
// }
```


-------------------------------

Updated on 2022-09-26 at 11:58:18 +0900

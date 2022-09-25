---
title: include/cpp_robotics/chassis/mecanum_ik.hpp

---

# include/cpp_robotics/chassis/mecanum_ik.hpp






## Source code

```cpp
// #pragma once

// #include "../_Interface/IDriveIK.hpp"
// #include "../../Common/SCLMath.hpp"
// #include <array>

// namespace STB
// {
//     /**
//      * @brief メカナムの逆運動学モデル
//      * 
//      */
//     class MecanumIK : public IDriveIK<float>
//     {
//     public:
//         /**
//          * @brief Construct a new Mecanum I K object
//          * 
//          * @param config 
//          * @param specification 
//          */
//         MecanumIK(DriveIKContents::mecanumConfig_t config, DriveIKContents::specification_t specification):
//             _config(config), _specification(specification)
//         {
//             setDefaultRateMatrix();
//         }

//         /**
//          * @brief 
//          * 
//          * @return size_t 
//          */
//         virtual size_t wheel_num() { return 4; }

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

//                 if (abs(velocityVector[element]) < _specification.minLinearInput)
//                     velocityVector[element] = 0.0;
//             }

//             velocityVector[2] = clamp<float>(velocityVector[2], -_specification.maxAngularInput, _specification.maxAngularInput);
//             if(abs(velocityVector[2]) < _specification.minAngularInput)
//                 velocityVector[2] = 0;

//             velocityVector.rotate(-angle);

//             float maxValue = 0;
//             for(size_t wheel = 0; wheel < 4; wheel++)
//             {
//                 v[wheel] = 0;
//                 for(size_t element = 0; element < 3; element++) {
//                     v[wheel] += _rateMatrix[wheel][element] * velocityVector[element];
//                 }

//                 if(abs(v[wheel]) > maxValue)
//                     maxValue = abs(v[wheel]);
//             }

//             for(size_t wheel = 0; wheel < 4; wheel++)
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
//          * @return std::array<float, 4> 
//          */
//         std::array<float, 4> wheel_vel() { return v; }

//         /**
//          * @brief 
//          * 
//          * @return DriveIKContents::mecanumConfig_t& 
//          */
//         DriveIKContents::mecanumConfig_t &config()        { return _config; }

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
//         float operator [](const size_t num)
//         {
//             return wheel_vel(num);
//         }
        
//     protected:
//         void setDefaultRateMatrix()
//         {
//             float x = _config.width / 2;
//             float y = _config.length / 2;
//             float length = sqrt(x*x + y*y);
            
//             _rateMatrix[0][0] = -1; 
//             _rateMatrix[0][1] = 1; 
            
//             _rateMatrix[1][0] = -1; 
//             _rateMatrix[1][1] = -1; 
            
//             _rateMatrix[2][0] = 1; 
//             _rateMatrix[2][1] = -1; 
            
//             _rateMatrix[3][0] = 1; 
//             _rateMatrix[3][1] = 1; 
            
//             for(size_t i = 0; i < 4; i++)
//                 _rateMatrix[i][2] = length;
                
//             // Todo
//             /*
//             // 理想的なメカナムホイールの配置（45deg）からのズレの度合い
//             float rotationCorrection = cos(atan2(y, x) - PI / 4); 
            
//             float buf_rateMatrix[4][3] = 
//             {
//                 {-1 * x_option,  1, length * rotationCorrection},
//                 {-1 * x_option, -1, length * rotationCorrection},
//                 { 1 * x_option, -1, length * rotationCorrection},
//                 { 1 * x_option,  1, length * rotationCorrection}
//             };
//             */
//         }
        
//     protected:
//         DriveIKContents::mecanumConfig_t _config;
//         DriveIKContents::specification_t _specification;
//         std::array<std::array<float, 3>, 4> _rateMatrix;
//         std::array<float, 4> v;
//     };
// }
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900

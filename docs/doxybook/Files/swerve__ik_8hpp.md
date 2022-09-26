---
title: include/cpp_robotics/chassis/swerve_ik.hpp

---

# include/cpp_robotics/chassis/swerve_ik.hpp






## Source code

```cpp
// #pragma once

// #include "../_Interface/IDriveIK.hpp"
// #include "../../Common/SCLMath.hpp"
// #include <array>

// namespace STB
// {
//     /**
//      * @brief 独立4輪ステアリングの逆運動学モデル
//      * 
//      */
//     class SwerveIK : public IDriveIK<Vec2F>
//     {
//     public:
//         /**
//          * @brief Construct a new Swerve I K object
//          * 
//          * @param config 
//          * @param specification 
//          */
//         SwerveIK(DriveIKContents::swerveConfig_t config, DriveIKContents::specification_t& specification):
//             _config(config), _specification(specification)
//         {
//             float x = _config.width / 2;
//             float y = _config.length / 2;
        
//             _length = sqrt(x*x + y*y);
            
//             _theta = atan2(y, x);
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
                    
//                 if(abs(velocityVector[element]) < _specification.minLinearInput)
//                     velocityVector[element] = 0;
//             }
//             velocityVector[2] = clamp<float>(velocityVector[2], -_specification.maxAngularInput, _specification.maxAngularInput);
//             if(abs(velocityVector[2]) < _specification.minAngularInput)
//                 velocityVector[2] = 0;
            
//             velocityVector.rotate(-angle);

//             float maxValue = 0;

//             v[0].x = velocityVector[0] - _length * velocityVector[2] * sin(_theta);
//             v[0].y = velocityVector[1] + _length * velocityVector[2] * cos(_theta);
                
//             v[1].x = velocityVector[0] - _length * velocityVector[2] * cos(_theta);
//             v[1].y = velocityVector[1] - _length * velocityVector[2] * sin(_theta);
                
//             v[2].x = velocityVector[0] + _length * velocityVector[2] * sin(_theta);
//             v[2].y = velocityVector[1] - _length * velocityVector[2] * cos(_theta);
                
//             v[3].x = velocityVector[0] + _length * velocityVector[2] * cos(_theta);
//             v[3].y = velocityVector[1] + _length * velocityVector[2] * sin(_theta);

//             for(size_t wheel = 0; wheel < 4; wheel++)
//             {
//                 if(v[wheel].norm() > maxValue)
//                     maxValue = v[wheel].norm();
//             }
            
//             for(size_t wheel = 0; wheel < 4; wheel++)
//             {
//                 if(maxValue > _specification.maxOutput)
//                     v[wheel] *= _specification.maxOutput / maxValue;
                    
//                 if(v[wheel].norm() < _specification.minOutput)
//                     v[wheel] = Vec2F::zero();
//             }
            
//             return (velocityVector == FieldVec2F::origin());
//         }
        
//         /**
//          * @brief 
//          * 
//          * @param num 
//          * @return Vec2F 
//          */
//         virtual Vec2F wheel_vel(const size_t num) { return v[num]; }

//         /**
//          * @brief 
//          * 
//          * @return std::array<Vec2F, 4> 
//          */
//         std::array<Vec2F, 4> wheel_vel() { return v; }

//         /**
//          * @brief 
//          * 
//          * @return DriveIKContents::swerveConfig_t& 
//          */
//         DriveIKContents::swerveConfig_t  &config()         { return _config; }

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
//          * @return Vec2F 
//          */
//         Vec2F operator [](const size_t num)
//         {
//             return wheel_vel(num);
//         }
        
//     protected:
//         DriveIKContents::swerveConfig_t _config;
//         DriveIKContents::specification_t _specification;
        
//         float _length;
//         float _theta;
//         std::array<Vec2F, 4> v;
//         //float rotationCorrection;
//     };
// }
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900

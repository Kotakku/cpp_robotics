---
title: include/cpp_robotics/controller/pfc.hpp

---

# include/cpp_robotics/controller/pfc.hpp






## Source code

```cpp
// #pragma once

// // https://hamachannel.hatenablog.com/entry/2018/01/13/233521

// #include "../../Matrix/Matrix.hpp"
// #include <functional>
// //#include <iostream>

// namespace STB
// {

// template<typename Scalar, size_t Dim>
// class SISOPFC;
// using SISOPFC2f = SISOPFC<float, 2>;

// template<typename Scalar, size_t Dim>
// class SISOPFC
// {
// public:
//     using value_type = Scalar;
//     using A_type = Matrix<value_type, Dim, Dim>;
//     using b_type = Matrix<value_type, Dim, 1>;
//     using c_type = Matrix<value_type, 1, Dim>;
//     using vec_type = Matrix<value_type, Dim, 1>;
//     using svec_type = Matrix<value_type, 3, 1>;
    
//     SISOPFC(const A_type& Am, const b_type& Bm, const c_type& Cm, const value_type delay, const value_type TCLRT, const value_type Ts):
//         A(Am), B(Bm), C(Cm), _TCLRT(TCLRT), _Ts(Ts), _prev_input(0)
//     {
//         //using namespace Eigen;

//         // setup
//         h1 = ceil(_TCLRT / (_Ts * 3));
//         h2 = ceil(_TCLRT / (_Ts * 2));
//         h3 = ceil(_TCLRT / (_Ts * 1));
//         hl = ceil(delay / _Ts);
        
//         lh = {
//             (1 - exp(-3 * h1 * _Ts / _TCLRT)),
//             (1 - exp(-3 * h2 * _Ts / _TCLRT)),
//             (1 - exp(-3 * h3 * _Ts / _TCLRT))};
        
//         CAh1 = CAh2 = CAh3 = C;
//         for(int i = 0; i < h1; i++)
//             CAh1 *= A;

//         for (int i = 0; i < h2; i++)
//             CAh2 *= A;

//         for (int i = 0; i < h3; i++)
//             CAh3 *= A;

//         G_inv = Matrix<value_type, 3, 3>::Zero();
//         c_type tmp = C;
//         for (int i = 0; i < h1; i++)
//         {
//             if(i > 0)
//                 tmp *= A;
//             value_type ele = (tmp * B);
//             value_type t1 = _Ts * (h1-1-i);
//             value_type t2 = t1 * t1;
//             G_inv(0, 0) += ele;
//             G_inv(0, 1) += ele * t1;
//             G_inv(0, 2) += ele * t2;
//         }
//         tmp = C;
//         for (int i = 0; i < h2; i++)
//         {
//             if (i > 0)
//                 tmp *= A;
//             value_type ele = (tmp * B);
//             value_type t1 = _Ts * (h2-1-i);
//             value_type t2 = t1 * t1;
//             G_inv(1, 0) += ele;
//             G_inv(1, 1) += ele * t1;
//             G_inv(1, 2) += ele * t2;
//         }
//         tmp = C;
//         for (int i = 0; i < h3; i++)
//         {
//             if (i > 0)
//                 tmp *= A;
//             value_type ele = (tmp * B);
//             value_type t1 = _Ts * (h3-1 - i);
//             value_type t2 = t1 * t1;
//             G_inv(2, 0) += ele;
//             G_inv(2, 1) += ele * t1;
//             G_inv(2, 2) += ele * t2;
//         }

//         G_inv = G_inv.inverse();

//         xm = vec_type::Zero();
//     }

//     value_type calculate(std::function<value_type(value_type)> refTarget, value_type nowState)
//     {
//         return calculate(refTarget, nowState, prev_input());
//     }

//     value_type calculate(std::function<value_type(value_type)> refTarget, value_type nowState, value_type prev_input)
//     {
//         // using namespace Eigen;
//         svec_type SV_future;
//         svec_type SF;

//         xm = A * xm + B * prev_input;
//         value_type y = C * xm;

//         value_type nowTarget = refTarget(hl);

//         SV_future = {
//             refTarget(hl + h1 * _Ts) - nowTarget,
//             refTarget(hl + h2 * _Ts) - nowTarget,
//             refTarget(hl + h3 * _Ts) - nowTarget};
        
//         SF = {
//             CAh1 * xm,
//             CAh2 * xm,
//             CAh3 * xm};

//         auto buf = G_inv * (SV_future + (nowTarget - nowState) * lh - SF + svec_type::Constant(y));
//         _prev_input = clamp<value_type>(buf(0), -12, 12);

//         return _prev_input;
//     }

//     value_type prev_input() { return _prev_input; }
// private:
//     Matrix<value_type, 3, 3> G_inv;
//     A_type A;
//     b_type B, xm, /*ym, */MV_pre;
//     c_type CAh1, CAh2, CAh3, C;
//     svec_type lh;
//     size_t h1, h2, h3, hl;
//     value_type _TCLRT, _Ts;
//     value_type _prev_input;
// };

// }
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900

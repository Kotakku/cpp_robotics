---
title: include/cpp_robotics/path_planning/frenet_frame.hpp

---

# include/cpp_robotics/path_planning/frenet_frame.hpp






## Source code

```cpp
// #pragma once

// // #include "Polynomial.hpp"
// // #include "../../Control/Trajectory/Trajectory2/Trajectory2.hpp"
// #include <cstdio>
// #include <string>
// #include <limits>
// #include <tuple>

// namespace cpp_robotics
// {
// // template <typename double>
// // void d_print_vector(const std::string name, const std::vector<double> &vec,
// //                   std::string fmt = "%8.3f")
// // {
// //     std::cout << name << " =" << std::endl;
// //     printf("[");
// //     for (auto &val : vec) printf(fmt.c_str(), val);
// //     printf("]\n");
// // }


//     /**
//      * @brief 4次式補間
//      * 
//      * @param x0 始点位置
//      * @param v0 始点速度
//      * @param a0 始点加速度
//      * @param v1 終点速度
//      * @param a1 終点加速度
//      * @param Time 区間長さ
//      */
//     Polynomial<double> quartic_poly(double x0, double v0, double a0, double v1, double a1, double Time)
//     {
//         std::vector<double> coeff;
//         coeff.resize(5);
        
//         const double T2 = sq(Time);
//         const double T3 = T2 * Time;

//         coeff[0] = x0;
//         coeff[1] = v0;
//         coeff[2] = 0.5 * a0;
//         coeff[3] = (3*(v1 - v0) - Time*(a1 + 2*a0)) / (3*T2);
//         coeff[4] = (-2*(v1 - v0) + Time*(a1 + a0)) / (4*T3);

//         return Polynomial<double>(coeff);
//     }

//     /**
//      * @brief 5次補間
//      * 
//      * @tparam double 
//      * @param x0 始点位置
//      * @param v0 始点速度
//      * @param a0 始点加速度
//      * @param x1 終点位置
//      * @param v1 終点速度
//      * @param a1 終点加速度
//      * @param Time 区間長さ
//      * @return Polynomial<double> 
//      */
//     template <typename double>
//     Polynomial<double> quintic_poly(double x0, double v0, double a0, double x1, double v1, double a1, double Time)
//     {
//         std::vector<double> coeff;
//         coeff.resize(6);
        
//         const double T2 = sq(Time);
//         const double T3 = T2 * Time;
//         const double T4 = T3 * Time;
//         const double T5 = T4 * Time;

//         coeff[0] = x0;
//         coeff[1] = v0;
//         coeff[2] = 0.5 * a0;
//         coeff[3] = ( 20*(x1 - x0) -   Time*( 8*v1 + 12*v0) + T2*(a1 - 3*a0)) / (2*T3);
//         coeff[4] = (-30*(x1 - x0) +   Time*(14*v1 + 16*v0) - T2*(a1 - 3*a0)) / (2*T4);
//         coeff[5] = ( 12*(x1 - x0) - 6*Time*(   v1 +    v0) + T2*(a1 -   a0)) / (2*T5);

//         return Polynomial<double>(coeff);
//     }

//     /**
//      * @brief 探索範囲用設定
//      * 
//      * @tparam double 
//      */
//     struct frenet_path_config_t
//     {
//         double dt;
//         double width;
//         size_t width_num;
//         double length_min, length_max;
//         size_t length_num;
//         double target_speed;
//         double speed_interval;
//         size_t speed_num;
//         double K_J, K_T, K_D, K_LAT, K_LON;
//     };

//     struct frenet_path_point_t
//     {
//         double t;
//         double d, d_d, d_dd, d_ddd;
//         double s, s_d, s_dd, s_ddd;
//         Vector2<double> pos;
//         double theta;
//         double ds;
//         double curvature;
//     };

//     struct frenet_path_t : public std::vector<frenet_path_point_t<double>>
//     {
//         double cd, cv, cf;
//     };

//     struct frenet_path_state_t
//     {
//         double c_speed;
//         double c_d;
//         double c_d_d;
//         double c_d_dd;
//         double s0;
//     };

//     template <typename double>
//     struct frenet_path_th_t
//     {
//         double max_speed;
//         double max_accel;
//         double max_curvature;
//         double radius;
//     };

//     std::vector<frenet_path_t<double>> frenet_path(
//         const frenet_path_config_t<double>& config, 
//         const frenet_path_state_t<double>& state)
//     {
//         double c_speed = state.c_speed;
//         double c_d = state.c_d;
//         double c_d_d = state.c_d_d;
//         double c_d_dd = state.c_d_dd;
//         double s0 = state.s0;

//         auto dt = config.dt;
//         std::vector<frenet_path_t<double>> paths;

//         // 側方距離変化
//         for(size_t di_idx = 0; di_idx < config.width_num; di_idx++)
//         {
//             //printf("di, %ld, %ld, %lf, %lf\n", di_idx, config.width_num-1, -config.width, config.width);
//             double di = map<double>(di_idx, 0, config.width_num-1, -config.width, config.width);


//             // 距離変化
//             for(size_t Ti_idx = 0; Ti_idx < config.length_num; Ti_idx++)
//             {
//                 double Ti = map<double>(Ti_idx, 0, config.length_num-1, config.length_min, config.length_max);

//                 //printf("%lf, %lf, %lf, %lf, %lf\n", c_d, c_d_d, c_d_dd, di, Ti);
//                 auto d_func = quintic_poly<double>(c_d, c_d_d, c_d_dd, di, 0, 0, Ti);
//                 frenet_path_t<double> fp;
//                 fp.resize(static_cast<size_t>(Ti/dt));

//                 //d_print_vector("d_func", d_func.coeff());

//                 for(size_t t_idx = 0; t_idx < fp.size(); t_idx++)
//                 {
//                     auto &fpp = fp[t_idx];
//                     fpp.t = t_idx * dt;
//                     fpp.d = d_func(fpp.t);
//                     //printf("fpp.t = %lf, d = %lf\n", fpp.t, fpp.d);
//                     fpp.d_d   = d_func.polyder(1)(fpp.t);
//                     fpp.d_dd  = d_func.polyder(2)(fpp.t);
//                     fpp.d_ddd = d_func.polyder(3)(fpp.t);
//                 }

//                 // 速度変化
//                 for(size_t tv_idx = 0; tv_idx < config.speed_num; tv_idx++)
//                 {
//                     double tv = map<double>(tv_idx, 0, config.speed_num-1, config.target_speed - config.speed_interval, config.target_speed + config.speed_interval);
//                     frenet_path_t<double> tfp = fp;
//                     auto s_func = quartic_poly<double>(s0, c_speed, 0, tv, 0, Ti);

//                     double Jp = 0, Js = 0;
//                     for(size_t t_idx = 0; t_idx < tfp.size(); t_idx++)
//                     {
//                         auto &tfpp = tfp[t_idx];
//                         tfpp.t = t_idx * dt;
//                         tfpp.s = s_func(tfpp.t);
//                         tfpp.s_d   = s_func.polyder(1)(tfpp.t);
//                         tfpp.s_dd  = s_func.polyder(2)(tfpp.t);
//                         tfpp.s_ddd = s_func.polyder(3)(tfpp.t);

//                         Jp += sq(tfpp.d_ddd);
//                         Js += sq(tfpp.s_ddd);
//                     }

//                     double ds = sq(config.target_speed - tfp.back().s_d);

//                     tfp.cd = config.K_J * Jp + config.K_T * Ti + config.K_D * sq(tfp.back().d);
//                     tfp.cv = config.K_J * Js + config.K_T * Ti + config.K_D * ds;
//                     tfp.cf = config.K_LAT * tfp.cd + config.K_LON * tfp.cv;

//                     paths.push_back(tfp);
//                 }
//             }
//         }

//         return paths;
//     }

//     void frenet_path_to_global_path(std::vector<frenet_path_t<double>> &fpath, const Trajectory2 &ref_path)
//     {
//         // パスごと
//         for(auto &fp : fpath)
//         {
//             // 点ごと
//             for(auto &fpp : fp)
//             {
//                 auto patht = min<double>(fpp.s, ref_path.length());
//                 //printf("patht: %lfm %lf\n", patht, fpp.s);
//                 auto ref_idx = ref_path.linear_index(patht);

//                 Vec2F pos = ref_path.position(ref_idx);
//                 Vec2F vel = ref_path.velocity(ref_idx);
//                 vel.normalize();
//                 double yaw = vel.angle();
//                 fpp.pos.x = pos.x + fpp.d * cos(yaw + HALF_PI);
//                 fpp.pos.y = pos.y + fpp.d * sin(yaw + HALF_PI);
//             }

//             for(size_t i = 0; i < fp.size()-1; i++)
//             {
//                 auto dpos = fp[i+1].pos - fp[i].pos;
//                 if(!dpos.is_zero())
//                 {
//                     fp[i].theta = dpos.angle();
//                     fp[i].ds = hypot(dpos.x, dpos.y);
//                 }
//                 else
//                 {
//                     fp[i].theta = fp[i].ds = 0;
//                 }
//             }

//             for(size_t i = 0; i < fp.size()-1; i++)
//             {
//                 fp[i].curvature = (fp[i+1].theta - fp[i].theta) / fp[i].ds;
//             }
//             fp.back().curvature = 0;
//         }
//     }

//     bool check_collision(const Vector2<double> &pos, double r, const std::vector<Vector2<double>>& obstacles)
//     {
//         const double r2 = sq(r);
//         for(auto & ob : obstacles)
//         {
//             if(r2 > (ob-pos).norm_sq())
//                 return true; // 衝突する判定
//         }
//         return false;
//     }

//     void check_path(std::vector<
//         frenet_path_t<double>> &fpath, 
//         const frenet_path_th_t<double>& ths,
//         const std::vector<Vector2<double>>& obstacles)
//     {
//         auto pit = fpath.begin();
//         while(pit != fpath.end())
//         {
//             bool path_delete = false;
//             for(auto &fpp : (*pit))
//             {
//                 if(fpp.s_d > ths.max_speed)
//                     path_delete = true;
                
//                 if(abs(fpp.s_dd) > ths.max_accel)
//                     path_delete = true;

//                 // if(abs(fpp.curvature) > ths.max_curvature)
//                 //     path_delete = true;
                
//                 if(check_collision<double>(fpp.pos, ths.radius, obstacles))
//                     path_delete = true;
//             }

//             if (path_delete == true)
//             {
//                 //printf("erase\n");
//                 pit = fpath.erase(pit);
//             }
//             else
//             {
//                 //printf("pit++;\n");
//                 pit++;
//             }
//         }
//     }

//     std::tuple<frenet_path_t<double>, std::vector<frenet_path_t<double>>> frenet_optimal_planning(
//         const frenet_path_config_t<double>& config, 
//         const frenet_path_state_t<double>& state,
//         const Trajectory2 &ref_path, 
//         const frenet_path_th_t<double>& ths,
//         const std::vector<Vector2<double>>& obstacles)
//     {
//         auto frenet_paths = frenet_path(config, state);

//         //printf("opt 1\n");

//         frenet_path_to_global_path(frenet_paths, ref_path);
        
//         //printf("opt 2\n");
        

//         check_path<double>(frenet_paths, ths, obstacles);

//         //printf("opt 3\n");
        
//         auto it = frenet_paths.begin();
//         double min_cost = (*it).cf;

//         for(auto cit = frenet_paths.begin()+1; cit < frenet_paths.end(); cit++)
//         {
//             if (min_cost > (*cit).cf)
//             {
//                 min_cost = (*cit).cf;
//                 it = cit;
//             }
//         }

//         return {*it, frenet_paths};
//     }
// }
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900

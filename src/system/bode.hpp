#pragma once

#include <vector>
#include <tuple>
#include "./transfer_function.hpp"
#include "../external_lib/matplotlibcpp.h"
#include "../utility/space.hpp"
#include "../vector/vector2.hpp"
#include "../utility/math_utils.hpp"
#include "./polynomial.hpp"

namespace cpp_robotics
{

template<size_t NUM, size_t DEN>
static std::tuple<std::vector<double>, std::vector<double>> bode(TransferFunction<NUM, DEN> &tf, const std::vector<double> &omegas = logspace(-2, 2, 500))
{
    size_t n = omegas.size();
    std::vector<double> gain_db(n), phase_deg(n);

    Vector2d num_vec, den_vec;
    Polynomial num_poly(tf.num_array.begin(), tf.num_array.end());
    Polynomial den_poly(tf.den_array.begin(), tf.den_array.end());

    for(size_t i = 0; i < n; i++)
    {
        // gain
        {
            num_vec = Vector2d::zero();
            den_vec = Vector2d::zero();

            for(size_t n = 0; n < num_poly.size(); n++)
            {
                size_t deg = num_poly.degree() - n;
                
                int dir;
                bool is_real;
                switch(deg%4)
                {
                    case 0:
                        dir = 1;
                        is_real = true;
                        break;
                    case 1:
                        dir = 1;
                        is_real = false;
                        break;
                    case 2:
                        dir = -1;
                        is_real = true;
                        break;
                    case 3:
                        dir = -1;
                        is_real = false;
                        break;
                }

                if(is_real)
                    num_vec.x += dir * num_poly[n] * std::pow(omegas[i], deg);
                else
                    num_vec.y += dir * num_poly[n] * std::pow(omegas[i], deg);
            }

            for(size_t n = 0; n < den_poly.size(); n++)
            {
                size_t deg = den_poly.degree() - n;
                
                int dir;
                bool is_real;
                switch(deg%4)
                {
                    case 0:
                        dir = 1;
                        is_real = true;
                        break;
                    case 1:
                        dir = 1;
                        is_real = false;
                        break;
                    case 2:
                        dir = -1;
                        is_real = true;
                        break;
                    case 3:
                        dir = -1;
                        is_real = false;
                        break;
                }

                if(is_real)
                    den_vec.x += dir * den_poly[n] * std::pow(omegas[i], deg);
                else
                    den_vec.y += dir * den_poly[n] * std::pow(omegas[i], deg);
            }

            double gain = num_vec.norm() / den_vec.norm(); 
            gain_db[i] = 20 * std::log10(gain);
        }

        // phase
        {
            num_vec = Vector2d::zero();
            den_vec = Vector2d::zero();
            for(size_t didx = 0; didx < tf.num_array.size(); didx++)
            {
                size_t deg = tf.num_deg(didx);
                if(deg == 0)
                {
                    num_vec.x += tf.num_array[didx];
                }
                else
                {
                    double s = std::pow(omegas[i], deg);
                    num_vec.y += s * tf.num_array[didx];
                }
            }
            
            for(size_t didx = 0; didx < tf.den_array.size(); didx++)
            {
                size_t deg = tf.den_deg(didx);
                if(deg == 0)
                {
                    den_vec.x += tf.den_array[didx];
                }
                else
                {
                    double s = std::pow(omegas[i], deg);
                    den_vec.y += s * tf.den_array[didx];
                }
            }
            
            double phase = std::atan(num_vec.y/num_vec.x) - std::atan(den_vec.y/den_vec.x);
            phase_deg[i] = degrees(phase);
        }

    }

    return {gain_db, phase_deg};
}

template<size_t NUM, size_t DEN>
static void bode_plot(TransferFunction<NUM, DEN> &tf, const std::vector<double> &omegas = logspace(-2, 2, 500))
{
    namespace plt = matplotlibcpp;
    auto [g, ph] = bode(tf, omegas);

    plt::subplot(2, 1, 1);
    plt::ylabel("Magnitude(dB)");
    plt::semilogx(omegas, g);
    plt::xlim(std::pow(10,-2), std::pow(10,2));
    plt::ylim(-60, 30);
    plt::grid(true, "both");

    plt::subplot(2, 1, 2);
    plt::xlabel("Frequency(rad/s)");
    plt::ylabel("Phase(deg)");
    plt::semilogx(omegas, ph);
    plt::xlim(std::pow(10,-2), std::pow(10,2));
    plt::ylim(-90, 90);
    plt::yticks(std::vector<double>{-90, -45, 0, 45, 90});
    plt::grid(true, "both");

    plt::show();
}

}
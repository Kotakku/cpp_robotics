#pragma once

#include <Eigen/Dense>
#include "state_space_system.hpp"

namespace cpp_robotics
{

template<size_t NUM, size_t DEN>
class TransferFunction : public StateSpaceSystem<DEN>
{
public:
    using ss = StateSpaceSystem<DEN>;
    static constexpr size_t tf_num = NUM;
    static constexpr size_t tf_den = DEN;

    TransferFunction(std::array<double, NUM+1> _num, std::array<double, DEN+1> _den, const double _Ts):
        num_array(_num), den_array(_den), Ts(_Ts)
    {
        static_assert(NUM < DEN);
        assert(den_array[0] != 0);

        using a_mat_t = typename ss::a_mat_t;
        using b_mat_t = typename ss::b_mat_t;
        using c_mat_t = typename ss::c_mat_t;

        a_mat_t A = a_mat_t::Zero();
        for(size_t i = 0; i < DEN-1; i++)
        {
            A(i, i+1) = 1;
        }
        for(size_t i = 0; i < DEN; i++)
        {
            A(DEN-1, i) = -den_array[DEN - i] / den_array[0];
		}

        b_mat_t B = b_mat_t::Zero();
        B(DEN-1) = 1;

        c_mat_t C = c_mat_t::Zero();
        for(size_t i = 0; i <= NUM; i++)
        {
            C(i) = num_array[i] / den_array[0];
        }

        ss::set_continuous(A, B, C, Ts);
    }

    const std::array<double, NUM+1> num_array;
    const std::array<double, DEN+1> den_array;
    const double Ts;
};

}
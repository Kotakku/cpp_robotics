#pragma once

#include <Eigen/Dense>
#include <Eigen/../unsupported/Eigen/MatrixFunctions>
#include "discret.hpp"

namespace cpp_robotics
{

template<size_t STATE_SIZE, size_t INPUT_SIZE = 1, size_t OUTPUT_SIZE = 1>
class StateSpaceSystem
{
public:
    static constexpr size_t state_size = STATE_SIZE;
    static constexpr size_t input_size = INPUT_SIZE;
    static constexpr size_t output_size = OUTPUT_SIZE;

    using a_mat_t = Eigen::Matrix<double, state_size, state_size>;
    using b_mat_t = Eigen::Matrix<double, state_size, input_size>;
    using c_mat_t = Eigen::Matrix<double, output_size, state_size>;

    using x_vec_t = Eigen::Matrix<double, state_size, 1>;
    using u_vec_t = Eigen::Matrix<double, input_size, 1>;
    using y_vec_t = Eigen::Matrix<double, output_size, 1>;
    
    StateSpaceSystem() = default;

    void set_continuous(const a_mat_t &A, const b_mat_t &B, const c_mat_t &C, const double Ts)
    {
        A_ = A;
        B_ = B;
        Ts_ = Ts;
        std::tie(Ad_, Bd_) = Discret::discritize(A, B, Ts);
        Cd_ = C;
    }

    void set_discrite(const a_mat_t &Ad, const b_mat_t &Bd, const c_mat_t &Cd)
    {
        A_ = std::nullopt;
        B_ = std::nullopt;
        Ts_ = std::nullopt;
        
        Ad_ = Ad;
        Bd_ = Bd;
        Cd_ = Cd;
    }

    inline void set_state_zero()
    {
        set_state(x_vec_t::Zero());
    }

    void set_state(const x_vec_t &x)
    {
        x_ = x;
    }

    void set_state(const double &x)
    {
        static_assert(input_size == 1 && output_size == 1, "system is not SISO");
        x_vec_t x_vec;
        x_vec(0) = x;
        set_state(x_vec);
    }

    y_vec_t responce(const u_vec_t &u)
    {
        x_ =  Ad_*x_ + Bd_*u;
        return Cd_*x_;
    }

    double responce(double u)
    {
        static_assert(input_size == 1 && output_size == 1, "system is not SISO");
        u_vec_t u_vec;
        u_vec(0) = u;
        return responce(u_vec)(0);
    }

    std::optional<a_mat_t> A() const { return A_; }
    std::optional<b_mat_t> B() const { return B_; }
    std::optional<double>  Ts() const { return Ts_; }

    a_mat_t Ad() const { return Ad_; }
    b_mat_t Bd() const { return Bd_; }

    c_mat_t C()  const { return Cd_; }
    c_mat_t Cd() const { return Cd_; }

    x_vec_t x() const { return x_; }
    y_vec_t y() const { return Cd_*x_; }

private:
    a_mat_t Ad_;
    b_mat_t Bd_;
    c_mat_t Cd_;

    std::optional<a_mat_t> A_;
    std::optional<b_mat_t> B_;
    std::optional<double> Ts_;

    x_vec_t x_;
};

// 可制御マトリックス
// 可観測マトリックス

}
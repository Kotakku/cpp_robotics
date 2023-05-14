#pragma once

#include <Eigen/Dense>
#include <Eigen/../unsupported/Eigen/MatrixFunctions>
#include <optional>
#include "discret.hpp"

namespace cpp_robotics
{

/**
 * @brief 状態空間モデル
 * 
 */
class StateSpaceSystem
{
public:
    StateSpaceSystem() = default;

    template<typename DerivedA, typename DerivedB, typename DerivedC>
    StateSpaceSystem(const Eigen::MatrixBase<DerivedA> &A, const Eigen::MatrixBase<DerivedB> &B, const Eigen::MatrixBase<DerivedC> &C, const double Ts)
    {
        set_continuous(A, B, C, Ts);
    }

    template<typename DerivedA, typename DerivedB, typename DerivedC>
    void set_continuous(const Eigen::MatrixBase<DerivedA> &A, const Eigen::MatrixBase<DerivedB> &B, const Eigen::MatrixBase<DerivedC> &C, const double Ts, const bool skip_state_reset = false)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == B.rows());
        assert(A.cols() == C.cols());
        
        state_size_ = A.rows();
        input_size_ = B.cols();
        output_size_ = C.rows();

        A_ = A;
        B_ = B;
        Ts_ = Ts;
        std::tie(Ad_, Bd_) = Discret::discritize(A, B, Ts);
        Cd_ = C;

        if(not skip_state_reset)
            set_state_zero();
    }

    template<typename DerivedA, typename DerivedB, typename DerivedC>
    void set_discrite(const Eigen::MatrixBase<DerivedA> &Ad, const Eigen::MatrixBase<DerivedB> &Bd, const Eigen::MatrixBase<DerivedC> &Cd, const double Ts, const bool skip_state_reset = false)
    {
        assert(Ad.rows() == Ad.cols());
        assert(Ad.rows() == Bd.rows());
        assert(Ad.cols() == Cd.cols());
        
        state_size_ = Ad.rows();
        input_size_ = Bd.cols();
        output_size_ = Cd.rows();

        A_ = std::nullopt;
        B_ = std::nullopt;
        Ts_ = Ts;
        
        Ad_ = Ad;
        Bd_ = Bd;
        Cd_ = Cd;

        if(not skip_state_reset)
            set_state_zero();
    }

    size_t state_size() const { return state_size_; }
    size_t input_size() const { return input_size_; }
    size_t output_size() const { return output_size_; }

    bool is_siso_model() const { return (input_size() == 1 && output_size() == 1); }

    inline void set_state_zero()
    {
        set_state(Eigen::VectorXd::Zero(state_size()));
    }

    void set_state(const Eigen::VectorXd &x)
    {
        x_ = x;
    }

    void set_state(const double &x)
    {
        assert(input_size() == 1 && output_size() == 1);
        Eigen::VectorXd x_vec(1);
        x_vec(0) = x;
        set_state(x_vec);
    }

    auto responce(const Eigen::VectorXd &u)
    {
        x_ = Ad_*x_ + Bd_*u;
        return Cd_*x_;
    }

    double responce(double u)
    {
        assert(input_size() == 1 && output_size() == 1);
        Eigen::VectorXd u_vec(1);
        u_vec(0) = u;
        return responce(u_vec)(0);
    }

    std::optional<Eigen::MatrixXd> A() const { return A_; }
    std::optional<Eigen::MatrixXd> B() const { return B_; }
    double Ts() const { return Ts_; }

    Eigen::MatrixXd Ad() const { return Ad_; }
    Eigen::MatrixXd Bd() const { return Bd_; }

    Eigen::MatrixXd C()  const { return Cd_; }
    Eigen::MatrixXd Cd() const { return Cd_; }

    Eigen::VectorXd x() const { return x_; }
    Eigen::VectorXd y() const { return Cd_*x_; }

private:
    Eigen::MatrixXd Ad_;
    Eigen::MatrixXd Bd_;
    Eigen::MatrixXd Cd_;

    std::optional<Eigen::MatrixXd> A_;
    std::optional<Eigen::MatrixXd> B_;
    double Ts_;

    size_t state_size_;
    size_t input_size_;
    size_t output_size_;

    Eigen::VectorXd x_;
};

}
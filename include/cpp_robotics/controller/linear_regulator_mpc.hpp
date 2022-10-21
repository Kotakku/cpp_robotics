#pragma once

#include <utility>
#include <optional>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/quadprog.hpp>

namespace cpp_robotics
{

class LinearRegulatorMPC
{
public:
    LinearRegulatorMPC(const Eigen::MatrixXd &Ad, const Eigen::MatrixXd &Bd, const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R, const Eigen::MatrixXd &Qf, const size_t N, std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit = std::nullopt):
        Ad_(Ad), Bd_(Bd), Q_(Q), R_(R), Qf_(Qf), N_(N), u_limit_(u_limit)
    {
        // 正方行列
        assert(Ad_.rows() == Ad_.cols());
        assert(Q_.rows()  == Q_.cols());
        assert(Qf_.rows() == Qf_.cols());
        assert(R_.rows()  == R_.cols());

        // 
        assert(Ad_.rows() == Bd_.rows());
        assert(Q_.rows() == Qf_.rows());
        assert(Ad_.rows() == Q_.rows());
        assert(Bd_.cols() == R_.cols());

        input_size_ = Bd_.cols();
        state_size_ = Ad_.rows();

        // Nステップ分の行列表現
        Eigen::MatrixXd Ad_mat_ = Eigen::MatrixXd::Zero(state_size_*N_, state_size_);
        Eigen::MatrixXd Bd_mat_ = Eigen::MatrixXd::Zero(state_size_*N_, input_size_*N_);
        Eigen::MatrixXd Q_mat_ = Eigen::MatrixXd::Zero(state_size_*N_, state_size_*N_);
        Eigen::MatrixXd R_mat_ = Eigen::MatrixXd::Zero(input_size_*N_, input_size_*N_);

        Eigen::MatrixXd tmp = Ad_;
        for(size_t i = 0; i < N_; i++)
        {
            Ad_mat_.block(state_size_*i, 0, state_size_, state_size_) = tmp;
            tmp *= Ad_;
        }

        tmp = Bd_;
        for(size_t i = 0; i < N_; i++)
        {
            // 右下方向に埋めていく
            for(size_t j = 0; j < N_-i; j++)
            {
                Bd_mat_.block(state_size_*(i+j), input_size_*j, state_size_, input_size_) = tmp;
            }
            tmp = Ad_ * tmp;
        }

        for(size_t i = 0; i < N_-1; i++)
        {
            Q_mat_.block(state_size_*i, state_size_*i, state_size_, state_size_) = Q_;
        }
        Q_mat_.block(state_size_*(N_-1), state_size_*(N_-1), state_size_, state_size_) = Qf_;

        for(size_t i = 0; i < N_; i++)
        {
            R_mat_.block(input_size_*i, input_size_*i, input_size_, input_size_) = R_;
        }

        H_ = Bd_mat_.transpose()*Q_mat_*Bd_mat_ + R_mat_;
        g_ = Bd_mat_.transpose()*Q_mat_*Ad_mat_;
        qp_solver_.Q = H_;

        if(u_limit_)
        {
            // Todo infinityがあったら制限なしということでG_mat_, h_mat_にいれない操作をする
            Eigen::MatrixXd G_mat_ = Eigen::MatrixXd::Zero(input_size_*N_*2, input_size_*N_);
            Eigen::VectorXd h_mat_ = Eigen::VectorXd::Zero(input_size_*N_*2);

            G_mat_.block(0,0,input_size_*N_, input_size_*N_) = Eigen::MatrixXd::Identity(input_size_*N_, input_size_*N_);
            G_mat_.block(input_size_*N_,0,input_size_*N_, input_size_*N_) = -Eigen::MatrixXd::Identity(input_size_*N_, input_size_*N_);

            auto &[umin, umax] = u_limit_.value();
            for(size_t i = 0; i < N_; i++)
            {
                h_mat_.segment(input_size_*i, input_size_) = umax;
                h_mat_.segment(input_size_*(N_+i), input_size_) = -umin;
            }

            qp_solver_.A = G_mat_;
            qp_solver_.b = h_mat_;
        }

        U_ = Eigen::VectorXd::Zero(input_size_*N_);
    }

    void set_initial_input(const std::vector<Eigen::VectorXd> &u0)
    {
        assert(u0.size() == N_);
    }

    std::tuple<bool, Eigen::VectorXd> control(const Eigen::VectorXd &x0, bool warm_start = true)
    {
        assert(x0.size() == (Eigen::VectorXd::Index)(state_size_));

        qp_solver_.c = (g_*x0).transpose();
        latest_qp_result_ = qp_solver_.solve(U_);

        if(latest_qp_result_.is_solved)
        {
            if(warm_start)
            {
                U_ = latest_qp_result_.x;
            }

            return {true, latest_qp_result_.x.head(input_size_)};
        }
        else
        {
            std::cout << "???" << std::endl;
        }
        
        return {false, Eigen::VectorXd::Zero(input_size_)};
    }

    QuadProg::Result latest_qp_result() const { return latest_qp_result_; }

    Eigen::MatrixXd Ad() const { return Ad_; }
    Eigen::MatrixXd Bd() const { return Bd_; }
    Eigen::MatrixXd Q() const { return Q_; }
    Eigen::MatrixXd R() const { return R_; }
    Eigen::MatrixXd Qf() const { return Qf_; }
    size_t N() const { return N_; }

private:
    // システム
    const Eigen::MatrixXd Ad_;
    const Eigen::MatrixXd Bd_;
    const Eigen::MatrixXd Q_;
    const Eigen::MatrixXd R_;
    const Eigen::MatrixXd Qf_;
    const size_t N_;
    const std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit_;
    size_t input_size_;
    size_t state_size_;

    // QPソルバ用の評価関数の２次形表現
    Eigen::MatrixXd H_;
    Eigen::MatrixXd g_;
    
    // QPソルバ
    QuadProg qp_solver_;
    Eigen::VectorXd U_;
    QuadProg::Result latest_qp_result_;
};

}
#pragma once

#include <Eigen/Dense>
#include <vector>
#include <optional>
#include <cpp_robotics/system/discret.hpp>

namespace cpp_robotics
{


class DiscreteLinearOCP
{
public:
    Eigen::MatrixXd Ad;
    Eigen::MatrixXd Bd;
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
    Eigen::MatrixXd Qf;
    size_t N;
    std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit;
    std::vector<Eigen::VectorXd> x_ref; // x[0]...x[N]の参照軌道

    static DiscreteLinearOCP from_continuous(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R, const Eigen::MatrixXd &Qf, const double dt, const size_t N, std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit = std::nullopt)
    {
        auto [Ad, Bd] = Discret::discritize(A, B, dt);
        return DiscreteLinearOCP(Ad, Bd, Q, R, Qf, N, u_limit);
    }

    DiscreteLinearOCP(const Eigen::MatrixXd &Ad, const Eigen::MatrixXd &Bd, const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R, const Eigen::MatrixXd &Qf, const size_t N, std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit = std::nullopt):
        Ad(Ad), Bd(Bd), Q(Q), R(R), Qf(Qf), N(N), u_limit(u_limit)
    {
        // 正方行列
        assert(Ad.rows() == Ad.cols());
        assert(Q.rows()  == Q.cols());
        assert(Qf.rows() == Qf.cols());
        assert(R.rows()  == R.cols());

        // 行列・ベクトル同士のサイズ確認
        assert(Ad.rows() == Bd.rows());
        assert(Q.rows() == Qf.rows());
        assert(Ad.rows() == Q.rows());
        assert(Bd.cols() == R.cols());

        x_ref.resize(N+1);
        for (size_t i = 0; i < N+1; ++i)
        {
            x_ref[i] = Eigen::VectorXd::Zero(state_size());
        }
    }

    size_t input_size() const
    {
        return Bd.cols();
    }

    size_t state_size() const
    {
        return Ad.rows();
    }

    size_t horizon() const
    {
        return N;
    }

    auto model(auto x, auto u) const
    {
        return Ad * x + Bd * u;
    }

    double running_cost(auto x, auto u, size_t i) const
    {
        Eigen::VectorXd e = x - x_ref[i];
        return (e.transpose() * Q * e + u.transpose() * R * u)[0];
    }

    double terminal_cost(auto x) const
    {
        Eigen::VectorXd e = x - x_ref.back();
        return (e.transpose() * Qf * e)[0];
    }

    void set_x_ref(const Eigen::VectorXd &x_ref)
    {
        for (size_t i = 0; i < N+1; ++i)
        {
            this->x_ref[i] = x_ref;
        }
    }
};

class DiscreteNonlinearOCP
{

};

}
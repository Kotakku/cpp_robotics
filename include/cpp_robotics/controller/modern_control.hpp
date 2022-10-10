#pragma once

#include <array>
#include <Eigen/Dense>
#include "../system/state_space_system.hpp"
#include "../system/polynomial.hpp"

namespace cpp_robotics
{
    /**
     * @brief 可制御性行列の計算
     * 
     * @param A 
     * @param B 
     * @return Eigen::MatrixXd 
     */
    static Eigen::MatrixXd controllability_matrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& B)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == B.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uc(dim, dim);
        Eigen::VectorXd colv = B;

        for(int i = 0; i < dim; i++)
        {
            Uc.col(i) = colv;
            colv = A * colv;
        }

        return Uc;
    }

    /**
     * @brief 可制御性の判別
     * 
     * @param A 
     * @param B 
     * @return true システムが可制御である
     * @return false システムが可制御でない
     */
    static bool is_controllable(const Eigen::MatrixXd& A, const Eigen::VectorXd& B)
    {
        const int dim = A.rows();
        Eigen::FullPivLU<Eigen::MatrixXd> lu(controllability_matrix(A, B));
        return (lu.rank() == dim);
    }
    
    static bool is_controllable(const StateSpaceSystem& sys)
    {
        return is_controllable(sys.A().value(), sys.B().value());
    }

    /**
     * @brief 可観測性行列を計算する
     * 
     * @param A 
     * @param C 
     * @return Eigen::MatrixXd 
     */
    static Eigen::MatrixXd observability_matrix(const Eigen::MatrixXd& A, const Eigen::RowVectorXd& C)
    {
        assert(A.rows() == A.cols());
        assert(A.rows() == C.size());
        const int dim = A.rows();

        Eigen::MatrixXd Uo(dim, dim);
        Eigen::RowVectorXd colv = C;

        for(int i = 0; i < dim; i++)
        {
            Uo.row(i) = colv;
            colv = colv * A;
        }

        return Uo;
    }

    /**
     * @brief 可観測性の判別
     * 
     * @param A 
     * @param C 
     * @return true システムが可観測である
     * @return false システムが可観測でない
     */
    static bool is_observable(const Eigen::MatrixXd& A, const Eigen::RowVectorXd& C)
    {
        const int dim = A.rows();
        Eigen::FullPivLU<Eigen::MatrixXd> lu(observability_matrix(A, C));
        return (lu.rank() == dim);
    }

    /**
     * @brief 
     * 
     * @param sys 可観測性の判別
     * @return true システムが可観測である
     * @return false システムが可観測でない
     */
    static bool is_observable(const StateSpaceSystem& sys)
    {
        return is_observable(sys.A().value(), sys.C());
    }

    enum class CanonicalizeMode
    {
        // MODEL,
        COMPANION,
        OBSERBAVLE,
        CONTROLLABLE
    };

    // https://www.mathworks.com/help/control/ug/canonical-state-space-realizations.html
    /**
     * @brief 同値変換による可制御正準形への変換
     * 
     * @param A 
     * @param B 
     * @param C 
     * @param mode 
     * @return std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> 
     */
    static std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> canonicalize_system(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& C, CanonicalizeMode mode = CanonicalizeMode::COMPANION)
    {
        // if(mode == MODEL)
        // else
        if(mode == CanonicalizeMode::CONTROLLABLE || mode == CanonicalizeMode::COMPANION || mode == CanonicalizeMode::OBSERBAVLE)
        {
            if(mode == CanonicalizeMode::CONTROLLABLE)
            {
                auto [A_tilda, B_tilda, C_tilda] = canonicalize_system(A, B, C, CanonicalizeMode::COMPANION);
                return {
                    A_tilda.transpose(),
                    C_tilda.transpose(),
                    B_tilda.transpose()
                };
            }
            else
            {
                Eigen::MatrixXd Uc = controllability_matrix(A, B);
                Eigen::MatrixXd Ucinv = Uc.inverse();
                return {
                    Ucinv*A*Uc,
                    Ucinv*B,
                    C*Uc
                };
            }
        }

        return canonicalize_system(A, B, C, CanonicalizeMode::COMPANION);
    }

    /**
     * @brief 同値変換による可制御正準形への変換
     * 
     * @param sys 
     * @param mode 
     * @return std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> 
     */
    static std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> canonicalize_system(const StateSpaceSystem& sys, CanonicalizeMode mode = CanonicalizeMode::COMPANION)
    {
        return canonicalize_system(sys.A().value(), sys.B().value(), sys.C(), mode);
    }

    // https://ossyaritoori.hatenablog.com/entry/2018/05/16/%E6%A5%B5%E9%85%8D%E7%BD%AE%E3%81%AE%E5%AE%9F%E8%A3%85%EF%BC%9A%E3%82%A2%E3%83%83%E3%82%AB%E3%83%BC%E3%83%9E%E3%83%B3%E6%B3%95%E3%81%AEMATLAB%E5%AE%9F%E8%A3%85#Outline
    /**
     * @brief アッカーマン法によるSISOモデルの極配置
     * 
     * @param sys 
     * @param poles 
     * @return Eigen::VectorXd 
     */
    static Eigen::VectorXd place(const StateSpaceSystem& sys, std::vector<double> poles)
    {
        assert(sys.state_size() == poles.size());
        assert(sys.is_siso_model());

        auto pole_poly = Polynomial::expand(poles);

        auto Uc = controllability_matrix(sys.A().value(), sys.B().value());

        Eigen::MatrixXd tmp = Eigen::MatrixXd::Zero(sys.state_size(), sys.state_size());
        Eigen::MatrixXd An = Eigen::MatrixXd::Identity(sys.state_size(), sys.state_size());

        for(size_t i = 0; i < sys.state_size(); i++)
        {
            tmp += pole_poly.at_degree(i)*An;
            An *= sys.A().value();
        }
        tmp += An;

        return (Uc.inverse() * tmp).row(sys.state_size()-1);
    }

    // 可制御正準形の\tilda{A}の係数比較により極配置を行う
    // https://www.youtube.com/watch?v=yiFgI6Oos88
//     static Eigen::VectorXd place(const StateSpaceSystem& sys, std::vector<double> poles)
//     {

//     }
}
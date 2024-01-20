#pragma once

#include <Eigen/Dense>
#include "./newton_method.hpp"

namespace cpp_robotics
{

// min 1/2 x^T Q x + cx
// s.t. Ax <= b
// x 等式制約は2つの不等式制約に変換する
// o 等式制約は常にアクティブであるとする
/**
 * @brief 線形不等式制約を持つ2次計画法を解く有効制約法
 * 
 */
class ActiveSetMethod
{
public:
    struct Problem
    {
        Problem() = default;
        // Problem(size_t x_size_, size_t constraint_size_)
        // {
        //     x_size = x_size_;
        //     constraint_size = constraint_size_;
        //     Q = Eigen::MatrixXd::Zero(x_size, x_size);
        //     c = Eigen::VectorXd::Zero(x_size_);
        //     A = Eigen::MatrixXd::Zero(constraint_size, x_size_);
        //     b = Eigen::VectorXd::Zero(constraint_size);
        // }

        Problem(size_t x_size_)
        {
            x_size = x_size_;
            Q = Eigen::MatrixXd::Zero(x_size, x_size);
            c = Eigen::VectorXd::Zero(x_size_);
        }

        // Ax <= b の制約を追加する
        void add_inequality_constraint(const Eigen::MatrixXd &An, Eigen::VectorXd bn)
        {
            // for(Eigen::MatrixXd::Index i = 0; i < An.rows(); i++)
            // {
            //     if(An.row(i).norm() < 1e-9)
            //         return;
            // }

            if(A.cols() != 0)
            {
                assert(A.cols() == An.cols());
                Eigen::MatrixXd new_A(A.rows() + An.rows(), A.cols());
                new_A << A, An;
                A = new_A;
            }
            else
            {
                A = An;
            }

            if(b.cols() != 0)
            {
                Eigen::VectorXd new_b(b.rows() + bn.rows());
                new_b << b, bn;
                b = new_b;
            }
            else
            {
                b = bn;
            }

            // std::cout << "add A" << std::endl << A << std::endl;
            // std::cout << "add b" << std::endl << b << std::endl;
            

            assert(A.rows() == b.rows());
            constraint_size = A.rows();
        }

        // Ax = b の制約を追加する
        void add_equality_constraint(const Eigen::MatrixXd &An, Eigen::VectorXd bn)
        {
            (void) An;
            (void) bn;
        }
        
        Eigen::MatrixXd Q;
        Eigen::VectorXd c;
        Eigen::MatrixXd A;
        Eigen::VectorXd b;

        size_t max_iter = 1000;
        size_t max_iter_get_initial_feasible_x = 1000;

        size_t x_size = 0; 
        size_t constraint_size = 0;

        double alpha = 1.1;
    };

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x_opt;
        Eigen::VectorXd lambda_opt;
        size_t iter_cnt = 0;
    };

    Result solve(Problem prob, Eigen::VectorXd x)
    {
        prob_ = prob;
        Result result;

        // 制約がない場合はニュートン法で解く
        if(prob_.constraint_size == 0)
        {
            auto grad = [&](const Eigen::VectorXd &x) { return (prob_.Q * x + prob_.c); };
            auto hess = [&](const Eigen::VectorXd &x) { (void) x; return  prob_.Q; };
            std::tie(result.is_solved, result.x_opt, result.iter_cnt) = 
                newton_method(grad, hess, x, 1e-6, prob_.max_iter);
            return result;
        }

        // std::cout << "--------------------" << std::endl;
        // std::cout << "Q" << std::endl << prob_.Q << std::endl;
        // std::cout << "c" << std::endl << prob_.c << std::endl;
        // std::cout << "A" << std::endl << prob_.A << std::endl;
        // std::cout << "b" << std::endl << prob_.b << std::endl;
        

        // 初期値のチェック
        if(not discrimination_feasiblity(x))
        {
            // std::cout << "初期値が実行不可能" << std::endl;
            x = get_initial_feasible_x(x);
        }
        
        auto active_idx = active_set_index(x);

        // debug
        // std::cout << "active_idx" << std::endl;
        // std::for_each(active_idx.begin(), active_idx.end(), [&](auto idx)
        // {
        //     std::cout << "- " << idx << std::endl;
        // });

        // 解無し
        if (not discrimination_feasiblity(x))
        {
            // std::cout << "解無し & 修正不可能" << std::endl;
            return result;
        }

        // 反復計算
        result.is_solved = false;
        for(result.iter_cnt = 0; result.iter_cnt < prob_.max_iter; result.iter_cnt++)
        {
            if(result.is_solved)
                break;

            auto [x_hat, lambda_hat] = get_solution(active_idx);

            // std::cout << "x_hat = " << std::endl;
            // std::cout << x_hat.transpose() << std::endl << std::endl;
            
            // std::cout << "lambda_hat = " << std::endl;
            // std::cout << lambda_hat.transpose() << std::endl << std::endl;

            if(not discrimination_feasiblity(x_hat))
            {
                // std::cout << "実行不可能 & x_hat_dash 修正" << std::endl;
                // 実行可能領域の外に出たので中に戻す
                x = get_x_hat_dash(x_hat, x);
                x_hat = x;
                active_idx = active_set_index(x);

                // std::cout << "x_hat_dash" << std::endl;
                // std::cout << x << std::endl;
                
            }
            else
            {
                // std::cout << "実行可能" << std::endl;
                // 最適性の判別
                if((lambda_hat.array()>=0.0).count() == lambda_hat.rows())
                {
                    // ラムダが全て負の値でない = 全ての制約を満たす 
                    result.is_solved = true;
                }
                else
                {
                    // lambda_i < 0 が存在する実行不可能解
                    // lambda_hatの最小値を削除してlambdaとする
                    Eigen::VectorXd::Index min_idx;
                    lambda_hat.minCoeff(&min_idx);
                    for(auto itr = active_idx.begin(); itr != active_idx.end(); itr++)
                    {
                        if(*itr == static_cast<size_t>(min_idx))
                        {
                            active_idx.erase(itr);
                            break;
                        }
                    }
                    std::sort(active_idx.begin(), active_idx.end());
                }
            }

            result.x_opt = x_hat;
            result.lambda_opt = lambda_hat;
        }

        return result;
    }

private:
    auto f(const Eigen::VectorXd &x) const
    {
        return (0.5 * x.transpose() * prob_.Q * x + prob_.c * x);
    }

    auto grad_f(const Eigen::VectorXd &x) const
    {
        return (prob_.Q * x + prob_.c);
    }

    auto g(const Eigen::VectorXd &x) const
    {
        return (prob_.A*x - prob_.b);
    }

    auto grad_g(void) const
    {
        return prob_.A;
    }

    std::vector<size_t> active_set_index(const Eigen::VectorXd &x) const
    {
        auto gval = g(x);

        std::vector<size_t> idx;
        idx.reserve(gval.rows());
        for(Eigen::VectorXd::Index i = 0; i < gval.rows(); i++)
        {
            if(std::abs(gval(i)) < eps_)
                idx.push_back(i);
        }
        return idx;
    }

    std::pair<Eigen::VectorXd, Eigen::VectorXd> get_solution(const std::vector<size_t> &active_idx) const
    {
        size_t m = prob_.A.rows();
        size_t n = prob_.A.cols();

        Eigen::VectorXd x_hat, lambda_hat;
        // std::cout << "active_idx.size(): " << active_idx.size() << std::endl;
        if(active_idx.size() == 0)
        {
            // 有効制約なし
            x_hat = prob_.Q.inverse() * -prob_.c;
            lambda_hat = Eigen::VectorXd::Zero(m);
        }
        else
        {
            // 有効制約あり
            Eigen::MatrixXd Aq = Eigen::MatrixXd::Zero(active_idx.size(), prob_.A.cols());
            Eigen::VectorXd bq = Eigen::VectorXd::Zero(active_idx.size());

            for(size_t i = 0; i < active_idx.size(); i++)
            {
                Aq.row(i) = prob_.A.row(active_idx[i]);
                bq.row(i) = prob_.b.row(active_idx[i]);
            }

            // std::cout << "Aq= " << std::endl;
            // std::cout << Aq << std::endl << std::endl;
            // std::cout << "bq= " << std::endl;
            // std::cout << bq << std::endl << std::endl;


            size_t mq = Aq.rows();
            // size_t nq = Aq.cols(); // = n
            
            // tmp_a = | Aq   0   |
            //         | Q   Aq^T |
            Eigen::MatrixXd tmp_a = Eigen::MatrixXd::Zero(mq+n, mq+n);

            tmp_a.block(0,  0, mq, n)  = Aq;
            tmp_a.block(mq, 0, n, n) = prob_.Q;
            tmp_a.block(mq, n, n,  mq) = Aq.transpose();

            // tmp_b = | bq |
            //         | c  |
            Eigen::VectorXd tmp_b = Eigen::VectorXd(mq+n);
            tmp_b << bq, -prob_.c;

            
            // std::cout << "tmp_a= " << std::endl;
            // std::cout << tmp_a << std::endl << std::endl;
            // std::cout << "tmp_b= " << std::endl;
            // std::cout << tmp_b << std::endl << std::endl;
            
            Eigen::VectorXd p_hat = tmp_a.fullPivLu().solve(tmp_b);

            // std::cout << "p_hat.size()= " << p_hat.size() << std::endl;
            
            // std::cout << "p_hat= " << std::endl;
            // std::cout << p_hat << std::endl << std::endl;

            x_hat = p_hat.head(n);
            lambda_hat = Eigen::VectorXd::Zero(m);
            for(size_t i = 0; i < mq; i++)
            {
                lambda_hat(active_idx[i]) = p_hat(n + i);
            }

            // std::cout << "x_hat= " << std::endl;
            // std::cout << x_hat << std::endl << std::endl;

            // std::cout << "lambda_hat= " << std::endl;
            // std::cout << lambda_hat << std::endl << std::endl;
        }
        return {x_hat, lambda_hat};
    }

    // xが実行不可能であった場合に実行可能なxを返す
    // 最適性は問わない
    Eigen::VectorXd get_initial_feasible_x(Eigen::VectorXd x)
    {
        for(size_t i = 0; i < prob_.max_iter_get_initial_feasible_x; i++)
        {
            auto gval = g(x);

            // std::cout << "gval:" << std::endl;
            // std::cout << gval.transpose() << std::endl;

            size_t max_g_idx = 0;
            gval.maxCoeff(&max_g_idx);

            // std::cout << "max_g_idx: " << max_g_idx << std::endl;

            x -= prob_.alpha * grad_g().row(max_g_idx) * std::abs( (prob_.A.row(max_g_idx) * x - prob_.b.row(max_g_idx))(0) ) / prob_.A.row(max_g_idx).squaredNorm();

            // std::cout << "new x:" << std::endl;
            // std::cout << x.transpose() << std::endl;
            if(discrimination_feasiblity(x))
                break;
        }

        return x;
    }

    // xが全ての成約に対して実行可能かチェックする
    bool discrimination_feasiblity(const Eigen::VectorXd &x) const
    {
        bool is_feasible = true;
        auto gval = g(x);

        // g(x) <= 0 を満たさないものが一つでもあれば実行可能領域外にいる
        if((gval.array() > eps_).count() > 0)
            is_feasible = false;
        return is_feasible;
    }

    // x_hatが実行不可能, xが実行可能だとして実行可能なx_hat_dashを生成する
    Eigen::VectorXd get_x_hat_dash(Eigen::VectorXd x_hat, Eigen::VectorXd x)
    {
        double t = get_t(x_hat, x);

        // std::cout << "t = " << t << std::endl;
        // std::cout << "x:" << std::endl;
        // std::cout << x.transpose() << std::endl;
        // std::cout << "x_hat:" << std::endl;
        // std::cout << x_hat.transpose() << std::endl;

        return x + t * (x_hat - x);
    }

    double get_t(Eigen::VectorXd x_hat, Eigen::VectorXd x)
    {
        Eigen::VectorXd gg = prob_.A * (x_hat - x);

        for(Eigen::VectorXd::Index i = 0; i < gg.size(); i++)
        {
            if(std::abs(gg(i)) < eps_)
                gg(i) = eps_;
        }

        // std::cout << "gg:" << std::endl;
        // std::cout << gg.transpose() << std::endl;

        auto T = -g(x).array() / gg.array();
        auto T_selected = (T.array() > 0.0); // T_selectedは0/1のバイナリ型

        Eigen::VectorXd T_nn(T_selected.count());
        size_t row = 0;
        for(Eigen::VectorXd::Index i = 0; i < T.size(); i++)
        {
            if(T_selected[i])
                T_nn(row++) = T(i);
        }

        // std::cout << "-g(x):" << std::endl;
        // std::cout << (-g(x)).transpose() << std::endl;
        // std::cout << "gg:" << std::endl;
        // std::cout << gg.transpose() << std::endl;
        // std::cout << "T:" << std::endl;
        // std::cout << T.transpose() << std::endl;
        // std::cout << "T_nn:" << std::endl;
        // std::cout << T_nn.transpose() << std::endl;

        if(T_selected.count() != 0)
        {
            // T_i > 0 を満たすようそのうち最小のT_iを返す
            return T_nn.minCoeff();
        }

        return 0.0;
    }

    Problem prob_;
    static constexpr double eps_ = 1e-9;
};

}
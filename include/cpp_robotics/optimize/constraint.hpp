#pragma once

#include <cmath>
#include <functional>
#include <vector>
#include <optional>
#include <numeric>
#include <variant>
#include <Eigen/Dense>
#include "derivative.hpp"

namespace cpp_robotics
{

/**
 * @brief 数理最適問題に使用する制約クラス
 * 
 */
struct Constraint
{
    using func_type = std::function<double(Eigen::VectorXd)>;
    using grad_func_type = std::function<Eigen::VectorXd(Eigen::VectorXd)>;
    using hessian_func_type = std::function<Eigen::MatrixXd(Eigen::VectorXd)>;
    
    enum Type : uint8_t
    {
        // g(x) = 0
        Eq,

        // g(x) <= 0
        Ineq,

        // undefined
        None
    };
    
    Type type;
    func_type con_f;
    std::optional<grad_func_type> con_grad_f;
    std::optional<hessian_func_type> con_hessian_f;

    Constraint():
        type(Type::None), con_f([](Eigen::VectorXd x) { (void)x; return 0; }) {}
    Constraint(Type type_, func_type con_):
        type(type_), con_f(con_) {}

    double eval(const Eigen::VectorXd &x) const
    {
        return con_f(x);
    }

    bool satisfy(const Eigen::VectorXd &x, const double tol) const
    {
        const double val = eval(x);
        if(type == Type::Eq)
        {
            return std::abs(val) < tol;
        }
        else
        {
            return val < tol;
        }
    }

    Eigen::VectorXd grad(Eigen::VectorXd x)
    {
        if(con_grad_f)
            return con_grad_f.value()(x);
        
        return derivative(con_f, x);
    }

    Eigen::MatrixXd hessian(Eigen::VectorXd x)
    {
        if(con_hessian_f)
            return con_hessian_f.value()(x);
        
        return approx_hessian(con_f, x);
    }
};

/**
 * @brief 数理最適化問題の制約の集合
 * 
 */
class ConstraintArray : public std::vector<Constraint>
{
    template<class Type1, class Type2>
    struct VariItem
    {
        using vari_type = std::variant<Type1, Type2>;
        // VariItem() = default;
        VariItem(Type1 val) { val_ = val; }
        VariItem(Type2 val) { val_ = val; }

        vari_type &item() { return val_; } 

    private:
        vari_type val_;
    };
public:
    // std::vector<Constraint>::size_type size() const
    // {
    //     return this->size();
    // }

    ConstraintArray() = default;
    ConstraintArray(std::initializer_list<Constraint> con):
        vector(con.begin(), con.end()) {}

    ConstraintArray(std::initializer_list<VariItem<Constraint, ConstraintArray>> cons)
    {
        for(auto c : cons)
        {
            if(std::holds_alternative<Constraint>(c.item()))
            {
                auto & cval = std::get<Constraint>(c.item());
                this->insert(this->end(), cval);
            }
            else
            {
                auto & cary = std::get<ConstraintArray>(c.item());
                this->insert(this->end(), cary.begin(), cary.end());
            }
        }
    }

    std::vector<double> eval(const Eigen::VectorXd &x) const
    {
        std::vector<double> val(this->size());
        for(size_t i = 0; i < this->size(); i++)
        {
            
            val[i] = this->at(i).eval(x);
        }
        return val;
    }

    double eval_sum(const Eigen::VectorXd &x) const
    {
        auto val = eval(x);
        return std::accumulate(val.begin(), val.end(), 0.0);
    }

    bool all_satisfy(const Eigen::VectorXd &x, const double tol) const
    {
        bool satisfy = true;

        for(auto & con : *this)
        {
            if(not con.satisfy(x, tol))
            {
                // std::cout << "not satisfy" << std::endl;
                satisfy = false;
            }
            // else
            // {
                // std::cout << "satisfy" << std::endl;
                // 
            // }
        }
        return satisfy;
    }

    std::vector<Constraint>::size_type eq_constraint_size() const
    {
        std::vector<Constraint>::size_type num = 0;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Eq)
                num++;
        }
        return num;
    }

    std::vector<Constraint>::size_type ineq_constraint_size() const
    {
        std::vector<Constraint>::size_type num = 0;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Ineq)
                num++;
        }
        return num;
    }

    std::vector<Constraint> gen_eq_constraint_list() const
    {
        std::vector<Constraint> ret;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Eq)
                ret.push_back(con);
        }
        return ret;
    }

    std::vector<Constraint> gen_ineq_constraint_list() const
    {
        std::vector<Constraint> ret;
        for(auto & con : *this)
        {
            if(con.type == Constraint::Type::Ineq)
                ret.push_back(con);
        }
        return ret;
    }
};

}
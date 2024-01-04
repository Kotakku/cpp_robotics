#pragma once

#include <Eigen/Dense>
#include <cpp_robotics/optimize/derivative.hpp>
#include <variant>
#include <optional>
#include <memory>

namespace cpp_robotics
{

enum OCPConstraintType : uint8_t
{
    Eq, // g(x) = 0
    Ineq // g(x) <= 0
};

class OCPConstraint
{
public:
    using SharedPtr = std::shared_ptr<OCPConstraint>;

    double eps = 1e-6;
    OCPConstraintType type;

    OCPConstraint():
        type(OCPConstraintType::Eq) {}
    OCPConstraint(OCPConstraintType type):
        type(type) {}

    virtual double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const = 0;

    bool satisfy(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const double tol) const
    {
        const double val = eval(x, u);
        if(type == OCPConstraintType::Eq)
        {
            return std::abs(val) < tol;
        }
        else
        {
            return val < tol;
        }
    }

    virtual Eigen::VectorXd grad_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return derivative([&](const Eigen::VectorXd &x){ return eval(x, u); }, x, eps);
    }

    virtual Eigen::VectorXd grad_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return derivative([&](const Eigen::VectorXd &u){ return eval(x, u); }, u, eps);
    }

    virtual Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return second_derivative([&](const Eigen::VectorXd &x){ return eval(x, u); }, x, eps);
    }

    virtual Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return second_derivative([&](const Eigen::VectorXd &u){ return eval(x, u); }, u, eps);
    }

    virtual Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        Eigen::MatrixXd Q(u.size(), x.size());

        for (int c = 0; c < x.size(); c++)
        {
            for (int r = 0; r < u.size(); r++)
            {
                Eigen::VectorXd e_u = Eigen::VectorXd::Zero(u.size());
                Eigen::VectorXd e_x = Eigen::VectorXd::Zero(x.size());
                e_u[r] = eps;
                e_x[c] = eps;

                double f_rc = eval(x + e_x, u + e_u) - eval(x + e_x, u - e_u) - eval(x - e_x, u + e_u) + eval(x - e_x, u - e_u);
                Q(r, c) = f_rc / (4 * eps * eps);
            }
        }

        return Q;
    }
};

class OCPConstraintArray : public std::vector<OCPConstraint::SharedPtr>
{
    template<class Type1, class Type2>
    struct VariItem
    {
        using vari_type = std::variant<Type1, Type2>;
        VariItem(Type1 val) { val_ = val; }
        VariItem(Type2 val) { val_ = val; }

        vari_type &item() { return val_; } 

    private:
        vari_type val_;
    };
public:
    OCPConstraintArray() = default;
    OCPConstraintArray(std::initializer_list<OCPConstraint::SharedPtr> con):
        vector(con.begin(), con.end()) {}

    OCPConstraintArray(std::initializer_list<VariItem<OCPConstraint::SharedPtr, OCPConstraintArray>> cons)
    {
        for(auto c : cons)
        {
            if(std::holds_alternative<OCPConstraint::SharedPtr>(c.item()))
            {
                auto & cval = std::get<OCPConstraint::SharedPtr>(c.item());
                this->insert(this->end(), cval);
            }
            else
            {
                auto & cary = std::get<OCPConstraintArray>(c.item());
                this->insert(this->end(), cary.begin(), cary.end());
            }
        }
    }

    using vector::push_back;
    void push_back(const OCPConstraintArray &cons)
    {
        this->insert(this->end(), cons.begin(), cons.end());
    }

    Eigen::VectorXd eval_all_vec(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        Eigen::VectorXd ret(size());
        for (size_t i = 0; i < size(); i++)
        {
            ret[i] = at(i)->eval(x, u);
        }
        return ret;
    }

    std::vector<double> eval_all(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        std::vector<double> ret(size());
        for (size_t i = 0; i < size(); i++)
        {
            ret[i] = at(i)->eval(x, u);
        }
        return ret;
    }
};

class OCPFunctionalConstraint : public OCPConstraint
{
public:
    using func_t = std::function<double(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
    using grad_func_t = std::function<Eigen::VectorXd(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
    using hessian_func_t = std::function<Eigen::MatrixXd(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
    
    OCPFunctionalConstraint(OCPConstraintType type, func_t f):
        OCPConstraint(type), f(f) {}

    func_t f;
    std::optional<grad_func_t> f_grad_x;
    std::optional<grad_func_t> f_grad_u;
    std::optional<hessian_func_t> f_hessian_xx;
    std::optional<hessian_func_t> f_hessian_ux;
    std::optional<hessian_func_t> f_hessian_uu;
    
    double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        return f(x, u);
    }

    Eigen::VectorXd grad_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        if(f_grad_x)
            return f_grad_x.value()(x, u);
        return OCPConstraint::grad_x(x, u);
    }

    Eigen::VectorXd grad_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        if(f_grad_u)
            return f_grad_u.value()(x, u);
        return OCPConstraint::grad_u(x, u);
    }

    Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        if(f_hessian_xx)
            return f_hessian_xx.value()(x, u);
        return OCPConstraint::hessian_xx(x, u);
    }

    Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        if(f_hessian_uu)
            return f_hessian_uu.value()(x, u);
        return OCPConstraint::hessian_uu(x, u);
    }

    Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        if(f_hessian_ux)
            return f_hessian_ux.value()(x, u);
        return OCPConstraint::hessian_ux(x, u);
    }
};

class OCPInputIndexedBoundConstraint : public OCPConstraint
{
public:
    enum BoundType : uint8_t
    {
        Lower,
        Upper
    };
    OCPInputIndexedBoundConstraint(BoundType type, size_t index, double bound_val, double scale = 1.0):
        OCPConstraint(OCPConstraintType::Ineq), type_(type), index_(index), bound_val_(bound_val), scale_(scale) {}

    double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        if(type_ == BoundType::Lower)
        {
            return scale_ * (bound_val_ - u[index_]); // lb <= u
        }
        else
        {
            return scale_ * (u[index_] - bound_val_); // u <= ub
        }
    }

    Eigen::VectorXd grad_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) u;
        return Eigen::VectorXd::Zero(x.size());
    }

    Eigen::VectorXd grad_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        Eigen::VectorXd grad = Eigen::VectorXd::Zero(u.size());
        if(type_ == BoundType::Lower)
        {
            grad[index_] = -scale_;
        }
        else
        {
            grad[index_] = scale_;
        }
        return grad;
    }

    Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) u;
        return Eigen::MatrixXd::Zero(x.size(), x.size());
    }

    Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        return Eigen::MatrixXd::Zero(u.size(), u.size());
    }

    Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        return Eigen::MatrixXd::Zero(u.size(), x.size());
    }

private:
    BoundType type_;
    size_t index_;
    double bound_val_;
    double scale_;
};

class OCPStateIndexedBoundConstraint : public OCPConstraint
{
public:
    enum BoundType : uint8_t
    {
        Lower,
        Upper
    };
    OCPStateIndexedBoundConstraint(BoundType type, size_t index, double bound_val, double scale = 1.0):
        OCPConstraint(OCPConstraintType::Ineq), type_(type), index_(index), bound_val_(bound_val), scale_(scale) {}

    double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) u;
        if(type_ == BoundType::Lower)
        {
            return scale_ * (bound_val_ - x[index_]); // lb <= x
        }
        else
        {
            return scale_ * (x[index_] - bound_val_); // x <= ub
        }
    }

    Eigen::VectorXd grad_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) u;
        Eigen::VectorXd grad = Eigen::VectorXd::Zero(x.size());
        if(type_ == BoundType::Lower)
        {
            grad[index_] = -scale_;
        }
        else
        {
            grad[index_] = scale_;
        }
        return grad;
    }

    Eigen::VectorXd grad_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        return Eigen::VectorXd::Zero(u.size());
    }

    Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) u;
        return Eigen::MatrixXd::Zero(x.size(), x.size());
    }

    Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        return Eigen::MatrixXd::Zero(u.size(), u.size());
    }

    Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        return Eigen::MatrixXd::Zero(u.size(), x.size());
    }

private:
    BoundType type_;
    size_t index_;
    double bound_val_;
    double scale_;
};

static OCPConstraintArray OCPInputBoundConstraints(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub, double slope = 10.0)
{
    assert(lb.size() == ub.size());

    const size_t input_size = lb.size();

    OCPConstraintArray constraints;
    for(size_t i = 0; i < input_size; i++)
    {
        // lb <= u
        constraints.push_back(
            std::make_shared<OCPInputIndexedBoundConstraint>(OCPInputIndexedBoundConstraint::BoundType::Lower, i, lb[i], slope));

        // u <= ub
        constraints.push_back(
            std::make_shared<OCPInputIndexedBoundConstraint>(OCPInputIndexedBoundConstraint::BoundType::Upper, i, ub[i], slope));
    }
    return constraints;
}

static OCPConstraintArray OCPStateBoundConstrants(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub, double slope = 10.0)
{
    assert(lb.size() == ub.size());

    const size_t state_size = lb.size();

    OCPConstraintArray constraints;
    for(size_t i = 0; i < state_size; i++)
    {
        // lb <= x
        constraints.push_back(
            std::make_shared<OCPStateIndexedBoundConstraint>(OCPStateIndexedBoundConstraint::BoundType::Lower, i, lb[i], slope));

        // x <= ub
        constraints.push_back(
            std::make_shared<OCPStateIndexedBoundConstraint>(OCPStateIndexedBoundConstraint::BoundType::Upper, i, ub[i], slope));
    }
    return constraints;
}

}
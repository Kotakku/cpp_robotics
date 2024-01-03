#pragma once

// #include <Eigen/Dense>
// #include <vector>
// #include <optional>
// #include <cpp_robotics/system/discret.hpp>
// #include <cpp_robotics/optimize/constraint.hpp>
// #include <cpp_robotics/optimize/derivative.hpp>

#include <cpp_robotics/controller/ocp_dynamics.hpp>
#include <cpp_robotics/controller/ocp_cost.hpp>
#include <cpp_robotics/controller/ocp_constraint.hpp>

namespace cpp_robotics
{

class OptimalControlProblem
{
public:
    std::shared_ptr<OCPDynamics> dynamics;
    std::shared_ptr<OCPCost> cost;
    OCPConstraintArray constraints;

    OptimalControlProblem() = default;
    OptimalControlProblem(OCPDynamics::SharedPtr dynamics, OCPCost::SharedPtr cost, const OCPConstraintArray &constraints):
        dynamics(dynamics), cost(cost), constraints(constraints) {}

    size_t input_size() const { return dynamics->input_size(); }
    size_t state_size() const { return dynamics->state_size(); }
    size_t horizon() const { return dynamics->horizon(); }

};


// class DiscreteLinearOCP
// {
// public:
//     Eigen::MatrixXd Ad;
//     Eigen::MatrixXd Bd;
//     Eigen::MatrixXd Q;
//     Eigen::MatrixXd R;
//     Eigen::MatrixXd Qf;
//     std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit; // lower, upper
//     std::vector<Eigen::VectorXd> x_ref; // x[0]...x[N]の参照軌道

//     static DiscreteLinearOCP from_continuous(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R, const Eigen::MatrixXd &Qf, const double dt, const size_t N, std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit = std::nullopt)
//     {
//         auto [Ad, Bd] = Discret::discritize(A, B, dt);
//         return DiscreteLinearOCP(Ad, Bd, Q, R, Qf, N, u_limit);
//     }

//     DiscreteLinearOCP(const Eigen::MatrixXd &Ad, const Eigen::MatrixXd &Bd, const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R, const Eigen::MatrixXd &Qf, const size_t N, std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit = std::nullopt):
//         Ad(Ad), Bd(Bd), Q(Q), R(R), Qf(Qf), u_limit(u_limit), N(N)
//     {
//         // 正方行列
//         assert(Ad.rows() == Ad.cols());
//         assert(Q.rows()  == Q.cols());
//         assert(Qf.rows() == Qf.cols());
//         assert(R.rows()  == R.cols());

//         // 行列・ベクトル同士のサイズ確認
//         assert(Ad.rows() == Bd.rows());
//         assert(Q.rows() == Qf.rows());
//         assert(Ad.rows() == Q.rows());
//         assert(Bd.cols() == R.cols());

//         x_ref.resize(N+1);
//         for (size_t i = 0; i < N+1; ++i)
//         {
//             x_ref[i] = Eigen::VectorXd::Zero(state_size());
//         }
//     }

//     size_t input_size() const
//     {
//         return Bd.cols();
//     }

//     size_t state_size() const
//     {
//         return Ad.rows();
//     }

//     size_t horizon() const
//     {
//         return N;
//     }

//     Eigen::VectorXd dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         return Ad * x + Bd * u;
//     }

//     double running_cost(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         Eigen::VectorXd e = x - x_ref[i];
//         return (e.transpose() * Q * e + u.transpose() * R * u)[0];
//     }

//     double terminal_cost(const Eigen::VectorXd &x) const
//     {
//         Eigen::VectorXd e = x - x_ref.back();
//         return (e.transpose() * Qf * e)[0];
//     }

//     void set_x_ref(const Eigen::VectorXd &x_ref)
//     {
//         for (size_t i = 0; i < N+1; ++i)
//         {
//             this->x_ref[i] = x_ref;
//         }
//     }

// private:
//     size_t N;
// };

// class OCPConstraint
// {
// public:
//     using func_type = std::function<double(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
//     using grad_func_type = std::function<Eigen::VectorXd(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
//     using hessian_func_type = std::function<Eigen::MatrixXd(const Eigen::VectorXd &, const Eigen::VectorXd &)>;
    
//     enum Type : uint8_t
//     {
//         // g(x) = 0
//         Eq,

//         // g(x) <= 0
//         Ineq,

//         // undefined
//         None
//     };
    
//     Type type;
//     func_type con_f;
//     std::optional<grad_func_type> con_grad_fx;
//     std::optional<grad_func_type> con_grad_fu;
//     std::optional<hessian_func_type> con_hessian_fxx;
//     std::optional<hessian_func_type> con_hessian_fux;
//     std::optional<hessian_func_type> con_hessian_fuu;

//     OCPConstraint(double eps = 1e-4):
//         type(Type::None), con_f([](const Eigen::VectorXd &x, const Eigen::VectorXd &u) { (void)x; (void)u; return 0; }), eps_(eps) {}
//     OCPConstraint(Type type, func_type con, double eps = 1e-4):
//         type(type), con_f(con), eps_(eps) {}

//     double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         return con_f(x, u);
//     }

//     bool satisfy(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const double tol) const
//     {
//         const double val = eval(x, u);
//         if(type == Type::Eq)
//         {
//             return std::abs(val) < tol;
//         }
//         else
//         {
//             return val < tol;
//         }
//     }

//     Eigen::VectorXd grad_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if(con_grad_fx)
//             return con_grad_fx.value()(x, u);
        
//         return derivative([&](const Eigen::VectorXd &x){ return con_f(x, u); }, x, eps_);
//     }

//     Eigen::VectorXd grad_fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if(con_grad_fu)
//             return con_grad_fu.value()(x, u);
        
//         return derivative([&](const Eigen::VectorXd &u){ return con_f(x, u); }, u, eps_);
//     }

//     Eigen::MatrixXd hessian_fxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if(con_hessian_fxx)
//             return con_hessian_fxx.value()(x, u);
        
//         return second_derivative([&](const Eigen::VectorXd &x){ return con_f(x, u); }, x, eps_);
//     }

//     Eigen::MatrixXd hessian_fuu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if(con_hessian_fuu)
//             return con_hessian_fuu.value()(x, u);
        
//         return second_derivative([&](const Eigen::VectorXd &u){ return con_f(x, u); }, u, eps_);
//     }

//     Eigen::MatrixXd hessian_fux(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if(con_hessian_fux)
//             return con_hessian_fux.value()(x, u);
        
//         Eigen::MatrixXd Q(u.size(), x.size());

//         for (int c = 0; c < x.size(); c++)
//         {
//             for (int r = 0; r < u.size(); r++)
//             {
//                 Eigen::VectorXd e_u = Eigen::VectorXd::Zero(u.size());
//                 Eigen::VectorXd e_x = Eigen::VectorXd::Zero(x.size());
//                 e_u[r] = eps_;
//                 e_x[c] = eps_;

//                 double f_rc = con_f(x + e_x, u + e_u) - con_f(x + e_x, u - e_u) - con_f(x - e_x, u + e_u) + con_f(x - e_x, u - e_u);
//                 Q(r, c) = f_rc / (4 * eps_ * eps_);
//             }
//         }

//         return Q;
//     }

// private:
//     double eps_;
// };

// class OCPConstraintArray : public std::vector<OCPConstraint>
// {
//     template<class Type1, class Type2>
//     struct VariItem
//     {
//         using vari_type = std::variant<Type1, Type2>;
//         // VariItem() = default;
//         VariItem(Type1 val) { val_ = val; }
//         VariItem(Type2 val) { val_ = val; }

//         vari_type &item() { return val_; } 

//     private:
//         vari_type val_;
//     };
// public:
//     OCPConstraintArray() = default;
//     OCPConstraintArray(std::initializer_list<OCPConstraint> con):
//         vector(con.begin(), con.end()) {}

//     OCPConstraintArray(std::initializer_list<VariItem<OCPConstraint, OCPConstraintArray>> cons)
//     {
//         for(auto c : cons)
//         {
//             if(std::holds_alternative<OCPConstraint>(c.item()))
//             {
//                 auto & cval = std::get<OCPConstraint>(c.item());
//                 this->insert(this->end(), cval);
//             }
//             else
//             {
//                 auto & cary = std::get<OCPConstraintArray>(c.item());
//                 this->insert(this->end(), cary.begin(), cary.end());
//             }
//         }
//     }

//     using std::vector<OCPConstraint>::push_back;
//     void push_back(const OCPConstraintArray &cons)
//     {
//         this->insert(this->end(), cons.begin(), cons.end());
//     }

//     Eigen::VectorXd eval_all_vec(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         Eigen::VectorXd ret(size());
//         for (size_t i = 0; i < size(); i++)
//         {
//             ret[i] = at(i).eval(x, u);
//         }
//         return ret;
//     }

//     std::vector<double> eval_all(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
//     {
//         std::vector<double> ret(size());
//         for (size_t i = 0; i < size(); i++)
//         {
//             ret[i] = at(i).eval(x, u);
//         }
//         return ret;
//     }
// };

// static OCPConstraintArray OCPInputBoundConstraints(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub, double slope = 10.0)
// {
//     assert(lb.size() == ub.size());

//     const size_t input_size = lb.size();

//     OCPConstraintArray constraints;
//     for(size_t i = 0; i < input_size; i++)
//     {
//         // lb <= u
//         OCPConstraint lb_bound(OCPConstraint::Type::Ineq, [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; return slope*(lb[i] - u[i]); });
//         lb_bound.con_grad_fx = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)u; return Eigen::VectorXd::Zero(x.size()); };
//         lb_bound.con_grad_fu = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; Eigen::VectorXd grad = Eigen::VectorXd::Zero(u.size()); grad[i] = -slope; return grad; };
//         lb_bound.con_hessian_fxx = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)u; return Eigen::MatrixXd::Zero(x.size(), x.size()); };
//         lb_bound.con_hessian_fuu = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; return Eigen::MatrixXd::Zero(u.size(), u.size()); };
//         lb_bound.con_hessian_fux = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ return Eigen::MatrixXd::Zero(u.size(), x.size()); };
//         constraints.push_back(lb_bound);

//         // u <= ub
//         OCPConstraint ub_bound(OCPConstraint::Type::Ineq, [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; return slope*(u[i] - ub[i]); });
//         ub_bound.con_grad_fx = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)u; return Eigen::VectorXd::Zero(x.size()); };
//         ub_bound.con_grad_fu = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; Eigen::VectorXd grad = Eigen::VectorXd::Zero(u.size()); grad[i] = slope; return grad; };
//         ub_bound.con_hessian_fxx = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)u; return Eigen::MatrixXd::Zero(x.size(), x.size()); };
//         ub_bound.con_hessian_fuu = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ (void)x; return Eigen::MatrixXd::Zero(u.size(), u.size()); };
//         ub_bound.con_hessian_fux = [=](const Eigen::VectorXd &x, const Eigen::VectorXd &u){ return Eigen::MatrixXd::Zero(u.size(), x.size()); };
//         constraints.push_back(ub_bound);
//     }
//     return constraints;
// }

// class DiscreteNonlinearOCP
// {
// public:
//     std::optional<std::pair<Eigen::VectorXd, Eigen::VectorXd>> u_limit; // lower, upper
//     OCPConstraintArray constraints;

//     DiscreteNonlinearOCP(size_t state_size, size_t input_size, size_t horizon):
//         state_size_(state_size), input_size_(input_size), horizon_(horizon)
//     {
//     }

//     size_t input_size() const
//     {
//         return input_size_;
//     }

//     size_t state_size() const
//     {
//         return state_size_;
//     }

//     size_t horizon() const
//     {
//         return horizon_;
//     }

//     virtual Eigen::VectorXd dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const = 0;
//     virtual double running_cost(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const = 0;
//     virtual double terminal_cost(const Eigen::VectorXd &x) const = 0;

// private:
//     const size_t state_size_;
//     const size_t input_size_;
//     const size_t horizon_;
// };


// template<class Model>
// class OCPDifferentiator
// {
//     static constexpr bool is_linear_ocp = std::is_base_of<DiscreteLinearOCP, Model>::value;
//     static constexpr bool is_nonlinear_ocp = std::is_base_of<DiscreteNonlinearOCP, Model>::value;
// public:
//     OCPDifferentiator(const Model &model, double eps = std::pow(std::numeric_limits<double>::epsilon(), 0.5)):
//         model_(model), eps_(eps) {}
    
//     // dynamics
//     Eigen::MatrixXd fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Ad;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return derivative([&](const Eigen::VectorXd &x){ return model_.dynamics(x, u); }, x, eps_);
//         }
//     }

//     Eigen::MatrixXd fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Bd;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return derivative([&](const Eigen::VectorXd &u){ return model_.dynamics(x, u); }, u, eps_);
//         }
//     }

//     // running cost
//     Eigen::VectorXd lx(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Q * (x - model_.x_ref[i]);
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return derivative([&](const Eigen::VectorXd &x){ return model_.running_cost(x, u, i); }, x, eps_);
//         }
//     }

//     Eigen::VectorXd lu(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.R * u;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return derivative([&](const Eigen::VectorXd &u){ return model_.running_cost(x, u, i); }, u, eps_);
//         }
//     }

//     Eigen::MatrixXd lxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Q;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return second_derivative([&](const Eigen::VectorXd &x){ return model_.running_cost(x, u, i); }, x, eps_);
//         }
//     }

//     Eigen::MatrixXd luu(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.R;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return second_derivative([&](const Eigen::VectorXd &u){ return model_.running_cost(x, u, i); }, u, eps_);
//         }
//     }

//     Eigen::MatrixXd lux(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t i) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return Eigen::MatrixXd::Zero(model_.input_size(), model_.state_size());
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             Eigen::MatrixXd Q(model_.input_size(), model_.state_size());

//             for (size_t c = 0; c < model_.state_size(); c++)
//             {
//                 for (size_t r = 0; r < model_.input_size(); r++)
//                 {
//                     Eigen::VectorXd e_u = Eigen::VectorXd::Zero(model_.input_size());
//                     Eigen::VectorXd e_x = Eigen::VectorXd::Zero(model_.state_size());
//                     e_u[r] = eps_;
//                     e_x[c] = eps_;

//                     double f_rc = model_.running_cost(x + e_x, u + e_u, i) - model_.running_cost(x + e_x, u - e_u, i) - model_.running_cost(x - e_x, u + e_u, i) + model_.running_cost(x - e_x, u - e_u, i);
//                     Q(r, c) = f_rc / (4 * eps_ * eps_);
//                 }
//             }

//             return Q;
//         }
//     }

//     // terminal cost
//     Eigen::VectorXd lNx(const Eigen::VectorXd &x) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Qf * (x - model_.x_ref.back());
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return derivative([&](const Eigen::VectorXd &x){ return model_.terminal_cost(x); }, x, eps_);
//         }
//     }

//     Eigen::MatrixXd lNxx(const Eigen::VectorXd &x) const
//     {
//         if constexpr(is_linear_ocp)
//         {
//             return model_.Qf;
//         }
//         else if constexpr(is_nonlinear_ocp)
//         {
//             return second_derivative([&](const Eigen::VectorXd &x){ return model_.terminal_cost(x); }, x, eps_);
//         }
//     }

// private:
//     const Model &model_;
//     const double eps_;
// };

}
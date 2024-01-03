#pragma once

#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
#include <functional>

namespace cpp_robotics
{

template<class DerType>
using ADScalar = Eigen::AutoDiffScalar<DerType>;

template<class DerType, int NX=Eigen::Dynamic>
class ADVector : public Eigen::Matrix<ADScalar<DerType>, NX, 1>
{
public:
    ADVector(const size_t dim): 
        Eigen::Matrix<ADScalar<DerType>, NX, 1>(dim) 
    {
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = 0;
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
        }
    }

    ADVector(const size_t dim, const DerType &x)
    {
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = x(i);
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
        }
    }
};

// template<class DerType>
// static auto make_auto_diff_vector(const size_t &dim, const std::optional<DerType> &x = std::nullopt)
// {
//     ADVectorXd<DerType> ax(dim);
//     for(size_t i = 0; i < dim; i++)
//     {
//         if(x.has_value())
//             ax(i).value() = x.value()(i);
//         else
//             ax(i).value() = 0;
//         ax(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
//     }
//     return ax;
// }

/**
 * @brief 自動微分でヤコビアンを求めるクラス
 * 
 * @tparam Functor 関数のクラス, template<typename T> static void eval_func(const Eigen::Matrix<T,Eigen::Dynamic,1>& x, Eigen::Matrix<T,Eigen::Dynamic,1>& y)を持つ必要がある
 * @tparam DerType 
 * @tparam Scalar 
 * @tparam NX 
 * @tparam NY 
 */
// template<class Functor, class DerType = Eigen::VectorXd, typename Scalar = double, int NX=Eigen::Dynamic, int NY=Eigen::Dynamic>
// class AutoDiffAdaptor
// {
// public:
//     using InputVector = Eigen::Matrix<Scalar, NX, 1>;
//     using ValueVector = Eigen::Matrix<Scalar, NY, 1>;
//     using JacobianMatrix = Eigen::Matrix<Scalar, NY, NX>;
//     using HessianMatrix = Eigen::Matrix<Scalar, NX, NX>;
//     enum {
//         InputsAtCompileTime = NX,
//         ValuesAtCompileTime = NY
//     };

//     /**
//      * @brief 引数/戻り値が静的サイズのベクトルである場合のコンストラクタ
//      * 
//      * @param functor 
//      */
//     AutoDiffAdaptor(Functor &functor): 
//         functor_(functor), input_size_(NX), value_size_(NY) {}

//     /**
//      * @brief 引数/戻り値が動的サイズのベクトルである場合のコンストラクタ
//      * 
//      * @param functor 
//      * @param input_size 関数の引数の次元
//      * @param value_size 関数の戻り値の次元
//      */
//     AutoDiffAdaptor(Functor &functor, const size_t input_size, const size_t value_size):
//         functor_(functor), input_size_(input_size), value_size_(value_size) {}

//     /**
//      * @brief 関数の評価
//      * 
//      * @param x 
//      * @param y 
//      */
//     void evalute(const InputVector &x, ValueVector &y)
//     {
//         return functor_.eval_func(x, y);
//     }

//     /**
//      * @brief 関数の評価
//      * 
//      * @param x 
//      * @return ValueVector 
//      */
//     ValueVector evalute(const InputVector &x)
//     {
//         ValueVector y;
//         if constexpr(ValueVector::SizeAtCompileTime == Eigen::Dynamic)
//             y.resize(value_size_);
//         evalute(x, y);
//         return y;
//     }

//     std::function<ValueVector(InputVector)> evalute_func()
//     {
//         return [this](InputVector x) { return evalute(x); };
//     }

//     std::function<double(InputVector)> evalute_func_scalar()
//     {
//         assert(value_size_ == 1);
//         return [this](InputVector x) { return evalute(x)(0); };
//     }

//     /**
//      * @brief ヤコビアンの評価
//      * 
//      * @param x 
//      * @param jac 
//      */
//     void jacobian(const InputVector &x, JacobianMatrix &jac)
//     {
//         using ADScalar = AutoDiffScalar<DerType>;
//         using ADInput = ADVectorXd<DerType, NX>;
//         using ADValue = ADVectorXd<DerType, NY>;
        
//         ADInput ax = x.template cast<ADScalar>();
//         ADValue ay(jac.rows());

//         if constexpr(InputsAtCompileTime==Eigen::Dynamic)
//         for (Eigen::Index j=0; j<jac.rows(); j++)
//             ay[j].derivatives().resize(x.rows());

//         for (Eigen::Index i=0; i<jac.cols(); i++)
//             ax[i].derivatives() = DerType::Unit(x.rows(),i);

//         functor_.eval_func(ax, ay);

//         for (Eigen::Index i=0; i<jac.rows(); i++)
//         {
//             jac.row(i) = ay[i].derivatives();
//         }
//     }

//     /**
//      * @brief ヤコビアンの評価
//      * 
//      * @param x 
//      * @return JacobianMatrix 
//      */
//     JacobianMatrix jacobian(const InputVector &x)
//     {
//         JacobianMatrix jac;
//         if constexpr(JacobianMatrix::SizeAtCompileTime == Eigen::Dynamic)
//             jac.resize(value_size_, input_size_);
        
//         jacobian(x, jac);
//         return jac;
//     }

//     std::function<JacobianMatrix(InputVector)> jacobian_func()
//     {
//         return [this](InputVector x) { return jacobian(x); };
//     }

//     std::function<Eigen::Matrix<Scalar, NX, 1>(InputVector)> jacobian_func_row_vector()
//     {
//         assert(value_size_ == 1);
//         return [this](InputVector x) { return jacobian(x).transpose().col(0).eval(); };
//     }

//     // void hessian(const EigenVectorType &x, HessianMatrix &hess)
//     // {
//     //     assert(value_size_ == 1);
//     // }
    
//     // HessianMatrix hessian(const InputVector &x)
//     // {
//     //     HessianMatrix hess;
//     //     if constexpr(HessianMatrix::SizeAtCompileTime == Eigen::Dynamic)
//     //         hess.resize(input_size_, input_size_);
//     //     hessian(x, hess);
//     //     return hess;
//     // }

// private:
//     Functor &functor_;
//     const size_t input_size_;
//     const size_t value_size_;
// };

}
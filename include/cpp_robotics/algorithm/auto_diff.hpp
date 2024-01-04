#pragma once

#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
#include <functional>

namespace cpp_robotics
{

template<class DerType = Eigen::VectorXd>
using ADScalar = Eigen::AutoDiffScalar<DerType>;

template<class DerType, int NX>
class ADVector : public Eigen::Matrix<ADScalar<DerType>, NX, 1>
{
public:
    using Scalar = ADScalar<DerType>;
    using RealVector = Eigen::Matrix<double, NX, 1>;

    ADVector(const size_t dim): 
        Eigen::Matrix<ADScalar<DerType>, NX, 1>(dim) 
    {
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = 0;
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
        }
    }

    ADVector(const DerType &x)
    {
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(x.size());
        for(int i = 0; i < x.size(); i++)
        {
            this->operator()(i).value() = x(i);
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(x.size(), i);
        }
    }

    ADVector(const size_t dim, const size_t all_dim, const size_t start)
    {
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = 0;
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(all_dim, start + i);
        }
    }

    ADVector(const size_t dim, const size_t all_dim, const size_t start, const DerType &x)
    {   
        assert(static_cast<long int>(dim) == x.size());
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = x(i);
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(all_dim, start + i);
        }
    }

    ADVector& operator=(const RealVector &x)
    {
        assert(static_cast<long int>(this->size()) == x.size());
        for(int i = 0; i < x.size(); i++)
        {
            this->operator()(i).value() = x(i);
        }
        return *this;
    }

    RealVector real_cast() const
    {
        RealVector result(this->size());
        for(int i = 0; i < this->size(); ++i)
        {
            result(i) = this->operator()(i).value();
        }
        return result;
    }

    ADVector operator+(const ADVector& other) const
    {
        assert(this->size() == other.size());
        ADVector result = *this;
        for(int i = 0; i < this->size(); ++i)
        {
            result(i) += other(i);
        }
        return result;
    }

    ADVector operator-(const ADVector& other) const
    {
        assert(this->size() == other.size()); 
        ADVector result = *this;
        for(int i = 0; i < this->size(); ++i)
        {
            result(i) -= other(i);
        }
        return result;
    }

    void operator +=(const ADVector& other)
    {
        assert(this->size() == other.size());
        for(int i = 0; i < this->size(); ++i)
        {
            this->operator()(i) += other(i);
        }
    }

    void operator -=(const ADVector& other)
    {
        assert(this->size() == other.size());
        for(int i = 0; i < this->size(); ++i)
        {
            this->operator()(i) -= other(i);
        }
    }

    template<class SScalar>
    ADVector operator*(const SScalar& scalar) const
    {
        ADVector result = *this;
        for(int i = 0; i < this->size(); ++i)
        {
            result(i) *= scalar;
        }
        return result;
    }

    template<class SScalar>
    friend ADVector operator*(const SScalar& scalar, const ADVector& vec)
    {
        return vec * scalar;
    }

    template<class SScalar>
    void operator *=(const SScalar& scalar)
    {
        for(int i = 0; i < this->size(); ++i)
        {
            this->operator()(i) *= scalar;
        }
    }

    template<class SScalar>
    ADVector operator/(const SScalar& scalar) const
    {
        ADVector result = *this;
        for(int i = 0; i < this->size(); ++i)
        {
            result(i) /= scalar;
        }
        return result;
    }

    template<class SScalar>
    void operator /=(const SScalar& scalar)
    {
        for(int i = 0; i < this->size(); ++i)
        {
            this->operator()(i) /= scalar;
        }
    }
};

using ADVectorXd = ADVector<Eigen::VectorXd, Eigen::Dynamic>;

}
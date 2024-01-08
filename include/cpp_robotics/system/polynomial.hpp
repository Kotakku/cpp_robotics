#pragma once

#include <vector>
#include <cassert>
#include <tuple>
#include <cpp_robotics/utility/cpp_support.hpp>

namespace cpp_robotics
{

// _coeff.front()が最高次数
// _coeff.back()が次数0
/**
 * @brief 多項式
 * 
 */
struct Polynomial
{
    Polynomial() = default;

    Polynomial(std::initializer_list<double> coeff):
        _coeff(coeff.begin(), coeff.end())
    {
        check_degree();
    }

    Polynomial(const std::vector<double> &coeff):
        _coeff(coeff)
    {
        check_degree();
    }

    template<class IteratorType>
    Polynomial(IteratorType begin, IteratorType end):
        _coeff(begin, end)
    {
        check_degree();
    }

    // (x-a1)(x-a2)...(x-aN)の{a...aN}を引数にとり展開した多項式を返す
    static Polynomial expand(std::vector<double> roots)
    {
        std::vector<double> coeff, buf;
        coeff.reserve(roots.size()+1);
        buf.reserve(roots.size());
        coeff.resize(1);
        
        coeff[0] = 1;
        for(auto &c : roots)
        {
            ////////// (x^m+a*x^m-1 ... c)(x+d)を計算する

            // (x^m+a*x^m-1 ... c) * xを計算する
            buf = coeff;
            coeff.push_back(0);

            // (x^m+a*x^m-1 ... c) * dを計算する
            for(auto &bval : buf)
                bval *= -c;

            // (x^m+a*x^m-1 ... c) * dを加算する
            for(size_t i = 0; i < buf.size(); i++)
            {
                coeff[i+1] += buf[i];
            }
        }

        return Polynomial{coeff};
    }

    void set_degree(size_t deg) { _coeff.resize(deg + 1); }
    size_t size() const { return _coeff.size(); }
    size_t degree() const { return size() ? (size() - 1) : 0; }
    //size_t degree_at(size_t i) const { return size() ? (degree() - i) : 0; }

    std::vector<double> coeff() const { return _coeff; }

    double &at(size_t i) { return _coeff[i]; }
    double  at(size_t i) const { return _coeff[i]; }

    double &at_degree(size_t i) { return _coeff[degree()-i]; }
    double  at_degree(size_t i) const { return _coeff[degree()-i]; }

    double &operator [](size_t i) { return at(i); }
    double operator [](size_t i) const { return at(i); }

    double evalute(double x) const
    {
        assert(_coeff.size() != 0);

        double xn = 1;
        double y = _coeff.back();
        for(auto it = _coeff.rbegin()+1; it != _coeff.rend(); it++)
        {
            y = y*x + (*it);
        }

        return y;
    }

    // /**
    //  * @brief 多項式をn階微分した多項式を返す
    //  * 
    //  * @param i 
    //  * @return Polynomial 
    //  */
    // Polynomial polyder(size_t i) const
    // {
    //     assert(degree() > 0);

    //     if(i == 0)
    //         return *this;
    //     if(i > degree())
    //         return {0};
        
    //     Polynomial dpol = *this;

    //     for(size_t c = 0; c < dpol.size(); c++)
    //     {
    //         if(c >= i)
    //         {
    //             size_t nc = 1;
    //             for(size_t r = 0; r < i; r++)
    //             {
    //                 nc *= (c - r);
    //             }
    //             dpol[c] *= static_cast<double>(nc);
    //         }

    //     }
    //     dpol._coeff.erase(dpol._coeff.begin(), dpol._coeff.begin()+i);


    //     // size_t deg = dpol.degree();
    //     // dpol._coeff.resize(dpol.size() - i);

    //     // for(size_t c = 0; c < dpol.size(); c++)
    //     // {
    //     //     size_t nc = 1;
    //     //     for(size_t r = 0; r < i; r++)
    //     //     {
    //     //         nc *= (deg - c - r);
    //     //     }
    //     //     dpol[c] *= static_cast<double>(nc);
    //     // }

    //     return dpol;
    // }

    // Polynomial polyint(double C = 0) const
    // {
    //     Polynomial ipol = *this;
        
    //     for(size_t i = 0; i < ipol.size(); i++)
    //     {
    //         double ndeg = static_cast<double>(i + 1);
    //         ipol[i] /= ndeg;
    //     }

    //     ipol._coeff.insert(ipol._coeff.begin(), C);

    //     return ipol;
    // }

    void swap(Polynomial &poly)
    {
        Polynomial tmp = *this;
        *this = poly;
        poly = tmp;
    }

    double operator()(double x) const
    {
        return evalute(x);
    }

    Polynomial operator +() const
    {
        return *this;
    }

    Polynomial operator -() const
    {
        Polynomial ret = *this;
        for(auto &c : ret._coeff)
            c *= -1;
        return ret;
    }

    Polynomial operator +(double s) const
    {
        Polynomial ret = *this;
        ret[ret.degree()] += s;
        ret.check_degree();
        return ret;
    }

    Polynomial operator -(double s) const
    {
        Polynomial ret = *this;
        ret[ret.degree()] -= s;
        ret.check_degree();
        return ret;
    }

    /**
     * @brief 多項式の0次の項に値を加算する
     * 
     * @param s 
     * @return Polynomial& 
     */
    Polynomial& operator +=(double s)
    {
        this->at(this->degree()) += s;
        this->check_degree();
        return *this;
    }

    /**
     * @brief 多項式の0次の項に値を減算する
     * 
     * @param s 
     * @return Polynomial& 
     */
    Polynomial& operator -=(double s)
    {
        this->at(this->degree()) -= s;
        this->check_degree();
        return *this;
    }

    /**
     * @brief 多項式をs倍した多項式を返す
     * 
     * @param s 
     * @return Polynomial 
     */
    Polynomial operator *(double s) const
    {
        Polynomial ret = *this;
        for(auto &c : ret._coeff)
            c *= s;
        ret.check_degree();
        return ret;
    }

    /**
     * @brief 多項式をs倍した多項式を返す
     * 
     * @param s 
     * @param poly 
     * @return Polynomial 
     */
    friend Polynomial operator *(double s, const Polynomial &poly)
    {
        return poly * s;
    }

    /**
     * @brief 自身をs倍する
     * 
     * @param s 
     * @return Polynomial& 
     */
    Polynomial& operator *=(double s)
    {
        *this = *this * s;
        return *this;
    }

    /**
     * @brief 多項式を1/s倍した多項式を返す
     * 
     * @param s 
     * @return Polynomial 
     */
    Polynomial operator /(double s) const
    {
        Polynomial ret = *this;
        for(auto &c : ret._coeff)
            c /= s;
        ret.check_degree();
        return ret;
    }

    /**
     * @brief 自身を1/s倍する
     * 
     * @param s 
     * @return Polynomial& 
     */
    Polynomial& operator /=(double s)
    {
        *this = *this / s;
        return *this;
    }

    /**
     * @brief 多項式同士の積を取る
     * 
     * @param p 
     * @return Polynomial 
     */
    Polynomial operator *(const Polynomial &p) const
    {
        std::vector<double> new_coeff(this->degree() + p.degree() + 1);
        size_t new_deg = new_coeff.size()-1;

        std::vector<double> c0 = this->coeff();
        std::vector<double> c1 = p.coeff();

        for(size_t i0 = 0; i0 < c0.size(); i0++)
        {
            for(size_t i1 = 0; i1 < c1.size(); i1++)
            {
                size_t deg0 = this->degree() - i0;
                size_t deg1 = p.degree() - i1;
                
                size_t deg = new_deg - (deg0 + deg1);

                new_coeff[deg] += c0[i0] * c1[i1];
            }
        }
        Polynomial new_p(new_coeff);
        return new_p;
    }

    Polynomial& operator *=(const Polynomial &p)
    {
        *this = *this * p;
        return *this;
    }

    /**
     * @brief 多項式同士の和を取る
     * 
     * @param poly 
     * @return Polynomial 
     */
    Polynomial operator +(Polynomial poly) const
    {
        Polynomial ret = *this;
        if(ret.degree() < poly.degree())
        {
            ret.swap(poly);
        }
        
        for (auto [it, rit] =
                std::tuple{poly._coeff.rbegin(), ret._coeff.rbegin()};
                it != poly._coeff.rend(); it++, rit++)
        {
            *rit += *it;
        }
        ret.check_degree();
        return ret;
    }

    /**
     * @brief 自身に他の多項式を加算する
     * 
     * @param poly 
     * @return Polynomial& 
     */
    Polynomial& operator +=(Polynomial poly)
    {
        *this = *this + poly;
        return *this;
    }

    Polynomial operator -(Polynomial poly) const
    {
        Polynomial ret = *this;
        int pm = 1;
        if(ret.degree() < poly.degree())
        {
            ret.swap(poly);
            pm = -1;
        }
        
        for (auto [it, rit] =
                std::tuple{poly._coeff.rbegin(), ret._coeff.rbegin()};
                it != poly._coeff.rend(); it++, rit++)
        {
            *rit -= *it;
        }
        ret.check_degree();
        return pm*ret;
    }

    /**
     * @brief 自身に他の多項式を減算する
     * 
     * @param poly 
     * @return Polynomial& 
     */
    Polynomial& operator -=(Polynomial poly)
    {
        *this = *this - poly;
        return *this;
    }

    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs)
    {
        return lhs._coeff == rhs._coeff;
    }

    friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs)
    {
        return lhs._coeff != rhs._coeff;
    }

private:
    void check_degree()
    {
        while(size())
        {
            if(_coeff[0] != 0)
                return;
            _coeff.erase(_coeff.begin());
        }
    }
    
    std::vector<double> _coeff;
};

}
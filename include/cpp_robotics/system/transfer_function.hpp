#pragma once

#include <cpp_robotics/system/discret.hpp>
#include <cpp_robotics/system/polynomial.hpp>

namespace cpp_robotics
{

/**
 * @brief 伝達関数モデル
 * 
 */
class TransferFunction
{
public:
    struct tf_t
    {
        std::vector<double> num;
        std::vector<double> den;
        double Ts;

        tf_t inv() const
        {
            return {
                den,
                num,
                Ts
            };
        }

        tf_t operator+(double val) const
        {
            return {
                (Polynomial(num) + Polynomial(den)*val).coeff(),
                den,
                Ts
            };
        }

        tf_t operator-(double val) const
        {
            return {
                (Polynomial(num) - Polynomial(den)*val).coeff(),
                den,
                Ts
            };
        }

        tf_t operator*(double val) const
        {
            return {
                (Polynomial(num)*val).coeff(),
                den,
                Ts
            };
        }

        tf_t operator/(double val) const
        {
            return {
                (Polynomial(num)/val).coeff(),
                den,
                Ts
            };
        }

        tf_t operator+(const tf_t &tf) const
        {
            return {
                (Polynomial(num)*Polynomial(tf.den) + Polynomial(tf.num)*Polynomial(den)).coeff(),
                (Polynomial(den)*Polynomial(tf.den)).coeff(),
                Ts
            };
        }

        tf_t operator-(const tf_t &tf) const
        {
            return {
                (Polynomial(num)*Polynomial(tf.den) - Polynomial(tf.num)*Polynomial(den)).coeff(),
                (Polynomial(den)*Polynomial(tf.den)).coeff(),
                Ts
            };
        }

        tf_t operator*(const tf_t &tf) const
        {
            return {
                (Polynomial(num)*Polynomial(tf.num)).coeff(),
                (Polynomial(den)*Polynomial(tf.den)).coeff(),
                Ts
            };
        }

        tf_t operator/(const tf_t &tf) const
        {
            return {
                (Polynomial(num)*Polynomial(tf.den)).coeff(),
                (Polynomial(den)*Polynomial(tf.num)).coeff(),
                Ts
            };
        }

        friend tf_t operator+(double val, const tf_t &tf)
        {
            return tf + val;
        }

        friend tf_t operator-(double val, const tf_t &tf)
        {
            return tf - val;
        }

        friend tf_t operator*(double val, const tf_t &tf)
        {
            return val*tf;
        }

        friend tf_t operator/(double val, const tf_t &tf)
        {
            return val*tf.inv();
        }

        TransferFunction simulatable()
        {
            return TransferFunction(num, den, Ts);
        }

#ifndef CR_NO_USE_COUT
        friend std::ostream& operator<<(std::ostream& stream, const tf_t& tf)
        {
            std::stringstream ssnum, ssden;
        
            for(size_t i = 0; i < tf.num.size(); i++)
            {
                if(tf.num[i] > 0 && i != 0)
                    ssnum << "+";
                ssnum << tf.num[i];
                if(auto deg = tf.num.size()-1-i; deg != 0)
                {
                    if(deg == 1)
                        ssnum << "s";
                    else
                        ssnum << "s^" << deg;
                }
                if(i != tf.num.size()-1)
                    ssnum << " ";
            }

            for(size_t i = 0; i < tf.den.size(); i++)
            {
                if(tf.den[i] > 0 && i != 0)
                    ssden << "+";
                ssden << tf.den[i];
                if(auto deg = tf.den.size()-1-i; deg != 0)
                {
                    if(deg == 1)
                        ssden << "s";
                    else
                        ssden << "s^" << deg;
                }
                if(i != tf.den.size()-1)
                    ssden << " ";
            }

            size_t len = std::max(ssnum.str().length(), ssden.str().length());
            std::string bar(len, '-');

            stream << std::string((len-ssnum.str().length())/2, ' ') + ssnum.str() + "\n"
                        + bar + "\n" 
                        + std::string((len-ssden.str().length())/2, ' ') + ssden.str();

            return stream;
        };
#endif
    };

    static TransferFunction make_first_order_system(const double T, const double Ts)
    {
        return TransferFunction({1}, {T, 1}, Ts);
    }

    static TransferFunction make_second_order_system(const double omega, const double zeta, const double Ts)
    {
        return TransferFunction({omega*omega}, {1.0, 2.0*zeta*omega, omega*omega}, Ts);
    }

    TransferFunction() = default;
    
    /**
     * @brief Construct a new Transfer Function object
     * @param num 分子の係数 配列の先頭が最高次の係数
     * @param den 分母の係数 配列の先頭が最高次の係数
     * @param Ts サンプリング周期
    */
    TransferFunction(std::vector<double> num, std::vector<double> den, const double Ts):
        num_array_(num), den_array_(den)
    {
        set_continuous(num_array_, den_array_, Ts);
    }

    TransferFunction(const tf_t &tf_config):
        num_array_(tf_config.num), den_array_(tf_config.den)
    {
        set_continuous(num_array_, den_array_, tf_config.Ts);
    }

    void set_continuous(std::vector<double> num, std::vector<double> den, const double dt)
    {
        if(num.size() == 1 && den.size() == 1)
        {
            num_ = num;
            den_ = den;
            dt_ = dt;
            u_.resize(1);
            y_.resize(1);
            return;
        }
        auto [num_disc, den_disc] = DiscretTransferFunction::discritize(num, den, dt);
        set_discrite(num_disc, den_disc, dt);
    }

    // z領域の伝達関数の分子と分母を降べきの準に与える
    void set_discrite(std::vector<double> num_disc, std::vector<double> den_disc, const double dt)
    {
        assert(num_disc.size() > 0);
        assert(den_disc.size() > 0);
        
        num_ = num_disc;
        den_ = den_disc;

        u_.resize(num_.size());
        y_.resize(den_.size()-1);

        dt_ = dt;

        reset();
    }

    /**
     * @brief サンプリング周期
     * 
     * @return double 
     */
    double Ts() const { return dt_; }

    virtual void reset(double state = 0)
    {
        for(auto &u : u_)
            u = 0;
        for(auto &y : y_)
            y = state;
        u_.reset_position();
        y_.reset_position();
    }

    double responce(double u)
    {
        double y = 0;
        u_.insert_front(u);

        for(size_t i = 0; i < num_.size(); i++)
        {
            y += num_[i]*u_.at_circular(i);
        }

        if(den_.size() != 1)
        {
            for(size_t i = 0; i < den_.size()-1; i++)
            {
                y -= den_[i+1]*y_.at_circular(i);
            }
        }
        y /= den_[0];

        y_.insert_front(y);
        return y;
    }

    size_t num_deg(size_t num_idx = 0) const
    {
        return num_array_.size()-1 - num_idx;
    }

    size_t den_deg(size_t num_idx = 0) const
    {
        return den_array_.size()-1 - num_idx;
    }

    std::vector<double> num_array() const { return num_array_; }
    std::vector<double> den_array() const { return den_array_; }

    operator tf_t() const
    {
        return{
            num_array_,
            den_array_,
            dt_
        };
    } 

    tf_t inv() const
    {
        return {
            den_array_,
            num_array_,
            dt_
        };
    }

    tf_t operator+(double val) const
    {
        return {
            (Polynomial(num_array_) + Polynomial(den_array_)*val).coeff(),
            den_array_,
            dt_
        };
    }

    tf_t operator-(double val) const
    {
        return {
            (Polynomial(num_array_) - Polynomial(den_array_)*val).coeff(),
            den_array_,
            dt_
        };
    }

    tf_t operator*(double val) const
    {
        return {
            (Polynomial(num_array_)*val).coeff(),
            den_array_,
            dt_
        };
    }

    tf_t operator/(double val) const
    {
        return {
            (Polynomial(num_array_)/val).coeff(),
            den_array_,
            dt_
        };
    }

    friend tf_t operator+(double val, const TransferFunction &tf)
    {
        return tf + val;
    }

    friend tf_t operator-(double val, const TransferFunction &tf)
    {
        return tf - val;
    }

    friend tf_t operator*(double val, const TransferFunction &tf)
    {
        return tf*val;
    }

    friend tf_t operator/(double val, const TransferFunction &tf)
    {
        return val*tf.inv();
    }

    friend tf_t operator+(const tf_t &a, const TransferFunction &b)
    {
        return a + (tf_t)(b);
    }

    friend tf_t operator-(const tf_t &a, const TransferFunction &b)
    {
        return a - (tf_t)(b);
    }
    
    friend tf_t operator*(const tf_t &a, const TransferFunction &b)
    {
        return a * (tf_t)(b);
    }
    
    friend tf_t operator/(const tf_t &a, const TransferFunction &b)
    {
        return a / (tf_t)(b);
    }
    
    friend tf_t operator+(const TransferFunction &a, const tf_t &b)
    {
        return (tf_t)(a) + b;
    }

    friend tf_t operator-(const TransferFunction &a, const tf_t &b)
    {
        return (tf_t)(a) - b;
    }

    friend tf_t operator*(const TransferFunction &a, const tf_t &b)
    {
        return (tf_t)(a) * b;
    }

    friend tf_t operator/(const TransferFunction &a, const tf_t &b)
    {
        return (tf_t)(a) / b;
    }

    friend tf_t operator+(const TransferFunction &a, const TransferFunction &b)
    {
        return (tf_t)(a) + (tf_t)(b);
    }

    friend tf_t operator-(const TransferFunction &a, const TransferFunction &b)
    {
        return (tf_t)(a) - (tf_t)(b);
    }

    friend tf_t operator*(const TransferFunction &a, const TransferFunction &b)
    {
        return (tf_t)(a) * (tf_t)(b);
    }

    friend tf_t operator/(const TransferFunction &a, const TransferFunction &b)
    {
        return (tf_t)(a) / (tf_t)(b);
    }

#ifndef CR_NO_USE_COUT
    friend std::ostream& operator<<(std::ostream& stream, const TransferFunction& tf)
    {
        std::stringstream ssnum, ssden;
    
        for(size_t i = 0; i < tf.num_array_.size(); i++)
        {
            if(tf.num_array_[i] > 0 && i != 0)
                ssnum << "+";
            ssnum << tf.num_array_[i];
            if(auto deg = tf.num_deg(i); deg != 0)
            {
                if(deg == 1)
                    ssnum << "s";
                else
                    ssnum << "s^" << deg;
            }
            if(i != tf.num_array_.size()-1)
                ssnum << " ";
        }

        for(size_t i = 0; i < tf.den_array_.size(); i++)
        {
            if(tf.den_array_[i] > 0 && i != 0)
                ssden << "+";
            ssden << tf.den_array_[i];
            if(auto deg = tf.den_deg(i); deg != 0)
            {
                if(deg == 1)
                    ssden << "s";
                else
                    ssden << "s^" << deg;
            }
            if(i != tf.den_array_.size()-1)
                ssden << " ";
        }

        size_t len = std::max(ssnum.str().length(), ssden.str().length());
        std::string bar(len, '-');

        stream << std::string((len-ssnum.str().length())/2, ' ') + ssnum.str() + "\n"
                    + bar + "\n" 
                    + std::string((len-ssden.str().length())/2, ' ') + ssden.str();

        return stream;
    };
#endif

protected:
    std::vector<double> num_array_;
    std::vector<double> den_array_;

    template<typename T>
    class CircularBuffer : public std::vector<T>
    {
    public:
        void reset_position()
        {
            i = 0;
        }

        T& at_circular(size_t idx)
        {
            idx += i;
            if(this->size() <= idx)
                idx-=this->size();
            return this->at(idx);
        }

        void insert_front(T val)
        {
            i += this->size()-1;
            if(this->size() <= i)
                i-=this->size();
            this->at(i) = val;
        }

    private:
        size_t i = 0;
    };
    std::vector<double> num_;
    std::vector<double> den_;
    CircularBuffer<double> u_;
    CircularBuffer<double> y_;
    double dt_;
};

}
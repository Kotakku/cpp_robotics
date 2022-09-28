#pragma once

#include "cpp_robotics/system/discrete_transfer_function.hpp"

namespace cpp_robotics
{

/// ノッチフィルタ
//         s^2 + d*2*zeta*omega + omega^2
// G(s) = -------------------------------- を双一次変換
//          s^2 + 2*zeta*omega + omega^2
class NotchFilter
{
public:
    /**
     * @brief Construct a new Notch Filter object
     * 
     * @param w 中心周波数[rad/s]
     * @param zeta 鋭さ
     * @param d 深さ(0.0で一番深く、1.0に近づけるほどフィルタの効果が弱くなる)
     * @param dt サンプリング周期
     */
    NotchFilter(double w, double zeta, double d, double dt):
        w_(w), zeta_(zeta), d_(d), dt_(dt)
    {
        const double ww = w*w;
        const double dtdt = dt*dt;

        tf_.set_discrite(
            {(4+d*(4*dt*zeta*w)+dtdt*ww), (-8+2*dtdt*ww), (4-d*(4*dt*zeta*w)+dtdt*ww)},
            {(4+  (4*dt*zeta*w)+dtdt*ww), (-8+2*dtdt*ww), (4-  (4*dt*zeta*w)+dtdt*ww)},
            dt
        );
    }

    void reset()
    {
        tf_.reset();
    }
    
    double filtering(double u)
    {
        return tf_.responce(u);
    }

    double w() const { return w_; }
    double zeta() const { return zeta_; }
    double d() const { return d_; }
    double dt() const {return dt_; }
private:
    const double w_;
    const double zeta_;
    const double d_;
    const double dt_;
    DiscreteTransferFunction tf_;
};

}
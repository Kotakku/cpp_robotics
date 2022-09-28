#pragma once

namespace cpp_robotics
{

/// バンドパスフィルタ
//               2*zeta*omega
// G(s) = ------------------------------ を双一次変換
//         s^2 + 2*zeta*omega + omega^2
class BandPassFilter
{
public:
    /**
     * @brief Construct a new Notch Filter object
     * 
     * @param w 中心周波数[rad/s]
     * @param zeta 鋭さ
     * @param dt サンプリング周期
     */
    BandPassFilter(double w, double zeta, double dt):
        w_(w), zeta_(zeta), dt_(dt)
    {
        const double ww = w*w;
        const double dtdt = dt*dt;

        tf_.set_discrite(
            {     (4*dt*zeta*w),                0,            (-4*dt*zeta*w)},
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
    double dt() const {return dt_; }
private:
    const double w_;
    const double zeta_;
    const double dt_;
    DiscreteTransferFunction tf_;
};

}
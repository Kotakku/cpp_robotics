#pragma once

#include <tuple>
#include "../vector/vector2.hpp"

namespace cpp_robotics
{

// https://myenigma.hatenablog.com/entry/2017/06/05/111007
// https://sd08419ttic.hatenablog.com/entry/2020/03/22/152044
// https://www.youtube.com/watch?v=zMdoLO4kRKg
// https://www.coursera.org/lecture/intro-self-driving-cars/lesson-2-geometric-lateral-control-pure-pursuit-44N7x
// https://www.youtube.com/watch?v=34CSRIlHMNk

/**
 * @brief Pure pursuit制御器
 * 
 */
class PurePursuit
{
public:
    // Kは正の実数、0に近いほどロバスト性が落ちる
    PurePursuit(double K):
        K_(K) {}

    void set_K(double K)
    {
        K_ = K;
    }

    /**
     * @brief 
     * 
     * @param traj_ref 始点からの長さによる経路の関数
     * @param traj_progress 現在の経路上の長さ位置
     * @param pos_present 現在の座標
     * @param target_angle_offset traj_refから目標座標を取ってきた時に位置誤差から角度を出した時に加えるオフセット
     * @param vel 現在の進行方向の速度
     * @param angle_present 現在のロボットのYaw角度
     * @return std::tuple<bool, double> [Pure Pursuitが有効な出力を返すか, 出力値]
     */
    std::tuple<bool, double> control(std::function<Vector2d(double)> traj_ref, double traj_progress, Vector2d pos_present, double vel, double angle_present)
    {
        vel = std::abs(vel);

        // lookahead
        double L = K_ * vel;

        // lookahead座標
        Vector2d pos_ref = traj_ref(traj_progress + L);

        double omega = 0.0f;
        const double pos_diff = (pos_ref-pos_present).norm();
        if(std::abs(vel) > 1e-2 && pos_diff > 0.001f)
        {
            // Yaw方向エラー
            double raw_dir_err = ((pos_ref - pos_present).angle()) - angle_present;
            double dir_err = raw_dir_err;

            // Yaw方向制御量
            omega = (2.0f * vel * std::sin(dir_err)) / L;
            return {true, omega};
        }
            
        return {false, 0.0f};
    }

private:
    double K_;
};

}

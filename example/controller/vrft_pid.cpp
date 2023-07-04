#define CR_USE_MATPLOTLIB
#include <cpp_robotics/system.hpp>
#include <cpp_robotics/controller.hpp>
#include <cpp_robotics/motor/dc_motor_list.hpp>
#include <cpp_robotics/motor/motor_tf.hpp>
#include <string>
#include <iomanip>

void eigen_named_plot(std::string name, const Eigen::VectorXd &x, const Eigen::VectorXd &val)
{
    namespace plt = matplotlibcpp;
    std::vector<double> xvec(x.data(), x.data() + x.rows() * x.cols());
    std::vector<double> vec(val.data(), val.data() + val.rows() * val.cols());
    plt::named_plot(name, xvec, vec);
}

void vrft_pid_with_open_loop()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    const double Ts = 0.01; // サンプリング周期
    const double sim_time = 3.0;
    // 制御対象
    const double omega = 10.0;
    const double zeta = 0.3;
    auto tf = cr::TransferFunction::make_second_order_system(omega, zeta, Ts); 

    // 4秒分のステップ応答を計算
    auto u = cr::stepspace<Eigen::VectorXd>(sim_time, Ts);
    auto [t1, y] = cr::lsim(tf, u);

    // 規範モデル
    cr::TransferFunction ref_model({1.0}, {0.2, 1.0}, Ts); 

    // VRFTでPIDゲインを求める
    auto K = cr::vrft_pid(u, y, Ts, ref_model, ref_model);
    std::cout << "PID gain =" << std::endl;
    std::cout << K << std::endl;

    cr::PID::pid_param_t pid_param = 
    {
        .Ts = Ts,
        .gpd = 100*2*M_PI,
        .Kp = K[0],
        .Ki = K[1],
        .Kd = K[2],
        .output_limit = std::nullopt
    };
    cr::PID pid(pid_param);
    // PIDコントローラとtfからなるフィードバック制御系
    cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(pid, tf); 

    // VRFTでチューニングしたPIDゲインを用いて閉ループのステップ応答をシミュレーション
    auto [t2, reu, responce] = cr::lsim(siso_sys, cr::stepspace(sim_time, Ts));

    // 開ループのステップ応答のグラフ表示
    plt::figure_size(1020, 500);
    plt::subplot(1, 2, 1);
    eigen_named_plot("Input", t1, u);
    eigen_named_plot("Responce", t1, y);
    plt::xlabel("Time [s]");
    plt::title("Open loop responce");
    plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);

    // チューニング後の結果のグラフ表示
    plt::subplot(1, 2, 2);
    plt::named_plot("Target", t2, cr::stepspace(sim_time, Ts));
    plt::named_plot("PID feedback responce", t2, responce);
    plt::xlabel("Time [s]");
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << "(Kp = " << K[0] << ", Ki = " << K[1] << ", Kd = " << K[2] << ")";
    plt::title("Closed loop responce\n" + ss.str());
    plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);
    plt::tight_layout();
    plt::show(false);
}

void vrft_pid_with_closed_loop()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    const double Ts = 0.01; // サンプリング周期
    const double sim_time = 3.0;
    // 制御対象
    const double omega = 10.0;
    const double zeta = 0.3;
    auto tf = cr::TransferFunction::make_second_order_system(omega, zeta, Ts); 

    // 4秒分のステップ応答を計算
    cr::PID::pid_param_t test_pid_param = 
    {
        .Ts = Ts,
        .gpd = 100*2*M_PI,
        .Kp = 1.0,
        .Ki = 0,
        .Kd = 0.1,
        .output_limit = std::nullopt
    };
    cr::PID test_pid(test_pid_param);
    cr::SisoFeedbackSystem test_siso_sys = cr::make_feedback_system(test_pid, tf); 
    // auto u = cr::stepspace<Eigen::VectorXd>(sim_time, Ts);
    auto [t1, u0, y0] = cr::lsim(test_siso_sys, cr::stepspace<Eigen::VectorXd>(sim_time, Ts));

    // 規範モデル
    cr::TransferFunction ref_model({1.0}, {0.2, 1.0}, Ts); 

    // VRFTでPIDゲインを求める
    auto K = cr::vrft_pid(u0, y0, Ts, ref_model, ref_model);
    std::cout << "PID gain =" << std::endl;
    std::cout << K << std::endl;

    cr::PID::pid_param_t pid_param = 
    {
        .Ts = Ts,
        .gpd = 100*2*M_PI,
        .Kp = K[0],
        .Ki = K[1],
        .Kd = K[2],
        .output_limit = std::nullopt
    };
    cr::PID pid(pid_param);
    // PIDコントローラとtfからなるフィードバック制御系
    cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(pid, tf); 

    // VRFTでチューニングしたPIDゲインを用いて閉ループのステップ応答をシミュレーション
    auto target = cr::stepspace<Eigen::VectorXd>(sim_time, Ts);
    auto [t2, u, responce] = cr::lsim(siso_sys, target);

    // 開ループのステップ応答のグラフ表示
    plt::figure_size(1020, 500);
    plt::subplot(1, 2, 1);
    eigen_named_plot("Target", t1, target);
    eigen_named_plot("Responce", t1, y0);
    plt::xlabel("Time [s]");
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << "(Kp = " << test_pid_param.Kp << ", Ki = " << test_pid_param.Ki << ", Kd = " << test_pid_param.Kd << ")";
    plt::title("Test closed loop responce\n" + ss.str());
    plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);

    // チューニング後の結果のグラフ表示
    plt::subplot(1, 2, 2);
    eigen_named_plot("Target", t2, target);
    eigen_named_plot("PID feedback responce", t2, responce);
    plt::xlabel("Time [s]");
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    ss << std::fixed << std::setprecision(3);
    ss << "(Kp = " << K[0] << ", Ki = " << K[1] << ", Kd = " << K[2] << ")";
    plt::title("Closed loop responce\n" + ss.str());
    plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);
    plt::tight_layout();
    plt::show();
}

int main()
{
    vrft_pid_with_open_loop();
    vrft_pid_with_closed_loop();
    return 0;
}
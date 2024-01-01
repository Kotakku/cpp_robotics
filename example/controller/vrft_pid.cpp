#define CR_USE_MATPLOTLIB
#include <cpp_robotics/system.hpp>
#include <cpp_robotics/controller.hpp>
#include <cpp_robotics/motor/dc_motor_list.hpp>
#include <cpp_robotics/motor/motor_tf.hpp>
#include <cpp_robotics/filter.hpp>
#include <cpp_robotics/optimize.hpp>
#include <string>
#include <iomanip>

void eigen_named_plot(std::string name, const Eigen::VectorXd &x, const Eigen::VectorXd &val)
{
    namespace plt = matplotlibcpp;
    std::vector<double> xvec(x.data(), x.data() + x.rows() * x.cols());
    std::vector<double> vec(val.data(), val.data() + val.rows() * val.cols());
    plt::named_plot(name, xvec, vec);
}

void eigen_named_plot(std::string name, const Eigen::VectorXd &val)
{
    namespace plt = matplotlibcpp;
    std::vector<double> vec(val.data(), val.data() + val.rows() * val.cols());
    plt::named_plot(name, vec);
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

using namespace cpp_robotics;
namespace plt = matplotlibcpp;
Eigen::VectorXd vrft_nctf(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, std::function<double(double)> nct, PID::pid_param_t base_param, TransferFunction ref_model, std::optional<TransferFunction> prefilter, double Td = 0.01)
{
    // PID::pid_param_t p_param =
    // {
    //     .Ts = base_param.Ts,
    //     .gpd = base_param.gpd,
    //     .Kp = 1,
    //     .Ki = 0,
    //     .Kd = 0,
    //     .output_limit = std::nullopt
    // };
    // PID::pid_param_t i_param =
    // {
    //     .Ts = base_param.Ts,
    //     .gpd = base_param.gpd,
    //     .Kp = 0,
    //     .Ki = 1,
    //     .Kd = 0,
    //     .output_limit = std::nullopt
    // };
    // std::vector<NctfController> control_base = {
    //     NctfController(nct, p_param, Ts),
    //     NctfController(nct, i_param, Ts)
    // };

    // (void) Ts;

    // Eigen::VectorXd uf, ef;
    // if(prefilter)
    // {
    //     uf = lsim_y(prefilter.value(), u);
    //     ef = lsim_y(prefilter.value()*(ref_model.inv()-1.0), y);
    // }
    // else
    // {
    //     uf = u;
    //     ef = lsim_y((ref_model.inv()-1.0), y);;
    // }

    // Eigen::MatrixXd phi(ef.size(), control_base.size());
    // for(size_t i = 0; i < control_base.size(); ++i)
    // {
    //     phi.col(i) = lsim_y([&](double e){ return control_base[i].control(e); }, Ts, ef);
    // }

    // plt::figure();
    // eigen_named_plot("ef", ef);
    // eigen_named_plot("y", y);
    // eigen_named_plot("p0", phi.col(0));
    // eigen_named_plot("p1", phi.col(1));
    // plt::legend();
    // plt::show(false);
    // return leastsq(phi, uf);


    std::vector<TransferFunction> control_base = {
        TransferFunction({1.0}, {1.0}, Ts),
        TransferFunction({1.0}, {1.0, 0.0}, Ts)
    };

    Differentiator vel_diff(base_param.gpd, Ts);
    Eigen::VectorXd vel = lsim_y(vel_diff, y);

    plt::figure();
    eigen_named_plot("Vel", vel);
    

    Eigen::VectorXd uf, ef;
    // prefilter.reset();
    if(prefilter)
    {
        uf = lsim_y(prefilter.value(), u);
        ef = lsim_y(prefilter.value()*(ref_model.inv()-1.0), vel);
    }
    else
    {
        uf = u;
        ef = lsim_y((ref_model.inv()-1.0), vel);
    }
    ef = y[y.size()-1]*Eigen::VectorXd::Ones(ef.size()) - y;

    // ud = -NCT(u)+ u*sを求める
    Differentiator diff(base_param.gpd, Ts);
    diff.reset_test(0, ef[0]);
    Eigen::VectorXd ed = lsim_y(diff,ef,true);
    for(int i = 0; i < y.size(); i++)
    {
        ed[i] -= nct(ef[i]);
    }

    eigen_named_plot("ef", ef);
    eigen_named_plot("ed", ed);
    eigen_named_plot("y", y);
    plt::legend();
    plt::show(false);

    Eigen::MatrixXd phi(ef.size(), control_base.size());
    for(size_t i = 0; i < control_base.size(); ++i)
    {
        phi.col(i) = lsim_y(control_base[i], ed);
    }

    // ActiveSetMethod asmethod;
    // ActiveSetMethod::Problem p;
    // std::tie(p.Q, p.c) = lsi2qp(phi, -uf);
    // // p.A = -Eigen::Matrix2d::Identity();
    // // p.b = Eigen::Vector2d::Zero();
    // // p.constraint_size = 2;
    // auto result = asmethod.solve(p, Eigen::Vector2d::Ones());
    // return result.x_opt;

    return leastsq(phi, uf);

    // return vrft_pi(ed, vel, Ts, ref_model, ref_model);
}

// まずは評価関数に落とし込むところから考える
Eigen::VectorXd vrft_nctf2(const Eigen::VectorXd &u, const Eigen::VectorXd &y, const double Ts, std::function<double(double)> nct, PID::pid_param_t base_param, TransferFunction ref_model, std::optional<TransferFunction> prefilter)
{
    namespace cr = cpp_robotics;
    std::cout << "vrft_nctf2" << std::endl;
    // PID::pid_param_t p_param =
    // {
    //     .Ts = base_param.Ts,
    //     .gpd = base_param.gpd,
    //     .Kp = 1,
    //     .Ki = 0,
    //     .Kd = 0,
    //     .output_limit = std::nullopt
    // };
    // PID::pid_param_t i_param =
    // {
    //     .Ts = base_param.Ts,
    //     .gpd = base_param.gpd,
    //     .Kp = 0,
    //     .Ki = 1,
    //     .Kd = 0,
    //     .output_limit = std::nullopt
    // };
    // std::vector<NctfController> control_base = {
    //     NctfController(nct, p_param, Ts),
    //     NctfController(nct, i_param, Ts)
    // };

    // std::vector<TransferFunction> control_base = {
    //     TransferFunction({1.0}, {1.0}, Ts),
    //     TransferFunction({1.0}, {1.0, 0.0}, Ts)
    // };

    Differentiator vel_diff(base_param.gpd, Ts);
    Eigen::VectorXd vel = lsim_y(vel_diff, y);

    Eigen::VectorXd uf, ef;
    // prefilter.reset();
    Eigen::VectorXd vref;

    prefilter = cr::TransferFunction({1.0}, {0.001, 1.0}, base_param.Ts);
    if(prefilter)
    {
        uf = lsim_y(prefilter.value(), u);
        ef = lsim_y(prefilter.value()*(ref_model.inv()-1.0), y);
        vref = lsim_y(prefilter.value()*(ref_model.inv()), y);
    }
    else
    {
        uf = u;
        ef = lsim_y((ref_model.inv()), y);
    }

    plt::figure();
    eigen_named_plot("ef", ef);
    eigen_named_plot("vref", vref);
    // eigen_named_plot("ed", ed);
    // eigen_named_plot("vel", vel);
    eigen_named_plot("y", y);
    plt::legend();
    plt::show(false);

    // 最小二乗法で解こうとしてるのが間違い？
    // Eigen::MatrixXd phi(vf.size(), control_base.size());
    // for(size_t i = 0; i < control_base.size(); ++i)
    // {
    //     phi.col(i) = lsim_y([&](double e){ return control_base[i].control(e); }, base_param.Ts, vf);
    // }

    // return leastsq(phi, uf);

    auto cost_f = [&](Eigen::VectorXd K)
    {
        PID::pid_param_t nctf_param =
        {
            .Ts = base_param.Ts,
            .gpd = base_param.gpd,
            .Kp = K[0],
            .Ki = 3,
            .Kd = 0,
            .output_limit = base_param.output_limit
        };
        NctfController nctf(nct, nctf_param, Ts);
        Eigen::VectorXd uc = lsim_y([&](double e){ return nctf.control(e); }, base_param.Ts, ef);
        std::cout << "uc = " << uc.squaredNorm() << std::endl;
        return (uf-uc).squaredNorm();
    };
    auto cost_grad = [&](const Eigen::VectorXd &K)
    {
        return cr::derivative(cost_f, K);
    };
    auto [ret, rx, rcnt] = cr::quasi_newton_method(cost_f, cost_grad, Eigen::VectorXd::Zero(1));
    if(ret)
    {
        std::cout << "quasi_newton_method : sucsess" << std::endl;
        return rx;
    }
    else
    {
        std::cout << "quasi_newton_method : failed" << std::endl;
        return Eigen::VectorXd::Zero(2);
    }
}

void check_nct(Eigen::VectorXd y, double Ts, std::function<double(double)> nct)
{

    namespace plt = matplotlibcpp;
    Differentiator diff(600, Ts);
    diff.reset_test(0,y[0]);
    Eigen::VectorXd vel = lsim_y(diff, y,true);

    // Eigen::VectorXd y2(y.size()*2), vel2(vel.size()*2);
    // y2 << Eigen::VectorXd(-y.array().reverse()), y;
    // vel2 << Eigen::VectorXd(vel.array().reverse()), -vel;

    Eigen::VectorXd nct_out(y.size());
    for(int i = 0; i < y.size(); i++)
    {
        nct_out[i] = nct(y[i]);
    }

    plt::figure();
    eigen_named_plot("sys", y, (vel).eval());
    eigen_named_plot("NCT", y, nct_out);
    plt::xlim(-1.5, 1.5);
    plt::ylim(-20, 5);
    plt::legend();
    plt::show(false);
}

void vrft_nctf_with_open_loop()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    const double Ts = 0.001; // サンプリング周期
    const double sim_time = 2.0;
    const double exp_sim_time = 0.5;
    // 制御対象
    const double omega = 50.0;
    const double zeta = 1.0;
    const double max_input = 50;
    cr::TransferFunction tf = cr::TransferFunction::make_second_order_system(omega, zeta, Ts) * cr::TransferFunction({0.3}, {1,0}, Ts); 

    // 4秒分のステップ応答を計算
    Eigen::VectorXd u = max_input * cr::stepspace<Eigen::VectorXd>(exp_sim_time, Ts);
    for(int i = 2.0*u.size()/4; i < u.size(); ++i)
    {
        u[i] = 0;
    }
    for(int i = u.size()/2; i < u.size(); ++i)
    {
        const int size = u.size()/2;
        // u[i] *= (double)i/(u.size()/2);
        // u[i] = -max_input + std::sin((i-u.size()/2) *0.5*M_PI/size)*max_input;
    }
    auto [t1, y] = cr::lsim(tf, u);

    const double nct_max_velocity = max_input*0.3;
    const double nct_slope = 0.6/0.015;
    check_nct(Eigen::VectorXd::Constant(y.size(), y[y.size()-1]) - y, Ts, NctfController::make_simple_nct(nct_max_velocity, nct_slope));

    // 規範モデル
    cr::TransferFunction ref_model = cr::TransferFunction({1.0}, {0.01, 1.0}, Ts);

    // VRFTでPIDゲインを求める
    cr::PID::pid_param_t nctf_pid_param = 
    {
        .Ts = Ts,
        .gpd = 100*2*M_PI,
        .Kp = 0,
        .Ki = 0,
        .Kd = 0,
        .output_limit = std::pair(-max_input, max_input)
    };

    auto K = vrft_nctf2(u, y, Ts, NctfController::make_simple_nct(nct_max_velocity, nct_slope), nctf_pid_param, ref_model, ref_model);
    // auto K = cr::vrft_pi(u,y,Ts,ref_model,ref_model);
    // Eigen::Vector2d K(5.0, 0.0);
    std::cout << "PI gain =" << std::endl;
    std::cout << K << std::endl;
    nctf_pid_param.Kp = K[0];
    nctf_pid_param.Ki = 0.0;
    // nctf_pid_param.Kd = K[2];


    cr::NctfController nctf(nct_max_velocity, nct_slope, nctf_pid_param, Ts);
    // cr::PID pid(nctf_pid_param);
    
    // cr::PID pid(pid_param);
    // // PIDコントローラとtfからなるフィードバック制御系
    cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(nctf, tf); 

    // VRFTでチューニングしたPIDゲインを用いて閉ループのステップ応答をシミュレーション
    const double target_pos = 5.0;
    Eigen::VectorXd test_y_ref = Eigen::VectorXd(target_pos * cr::stepspace<Eigen::VectorXd>(sim_time, Ts));
    size_t i = 0;
    for(; i < 100; i++)
    {
        test_y_ref[i] *= 0.02;
    }
    for(; i < 300; i++)
    {
        test_y_ref[i] *= 0.1;
    }
    for(; i < 700; i++)
    {
        test_y_ref[i] *= 0.5;
    }
    auto [t2, reu, responce] = cr::lsim(siso_sys, test_y_ref);

    check_nct(Eigen::VectorXd::Constant(responce.size(), responce[responce.size()-1])-responce, Ts, NctfController::make_simple_nct(nct_max_velocity, nct_slope));

    // 開ループのステップ応答のグラフ表示
    plt::figure_size(1020, 500);
    plt::subplot(1, 2, 1);
    eigen_named_plot("Input", t1, u);
    eigen_named_plot("Responce", t1, y);
    plt::xlabel("Time [s]");
    plt::title("Open loop responce");
    // plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);

    // チューニング後の結果のグラフ表示
    plt::subplot(1, 2, 2);
    eigen_named_plot("Target", t2, test_y_ref);
    eigen_named_plot("PID feedback responce", t2, responce);
    plt::xlabel("Time [s]");
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    // ss << "(Kp = " << K[0] << ", Ki = " << K[1] << ")";
    plt::title("Closed loop responce\n" + ss.str());
    // plt::ylim(-0.1, 1.5);
    plt::legend();
    plt::grid(true);
    plt::tight_layout();
    plt::show();
    
}

int main()
{
    // vrft_pid_with_open_loop();
    // vrft_pid_with_closed_loop();
    vrft_nctf_with_open_loop();
    return 0;
}
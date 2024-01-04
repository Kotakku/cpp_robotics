#include <cpp_robotics/controller/ilqr.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <chrono>

int main()
{
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;

    const double Ts = 0.05;

    Eigen::MatrixXd A(4, 4);
    A << 0, 0, 1, 0,
         0, 0, 0, 1,
         0, 0, -0.6, 0.0,
         0, 0, 0, -0.3;
    
    Eigen::MatrixXd B(4, 2);
    B << 0,0,
         0,0,
         0.7, 0,
         0, 1;

    auto model = std::make_shared<OCPContinuousLinearDynamics>(A, B, Ts, 30);
    auto cost = std::make_shared<OCPCostQuadratic>(model);
    cost->Q = (Eigen::VectorXd(4) << 5,5,0.5,0.5).finished().asDiagonal();
    cost->R = (Eigen::VectorXd(2) << 0.1,0.1).finished().asDiagonal();
    cost->Qf = cost->Q;

    iLQR ilqr(model, cost);

    Eigen::VectorXd x0(4);
    x0 << 5, 5, 3, -2;

    std::vector<double> u1, u2, x1, x2, t, solve_time;
    for(size_t i = 0; i < 100; i++)
    {
        auto start = std::chrono::system_clock::now();
        auto ret = ilqr.generate_trajectory(x0);
        auto end = std::chrono::system_clock::now();

        if(ret != iLQR::Result::SUCCESS)
        {
            std::cout << "Failed to solve at " << i << " code: " << static_cast<int>(ret) << std::endl;
        }

        double milliseconds = 1e-3 * std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        x0 = model->eval(x0, ilqr.get_input()[0]);

        t.push_back(i * Ts);
        u1.push_back(ilqr.get_input()[0](0));
        u2.push_back(ilqr.get_input()[0](1));
        x1.push_back(ilqr.get_state()[0](0));
        x2.push_back(ilqr.get_state()[0](1));
        solve_time.push_back(milliseconds);
    }

    plt::named_plot("u1", t, u1);
    plt::named_plot("u2", t, u2);
    plt::named_plot("x1", t, x1);
    plt::named_plot("x2", t, x2);
    plt::legend();
    plt::show(false);

    plt::figure();
    plt::named_plot("solve_time[ms]", t, solve_time, ".");
    plt::legend();
    plt::show();

    return 0;
}
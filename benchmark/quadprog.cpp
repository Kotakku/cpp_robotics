#include <cpp_robotics/optimize/quadprog.hpp>
#include <cpp_robotics/utility/random.hpp>
#include <cpp_robotics/utility/timer.hpp>
#include <cpp_robotics/matplotlibcpp.hpp>
#include <cpp_robotics/utility/space.hpp>
#include <chrono>
#include <vector>
#include <iostream>

template<class Matrix>
void init_mat(Matrix &mat, std::function<double(double)> f)
{
    for(int j = 0; j < mat.cols(); j++)
    {
        for(int i = 0; i < mat.rows(); i++)
        {
            mat(i,j) = f(0);
        }
    }
}

int main(void)
{
    using namespace cpp_robotics;
    const size_t batch_num = 100;

    std::vector<size_t> dim_list = {10, 50, 100}; 

    std::vector<double> ipm_avg_time_ms(dim_list.size());
    std::vector<double> ipm_success_ratio(dim_list.size());
    std::vector<double> ipm_avg_iter_count(dim_list.size());
    
    std::vector<double> admm_avg_time_ms(dim_list.size());
    std::vector<double> admm_success_ratio(dim_list.size());
    std::vector<double> admm_avg_iter_count(dim_list.size());

    UniformRealRandomEngine uniform(0.0, 1.0);
    NormalRandomEngine normal(0.0, 1.0);

    Timer timer;

    for(size_t cond = 0; cond < dim_list.size(); cond++)
    {
        const size_t n = dim_list[cond];
        const size_t m = n;

        std::cout << "---------------- " << (cond+1) << "/" << dim_list.size() <<  " ----------------" << std::endl;
        for(size_t i = 0; i < batch_num; i++)
        {
            std::cout << "i: " << i+1 << "/" << batch_num << std::endl;
            // setup qp
            QuadProgProblem qp;
            qp.set_problem_size(n, m, 0, false);
            Eigen::MatrixXd M(n,n);
            init_mat(M, [&](double) { return normal.value(); });
            double alpha = 1e-2;
            qp.Q = M*(M.transpose()) + alpha * Eigen::MatrixXd::Identity(n,n);
            init_mat(qp.c, [&](double) { return normal.value(); });
            init_mat(qp.A, [&](double) 
                { 
                    if (uniform.value() < 0.15)
                        return normal.value(); 
                    return 0.0;
                });
            init_mat(qp.b, [&](double) { return uniform.value(); });

            // solve InteriorPointMethod
            {
                std::cout << "solve InteriorPointMethod ..." << std::endl;
                timer.start();
                QuadProg solver(qp, QuadProg::Method::InteriorPointMethod);
                auto result = solver.solve();
                timer.stop();
                std::cout << " solve iter: " << result.iter_cnt << std::endl;

                int microsec = timer.count<std::chrono::microseconds>();
                bool success = result.is_solved && solver.satisfy(result.x);
                ipm_avg_time_ms[cond] += 1e-3*microsec/batch_num;
                if(success)
                    ipm_success_ratio[cond] += 1.0 / batch_num;
                ipm_avg_iter_count[cond] += static_cast<double>(result.iter_cnt) / batch_num;
            }

            // solve ADMM
            {
                std::cout << "solve ADMM ..." << std::endl;
                timer.start();
                QuadProg solver(qp, QuadProg::Method::ADMM);
                auto result = solver.solve();
                timer.stop();
                std::cout << " solve iter: " << result.iter_cnt << std::endl;

                int microsec = timer.count<std::chrono::microseconds>();
                bool success = result.is_solved && solver.satisfy(result.x);
                admm_avg_time_ms[cond] += 1e-3*microsec/batch_num;
                if(success)
                    admm_success_ratio[cond] += 1.0 / batch_num;
                admm_avg_iter_count[cond] += static_cast<double>(result.iter_cnt) / batch_num;
            }
        }
    }

    std::cout << "---------------- finished ----------------" << std::endl;

    namespace plt = matplotlibcpp;
    auto ipm_x = linspace(0, 3*(dim_list.size()-1), dim_list.size());
    auto admm_x = linspace(0+1, 3*(dim_list.size()-1)+1, dim_list.size());
    auto label_x = linspace(0+0.5, 3*(dim_list.size()-1)+0.5, dim_list.size());
    std::vector<std::string> cond_label;
    for(size_t i = 0; i < dim_list.size(); i++)
    {
        cond_label.push_back(std::to_string(dim_list[i]));
    }

    std::map<std::string, std::string> legend_kwarg, loc_kwarg;
    plt::figure();
    legend_kwarg["label"] = "InteriorPointMethod";
    plt::bar(ipm_x, ipm_avg_time_ms, "b", "-", 1.0, legend_kwarg);
    legend_kwarg["label"] = "ADMM";
    plt::bar(admm_x, admm_avg_time_ms, "r", "-", 1.0, legend_kwarg);
    plt::xticks(label_x, cond_label);
    plt::xlabel("variable dimension");
    plt::ylabel("average solve time [ms]");
    loc_kwarg["loc"] = "upper left";
    plt::legend(loc_kwarg);
    plt::show(false);

    plt::figure();
    legend_kwarg["label"] = "InteriorPointMethod";
    plt::bar(ipm_x, ipm_avg_iter_count, "b", "-", 1.0, legend_kwarg);
    legend_kwarg["label"] = "ADMM";
    plt::bar(admm_x, admm_avg_iter_count, "r", "-", 1.0, legend_kwarg);
    plt::xticks(label_x, cond_label);
    plt::xlabel("variable dimension");
    plt::ylabel("average iteration");
    loc_kwarg["loc"] = "upper left";
    plt::legend(loc_kwarg);
    plt::show(false);

    plt::figure();
    legend_kwarg["label"] = "InteriorPointMethod";
    plt::bar(ipm_x, ipm_success_ratio, "b", "-", 1.0, legend_kwarg);
    legend_kwarg["label"] = "ADMM";
    plt::bar(admm_x, admm_success_ratio, "r", "-", 1.0, legend_kwarg);
    plt::xticks(label_x, cond_label);
    plt::xlabel("variable dimension");
    plt::ylabel("solve success ratio");
    loc_kwarg["loc"] = "lower left";
    plt::legend(loc_kwarg);
    plt::show();
    
    return 0;
}
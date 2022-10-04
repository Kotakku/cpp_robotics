#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
#include <cpp_robotics/utility/auto_diff_utils.hpp>

template<typename T>
T func1(const T &x)
{
    return 2*x*x + 3*x + 1;
}

double der_func1(double x)
{
    return 4*x + 3;
}

template<typename T>
T func2(const T &x, const T &y)
{
    return 2*x*x + 3*x + 3*x*y*y + 2*y + 1;
}

double der_x_func2(double x, double y)
{
    return 4*x + 3 + 3*y*y;
}

double der_y_func2(double x, double y)
{
    return 6*x*y + 2;
}

TEST(auto_diff, scaler_diff1) {
    // テンプレート引数のEigen::VectorXdはderivatives()の返り値の型
    Eigen::AutoDiffScalar<Eigen::VectorXd> x, y, f1, f2;

    // 変数の値
    x.value() = 1;
    // 関数の入力の次元とその変数のインデックス
    x.derivatives() = Eigen::VectorXd::Unit(1, 0);
    f1 = func1(x);

    EXPECT_DOUBLE_EQ(func1(1.0), f1.value());
    EXPECT_DOUBLE_EQ(der_func1(1.0), f1.derivatives()(0));

    x.value() = 1;
    x.derivatives() = Eigen::VectorXd::Unit(2, 0);
    y.value() = 2;
    y.derivatives() = Eigen::VectorXd::Unit(2, 1);

    f2 = func2(x, y);

    EXPECT_DOUBLE_EQ(func2(1.0, 2.0), f2.value());
    EXPECT_DOUBLE_EQ(der_x_func2(1.0, 2.0), f2.derivatives()(0));
    EXPECT_DOUBLE_EQ(der_y_func2(1.0, 2.0), f2.derivatives()(1));
}

TEST(auto_diff, vecotor_diff1)
{
    using namespace cpp_robotics;
    AutoDiffVector<Eigen::VectorXd> x = make_auto_diff_vector<Eigen::VectorXd>(2);

    EXPECT_DOUBLE_EQ(x(0).value(), 0);
    EXPECT_DOUBLE_EQ(x(1).value(), 0);
    
    x = make_auto_diff_vector<Eigen::VectorXd>(2, Eigen::Vector2d(3.0, 2.0));

    EXPECT_DOUBLE_EQ(x(0).value(), 3);
    EXPECT_DOUBLE_EQ(x(1).value(), 2);
}

template<typename VectorType>
VectorType ad_func(VectorType x)
{
    return 2*x*x;
}

struct TestAutoDiffClass
{
    template<typename T>
    void eval_func(const Eigen::Matrix<T,Eigen::Dynamic,1>& x, Eigen::Matrix<T,Eigen::Dynamic,1>& y)
    {
        using namespace std;
        y(0) = 2*sin(x(0)) + cos(x(1));
    }
};

TEST(auto_diff, jac_test1)
{
    using namespace cpp_robotics;

    TestAutoDiffClass functor;
    AutoDiffAdaptor<TestAutoDiffClass> ad(functor, 2, 1);

    Eigen::VectorXd x = Eigen::Vector2d(0.0, 0.0);

    Eigen::VectorXd y = ad.evalute(x);

    std::cout << "eval y" << std::endl;
    std::cout << y << std::endl;

    Eigen::MatrixXd jac = ad.jacobian(x);
    std::cout << "jac" << std::endl;
    std::cout << jac << std::endl;
}
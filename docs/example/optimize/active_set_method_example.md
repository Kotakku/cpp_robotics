# 有効制約法

```cpp
#include <iostream>
#include <cpp_robotics/algorithm.hpp>
#include <cpp_robotics/optimize/active_set_method.hpp>

int main()
{
    namespace cr = cpp_robotics;

    cr::ActiveSetMethod solver;

    cr::ActiveSetMethod::Problem prob(2);

    std::cout << "prob setup" << std::endl;
    prob.Q << 1,0,0,1;
    prob.c << -6,-2;

    Eigen::VectorXd A(2);
    A << 0,0;
    Eigen::VectorXd b(1);
    b << 1;

    // prob.add_inequality_constraint(A.transpose(), b); // x2 = 1の制約
    // A << -1, 0;
    // prob.add_equality_constraint(A.transpose(), b); // x1 = 1の制約

    Eigen::Vector2d x0;
    x0 << 3,2;

    std::cout << "prob setup end" << std::endl;

    auto result = solver.solve(prob, x0);

    if(result.is_solved)
    {
        std::cout << "解けた" << std::endl;
    }
    else
    {
        std::cout << "解無し" << std::endl;
    }

    std::cout << result.x_opt.transpose() << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

}
```
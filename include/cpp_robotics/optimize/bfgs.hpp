#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

/**
 * @brief BFGS法
 * 
 * @param hess 前ステップまでの近似ヘッシアン
 * @param s x_k+1 - x_k
 * @param y \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k)
 */
static void bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y)
{
    double sy, sBs;
    Eigen::VectorXd Bs;

    Bs.noalias() = hess * s;
    sBs = s.dot(Bs);
    sy = s.dot(y);

    hess += -( Bs * Bs.transpose() )/sBs + ( y*y.transpose() )/( sy );
}

/**
 * @brief パウエルの修正BFGS法
 * 
 * @param hess 前ステップまでの近似ヘッシアン
 * @param s x_k+1 - x_k
 * @param y \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k)
 * @param gamma 
 */
static void powells_modified_bfgs_step(Eigen::MatrixXd &hess, Eigen::VectorXd s, Eigen::VectorXd y, double gamma = 0.2)
{
    // y_tilde
    if(s.transpose()*y < gamma * s.transpose()*hess*s)
    {
        double sy, sBs;
        Eigen::VectorXd Bs;

        Bs.noalias() = hess * s;
        sBs = s.dot(Bs);
        sy = s.dot(y);

        double beta = (1-gamma)*sBs / ( sBs - sy );
        y = beta*y + (1-beta)*hess*s;
    }
    
    bfgs_step(hess, s, y);
}

}
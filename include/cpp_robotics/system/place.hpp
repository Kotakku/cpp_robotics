#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

// 極配置法
// (A-dot(B, K))の固有値が与えられた極になるようなKを計算する
// Kautsky, J., N.K. Nichols, and P. Van Dooren, "Robust Pole Assignment in Linear State Feedback," International Journal of Control, 41 (1985), pp. 1129-1155.
// https://github1s.com/scipy/scipy/blob/HEAD/scipy/signal/_ltisys.py
static Eigen::MatrixXd place(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, const Eigen::MatrixXd &p)
{
    bool B_fulllank = false;
    if(B_fulllank)
    {
        // Bがフルランクの時逆行列を利用してフィードバックゲインKを求めることができる
        return B.inverse() * (p.diagonal() - A);
    }
    else
    {
        // // step A. BをQR分解またはSVD分解してU0, U1, Zを計算する
        // u, z = s_qr(B, mode="full")
        // rankB = np.linalg.matrix_rank(B)
        // u0 = u[:, :rankB]
        // u1 = u[:, rankB:]
        // z = z[:rankB, :]

        // // step X. xを選択する

        // bool skip_conjugate = false; // 極が複素数の時に使用する
        for(Eigen::VectorXd::Index j = 0; j < B.rows(); j++)
        {
            // if(skip_conjugate)
            // {
            //     skip_conjugate = false;
            //     continue;
            // }

            // auto pole_space_j = np.dot(u1.T, A-poles[j]*np.eye(B.shape[0])).T

            // // QR分解
            // Q, _ = s_qr(pole_space_j, mode="full")

            // transfer_matrix_j = np.sum(ker_pole_j, axis=1)[:, np.newaxis]
            // transfer_matrix_j = (transfer_matrix_j / np.linalg.norm(transfer_matrix_j))

            // // 極が複素数のときはこの操作が変わる
            // ker_pole.append(ker_pole_j)

            // if(j == 0)
            //     transfer_matrix = transfer_matrix_j
            // else
                // transfer_matrix = np.hstack((transfer_matrix, transfer_matrix_j))
        }


        // // step F. フィードバックベクトルFを作る
        // M*X = X*Deltaを解く
            // m = np.linalg.solve(transfer_matrix.T, np.dot(np.diag(poles),
            //                                       transfer_matrix.T)).T
        // // -> F = Z^-1 * U0^T * (M-A)
            // gain_matrix = np.linalg.solve(z, np.dot(u0.T, m-A))

        // Eigen::MatrixXd K = Z.inverse() * U0.transpose() * (M-A);
    }

    return Eigen::VectorXd::Zero(1);
}

}
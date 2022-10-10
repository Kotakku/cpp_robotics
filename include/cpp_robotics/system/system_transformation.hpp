#pragma once

#include <cpp_robotics/system/transfer_function.hpp>
#include <cpp_robotics/system/state_space_system.hpp>

namespace cpp_robotics
{

StateSpaceSystem tf2ss(const TransferFunction &tf)
{
    // 伝達関数を可制御正準系に変換して保存
    auto num_array = tf.num_array();
    auto den_array = tf.den_array();
    const size_t num_size = num_array.size();
    const size_t den_size = den_array.size();
    const size_t state_size = tf.den_deg();

    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(state_size, state_size);
    // 対角要素の1個右隣を1埋め
    for(size_t i = 0; i < state_size-1; i++)
    {
        A(i, i+1) = 1;
    }
    // 一番下の行を伝達関数の要素で埋め
    for(size_t i = 0; i < state_size; i++)
    {
        A(state_size-1, i) = -den_array[state_size - i] / den_array[0];
    }

    Eigen::MatrixXd B = Eigen::VectorXd::Zero(state_size);
    B(state_size-1) = 1;

    Eigen::MatrixXd C = Eigen::RowVectorXd::Zero(state_size);
    for(size_t i = 0; i <= num_size; i++)
    {
        C(i) = num_array[i] / den_array[0];
    }

    return StateSpaceSystem(A, B, C, tf.Ts());
}

}
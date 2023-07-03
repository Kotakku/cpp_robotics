#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/system/transfer_function.hpp>

TEST(transfer_function, exp_fn) {
    using namespace cpp_robotics;

    const double dt = 1e-3;

    TransferFunction tf({2}, {1, 2}, dt);
    TransferFunction tf2 = tf + 1.0;
    TransferFunction tf3 = 2.0*tf;
    TransferFunction tf4 = (tf.inv()-1)*tf;
    TransferFunction tf5 = (1 - tf);
}

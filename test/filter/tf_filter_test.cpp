#include <gtest/gtest.h>

#include <cpp_robotics/filter/filter.hpp>

TEST(tf_filter, constructor) {
    namespace cr = cpp_robotics;

    cr::LowPassFilter lpf(0.628, 0.001);
    const double lpf_val = lpf.filtering(1);

    cr::HighPassFilter hpf(0.628, 0.001);
    const double hpf_val = hpf.filtering(1);

    cr::NotchFilter ntf(10*2*M_PI, 0.1, 0.01, 0.001);
    const double ntf_val = ntf.filtering(1);

    cr::BandPassFilter bpf(10*2*M_PI, 0.1, 0.001);
    const double bpf_val = bpf.filtering(1);
}
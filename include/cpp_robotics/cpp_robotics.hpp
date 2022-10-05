#pragma once

#include "core.hpp"

#include "path_planning/path_planning.hpp"
#include "geometry/geometry.hpp"
#include "chassis/chassis.hpp"
#include "algorithm/algorithm.hpp"
#include "motor/dc_motor_list.hpp"
#include "optimize/optimize.hpp"
#include "motor/motor_tf.hpp"

#ifdef CR_USE_MATPLOTLIB
#include "third_party/matplotlib-cpp/matplotlibcpp.h"
#endif

// #include "robot"
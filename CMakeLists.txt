cmake_minimum_required(VERSION 3.5)
project(cpp_robotics)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O2 -Wall -Wextra -Wpedantic -Wno-unused-variable -Wno-unused-function)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(Eigen3 REQUIRED)

option(BUILD_EXAMPLES "build examples" OFF)
option(BUILD_TESTS "build tests" OFF)
option(BUILD_BENCHMARKS "build benchmarks" OFF)

#################### example ####################
if(BUILD_EXAMPLES)

find_package(Python3 COMPONENTS Development NumPy)

set(example_files
  hello_world
  controller/motor_pid_control
  controller/pid_vs_nctf
  controller/lqr
  controller/canonicalize
  controller/place
  controller/linear_mpc
  controller/vrft_pid
  controller/nctf_example
  controller/ilqr_linear_example
  controller/ilqr_diffbot_example
  controller/alilqr_cartpole_example
  controller/alilqr_diffbot_example

  filter/lpf_step
  filter/hpf_step
  filter/vel_limit_filter

  system/step_responce
  system/bode_nyquist
  system/state_space_system
  algorithm/kdtree_sample
  algorithm/icp_sample
  algorithm/mahalanobis
  algorithm/random_example

  optimize/optimize_scalar
  optimize/optimize_without_constraint
  optimize/optimize_rosenbrock
  optimize/optimize_with_constraint
  optimize/quadprog
  optimize/sqp_example

  path_planning/dubins_path

  unit/unit_example
)

foreach(example_file ${example_files})
get_filename_component(example_name example/${example_file}.cpp NAME_WE)
add_executable(${example_name} example/${example_file}.cpp)
target_include_directories(${example_name} PRIVATE include)
target_link_libraries(${example_name} PRIVATE Eigen3::Eigen Python3::Python Python3::NumPy)
endforeach()
endif()

#################### test ####################
if(BUILD_TESTS)
find_package(GTest REQUIRED)
enable_testing()
set(test_files
  # common/lib_test
  utility/singleton_test
  utility/random_test

  algorithm/poly_regression_test
  algorithm/k_means_test
  algorithm/auto_diff_test
  algorithm/icp_test

  system/polynomial_test
  system/discret_tf_test
  system/time_responce_test
  system/transfer_function_test

  filter/tf_filter_test
  filter/extended_kalman_filter_test

  geometry/shape_test
  geometry/geometry_test

  chassis/mecanum_test
  chassis/omni_test
  chassis/swerve_test

  optimize/bfgs_test
  optimize/quadprog_test
  optimize/breacketing_search_test
  optimize/sqp_test
  
  controller/pid_test
  controller/pid2_test
  controller/psmc_test
  controller/pfc_test
  controller/vrft_test

  arm_kinematics/xy_2link_robot_test
)
include(GoogleTest)
foreach(test_file ${test_files})
get_filename_component(test_name test/${test_file}.cpp NAME_WE)
add_executable(${test_name} test/${test_file}.cpp)
target_include_directories(${test_name} PRIVATE include)
target_link_libraries(${test_name} PRIVATE Eigen3::Eigen GTest::GTest GTest::Main)
gtest_discover_tests(${test_name})
endforeach()
endif()

#################### benchmark ####################
if(BUILD_BENCHMARKS)

find_package(Python3 COMPONENTS Development NumPy)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftime-report")

set(bench_test_files
  build_time
  autodiff
  eigen_arg_ret
)

foreach(bench_test_file ${bench_test_files})
get_filename_component(bench_test_file benchmark/${bench_test_file}.cpp NAME_WE)
add_executable(bench_${bench_test_file} benchmark/${bench_test_file}.cpp)
target_include_directories(bench_${bench_test_file} PRIVATE include)
target_link_libraries(bench_${bench_test_file} PRIVATE Eigen3::Eigen Python3::Python Python3::NumPy)
endforeach()
endif()

#################### install ####################
add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
)

install(EXPORT ${PROJECT_NAME}-config
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION include
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
cmake_minimum_required(VERSION 3.5)
project(cpp_robotics)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O2 -Wall -Wextra -Wpedantic -Wno-unused-variable -Wno-unused-function)
endif()

find_package(Eigen3 REQUIRED)
find_package(Python3 COMPONENTS Development NumPy)

#################### example ####################
if("${CR_BUILD_EXAMPLE}" STREQUAL "ON")
set(example_files
  # hello_world
  # controller/pid_vs_nctf
  # controller/lqr
  # controller/canonicalize
  # controller/place

  filter/lpf_step
  filter/hpf_step

  # system/step_responce
  # system/bode_nyquist
  # system/disc_tf
  # system/state_space_system
  # algorithm/kdtree_sample
  # algorithm/icp_sample
  # algorithm/mahalanobis
  # algorithm/random_example

  # optimize/optimize_scalar
  # optimize/optimize
  # optimize/optimize_rosenbrock
  # optimize/optimize_with_constraint
  # optimize/active_set_method_example
  # optimize/sqp_example
  # optimize/quadprog

  # path_planning/dubins_path

  # units/unit_test
)

foreach(example_file ${example_files})
get_filename_component(example_name example/${example_file}.cpp NAME_WE)
add_executable(${example_name} example/${example_file}.cpp)
target_include_directories(${example_name} PRIVATE include ${EIGEN3_INCLUDE_DIR} ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(${example_name} PRIVATE Python3::Python Python3::NumPy)
endforeach()
endif()

#################### test ####################
find_package(GTest REQUIRED)
enable_testing()
set(test_files
  # common/lib_test
  utility/singleton_test

  algorithm/poly_regression_test
  algorithm/random_test
  algorithm/k_means_test
  algorithm/auto_diff_test
  algorithm/icp_test

  system/polynomial_test
  system/discret_tf_test

  filter/tf_filter_test
  filter/extended_kalman_filter_test

  chassis/mecanum_test
  chassis/omni_test
  chassis/swerve_test

  arm_ik/xy_2deg_robot_test

  optimize/fmin_search_test
  optimize/bfgs_test

)
include(GoogleTest)
foreach(test_file ${test_files})
get_filename_component(test_name test/${test_file}.cpp NAME_WE)
add_executable(${test_name} test/${test_file}.cpp)
target_include_directories(${test_name} PRIVATE include ${EIGEN3_INCLUDE_DIR})
target_link_libraries(${test_name} PRIVATE GTest::GTest GTest::Main)
gtest_discover_tests(${test_name})
endforeach()

#################### install ####################
install(
  DIRECTORY include
  DESTINATION share/${PROJECT_NAME}/
)

# ヘッダオンリーでコンパイルを要求しない
add_library(${PROJECT_NAME} INTERFACE)

# C++17以上
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE
    # 通常のビルドで使われるインクルードパス
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    # インストールされたパッケージを利用するとき使われるインクルードパス
    $<INSTALL_INTERFACE:include>)

# configの生成(*-config.cmake)
install(TARGETS ${PROJECT_NAME}
  # 生成するconfigファイルの名前
  EXPORT ${PROJECT_NAME}-config)

# インストールするconfigの指定、前項で生成したもの
install(EXPORT ${PROJECT_NAME}-config
  # 名前空間の指定
  NAMESPACE ${PROJECT_NAME}::
  # インストール先
  DESTINATION lib/cmake/${PROJECT_NAME})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  # コピー先
  DESTINATION include)

# エイリアスの登録
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
cmake_minimum_required(VERSION 3.5)
project(cpp_robotics)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# if(NOT CMAKE_CXX_STANDARD)
#   set(CMAKE_CXX_STANDARD 17)
# endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-variable -Wno-unused-function -std=gnu++2a)
endif()

find_package(Eigen3 REQUIRED)
find_package(Python3 COMPONENTS Development NumPy)

# file(GLOB qpoases_src src/third_party/qpOASES/*.cpp)
# add_library(cpp_robotics ${qpoases_src})
# target_include_directories(cpp_robotics PUBLIC include)

#################### example ####################
set(example_files
  hello_world
  controller/pid_vs_nctf
  controller/lqr
  system/system
  system/bode_nyquist
  algorithm/kdtree_sample
  algorithm/icp_sample

  optimize/optimize_scalar
  optimize/optimize
  optimize/optimize_rosenbrock
  optimize/optimize_with_constraint
  optimize/active_set_method_example
  optimize/sqp_example
  optimize/bfgs_test

  path_planning/dubins_path

  units/unit_test
)

foreach(example_file ${example_files})
get_filename_component(example_name example/${example_file}.cpp NAME_WE)
# message(${example_name})
add_executable(${example_name} example/${example_file}.cpp)
target_include_directories(${example_name} PRIVATE include ${EIGEN3_INCLUDE_DIR} ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(${example_name} Python3::Python Python3::NumPy)
endforeach()

#################### install ####################
install(
  DIRECTORY include
  DESTINATION share/${PROJECT_NAME}/
)
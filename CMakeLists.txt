cmake_minimum_required(VERSION 3.13)
project(cpp_17_test)

set(CMAKE_CXX_STANDARD 17)

set(GLOG_ROOT_DIR ${CMAKE_SOURCE_DIR}/lib/glog)
set(GLOG_INCLUDE_DIR ${GLOG_ROOT_DIR}/include)
set(GLOG_LIBRARY_DIR ${GLOG_ROOT_DIR}/lib)

add_subdirectory(src/cpp_17_test_module)
add_subdirectory(src/baekjoon_solutions)

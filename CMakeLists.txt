project(unique_ptr)

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

add_library(contrib_catch_main
  contrib/catch/catch_main.cpp)

target_include_directories(contrib_catch_main
  PUBLIC contrib/catch)

add_executable(test_unique_ptr test.cpp)

target_link_libraries(test_unique_ptr contrib_catch_main)
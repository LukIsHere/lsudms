cmake_minimum_required(VERSION 3.1.0)
project(lsudms VERSION 0.1.0)

include_directories(include)

add_library(lsudms SHARED include/lsudms.hpp lsudms.cpp)
add_executable(libtest test.cpp)
target_link_libraries(libtest PRIVATE lsudms)

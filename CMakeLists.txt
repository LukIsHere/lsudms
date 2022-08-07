cmake_minimum_required(VERSION 3.15.0)
project(lsudms VERSION 0.1.0)

include_directories(include)
add_library(lsudms STATIC include/lsudms.hpp lsudms.cpp)
target_include_directories(lsudms PUBLIC include)
add_executable(libtest test.cpp)


target_link_libraries(libtest PRIVATE lsudms)

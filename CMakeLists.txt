cmake_minimum_required(VERSION 3.20)
project(competitive)

set(CMAKE_CXX_STANDARD 14)

include_directories(ac-library)
include_directories(ac-library/atcoder)


file(GLOB_RECURSE contest_SRC "*/main.cpp")
add_executable(competitive ${contest_SRC})

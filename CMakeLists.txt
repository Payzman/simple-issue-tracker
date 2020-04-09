cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project("Simple Issue Tracker")

include_directories("inc")
add_subdirectory(inc)
add_subdirectory(src)
add_subdirectory(test)

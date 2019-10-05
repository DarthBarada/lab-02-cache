cmake_minimum_required(VERSION 3.4)

project(Cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(
  include
  PUBLIC
  ./include
)
add_executable(main ./sources/lab02.cpp)

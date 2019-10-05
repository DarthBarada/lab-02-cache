cmake_minimum_required(VERSION 3.4)

project(Cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/lab02.cpp)

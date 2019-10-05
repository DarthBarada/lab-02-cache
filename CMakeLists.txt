cmake_minimum_required(VERSION 3.4)

project(Cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
  ${PROJECT_NAME}
  PUBLIC
 ./sources/lab02.cpp
)
target_include_directories(
  include
  PUBLIC
  ./include
)
add_executable(main ./sources/lab02.cpp)

target_link_libraries(
 ${PROJECT_NAME}
 PUBLIC
 include
)

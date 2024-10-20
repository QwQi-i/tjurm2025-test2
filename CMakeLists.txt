cmake_minimum_required(VERSION 3.5)
project(tjurm_tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -O3 -g")

include_directories(${CMAKE_SOURCE_DIR}/include/)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(tjurm_tutorial main.cc ${sources})

target_link_libraries(tjurm_tutorial ${OpenCV_LIBS})

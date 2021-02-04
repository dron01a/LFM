cmake_minimum_required(VERSION 3.0.0)
project(Liza VERSION 0.1.5)

set (CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++17")

set (CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -Wall")

include_directories(libs/FSTool/src)
include_directories(libs/WPTool/src)

file(GLOB CPPS "./src/*.cpp")

add_executable(liza ${CPPS})

add_subdirectory(libs/FSTool)
add_subdirectory(libs/WPTool)

target_link_libraries(liza FSTool WPTool)

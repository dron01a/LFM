cmake_minimum_required(VERSION 3.0.0)
project(Liza VERSION 0.1.5)

set (CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++17")

set (CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -Wall")

file(GLOB CPPS "./src/*.cpp"
          FsPPS "./src/FSTool/*.cpp")

add_executable(liza ${CPPS} ${FsPPS})



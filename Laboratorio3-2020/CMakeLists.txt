cmake_minimum_required(VERSION 3.15)
project(Laboratorio3_2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laboratorio3_2020 main.cpp DriverInputT.cpp MapperInputT.cpp Coordinator.cpp ReducerInputT.cpp ResultT.cpp)

find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Laboratorio3_2020 ${Boost_LIBRARIES})
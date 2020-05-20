cmake_minimum_required(VERSION 3.15)
project(Laboratorio3_2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laboratorio3_2020 main.cpp Serializer.cpp MapperInputT.cpp Coordinator.cpp ReducerInputT.cpp ResultT.cpp)
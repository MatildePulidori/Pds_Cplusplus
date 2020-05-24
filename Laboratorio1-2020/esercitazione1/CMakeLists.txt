cmake_minimum_required(VERSION 3.10)
project(lezione_1)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_VERSION "1.0.0")
set(ARCHIVE_NAME ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION})

add_executable(lezione_1 main.cpp Message.cpp Message.h DurationLogger.h MessageStore.cpp MessageStore.h)
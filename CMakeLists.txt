cmake_minimum_required(VERSION 3.20.0)
project(hello VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(say-hello)
add_subdirectory(entry)

set(MY_VARIABLE "I am a variable.")

message(STATUS "This is to Santa. ${MY_VARIABLE}")
message(STATUS "Project name: ${PROJECT_NAME} Project version: ${PROJECT_VERSION}")
cmake_minimum_required(VERSION 3.20.0)
project(HelloTop VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SCRIPTS_DIR "${PROJECT_SOURCE_DIR}/cmake-scripts")

file(GLOB SCRIPT_FILES ${SCRIPTS_DIR}/*.cmake)

# Include all CMake scripts under `cmake-scripts`
foreach(script IN LISTS SCRIPT_FILES)
    include(${script})
    message(STATUS "Current including CMake scripts is: ${script}")
endforeach()

# Print variables
print_variables()
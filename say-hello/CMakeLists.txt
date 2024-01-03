cmake_minimum_required(VERSION 3.20.0)
project(HelloLibrary VERSION 1.0.0)

# Set include and source paths
set(HELLO_LIB say-hello)
set(HELLO_SOURCE_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HELLO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Print out current project information
include(${SCRIPTS_DIR}/PrintVariables.cmake)
print_variables()

# Library
add_library(${HELLO_LIB} 
${HELLO_SOURCE_DIR}/hello.cpp
${HELLO_SOURCE_DIR}/log.cpp)

# Add headers
target_include_directories(${HELLO_LIB} 
PUBLIC 
${HELLO_INCLUDE_DIR})

# Set proprocessor definition to specified version.
target_compile_features(${HELLO_LIB} PRIVATE cxx_std_20)
target_compile_definitions(${HELLO_LIB} PUBLIC SAY_HELLO_VERSION=1)
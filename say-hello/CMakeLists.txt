cmake_minimum_required(VERSION 3.20.0)
project(HelloLibrary VERSION 1.0.0)

set(HELLO_SOURCE_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/src)

# Print out current project information
include(${SCRIPTS_DIR}/PrintVariables.cmake)
print_variables()

add_library(say-hello 
${HELLO_SOURCE_DIR}/hello/hello.hpp
${HELLO_SOURCE_DIR}/hello/hello.cpp)

target_include_directories(say-hello 
PUBLIC 
${HELLO_SOURCE_DIR})

# Set proprocessor definition to specified version.
target_compile_definitions(say-hello PUBLIC SAY_HELLO_VERSION=1)
cmake_minimum_required(VERSION 3.20.0)

# CMake is case sensitive, writing Version or version will not compile.
project(Hello VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# CMake by default builds static libraries
# BUILD_SHARED_LIBS=TRUE will set CMake to build static libraries by default.
# MODULE is the third type of library that CMake can build.
add_library(say-hello hello.hpp hello.cpp)

add_executable(hello main.cpp)

target_link_libraries(hello PRIVATE say-hello)
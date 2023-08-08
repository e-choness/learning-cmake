################################################################
# Essential Project Settings
################################################################
cmake_minimum_required(VERSION 3.20.0)
project(Hello
        VERSION 1.0
        DESCRIPTION "An example project with CMAKE"
        LANGUAGES CXX)

################################################################
# Set C++ Standard
################################################################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD  20)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

################################################################
# Link External Libraries
################################################################
#include(FetchContent)
#
#FetchContent_Declare(
#        fmtlib
#        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#)
#FetchContent_MakeAvailable(fmtlib)

################################################################
# Include subdirectories
################################################################
add_subdirectory(src)
add_subdirectory(entry)

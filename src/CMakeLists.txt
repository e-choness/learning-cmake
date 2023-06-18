cmake_minimum_required(VERSION 3.25)

#----------------------------------------------------------------
# Package the source code into libraries
#----------------------------------------------------------------
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE src
        "${PROJECT_SOURCE_DIR}/*.cpp"
        "${PROJECT_SOURCE_DIR}/*.hpp"
        "${PROJECT_SOURCE_DIR}/*.h"
        )

add_library(src INTERFACE)
target_include_directories(src INTERFACE .)

#----------------------------------------------------------------
# Fetch boost packages
#----------------------------------------------------------------
#set(BOOST_INCLUDE_LIBRARIES math filesystem system program_options)
#set(BOOST_ENABLE_CMAKE ON)
#include(FetchContent)
#FetchContent_Declare(
#        Boost
#        GIT_REPOSITORY https://github.com/boostorg/boost.git
#        GIT_TAG master
#)
#FetchContent_MakeAvailable(boost)

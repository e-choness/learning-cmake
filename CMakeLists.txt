################################################################
# Essential Project Settings
################################################################
cmake_minimum_required(VERSION 3.20.0)
project(Hello
        VERSION 1.0
        DESCRIPTION "An example project with CMAKE"
        LANGUAGES CXX)

enable_testing()
################################################################
# Set C++ Standard
################################################################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD  20)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

################################################################
# Include subdirectories
################################################################
add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(entry)
add_subdirectory(tests)
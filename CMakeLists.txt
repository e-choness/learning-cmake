cmake_minimum_required(VERSION 3.25)
project(testing-stuff)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_executable(${PROJECT_NAME} EntryPoint.cpp)

target_link_libraries(
        src
)
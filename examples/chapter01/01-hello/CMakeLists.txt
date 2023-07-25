cmake_minimum_required(VERSION 3.0.0)
project(Hello
        VERSION 1.0
        DESCRIPTION "A brief CMAKE experiment"
        LANGUAGES CXX)
add_executable(Hello hello.cpp)
target_compile_features(Hello PRIVATE cxx_std_20)
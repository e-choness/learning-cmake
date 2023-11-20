################################################################
# Essential Project Settings
################################################################
project(Doctest_tests_run
        DESCRIPTION "Unit Tests"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

################################################################
# Add Executable
################################################################
#add_executable(${PROJECT_NAME} ConverterTests.cpp AbsoluteDateTest.cpp)
FILE(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_executable(${PROJECT_NAME} ${TEST_FILES})

################################################################
# Library Linkages
################################################################
target_link_libraries(${PROJECT_NAME} PUBLIC source_lib)


#cmake_minimum_required(VERSION 3.26)
#project(testing_test)
#
#set(CMAKE_CXX_STANDARD 17)
#
#set(SOURCE_FILES main.cpp)
#add_executable(DateConverter_run ${SOURCE_FILES})
#
#
#add_subdirectory(DateConverter_lib)
#
#target_link_libraries(DateConverter_run DateConverter_lib)

################################################################
# Essential Project Settings
################################################################
project(Doctest_tests
        DESCRIPTION "Unit Tests"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

################################################################
# Add Executable
################################################################
FILE(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
add_executable(${PROJECT_NAME} ${TEST_FILES})

################################################################
# Library Linkages
################################################################
target_link_libraries(${PROJECT_NAME} source_lib)


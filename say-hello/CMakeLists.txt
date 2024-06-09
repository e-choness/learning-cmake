cmake_minimum_required(VERSION 3.20.0)
project(HelloLibrary VERSION 1.0.0)

# Set include and source paths
set(HELLO_LIB say-hello)
set(HELLO_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HELLO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

configure_file(${HELLO_INCLUDE_DIR}/HELLOConfig.h.in ${HELLO_INCLUDE_DIR}/HELLOConfig.h)

set(GLFW_INCLUDE_DIR ../extern/glfw/include/GLFW)
set(GLFW_SRC_DIR ../extern/glfw/src)
# Print out current project information
include(${SCRIPTS_DIR}/PrintVariables.cmake)
print_variables()

# Library
add_library(${HELLO_LIB} 
    ${HELLO_SOURCE_DIR}/hello.cpp
    ${HELLO_SOURCE_DIR}/log.cpp
        ${HELLO_SOURCE_DIR}/HtmlParser.cpp
        ${HELLO_SOURCE_DIR}/HtmlProvider.cpp
    ${HELLO_SOURCE_DIR}/QueryBuilder.cpp
    ${HELLO_SOURCE_DIR}/Box.cpp
    ${HELLO_SOURCE_DIR}/BoxManipulator.cpp
    ${HELLO_SOURCE_DIR}/Spells.cpp
    ${HELLO_SOURCE_DIR}/Wizard.cpp
    ${HELLO_SOURCE_DIR}/BattleField.cpp)

# Add headers
target_include_directories(${HELLO_LIB} PUBLIC 
    ${HELLO_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR})

target_link_directories(${HELLO_LIB} PUBLIC ${GLFW_SRC_DIR})

target_link_libraries(${HELLO_LIB} PUBLIC glfw)

# Set pre-processor definition to specified version.
target_compile_features(${HELLO_LIB} PRIVATE cxx_std_20)
target_compile_definitions(${HELLO_LIB} PUBLIC SAY_HELLO_VERSION="1.1")
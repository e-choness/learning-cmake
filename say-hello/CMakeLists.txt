set(HELLO_SOURCE_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(say-hello 
${HELLO_SOURCE_DIR}/hello/hello.hpp
${HELLO_SOURCE_DIR}/hello/hello.cpp)

target_include_directories(say-hello 
PUBLIC 
${HELLO_SOURCE_DIR})
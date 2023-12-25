set(HELLO_SOURCE_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(say-hello 
${HELLO_SOURCE_DIR}/hello/hello.hpp
${HELLO_SOURCE_DIR}/hello/hello.cpp)

target_include_directories(say-hello 
PUBLIC 
${HELLO_SOURCE_DIR})

# Set proprocessor definition to specified version.
target_compile_definitions(say-hello PUBLIC SAY_HELLO_VERSION=1)
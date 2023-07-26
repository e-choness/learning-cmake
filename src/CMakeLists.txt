################################################################
# Set source and include directories
################################################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SOURCE_DIR}/include")

################################################################
# Define header files
################################################################
set(HEADER_LIST "${INCLUDE_DIR}/hello.hpp")

################################################################
# Add library
################################################################
add_library(my_library "${SOURCE_DIR}/hello.cpp" ${HEADER_LIST})

################################################################
# Include directories
################################################################
target_include_directories(my_library PRIVATE ${INCLUDE_DIR})

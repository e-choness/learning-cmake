################################################################
# Set source and include directories
################################################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SOURCE_DIR}/include")

################################################################
# Define header files
################################################################
file(GLOB HEADER_LIST ${INCLUDE_DIR}/*.h ${INCLUDE_DIR}/*.hpp)
file(GLOB SOURCE_LIST ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.cw)

################################################################
# Add library
################################################################
add_library(source_lib ${SOURCE_LIST} ${HEADER_LIST})

################################################################
# Include directories
################################################################
target_include_directories(source_lib PUBLIC ${INCLUDE_DIR})

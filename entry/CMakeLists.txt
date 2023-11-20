################################################################
# Essential Project Settings
################################################################
project(Entry
        DESCRIPTION "Entry point to this application"
        LANGUAGES CXX)

################################################################
# Add Executable and Set Compiler Features
################################################################
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

################################################################
# Library Linkages
################################################################
target_link_libraries(${PROJECT_NAME} PUBLIC source_lib)

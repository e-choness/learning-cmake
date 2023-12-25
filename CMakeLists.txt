cmake_minimum_required(VERSION 3.20.0)
project(hello VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(say-hello)
add_subdirectory(entry)

# Basic conditions
message(STATUS "Conditions example.")
set(CONDITION FALSE)

if(NOT CONDITION)
    message(STATUS "Condition was met.")
else()
    message(STATUS "Condition was not met.")
endif()

# String comparison
message(STATUS "String comparison example.")

set(ONE_STRING "One string")
set(ANOTHER_STRING "Another string")

if(ONE_STRING STREQUAL ANOTHER_STRING)
    message(STATUS "The strings are the same.")
# match string with substring
elseif(ONE_STRING MATCHES "string$")
    message(STATUS "The string ends with string.")
else()
    message(STATUS "The strings are different. First: ${ONE_STRING} Second: ${ANOTHER_STRING}")
endif()

# Numerics comparison
message(STATUS "Numerics comparison example.")

set(ONE_VARIABLE 1)
set(SAME_VARIABLE 1)
set(ANOTHER_VARIABLE 2)

if(ONE_VARIABLE EQUAL SAME_VARIABLE)
    message(STATUS "The variables are using the same value. First: ${ONE_VARIABLE} Second: ${SAME_VARIABLE}")
endif()

if(ONE_VARIABLE EQUAL ANOTHER_VARIABLE)
    message(STATUS "The variables are the same. First: ${ONE_VARIABLE} Second: ${ANOTHER_VARIABLE}")
else()
    message(STATUS "The variables are different. First: ${ONE_VARIABLE} Second: ${ANOTHER_VARIABLE}")
endif()

# While loop
message(STATUS "While loop example")

set(INDEX 5)
while(INDEX GREATER 0)
    message(STATUS "The index is ${INDEX}")
    # A mathmatical expression where INDEX is decremented by one at each loop
    math(EXPR INDEX "${INDEX} - 1")
endwhile()

# Foreach loop within an array of strings
message(STATUS "Foreach loop example")

foreach(ITEM IN ITEMS foo bar raar hoo)
    message(STATUS "${ITEM}")
endforeach()

# Foreach loop within a range, note the range is inclusive
# No need to use IN in front of RANGE
message(STATUS "Upper cap range example:")
foreach(INDEX RANGE 30)
    message(STATUS "${INDEX}")
endforeach()

message(STATUS "Both uppper and lower cap range example:")
foreach(INDEX RANGE 10 20)
    message(STATUS "${INDEX}")
endforeach()

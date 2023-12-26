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

# Arrays and how CMake expands them using ""
set(ARRAY 1 2 3 4)
# Using "${}", it will parse each element and concat them into a single string with ;
# Arrays 1;2;3;4
message(STATUS "Arrays ${ARRAY}")
# With out "", it will expand each element as it's own variable
# Arrays1234
message(STATUS "Arrays" ${ARRAY})

# Set property for variables
set(TARGET DIRECTORY "${PROJECT_SOURCE_DIR}")
set_property(${TARGET} PROPERTY FOO "${ARRAY}")

get_property(FOO_VALUE ${TARGET} PROPERTY FOO)

# The value of FOO is 1;2;3;4
message(STATUS "The value of FOO is ${FOO_VALUE}")

# CMake functions
function(do_something)
    message(STATUS "This function is doing something.")
endfunction()

# do_something is called four times
do_something()
do_something()
do_something()
do_something()

# CMake functions with arguments
function(do_another_thing args args2)
    message(STATUS "This function is having ${args}")
    message(STATUS "This function is having " ${args2})
endfunction()

# This function is having ARRAY
# If do_another_thing is having more than one arguments, the compiler will complain.
# do_another_thing(ARRAY)

# This function is having 1
do_another_thing(${ARRAY})

# CMake function take dynamic lists of arguments
function(multi_args_func arg1 arg2 arg3)
    # Interstingly, the elements in ARGN here are the ones NOT in passed arguments
    # ARGN represents the arguments that are not bound to the function declared arguments
    foreach(ARG IN LISTS ARGN)
        message(STATUS "Elements in ARGN ${ARG}")
    endforeach()
    foreach(ARG IN LISTS ARGV)
        message(STATUS "Elements in ARCV ${ARG}")
    endforeach()
endfunction()

# The compiler will complain even ARRAY is parsed using ${}
# muilt_args_func(${ARRAY})
multi_args_func(1 2 3 4 5 6 7 8 9)

# CMake variable scope
set(MEOW_STRING Meow)

function(say_meow)
    message(STATUS "The cat is saying ${MEOW_STRING} from top.")
    message(STATUS "The cat is saying ${ANOTHER_MEOW} from bottom.")
endfunction()

set(ANOTHER_MEOW MeowMeow)

# Global variables are evaluated right before the function is called.
say_meow()
message(STATUS "================================")
message(STATUS "Basic Function Example")
# CMake functions
function(do_something)
    message(STATUS "This function is doing something.")
endfunction()

# do_something is called four times
do_something()
do_something()
do_something()
do_something()
message(STATUS "================================\n")

message(STATUS "================================")
message(STATUS "Function with Arguments Example")
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
message(STATUS "================================\n")


message(STATUS "================================")
message(STATUS "Multi-variable Function Examples")
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
set(MEOW_GLOBAL MEOWWWW)
message(STATUS "The cat is saying ${MEOW_GLOBAL} before calling.")

function(say_meow)
    message(STATUS "The cat is saying ${MEOW_STRING} from top.")
    message(STATUS "The cat is saying ${ANOTHER_MEOW} from bottom.")
    
    set(MEOW_STRING meowww)
    message(STATUS "The cat is saying ${MEOW_STRING} from the inside.")
    
    # PARENT_SCOPE is used speficically within the function to mark the variable as global scope.
    set(MEOW_GLOBAL MEOW PARENT_SCOPE)
    message(STATUS "The cat is saying ${MEOW_GLOBAL} from the inside")

endfunction()

set(ANOTHER_MEOW MeowMeow)

# Global variables are evaluated right before the function is called.
say_meow()

message(STATUS "The cat is saying ${MEOW_GLOBAL} after calling.")

# MEOW_STRING is changed inside the function but will be reset after the function is returned.
message(STATUS "The cat is saying ${MEOW_STRING} from the outside.")
message(STATUS "================================\n")

message(STATUS "================================")
message(STATUS "Functions Return Value Example")
# A function that returns value
function(increment VAR)
    # To get the actual value of the passed argument it needs double dereferencing.
    # message(STATUS "The value before increment is ${${VAR}}")
    # Double dereferencing is also needed here for mathematic operations.
    math(EXPR NEW_VAR "${${VAR}} + 1")
    # The variable declared using set or math does not need double dereferencing.
    # message(STATUS "The value after increment is ${NEW_VAR}")
    # It's important to change the variable value by dereferencing and use double quotes.
    set("${VAR}" "${NEW_VAR}" PARENT_SCOPE)
endfunction()

set(VALUE 10)
message(STATUS "The value before function call is: ${VALUE}")

while(VALUE LESS 20)
    increment(VALUE)
endwhile()

message(STATUS "The values is returned as: ${VALUE}")

# A function that takes arguments and return a value
function(sum ARGA ARGB ARGC)
    # Adding the two variable values does not need double dereferencing, weird but that's how CMake works I suppose.
    math(EXPR SUM_VALUE "${ARGA} + ${ARGB}")
    set("${ARGC}" "${SUM_VALUE}" PARENT_SCOPE)
endfunction()

set(RETURN_VALUE 0)

message(STATUS "The return value before: ${RETURN_VALUE}")
sum(3 5 RETURN_VALUE)
message(STATUS "The return value after: ${RETURN_VALUE}")
message(STATUS "================================\n")
# Basic conditions
message(STATUS "================================")
message(STATUS "Conditions example.")
set(CONDITION FALSE)

if(NOT CONDITION)
    message(STATUS "Condition was met.")
else()
    message(STATUS "Condition was not met.")
endif()
message(STATUS "================================\n")

message(STATUS "================================")
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
message(STATUS "================================\n")

message(STATUS "================================")
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
message(STATUS "================================\n")
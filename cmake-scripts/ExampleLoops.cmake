# While loop
message(STATUS "================================")
message(STATUS "While loop example")

set(INDEX 5)
while(INDEX GREATER 0)
    message(STATUS "The index is ${INDEX}")
    # A mathmatical expression where INDEX is decremented by one at each loop
    math(EXPR INDEX "${INDEX} - 1")
endwhile()
message(STATUS "================================\n")

message(STATUS "================================")
# Foreach loop within an array of strings
message(STATUS "Foreach loop example")

foreach(ITEM IN ITEMS foo bar raar hoo)
    message(STATUS "The item inside a string array is ${ITEM}")
endforeach()
message(STATUS "================================\n")

# Foreach loop within a range, note the range is inclusive
# No need to use IN in front of RANGE
message(STATUS "================================")
message(STATUS "Upper cap range example:")
foreach(INDEX RANGE 30)
    message(STATUS "The current index is ${INDEX}")
endforeach()

message(STATUS "Both uppper and lower cap range example:")
foreach(INDEX RANGE 10 20)
    message(STATUS "The current index is ${INDEX}")
endforeach()
message(STATUS "================================\n")
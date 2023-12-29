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
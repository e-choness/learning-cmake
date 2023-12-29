message(STATUS "================================")
message(STATUS "Array Examples")
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
message(STATUS "================================\n")
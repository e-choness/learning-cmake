# Simply typing the scripts it would be very easy to make mistakes and introduce typoes.
# A function to generalize the steps would be a great way to make things simpler.
function(cmrc_add_test)
    # Set three variables named OPTIONS, ARGS AND LIST_ARGS, no values specified.
    set(OPTIONS WILL_FAIL)
    set(ARGS NAME SOURCE REGEX WHENCE PREFIX)
    set(LIST_ARGS RESOURCES TEST_ARGV)
    cmake_parse_arguments(
        # PARSE_ARGV indicates how many arguements to skip, in this case none are skipped.
        PARSE_ARGV 0
        # Executable prefix
        test
        "${OPTIONS}"
        "${ARGS}"
        "${LIST_ARGS}"
    )

    # test_UNPARSED_ARGUMENTS gets the arguements unprocessed by 
    message(STATUS "cmrc_add_test() is called.")
    foreach(arg IN LISTS test_UNPARSED_ARGUMENTS)
        # Put WARNING in the message to warn any unprocessed arguments
        message(WARNING "Unparsed argument: ${arg}")
    endforeach()
    
    # CMake parse arguments using prefix with argument name
    message(STATUS "ARGS NAME: ${test_NAME}")
    message(STATUS "ARGS SOURCE: ${test_SOURCE}")
    message(STATUS "LIST_ARGS RESOURCES: ${test_RESOURCES}")
    message(STATUS "ARGS REGEX: ${test_REGEX}")
    message(STATUS "OPTIONS: ${test_WILL_FAIL}")

    # Now we can use these arugments to actually generate tests
    cmrc_add_resource_library(
        rc_${test_NAME}
        NAMESPACE ${test_NAME}
        ${test_RESOURCES}
        WHENCE "${test_WHENCE}"
        PREFIX "${test_PREFIX}"
    )

    # Add generated tests to executable
    add_executable("${test_NAME}" "${test_SOURCE}")
    target_link_libraries("${test_NAME}" PRIVATE rc_${test_NAME})
    # test_TEST_ARGV needs to be expanded so no double quotes here.
    add_test("${test_NAME}" "${test_NAME}" ${test_TEST_ARGV})
    
    set_property(
        TEST "${test_NAME}"
        PROPERTY PASS_REGULAR_EXPRESSION
        "${test_PASS_REGEX}"
    )
    
    set_property(
        TEST "${test_NAME}"
        PROPERTY WILL_FAIL
        "${test_WILL_FAIL}"
    )

endfunction()

# Simple test
cmrc_add_test(
    NAME simple
    SOURCE simple.cpp
    RESOURCES hello.txt
    REGEX "^Hello, world!"
)
    
# Whence test
cmrc_add_test(
    NAME whence
    SOURCE whence.cpp
    RESOURCES subdir_a/subdir_b/file_a.txt
    REGEX "^I am a file!"
    WHENCE subdir_a
)

# Prefix test
cmrc_add_test(
    NAME prefix
    SOURCE prefix.cpp
    RESOURCES hello.txt
    PREFIX some-prefix
    REGEX "^Hello, world!"
)

# Prefix whence test
cmrc_add_test(
    NAME whence_prefix
    SOURCE whence_prefix.cpp
    RESOURCES subdir_a/subdir_b/file_b.txt
    WHENCE subdir_a
    PREFIX imaginary-prefix
    REGEX "^I am a file!"
)

# Flower test
cmrc_add_test(
    NAME flower
    # flower.cpp does not output anything, only checks if embedded file is the same as the file on the disk.
    SOURCE flower.cpp
    RESOURCES flower.jpg
    TEST_ARGV "${CMAKE_CURRENT_SOURCE_DIR}/flower.jpg"
)

cmrc_add_test(
    NAME iterate
    SOURCE iterate.cpp
    RESOURCES
        subdir_a/subdir_b/file_a.txt
        subdir_a/subdir_b/file_b.txt
    REGEX "^file_a.txt\nfile_b.txt\n$"
)

cmrc_add_test(
    NAME enoent
    SOURCE enoent.cpp
    WILL_FAIL
)
# Simply typing the scripts it would be very easy to make mistakes and introduce typoes.
# A function to generalize the steps would be a great way to make things simpler.
function(cmrc_add_test)
    # Set three variables named OPTIONS, ARGS AND LIST_ARGS, no values specified.
    set(OPTIONS)
    set(ARGS NAME SOURCE RESOURCE REGEX WHENCE)
    set(LIST_ARGS)
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
    message(STATUS "ARGS RESOURCE: ${test_RESOURCE}")
    message(STATUS "ARGS REGEX: ${test_REGEX}")

    # Now we can use these arugments to actually generate tests
    cmrc_add_resource_library(
        rc_${test_NAME}
        NAMESPACE ${test_NAME}
        ${test_RESOURCE}
        WHENCE "${test_WHENCE}"
    )

    # Add generated tests to executable
    add_executable("${test_NAME}" "${test_SOURCE}")
    target_link_libraries("${test_NAME}" PRIVATE rc_${test_NAME})
    add_test("${test_NAME}" "${test_NAME}")
    
endfunction()

# Simple test using the function
cmrc_add_test(
    NAME simple
    SOURCE simple.cpp
    RESOURCE hello.txt
    REGEX "^Hello, world!"
)

    
# # Whence test using the function
cmrc_add_test(
    NAME whence
    SOURCE whence.cpp
    RESOURCE subdir_a/subdir_b/file_a.txt
    REGEX "^I am a file!"
    WHENCE subdir_a
)

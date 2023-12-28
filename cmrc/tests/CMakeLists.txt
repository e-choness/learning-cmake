# Simply typing the scripts it would be very easy to make mistakes and introduce typoes.
# A function to generalize the steps would be a great way to make things simpler.
function(cmrc_add_test test_name main_source resource_file pass_regex whence_arg)
    cmrc_add_resource_library(
        rc_${test_name}
        NAMESPACE ${test_name}
        ${resource_file}
        WHENCE "${whence_arg}"
    )
    add_executable("${test_name}" "${main_source}")
    target_link_libraries("${test_name}" PRIVATE rc_${test_name})
    add_test("${test_name}" "${test_name}")
    set_property(
        TEST "${test_name}"
        PROPERTY PASS_REGULAR_EXPRESSION
        "${pass_regex}"
    )
endfunction()

# Simple test using the function
cmrc_add_test(
    simple
    simple.cpp
    hello.txt
    "^Hello, world!"
    ""
)
    
# Whence test using the function
cmrc_add_test(
    whence
    whence.cpp
    subdir_a/subdir_b/file_a.txt
    "^I am a file!"
    subdir_a
)

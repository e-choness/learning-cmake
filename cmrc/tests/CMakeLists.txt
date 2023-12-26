# Simply typing the scripts it would be very easy to make mistakes and introduce typoes.
# A function to generalize the steps would be a great way to make things simpler.
function()
endfunction()


# simple test
cmrc_add_resource_library(simple ALIAS rc::simple hello.txt)

add_executable(simple-test simple.cpp)
# Always remember to link libraries
target_link_libraries(simple-test PRIVATE rc::simple)
# If tests failed to run, it might be becuase the executable is not built.
# Try run `cmake --build .` to build the project and executables
add_test(simple simple-test)
set_property(
    TEST simple
    PROPERTY PASS_REGULAR_EXPRESSION
    "^Hello, world!"
)


# whence test
cmrc_add_resource_library(whence
    ALIAS rc::whence
    WHENCE subdir_a
    subdir_a/subdir_b/file_a.txt
    )

add_executable(whence-test whence.cpp)
target_link_libraries(whence-test PRIVATE rc::whence)
add_test(whence whence-test)
set_property(
    TEST whence
    PROPERTY PASS_REGULAR_EXPRESSION
    "^I am a file!"
)
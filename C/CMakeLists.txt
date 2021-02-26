cmake_minimum_required(VERSION 3.16)
project(bit)

add_subdirectory(${CMAKE_SOURCE_DIR}/../Unity ${CMAKE_BINARY_DIR}/Unity)

include(CTest)
enable_testing()

add_library(bit INTERFACE)
target_include_directories(bit INTERFACE 
    .
    include
)

# TESTS
set(WARNINGS_AS_ERRORS -Wall -Werror)
set(GCOV_FLAGS -g -fprofile-arcs -ftest-coverage -O0)

# TEST FUNCTION
function(add_bitmanipulation_test test_name test_file)
    message("Test name [${test_name}] -> Test file [${test_file}]")
    add_executable(${test_name} ${test_file})
    target_compile_options(${test_name} PRIVATE ${WARNINGS_AS_ERRORS} ${GCOV_FLAGS})
    target_link_options(${test_name} PRIVATE ${GCOV_FLAGS})
    target_link_libraries(${test_name} PRIVATE bit unity gcov)
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()


# BIT MASK TEST
add_bitmanipulation_test(bit_mask_test test/bit_mask_test.c)

# BIT SET TEST
add_bitmanipulation_test(bit_set_test test/bit_set_test.c)

# BIT RESET TEST
add_bitmanipulation_test(bit_reset_test test/bit_reset_test.c)

# BIT READ TEST
add_bitmanipulation_test(bit_read_test test/bit_read_test.c)

# BIT FLIP TEST
add_bitmanipulation_test(bit_flip_test test/bit_flip_test.c)

# COVERAGE target
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")
add_custom_target(coverage
    COMMAND cmake --build ${CMAKE_BINARY_DIR}
    COMMAND cmake --build ${CMAKE_BINARY_DIR} --target test
    COMMAND gcovr -r ${CMAKE_CURRENT_SOURCE_DIR} --html --html-details -o ${CMAKE_BINARY_DIR}/coverage/coverage.html
    BYPRODUCTS ${CMAKE_BINARY_DIR}/coverage/coverage.html
    VERBATIM USES_TERMINAL
)

cmake_minimum_required(VERSION 3.16)
project(bit)

add_subdirectory(${CMAKE_SOURCE_DIR}/../Unity ${CMAKE_BINARY_DIR}/Unity)

include(CTest)
enable_testing()

add_library(bit INTERFACE)
target_include_directories(bit INTERFACE .)


# TESTS
set(WARNINGS_AS_ERRORS -Wall -Werror)

# TEST FUNCTION
function(add_bitmanipulation_test test_name test_file)
    message("Test name [${test_name}] -> Test file [${test_file}]")
    add_executable(${test_name} ${test_file})
    target_compile_options(${test_name} PRIVATE ${WARNINGS_AS_ERRORS})
    target_link_libraries(${test_name} PRIVATE bit unity)
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

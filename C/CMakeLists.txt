cmake_minimum_required(VERSION 3.16)
project(bit)

add_subdirectory(${CMAKE_SOURCE_DIR}/../Unity ${CMAKE_BINARY_DIR}/Unity)

include(CTest)
enable_testing()

add_library(bit INTERFACE)
target_include_directories(bit INTERFACE .)


# TESTS
set(WARNINGS_AS_ERRORS -Wall -Werror)

# BIT MASK TEST
add_executable(bit_mask_test test/bit_mask_test.c)
target_compile_options(bit_mask_test PRIVATE ${WARNINGS_AS_ERRORS})
target_link_libraries(bit_mask_test PRIVATE bit unity)
add_test(NAME bit_mask_test COMMAND bit_mask_test)

# BIT SET CLEAR TEST
add_executable(bit_set_test test/bit_set_test.c)
target_compile_options(bit_set_test PRIVATE ${WARNINGS_AS_ERRORS})
target_link_libraries(bit_set_test PRIVATE bit unity)
add_test(NAME bit_set_test COMMAND bit_set_test)

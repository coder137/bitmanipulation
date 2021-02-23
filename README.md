- [Bit Manipulation](#bit-manipulation)
- [Usage](#usage)
  - [Manual](#manual)
  - [Use with CMake](#use-with-cmake)
- [Build Process](#build-process)
  - [Clone the repository](#clone-the-repository)
  - [Generate and build library](#generate-and-build-library)
  - [Running Tests](#running-tests)

# Bit Manipulation

![Github Action](https://github.com/coder137/bitmanipulation/actions/workflows/cmake.yml/badge.svg)

C and C++ Library for bit manipulation

# Usage

The **C** version of bit manipulation has only header dependencies and has one standard library dependency

## Manual

- Copy `C/bit.h` and `C/include` to your project
  - Make sure these are added to your include path
- Has dependency on `<stdint.h>` for standard C data types

## Use with CMake

- Add this project as a submodule OR copy this project into your repository
  - Make sure `Unity` has been added for unit testing as well
- Use `add_subdirectory` to build the project with CMake
  - Use the `bit` INTERFACE library with `target_link_libraries`

```cmake
add_subdirectory(bitmanipulation/C)

add_executable(dummy_target
  source_files.c
)
target_link_libraries(dummy_target
  PRIVATE/PUBLIC
  bit # The interface library to use
)
```

# Build Process

## Clone the repository

```
# Method 1
git clone <project>
git submodule init
git submodule update

# Method 2
git clone --recurse-submodules <project>
```

## Generate and build library

```
cd bitmanipulation\C
cmake -B build -G Ninja
cmake --build build

cd bitmaipulation\Cpp
cmake -B build -G Ninja
cmake --build build
```

## Running Tests

```
cmake --build build --config Debug --target all
ctest -C Debug -T test --output-on-failure
```

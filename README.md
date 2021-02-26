- [Bit Manipulation](#bit-manipulation)
- [Usage](#usage)
- [Build Process](#build-process)
  - [Clone the repository](#clone-the-repository)
  - [Generate and build library](#generate-and-build-library)
  - [Running Tests](#running-tests)

# Bit Manipulation

![Github Action](https://github.com/coder137/bitmanipulation/actions/workflows/cmake.yml/badge.svg)
[![codecov](https://codecov.io/gh/coder137/bitmanipulation/branch/master/graph/badge.svg?token=7727GKHSL7)](https://codecov.io/gh/coder137/bitmanipulation)

C and C++ Library for bit manipulation

# Usage

The **C** version of bit manipulation is just one header file and has one dependency

- Copy `C/bit.h` to your project
- Has dependency on `<stdint.h>` for data types

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

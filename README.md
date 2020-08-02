- [Bit Manipulation](#bit-manipulation)
- [Build Process](#build-process)
  - [Clone the repository](#clone-the-repository)
  - [Generate and build library](#generate-and-build-library)
  - [Running Tests](#running-tests)

# Bit Manipulation

[![Build Status](https://travis-ci.org/coder137/bitmanipulation.svg?branch=master)](https://travis-ci.org/coder137/bitmanipulation)

C and C++ Library for bit manipulation

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

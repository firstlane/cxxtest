cmake_minimum_required(VERSION 3.0.0)
project(test)

execute_process(
    COMMAND bash -c "bin/cxxtestgen --error-printer -o tests.cpp tests.h"
    OUTPUT_VARIABLE output
)

message(STATUS ${output})

add_executable(test
    tests.cpp
    tests.h
)

target_include_directories(test
    PRIVATE cxxtest
)

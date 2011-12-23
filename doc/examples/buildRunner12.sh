#!/bin/bash -v

. GetGlobals.sh

export PATH=$CXXTEST/bin:$PATH

# @main:
cxxtestgen -f --error-printer -o runner.cpp MyTestSuite4.h
# @:main

# @compile:
g++ -o runner -I$CXXTEST runner.cpp
# @:compile

./runner
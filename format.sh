#!/bin/bash
# This script runs clang-format on all of the source files.
#
clang-format -i src/lipsum.hpp src/lipsum.h src/lipsum_h.cpp

for file in examples/*.cpp; do
    clang-format -i "$file"
done
clang-format -i examples/CWrapper.c


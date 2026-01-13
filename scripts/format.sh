#!/bin/bash
# This script runs clang-format on all of the source files.
clang-format -i src/lipsum_h.cpp src/lipsum.hpp src/lipsum.h

for file in src/lipsum/*.hpp; do
    clang-format -i "$file"
done

for file in src/lipsum/*.inl; do
    clang-format -i "$file"
done


for file in examples/*.cpp; do
    clang-format -i "$file"
done
clang-format -i examples/CWrapper.c
clang-format -i src/jsbind/lipsum_binding_js.cpp

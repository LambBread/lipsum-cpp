# lipsum-cpp

Simple single-header library for generating sample Lorem Ipsum text in C++.

## Usage

Copy `lipsum.hpp` and `lipsum.inl` into your project's source code, or alternatively include it in CMake.

For static library or C wrapper builds, it is recommended to use CMake. Build it with the option `LPSM_BUILD_STATIC` equal to **`ON`**, or for C wrapper builds set options `LSPM_BUILD_STATIC` and `LSPM_BUILD_CWRAPPER` equal to **`ON`**.

## Examples

See `examples/` or [the live demo](https://lambbread.github.io/lipsumcpp-example/)

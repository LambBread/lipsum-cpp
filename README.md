# lipsum-cpp

A lightweight, single-header C++ library for generating sample Lorem Ipsum text. Useful for prototyping apps, UI testing, and anywhere placeholder text is needed.

## Features

- Header-only (just `lipsum.hpp` and `lipsum.inl` required)
- Customizable number of paragraphs, sentences, and words
- C++ and C API (static library and wrapper builds)
- CMake support for easy integration
- Example code and live demo available

## Installation

### Prerequisites

- A C/C++ compiler
- Optionally CMake, a build system (e.g. Make, Ninja, Visual Studio, ...), Doxygen, Python, and Git

#### Installation (Debian-based):
```bash
#Required
sudo apt update
sudo apt install build-essential
#Recommended
sudo apt install cmake
#Optional
sudo apt install ninja-build python3 doxygen git
```

### Header-only usage

Simply copy `lipsum.hpp` and `lipsum.inl` into your source tree.

### Manual static library + C wrapper build

Not recommended.

```bash
mkdir -p obj
mkdir -p bin
g++ -c src/lipsum.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum.o
g++ -c src/lipsum_h.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum_h.o
ar rcs bin/liblipsum-cpp.a obj/lipsum_h.o obj/lipsum.o
# build example
gcc examples/CWrapper.c -Isrc -Lbin -llipsum-cpp -DLIPSUM_BUILD_STATIC -o bin/CWrapper

```
### Using CMake (Recommended)

1. Clone or add this repo as a submodule:
    ```bash
    git submodule add https://github.com/LambBread/lipsum-cpp.git
    ```
2. Add to your CMake project:
    ```cmake
    add_subdirectory(lipsum-cpp)
    target_link_libraries(your_target lipsum-cpp)
    ```
3. To build as a static library (optional):  
   Set `LPSM_BUILD_STATIC=ON` in your CMake options.

4. For C wrapper builds, set both `LPSM_BUILD_STATIC` and `LPSM_BUILD_CWRAPPER` to **`ON`**.

## Usage

```cpp
#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate 5 paragraphs of 5-8 sentences of 1-3 sentence fragments of 4-9 words, starting with "Lorem ipsum..." (default)
    std::cout << lpsm::GenerateParagraphs();
    //generate 10 paragraphs of 7-10 sentences of 3-6 sentence fragments of 6-9 words, not starting with "Lorem ipsum..."
    std::cout << lpsm::GenerateParagraphs(10, lpsm::ArgVec2(6, 9), lpsm::ArgVec2(3, 6), lpsm::ArgVec2(7, 10), false);
    return 0;
}
```

## Examples

- See the [`examples/`](./examples) folder for sample code.
- [Live demo](https://lambbread.github.io/lipsumcpp-example/)
## Documentation

The documentation is available [here](https://lambbread.github.io/lipsum-cpp-docs/)

## C API Usage

For C projects, use the C wrapper (`lipsum.h`) and call functions with the `lpsm_` prefix. See the [`examples/README.md`](./examples/README.md) for details.

## Scripts

Utility scripts (see [`scripts/`](./scripts)):
- `split.py`: Converts the sample `lipsum.txt` into a vector for `lipsum.inl`.
- `lipsum.txt`: Source text for Lorem Ipsum sample generation.

## License

0BSD License. See [LICENSE.md](LICENSE.md) for details.

---

> Created by [LambBread](https://github.com/LambBread)

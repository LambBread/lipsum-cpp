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
- Optionally CMake and Doxygen

### Header-only usage

Simply copy `lipsum.hpp` and `lipsum.inl` into your source tree.

### Using CMake (Recommended for static/C builds)

1. Clone or add this repo as a submodule:
    ```bash
    git submodule add https://github.com/LambBread/lipsum-cpp.git
    ```
2. Add to your CMake project:
    ```cmake
    add_subdirectory(lipsum-cpp)
    target_link_libraries(your_target lipsum-cpp)
    ```
3. To build the static library:  
   Set `LPSM_BUILD_STATIC=ON` in your CMake options.

4. For C wrapper builds, set both `LPSM_BUILD_STATIC` and `LPSM_BUILD_CWRAPPER` to **`ON`**.

## Usage

```cpp
#define LIPSUM_IMPLEMENTATION // Only needed for header-only usage
#include "lipsum.hpp"
#include <iostream>

int main() {
    // 10 paragraphs, each 5-8 sentences, sentences with 4-12 words, not starting with "Lorem ipsum..."
    std::cout << lipsum::GenerateParagraphs(10, 5, 8, 4, 12, false);

    // Default: 5 paragraphs, each 5-8 sentences, 4-12 words per sentence, starting with "Lorem ipsum..."
    std::cout << lipsum::GenerateParagraphs();

    // Some other functions:
    // lipsum::GenerateParagraph(int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12)
    // lipsum::GenerateSentence(int minWord = 4, int maxWord = 12)
    // lipsum::GenerateWord()
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

0BSD License. See [LICENSE](LICENSE) for details.

---

> Created by [LambBread](https://github.com/LambBread)

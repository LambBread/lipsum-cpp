# lipsum-cpp

A header-only C++ library for generating sample Lorem Ipsum text. Useful for prototyping apps, UI testing, and anywhere placeholder text is needed.

## Features

- Header-only (also possible to use an amalgamated single-header `lipsum.hpp`)
- Customizable number of paragraphs, sentences, sentence fragments, and words
- C++, C, and JavaScript API (static/shared library, wrapper, and Emscripten module builds supported)
- CMake support for easy integration
- Example code and live demo available

## Installation

lipsum-cpp has been mainly tested on Linux and WebAssembly as well as cross-compiled to Windows, although it could likely run on other operating systems as well. 

### Prerequisites

- A C/C++ compiler (e.g. GCC, MSVC, Clang)
- Optionally:
    - CMake
    - Emscripten
    - a build system (e.g. Make, Ninja, MSBuild, ...)
    - Doxygen
    - Python
    - Git
    - Clang format
    - [quom](https://github.com/Viatorus/quom)

#### Installation (Debian-based):

```bash
# Required
sudo apt update
sudo apt install build-essential
# Recommended
sudo apt install cmake

# Optional
sudo apt install ninja-build python3 python3-pip python3-ply python3-venv doxygen git clang-format

# install emscripten here...

# may need to use venv on some systems
pip install --user quom

```

### Header-only usage

Simply copy `src/` into your source tree or download an amalgamated single-header release from the `Releases` section.

#### Amalgamating

Install [quom](https://github.com/Viatorus/quom) via `pip`, such as with:

```bash
# may need to use venv on some systems

pip install --user quom
```

In the root of the project, run `scripts/amalgamate.sh`.

### Manual static library + C wrapper build

Not recommended.

```bash
mkdir -p obj
mkdir -p bin
g++ -c src/lipsum_static.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum.o
g++ -c src/lipsum_h.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum_h.o
ar rcs bin/liblipsum-cpp.a obj/lipsum_h.o obj/lipsum.o
# build example
gcc examples/CWrapper.c -Isrc -Lbin -llipsum-cpp -DLIPSUM_BUILD_STATIC -o bin/CWrapper

```

### Build JS bindings

Either use CMake with the option `LPSM_BUILD_JSBIND=ON` while using Emscripten toolchain, or run:

```bash
mkdir -p bin
em++ src/jsbind/lipsum_binding_js.cpp -o bin/lipsum.js -s MODULARIZE=1 -s EXPORT_NAME=createLipsumCpp -lembind -Isrc/
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

4. To build as a shared library (optional):
   Set `LPSM_BUILD_SHARED=ON` in your CMake options.

5. For C wrapper builds, set either `LPSM_BUILD_STATIC` or `LPSM_BUILD_SHARED`, and `LPSM_BUILD_CWRAPPER` all to `ON`.

Alternatively, use `FetchContent` instead of submodules and `add_subdirectory()`.

## Usage

### Basic example

```cpp
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"

int main()
{
    // Create a generator.
    lpsm::Generator generator;

    // Generate 3 paragraphs.
    std::cout << generator.paragraph(3, true);

    // Generate 6 sentences.
    std::cout << generator.sentence(6, true) << '\n';

    // Generate a sentence fragment.
    std::cout << generator.sentence_fragment() << '\n';

    // Generate 5 words.
    std::cout << generator.word(5) << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << generator.md_paragraph(5, true);

    // Generate a Markdown document with 20 elements.
    std::cout << generator.md_text(20);

    return 0;
}
```

### Advanced example

```cpp
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate 5 paragraphs
    // of 5-8 sentences
    // of 1-3 sentence fragments
    // of 4-9 words,
    // starting with "Lorem ipsum..." (default)
    std::cout << lpsm::GenerateParagraphs();
    // generate 10 paragraphs
    // of 7-10 sentences
    // of 3-6 sentence fragments
    // of 6-9 words,
    // not starting with "Lorem ipsum..."
    std::cout << lpsm::GenerateParagraphs(10,
                                          lpsm::ArgVec2(6, 9),
                                          lpsm::ArgVec2(3, 6),
                                          lpsm::ArgVec2(7, 10),
                                          false);
    // equivalent statement
    std::cout << lpsm::GenerateParagraphsX(10, 6, 9, 3, 6, 7, 10, false);
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

## JS Binding Usage

For JavaScript projects, usage is similar to the C API. See the [`src/jsbind/README.md`](./src/jsbind/README.md) and [example](./examples/JSBinding.html) for details.

## Scripts

Utility scripts (see [`scripts/`](./scripts)):
- `split.py`: Converts the sample `lipsum.txt` into a vector for `lipsum.inl`.
- `lipsum.txt`: Source text for Lorem Ipsum sample generation.

## AI Usage

All of [`src/`](./src/) and most of [`examples/`](./examples/) were developed by a human, not an LLM. Some portions had some AI usage, such as this README which had some AI assistance involved, or example [`Advanced.cpp`](./examples/Advanced.cpp) which was entirely AI-generated.

## License

lipsum-cpp is under the BSD Zero-Clause License, a very permissive public-domain equivalent license. See [LICENSE.md](LICENSE.md) for details.

Example [`Markdown.cpp`](./examples/Markdown.cpp) uses library [maddy](https://github.com/progsource/maddy), under MIT License.

---

> Created by [LambBread](https://github.com/LambBread)

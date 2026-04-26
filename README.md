# lipsum-cpp

![GitHub License](https://img.shields.io/github/license/LambBread/lipsum-cpp)
![GitHub Tag](https://img.shields.io/github/v/tag/LambBread/lipsum-cpp)
![GitHub top language](https://img.shields.io/github/languages/top/LambBread/lipsum-cpp)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/LambBread/lipsum-cpp)
![GitHub last commit](https://img.shields.io/github/last-commit/LambBread/lipsum-cpp)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/LambBread/lipsum-cpp/build.yml)

A header-only library written in C++ for generating sample Lorem Ipsum text. Useful for prototyping apps, UI testing, and anywhere placeholder text is needed.

## Features

- Header-only (also possible to use an amalgamated single-header `lipsum.hpp`)
- Customizable number of paragraphs, sentences, sentence fragments, and words
- Multi-source lorem-ipsum generation including built-in lorem-ipsum, cat-ipsum, dog-ipsum, and corporate-ipsum
- Markdown, HTML, XML, and JSON generation
- Extensive documentation via Doxygen
- C++, C, and JavaScript support (static/shared library, wrapper, and Emscripten module builds supported)
- CMake support for easy integration
- Example code and live demo available

## Installation

lipsum-cpp has been mainly tested on Linux and WebAssembly, although there have been passing builds for Windows and macOS as well.

### Prerequisites

- A C/C++ compiler (e.g. GCC, MSVC, Clang)
- Recommended:
    - CMake
    - Make
    - Git
- Optional:
    - Emscripten
    - 7-Zip
    - a build system (e.g. Ninja, MSBuild, ...)
    - Doxygen
    - Clang format
    - Clang tidy
    - [quom](https://github.com/Viatorus/quom)

#### Installation (Debian-based):

```bash
# Required
sudo apt update
sudo apt install build-essential
# Recommended
sudo apt install cmake

# Optional
sudo apt install ninja-build python3 python3-pip python3-ply python3-venv \
    doxygen git clang-format clang-tidy 7zip

# install emscripten here...

# may need to use venv on some systems
pip install --user quom

```

### Adding to projects + Building

#### Using CMake (Recommended)

1. Clone or add this repo as a submodule:
    
    ```bash
    git submodule add https://github.com/LambBread/lipsum-cpp.git
    ```

2. Add to your CMake project:
    
    ```cmake
    add_subdirectory(lipsum-cpp)
    target_link_libraries(your_target lipsum-cpp)
    ```

3. To build as a static or shared library (optional):  
   Set `LPSM_BUILD_STATIC=ON` or `LPSM_BUILD_SHARED=ON` in your CMake options.

4. For C wrapper builds, set `LPSM_BUILD_STATIC` or `LPSM_BUILD_SHARED`, and `LPSM_BUILD_CWRAPPER` all to `ON`.

Alternatively, use `FetchContent` instead of submodules and `add_subdirectory()`.

#### Header-only usage

Simply copy `src/` into your source tree or download and extract an amalgamated single-header release from the `Releases` section.

#### Building manually via GCC

Not recommended.

```bash
mkdir -p obj
mkdir -p bin

# primary cpp portion
g++ -c src/lipsum_static.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum.o

# c wrapper
g++ -c src/lipsum_h.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum_h.o

# link together
ar rcs bin/liblipsum-cpp.a obj/lipsum_h.o obj/lipsum.o

# build example
gcc examples/CWrapper.c -Isrc -Lbin -llipsum-cpp -DLIPSUM_BUILD_STATIC -o bin/CWrapper

```

#### Amalgamating

Install [quom](https://github.com/Viatorus/quom) via `pip`, such as with:

```bash
# may need to use venv on some systems

pip install --user quom
```

At the root of the project, run `make amalgamate` or `make pkg`.


#### Building JS bindings

Use CMake with the option `LPSM_BUILD_JSBIND=ON`, or with `make em_build` or `make pkg`. Alternatively, build manually although this is not recommended.

```bash
mkdir -p bin
em++ src/jsbind/lipsum_binding_js.cpp -o bin/lipsum.js -s MODULARIZE=1 -s EXPORT_NAME=createLipsumCpp -lembind -Isrc/
```


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
    lpsm::Generator gen;

    // Generate 5 words.
    std::cout << gen.word(5) << '\n';
    
    // Generate a sentence fragment.
    std::cout << gen.sentence_fragment() << '\n';
    
    // Generate 6 sentences.
    std::cout << gen.sentence(6, true) << '\n';
    
    // Generate 3 paragraphs.
    std::cout << gen.paragraph(3, true);

    // Generate a text.
    std::cout << gen.text(true);

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
- A live demo of these examples are available [here.](https://lambbread.github.io/lipsumcpp-example/) These can also be built with `make em_build` or `make pkg`.

## Documentation

The documentation is available [here.](https://lambbread.github.io/lipsum-cpp-docs/) The documentation can also be generated by Doxygen by running `make build` or `make pkg`.

## C Wrapper Usage

For C projects, use the C wrapper (`lipsum.h`) and call functions with the `lpsm_` prefix. See the [`examples/README.md`](./examples/README.md) for details.

## JS Binding Usage

For JavaScript projects, usage is similar to the C wrapper. See the [`src/jsbind/README.md`](./src/jsbind/README.md) and [example](./examples/JSBinding.html) for details.

## Credits

- [`scripts/lipsum.txt`](./scripts/lipsum.txt) was generated with [lipsum.com](https://lipsum.com/).
- [`scripts/catipsum.txt`](./scripts/catipsum.txt) was generated with [catipsum.com](https://www.catipsum.com/).
- [`scripts/dogipsum.txt`](./scripts/dogipsum.txt) was generated with [doggoipsum.com](https://doggoipsum.com/).
- [`scripts/corporateipsum.txt`](./scripts/corporateipsum.txt) was generated with [corporate-ipsum.com](https://www.corporate-ipsum.com/).

---

> Created by [LambBread](https://github.com/LambBread)

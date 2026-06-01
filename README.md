# lipsum-cpp

![GitHub License](https://img.shields.io/github/license/LambBread/lipsum-cpp)
![GitHub Tag](https://img.shields.io/github/v/tag/LambBread/lipsum-cpp)
![GitHub top language](https://img.shields.io/github/languages/top/LambBread/lipsum-cpp)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/LambBread/lipsum-cpp)
![GitHub last commit](https://img.shields.io/github/last-commit/LambBread/lipsum-cpp)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/LambBread/lipsum-cpp/build.yml)

A header-only library written in C++ for generating sample lorem-ipsum text. Useful for prototyping apps,
UI testing, benchmarking Markdown/HTML/XML/JSON parser libraries, and anywhere placeholder text is needed.

## Features

- Header-only (also possible to use an amalgamated single-header `lipsum.hpp`)
- Zero third-party dependencies outside of build dependencies
- Customizable number of paragraphs, sentences, sentence fragments, and words
- Multi-source lorem-ipsum generation including built-in lorem-ipsum, cat-ipsum, dog-ipsum, and corporate-ipsum
- Extremely fast and very lightweight (see `Benchmarks` section)
- Markdown, HTML, XML, and JSON generation
- CLI tool for integration in projects
- Extensive documentation via Doxygen
- C++, C, and JavaScript support (static/shared library, wrapper, and Emscripten module builds supported)
- CMake support for easy integration
- Example code and live demo available

## Benchmarks

All tested with CMake `Release` build type, with default `lpsm::Generator` arguments.

*Medium-end computer: Debian 13, 8GB DDR4 RAM, Intel i3-6100 (4-core) @ 3.7GHz*:

- 23,825,730 words/second
- 1,129,105 sentences/second
- 165,406 paragraphs/second
- 146,052 Markdown paragraphs/second
- 294,004 Markdown "elements"/second

*Very low-end computer: BookwormPup32, 1GB DDR2 RAM, Intel Centrino Duo (2-core) @ 1.6GHz*:

- 2,767,236 words/second
- 105,033 sentences/second
- 15,833 paragraphs/second
- 15,267 Markdown paragraphs/second
- 27,966 Markdown "elements"/second

## Usage

### Basic example

```cpp
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    // Create a generator.
    lpsm::Generator gen;

    // Generate 5 words.
    std::cout << gen.word(5) << '\n';
    
    // Generate a sentence fragment.
    std::cout << gen.fragment() << '\n';
    
    // Generate 6 sentences.
    std::cout << gen.sentence(6, true) << '\n';
    
    // Generate 3 paragraphs.
    std::cout << gen.paragraph(3, true);

    // Generate a text.
    std::cout << gen.text(true);

    return 0;
}
```

[See this example live](https://lambbread.github.io/lipsumcpp-example/Generator.html)

### Advanced example

```cpp
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    // Create a generator using corporate ipsum and the specified seed.
    lpsm::Generator gen("corpo", 1234);

    // Change to 6-9 words per sentence fragment,
    // 3-6 sentence fragments per sentence,
    // 6-9 items in JSON arrays/objects
    gen.change_setting("word", 6, 9);
    gen.change_setting("frag", 3, 6);
    gen.change_setting("jsonLength", 6, 9);

    // Generate a URL.
    std::cout << gen.url() << '\n';

    // Generate a plain URL.
    std::cout << gen.plain_url() << '\n';

    // Generate a slug.
    std::cout << gen.slug('_') << '\n';

    // Generate a scramble.
    std::cout << gen.scramble(24, 'a', 'z') << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << gen.md_paragraph(5, true, false);

    // Generate a Markdown document with 20 elements.
    std::cout << gen.md_text(20, false);

    // Generate a Markdown subtitle.
    std::cout << gen.md_header(2, false);

    // Generate an italic Markdown sentence.
    std::cout << gen.md_emphasis(false, false) << '\n';

    // Generate a Markdown link.
    std::cout << gen.md_link(false) << '\n';

    // Generate an ordered Markdown list.
    std::cout << gen.md_list(true, false);

    // Generate 5 HTML paragraphs.
    std::cout << gen.md_paragraph(5, true, true);

    // Generate an HTML document with 20 elements.
    std::cout << gen.md_text(20, true);

    // Generate an XML document with 40 "choices".
    std::cout << gen.xml(40) << '\n';

    // Generate a JSON object with a max recursion of 5.
    std::cout << gen.json(0, 5, true) << '\n';

    // Generate a JSON value with a max recursion of 5.
    std::cout << gen.json_value(0, 5) << '\n';

    return 0;
}
```

[See this example live](https://lambbread.github.io/lipsumcpp-example/GeneratorFormats.html)


### Binding usage

For C projects, use the C wrapper (`lipsum.h`) and call functions with the `lpsm_`
prefix. See the [`examples/README.md`](./examples/README.md) for details.
For JavaScript projects, usage is similar to the C wrapper.
See the [`src/jsbind/README.md`](./src/jsbind/README.md) and [example](./examples/JSBinding.html)
for details.

## Installation

lipsum-cpp has been mainly tested on Linux (Debian 13) and WebAssembly, and there have also been passing builds on Windows and macOS.

```bash
# Debian-based
sudo apt install ./lipsum-cpp-x.x.x-Linux.deb

# RHEL/Fedora-based
sudo dnf install ./lipsum-cpp-x.x.x-Linux.rpm

# Arch-based
sudo pacman -U ./lipsum-cpp-x.x.x-x-x86_64.pkg.tar.zst

# Windows
# Run the .msi file provided.

# macOS
# Install the .dmg provided.

# Cross-platform
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DLPSM_BUILD_CLI=ON <... your CMake options here>
cmake --build build --config Release
sudo cmake --install build # or "Administrator" terminal on Windows

# From here, use find_package in your CMake project and/or use the CLI tool,
# lpsmcpp-cli

# Alternatively, do not install and use FetchContent or add_subdirectory in your CMake project instead.
```


### Adding to projects & Building

#### Build prerequisites

- A C/C++ compiler (e.g. GCC, MSVC, Clang) supporting C++20 or newer
- Recommended:
    - CMake (>= 3.20)
    - Make
    - another build system (e.g. Ninja, MSBuild, ...)
    - Git
- Optional:
    - Emscripten (>= 2.0 required, >= 3.x recommended)
    - 7-Zip
    - Doxygen
    - Clang format
    - Clang tidy
    - [quom](https://github.com/Viatorus/quom)

#### Using CMake (Recommended)

1. Add to your CMake project:
    
    ```cmake
    include(FetchContent)

    FetchContent_Declare(
        lipsum-cpp
        GIT_REPOSITORY https://github.com/LambBread/lipsum-cpp.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(lipsum-cpp)
    # ...
    target_link_libraries(your_target PRIVATE lipsum-cpp)
    ```

2. To build as a static or shared library with C wrapper support (optional):  
   Set `LPSM_BUILD_STATIC=ON` or `LPSM_BUILD_SHARED=ON` in your CMake options. For C wrapper builds,
   also set `LPSM_BUILD_CWRAPPER=ON`.

Alternatively, instead of `FetchContent`, use:

```cmake
# with add_subdirectory

add_subdirectory("/path/to/lipsum-cpp/")
# ...
target_link_libraries(your_target PRIVATE lipsum-cpp)


# with find_package

find_package(lipsum-cpp REQUIRED)
# ...
target_link_libraries(your_target PRIVATE lipsum-cpp::lipsum-cpp)
```

#### Header-only usage

Simply copy `src/` into your source tree or download and extract an amalgamated
single-header release from the `Releases` section (typically `lipsum-pkg.zip`).

#### Building manually

Not recommended.

```bash
mkdir -p obj
mkdir -p bin

# primary cpp portion
g++ -c src/lipsum_static.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum.o --std=c++20

# c wrapper
g++ -c src/lipsum_h.cpp -DLIPSUM_BUILD_STATIC -o obj/lipsum_h.o --std=c++20

# link together
ar rcs bin/liblipsum-cpp.a obj/lipsum_h.o obj/lipsum.o

# build example
gcc examples/CWrapper.c -Isrc -Lbin -llipsum-cpp -DLIPSUM_BUILD_STATIC -o bin/CWrapper

```

#### Amalgamating & Building JS binding

Install [quom](https://github.com/Viatorus/quom) via `pip`, such as with:

```bash
# may need to use venv on some systems

pip install --user quom
```

At the root of the project, run `make amalgamate` or `make pkg`.

For building the JS binding, use CMake with the option `LPSM_BUILD_JSBIND=ON`, or with `make em_build` or `make pkg`.
Alternatively, build manually although this is not recommended.

```bash
mkdir -p bin
em++ src/jsbind/lipsum_binding_js.cpp -o bin/lipsum.js -s MODULARIZE=1 -s EXPORT_NAME=createLipsumCpp -lembind -Isrc/ -std=c++20
```


## Examples & Documentation

- See the [`examples/`](./examples) folder for sample code.
- A live demo of these examples are available [here.](https://lambbread.github.io/lipsumcpp-example/) 
  These can also be built with `make em_build` or `make pkg`.
- The documentation is available [here.](https://lambbread.github.io/lipsum-cpp-docs/) 
  It can also be generated via Doxygen by running `make build` or `make pkg`.

## Credits

- [`scripts/lipsum.txt`](./scripts/lipsum.txt) was generated with [lipsum.com](https://lipsum.com/).
- [`scripts/catipsum.txt`](./scripts/catipsum.txt) was generated with [catipsum.com](https://www.catipsum.com/).
- [`scripts/dogipsum.txt`](./scripts/dogipsum.txt) was generated with [doggoipsum.com](https://doggoipsum.com/).
- [`scripts/corporateipsum.txt`](./scripts/corporateipsum.txt) was generated with [corporate-ipsum.com](https://www.corporate-ipsum.com/).

---

> Created by [LambBread](https://github.com/LambBread)

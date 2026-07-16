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
- Extremely fast and very lightweight (see [`Benchmarks`](#benchmarks) section)
- Zero third-party dependencies outside of build dependencies
- Multi-source lorem-ipsum generation including built-in lorem-ipsum, cat-ipsum, dog-ipsum, 
  and corporate-ipsum as well as custom sources
- Markdown, HTML, XML, JSON, CSV, and code block (C, C++, Rust, Python, and JavaScript snippet) generation
- Customizable number of paragraphs, sentences, sentence fragments, and words
- CLI tool for integration in projects
- Interactive CLI tool for easy generation
- Extensive documentation via Doxygen
- C++, C, and JavaScript support (static/shared library, wrapper, and Emscripten module builds supported)
- CMake support for easy integration
- Example code and live demo available

## Installation

lipsum-cpp has been mainly tested on Linux (Debian 13) and WebAssembly, and there have been passing CI/CD on Windows and macOS.

### Build prerequisites

- A C/C++ compiler (e.g. GCC, MSVC, Clang) supporting ideally C++20 or newer
- Recommended:
    - CMake (>= 3.20)
    - Make
    - another build system (e.g. Ninja, MSBuild, ...)
    - Git
- Optional:
    - Emscripten (>= 2.0 required, >= 3.x recommended)
    - 7-Zip
    - Doxygen
    - `clang-format`
    - `clang-tidy`
    - `libxml2` (for [`ParserStressTest.cpp`](./examples/ParserStressTest.cpp))
    - `libjson-c` (for [`ParserStressTest.cpp`](./examples/ParserStressTest.cpp))
    - `zlib` (for [`CompressionBenchmarks.cpp`](./examples/CompressionBenchmarks.cpp))
    - [quom](https://github.com/Viatorus/quom)

### Quick Start

#### Using CMake (Recommended)

lipsum-cpp with CMake defaults to a static library with C wrapper support. Some other presets include:

- Shared library (`LPSM_BUILD_SHARED=ON`)
- Header-only library (`LPSM_BUILD_STATIC=OFF` and `LPSM_BUILD_SHARED=OFF`)
- No C wrapper support (`LPSM_BUILD_CWRAPPER=OFF`), required with header-only builds
- "Minimum", "Quiet", and "Verbose" modes (see [`src/README.md`](./src/README.md); 
  change `LPSM_MIN_BUILD`, `LPSM_QUIET`, and `LPSM_VERBOSE` options)

To add to your CMake project:
    
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

Alternatively, instead of `FetchContent`, use `add_subdirectory`:

```cmake
add_subdirectory("/path/to/lipsum-cpp/")
# ...
target_link_libraries(your_target PRIVATE lipsum-cpp)
```

#### Header-only usage

Simply copy `src/` into your source tree or download and extract an amalgamated
single-header release from the `Releases` section (`lipsum-pkg.zip`).

##### Amalgamating

Install [quom](https://github.com/Viatorus/quom) via `pip`, such as with:

```bash
# may need to use venv on some systems

pip install --user quom
```

At the root of the project, run `make amalgamate`, `make pkg`, or `cmake --build build --target amalgamate`.

### System-wide installation (Optional)

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

# Cross-platform (build from source)
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DLPSM_BUILD_CLI=ON <... your CMake options here>
cmake --build build --config Release
sudo cmake --install build
```

From here, it is possible to use `find_package` in CMake projects.

```cmake
find_package(lipsum-cpp REQUIRED)
# ...
target_link_libraries(your_target PRIVATE lipsum-cpp::lipsum-cpp)
```

## Usage

### Basic example

*`LIPSUM_IMPLEMENTATION` must be defined in exactly one file per project for header-only usage.*

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
    std::cout << gen.sentence(6, lpsm::USELIPSUM) << '\n';

    // Generate 3 paragraphs.
    std::cout << gen.paragraph(3, lpsm::USELIPSUM);

    // Generate a text.
    std::cout << gen.text(lpsm::USELIPSUM);

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

    // Generate an email.
    std::cout << gen.email() << '\n';

    // Generate a slug.
    std::cout << gen.slug('_') << '\n';
    
    // Generate a camel case case slug.
    std::cout << gen.case_slug(lpsm::CaseSlugCase::CamelCase) << '\n';

    // Generate a scramble.
    std::cout << gen.scramble(24, 'a', 'z') << '\n';

    // Generate an IPv6 IP address with a port.
    std::cout << gen.ip_addr(lpsm::IPV6, lpsm::PORT) << '\n';
    
    // Generate a C++ pseudocode block.
    std::cout << gen.code(lpsm::CodeLanguage::Cpp) << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << gen.fmt_paragraph(5, lpsm::USELIPSUM, lpsm::MARKDOWN);

    // Generate a Markdown document with 20 elements.
    std::cout << gen.fmt_text(20, lpsm::MARKDOWN);

    // Generate a Markdown subtitle.
    std::cout << gen.fmt_header(2, lpsm::MARKDOWN);

    // Generate an italic Markdown sentence.
    std::cout << gen.fmt_emphasis(lpsm::ITALIC, lpsm::MARKDOWN) << '\n';

    // Generate a Markdown link.
    std::cout << gen.fmt_link(lpsm::MARKDOWN) << '\n';

    // Generate an ordered Markdown list.
    std::cout << gen.fmt_list(lpsm::ORDERED, lpsm::MARKDOWN);

    // Generate 5 HTML paragraphs.
    std::cout << gen.fmt_paragraph(5, lpsm::USELIPSUM, lpsm::HTML);

    // Generate an HTML document with 20 elements.
    std::cout << gen.fmt_text(20, lpsm::HTML);

    // Generate an XML document with 40 "choices".
    std::cout << gen.xml(40) << '\n';

    // Generate a JSON object with a max recursion of 5.
    std::cout << gen.json(5, lpsm::OBJECT) << '\n';

    // Generate a JSON value with a max recursion of 5.
    std::cout << gen.json_value(5) << '\n';
    
    // Generate a CSV document.
    std::cout << gen.csv();

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

### Examples & Documentation

- See the [`examples/`](./examples) folder for sample code.
- A live demo of these examples are available [here.](https://lambbread.github.io/lipsumcpp-example/) 
  These can also be built with `make em_build` or `make pkg`.
- The documentation is available [here.](https://lambbread.github.io/lipsum-cpp-docs/) 
  It can also be generated via Doxygen by running `make` or `make pkg`.

## Benchmarks

All tested with CMake `Release` build type, with default
`lpsm::Generator` arguments under a normal, static library build.

### Medium-end environment

*Debian 13, 8GB DDR4 RAM, Intel i3-6100 (4-core) @ 3.7GHz*:

| Metric              | Performance per second |
| ------------------- | ---------------------- |
| Words               | 28,825,730             |
| Sentences           | 1,129,105              |
| Paragraphs          | 165,406                |
| Markdown paragraphs | 146,052                |
| Markdown elements   | 294,004                |

### Low-end environment

*Puppy Linux (BookwormPup32), 1GB DDR2 RAM, Intel Centrino Duo (2-core) @ 1.6GHz*:

| Metric              | Performance per second |
| ------------------- | ---------------------- |
| Words               | 2,767,236              |
| Sentences           | 105,033                |
| Paragraphs          | 15,833                 |
| Markdown paragraphs | 15,267                 |
| Markdown elements   | 27,966                 |

### GitHub Actions Windows runner

| Metric              | Performance per second |
| ------------------- | ---------------------- |
| Words               | 18,206,408             |
| Sentences           | 490,375                |
| Paragraphs          | 67,996                 |
| Markdown paragraphs | 64,619                 |
| Markdown elements   | 109,314                |

### GitHub Actions macOS runner

| Metric              | Performance per second |
| ------------------- | ---------------------- |
| Words               | 14,804,787             |
| Sentences           | 720,016                |
| Paragraphs          | 106,058                |
| Markdown paragraphs | 95,303                 |
| Markdown elements   | 163,419                |

### GitHub Actions Ubuntu runner

| Metric              | Performance per second |
| ------------------- | ---------------------- |
| Words               | 24,511,520             |
| Sentences           | 1,100,179              |
| Paragraphs          | 163,271                |
| Markdown paragraphs | 152,726                |
| Markdown elements   | 266,789                |

## Credits

- [`scripts/lipsum.txt`](./scripts/lipsum.txt) was generated with [lipsum.com](https://lipsum.com/).
- [`scripts/catipsum.txt`](./scripts/catipsum.txt) was generated with [catipsum.com](https://www.catipsum.com/).
- [`scripts/dogipsum.txt`](./scripts/dogipsum.txt) was generated with [doggoipsum.com](https://doggoipsum.com/).
- [`scripts/corporateipsum.txt`](./scripts/corporateipsum.txt) was generated with [corporate-ipsum.com](https://www.corporate-ipsum.com/).

---

Licensed under [0BSD](https://opensource.org/license/0bsd). (see [`LICENSE.md`](./LICENSE.md) for details)

> Created by [LambBread](https://github.com/LambBread)

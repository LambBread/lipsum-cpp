# lipsum-cpp

Simple single-header library for generating sample Lorem Ipsum text in C++.

## Usage

Copy `lipsum.hpp` and `lipsum.inl` into your project's source code, or alternatively include it in CMake.

For static library or C wrapper builds, it is recommended to use CMake. Build it with the option `LPSM_BUILD_STATIC` equal to **`ON`**, or for C wrapper builds set options `LSPM_BUILD_STATIC` and `LSPM_BUILD_CWRAPPER` equal to **`ON`**.

## Examples

See `examples/` or [the live demo](https://lambbread.github.io/lipsumcpp-example/)

### Basic example
```cpp
#define LIPSUM_IMPLEMENTATION //not necessary when building as a static library
#include "lipsum.hpp"
int main()
{
  //10 paragraphs, each with between 5-8 sentences, which have 4-12 words
  std::cout << lipsum::GenerateParagraphList(10, 5, 8, 4, 12);
  //generate default of 5 paragraphs, each with 5-8 sentences, which have 4-12 words
  std::cout << lipsum::GenerateParagraphList();
  //other functions include:
  //lipsum::GenerateParagraph(int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12)
  //lipsum::GenerateSentence(int minWord = 4, int maxWord = 12)
  //lipsum::GenerateWord()
  return 0;
}
```

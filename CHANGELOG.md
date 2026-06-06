# lipsum-cpp Changelog

For a more brief overview, see [`TODO.md`](./TODO.md).

*Dates are measured in local time, UTC-7 / UTC-8.*

## 0.0.x

### 0.0.1 (2025-09-02)

- Start project
- New functions:

```cpp
std::string lipsum::GenerateSentence(int, int);
std::string lipsum::GenerateParagraph(int, int, int, int);
```

### 0.0.2 (2025-09-02)

- Add (broken) C wrapper
- New functions:

```cpp
std::string lipsum::GenerateParagraphList(int, int, int, int, int);

const char* lpsm_GenerateSentence(int, int);
const char* lpsm_GenerateParagraph(int, int, int, int);
const char* lpsm_GenerateParagraphList(int, int, int, int, int);
```

### 0.0.3 (2025-09-03)

- Add [`examples/`](./examples/) folder
- More `README.md`s (in [`scripts/`](./scripts/) and [`examples/`](./examples/))
- New functions:

```cpp
std::string lipsum::GenerateWord();

const char* lpsm_GenerateWord(void);
```

- New examples:

```
GenerateParagraph.cpp
GenerateParagraphList.cpp
GenerateSentence.cpp
GenerateWord.cpp
```

### 0.0.4 (2025-09-06)

- Add option `LPSM_BUILD_ASHTML` for WebAssembly builds

### 0.0.5 (2025-09-07)

- Overhaul [`README.md`](./README.md)
- Doxygen support, enabled with `LPSM_BUILD_DOCS` with target `doc`
- Add `useLipsum` param to certain functions
- New functions:

```cpp
std::string lipsum::GenerateDefaultLipsumSentence();
std::string lipsum::GeneerateSentences(int, int, int, bool);

const char* lpsm_GenerateDefaultLipsumSentence();
const char* lpsm_GenerateSentences();
```

- Changed functions:

```cpp
std::string lipsum::GenerateParagraphs(int, int, int, int, int, bool); 
// from std::string lipsum::GenerateParagraphList(int, int, int, int, int)
std::string lipsum::GenerateParagraph(int, int, int, int, bool);
// from std::string lipsum::GenerateParagraph(int, int, int, int)

const char* lpsm_GenerateParagraphs(int, int, int, int, int, bool);
// from const char* lpsm_GenerateParagraphList(int, int, int, int, int);
const char* lpsm_GenerateParagraph(int, int, int, int, bool);
// from const char* lpsm_GenerateParagraph(int, int, int, int);

```

- New examples:

```
GenerateDefaultLipsumSentence.cpp
GenerateSentences.cpp
```

- Changed examples:

```
GenerateParagraphs.cpp
// from GenerateParagraphList.cpp
```

### 0.0.6 (2025-09-07)

- New functions:

```cpp
std::string lipsum::internal::HandleHTMLEntity(const std::string&);
std::string lipsum::HTMLify(const std::string&);

const char* lpsm_HTMLify(const char*);
```

- New examples:

```
HTMLify.cpp
```

### 0.0.7 (2025-09-17)

- New parameter `ratio` to some functions
- Add Doxygen comments to C wrapper
- Changed functions:

```cpp
std::string lipsum::GenerateSentence(int, int, float);
// from std::string lipsum::GenerateSentence(int, int)
std::string lipsum::GenerateParagraph(int, int, int, int, bool, float);
// from std::string lipsum::GenerateParagraph(int, int, int, int, bool)
std::string lipsum::GenerateParagraphs(int, int, int, int, int, bool, float);
// from std::string lipsum::GenerateParagraphs(int, int, int, int, bool)
std::string lipsum::GenerateSentences(int, int, int, bool, float);
// from std::string lipsum::GenerateSentences(int, int, int, bool)

const char* lpsm_GenerateSentence(int, int, float);
// from const char* lpsm_GenerateSentence(int, int)
const char* lpsm_GenerateParagraph(int, int, int, int, bool, float);
// from const char* lpsm_GenerateParagraph(int, int, int, int, bool)
const char* lpsm_GenerateParagraphs(int, int, int, int, int, bool, float);
// from const char* lpsm_GenerateParagraphs(int, int, int, int, int, bool)
const char* lpsm_GenerateSentences(int, int, int, bool, float);
// from const char* lpsm_GenerateSentences(int, int, int, bool);
```

### 0.0.8 (2025-09-21)

- Fix major bug in C wrapper, i.e. C wrapper is no longer broken, must manually delete strings
- Add example [`CWrapper.c`](./examples/CWrapper.c)
- Add CMake option `LPSM_BUILD_SAMPLE` for regenerating [`lipsum.inl`](./src/lipsum/core/sample.inl)
- New functions:

```c
void lpsm_DeleteString(char*);
```

- Changed functions:

```c
char* lpsm_GenerateWord(void);
// from const char* lpsm_GenerateWord(void)
char* lpsm_GenerateSentence(int, int, float);
// from const char* lpsm_GenerateSentence(int, int, float)
char* lpsm_GenerateParagraph(int, int, int, int, bool, float);
// from const char* lpsm_GenerateParagraph(int, int, int, int, bool, float)
char* lpsm_GenerateParagraphs(int, int, int, int, int, bool, float);
// from const char* lpsm_GenerateParagraphs(int, int, int, int, int, bool, float)
char* lpsm_GenerateDefaultLipsumSentence(void);
// from const char* lpsm_GenerateDefaultLipsumSentence(void)
char* lpsm_GenerateSentences(int, int, int, bool, float);
// from const char* lpsm_GenerateSentences(int, int, int, bool, float)
char* lpsm_HTMLify(char*);
// from const char* lpsm_HTMLify(const char*)
```

- New examples:

```
CWrapper.c
```

## 0.1.x

### 0.1.0 (2025-11-10)

- Semicolons and dashes can now appear in sentences
- Switch to (broken) CMake generator expressions
- Argument `ratio` removed
- Overhaul Doxygen comments (i.e. more documentation of namespaces, examples, etc.)
- Rework functions to use `lpsm::ArgVec2`
- New features:

```cpp
namespace lpsm = lipsum;
struct lpsm::ArgVec2;

lpsm::ArgVec2::ArgVec2(int, int);
int lpsm::ArgVec2::Roll() const;
std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&);

char* lpsm_GenerateSentenceFragment(int, int);
```

- Changed functions:

```cpp
std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&);
// from std::string lpsm::GenerateSentence(int, int, float)
std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateParagraph(int, int, int, int, bool, float)
std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateParagraphs(int, int, int, int, int, bool, float)
std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateSentences(int, int, int, bool, float)

char* lpsm_GenerateSentence(int, int, int, int);
// from char* lpsm_GenerateSentence(int, int, float)
char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool);
// from char* lpsm_GenerateParagraph(int, int, int, int, bool, float)
char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool);
// from char* lpsm_GenerateParagraphs(int, int, int, int, int, bool, float)
char* lpsm_GenerateSentences(int, int, int, int, int, bool);
// from char* lpsm_GenerateSentences(int, int, int, bool, float);

```

- New examples:

```
GenerateSentenceFragment.cpp
```

### 0.1.1 (2025-11-11)

- Add `X` functions not taking `ArgVec2`
- New functions:

```cpp
std::string lpsm::GenerateSentenceFragmentX(int, int);
std::string lpsm::GenerateSentenceX(int, int, int, int);
std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool);
std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool);
std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool);
std::string lpsm::HTMLify(const char*);
```

- Changed functions:
```c
char* lpsm_HTMLify(const char*);
// from char* lpsm_HTMLify(char*)
```

- New examples:

```
FuncsX.cpp
```

### 0.1.2 (2025-11-15)

- Add shared library build support enabled via CMake option `LPSM_BUILD_SHARED`
- Add MinGW toolchain for Linux cross-compilation to Windows

## 0.2.x

### 0.2.0 (2025-11-29)

- Add (broken) seed support
- Rework code to use `internal::RandomNumber()`
- Bug fixes
    - Fix bug in `GenerateSentence()` where new random numbers would be generated when adding punctuation
    - Fix bug where `GenerateSentence()` ignored user preferences in sentence fragments
- New features:

```cpp
class lpsm::Generator;
lpsm::Generator::Generator(int);
std::string lpsm::Generator::word();
std::string lpsm::Generator::sentence_fragment();
std::string lpsm::Generator::sentence(int, bool);
std::string lpsm::Generator::paragraph(int, bool);
int lpsm::internal::RandomNumber(int, int, int);
```

- Changed functions:

```cpp
int lpsm::ArgVec2::Roll(int) const;
// from int lpsm::ArgVec2::Roll() const
std::string lpsm::GenerateWord(int);
// from std::string lpsm::GenerateWord()
std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&. int);
// from std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&)
std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&, int);
// from std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&)
std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const ArgVec2&, bool, int);
// from std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, int);
// from std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, int);
// from std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)

std::string lpsm::GenerateSentenceFragmentX(int, int, int);
// from std::string lpsm::GenerateSentenceFragmentX(int, int)
std::string lpsm::GenerateSentenceX(int, int, int, int, int);
// from std::string lpsm::GenerateSentenceX(int, int, int, int)
std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool, int); 
// from std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool)
std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool, int);
// from std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool)
std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool, int);
// from std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool)

char* lpsm_GenerateWord(int);
// from char* lpsm_GenerateWord(void)
char* lpsm_GenerateSentenceFragment(int, int, int);
// from char* lpsm_GenerateSentenceFragment(int, int)
char* lpsm_GenerateSentence(int, int, int, int, int);
// from char* lpsm_GenerateSentence(int, int, int, int)
char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool, int); 
// from char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool);
char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool, int);
// from char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool)
char* lpsm_GenerateSentences(int, int, int, int, int, bool, int);
// from char* lpsm_GenerateSentences(int, int, int, int, int, bool)
```

- New examples:

```
Basic.cpp
```

### 0.2.1 (2025-12-03)

- `seed` argument removed 
- [examples/ CMake](./examples/CMakeLists.txt) made less repetitive, lipsum-cpp version in CMake
- Style changed to always prefer `lpsm` alias
- New features:

```cpp
#define LIPSUM_CPP_VERSION
std::string lpsm::GenerateWords(int);

#define LIPSUM_CPP_VERSION_C
```

- Changed functions:

```cpp
// all changed functions of 0.2.0 reverted
std::string lpsm::Generator::words(int);
// from std::string lpsm::Generator::word()
```

- Removed functions:

```cpp
// use default constructor
lpsm::Generator::Generator(int);
```

- New examples:

```
GenerateWords.cpp
```

### 0.2.2 (2025-12-04)

- `clang-format` support
- Remove mentions of seeds in Doxygen comments
- New functions:

```c
char* lpsm_GenerateWords(int);
```

### 0.2.3 (2025-12-14)

- New functions:

```c
char* lpsm_gen_word(int);
char* lpsm_gen_sentence(int, bool);
char* lpsm_gen_sentence_fragment(void);
char* lpsm_gen_paragraph(int, bool);
```

- Changed functions:

```cpp
std::string lpsm::Generator::word(int);
// from std::string lpsm::Generator::words(int);
```

## 0.3.x

### 0.3.0 (2025-12-30)

- Add Markdown generation support
- Deprecate `lpsm::HTMLify()`
- New functions:

```cpp
template <typename T> std::string lpsm::internal::ToString(const T&);
std::string lpsm::Generator::md_paragraph(bool);
std::string lpsm::Generator::md_text(int);
std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&);
std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&);
std::string lpsm::GenerateMarkdownLink(const std::string&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&);
std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&);
std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                            const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool);
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
                                       const std::string&, int);
int lpsm::CountSentences(const std::string&);

char* lpsm_gen_md_paragraph(bool);
char* lpsm_gen_md_text(int);
int lpsm_CountSentences(const char*);
```

- New examples:

```
Markdown.cpp
```

- Removed examples:

```
HTMLify.cpp
```

### 0.3.1 (2025-12-31)

- Split [`lipsum.hpp`](./src/lipsum.hpp) into multiple files
- Add option to amalgamate into single-header library
- Split CMake options into [`options.cmake`](./cmake/options.cmake)
- New examples:

```
Advanced.cpp
```

### 0.3.2 (2026-01-01)

- Add [JS bindings](./src/jsbind/lipsum_binding_js.cpp) via Embind
- Add `@since` in Doxygen comments
- New features:

```cpp
std::string lpsm::GenerateText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                               bool);
std::string lpsm::GenerateTextX(int, int, int, int, int, int, int, int, bool);
std::string lpsm::LipsumVersion();
std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool);

#define lpsm_LipsumVersion()
char* lpsm_GenerateText(int, int, int, int, int, int, int, int, bool);
```

- Changed functions:

```cpp
std::string lpsm::Generator::md_paragraph(int, bool);
// from std::string lpsm::Generator::md_paragraph(bool);
```

### 0.3.3 (2026-01-12)

- Update copyrights to 2026
- Add [`TODO.md`](./TODO.md)
- New features:

```c
typedef void* lpsm_ArgVec2Handle;
lpsm_ArgVec2Handle lpsm_ArgVec2(int, int);
void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle);
void lpsm_ArgVec2Roll(lpsm_ArgVec2Handle);
void lpsm_ArgVec2GetMin(lpsm_ArgVec2Handle);
void lpsm_ArgVec2GetMax(lpsm_ArgVec2Handle);
```

### 0.3.4 (2026-01-23)

- `lpsm::GenerateMarkdownHeader()` now gives a warning when `level` > 6 or < 1
- New functions:

```cpp
std::string lpsm::GenerateMarkdownHeaderX(int, int, int);
std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int);
std::string lpsm::GenerateMarkdownLinkX(const std::string&, int, int, int, int, int, int);
std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int);

char* lpsm_GenerateMarkdownHeader(int, int, int);
char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int);
char* lpsm_GenerateMarkdownLink(const char*, int, int, int, int, int, int);
char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int);
```

- New examples:

```
GenerateMarkdownEmphasis.cpp
GenerateMarkdownHeader.cpp
GenerateText.cpp
Misc.cpp
```

- Removed examples:

```
FuncsX.cpp
```

### 0.3.5 (2026-01-24)

- New functions in C wrapper that take `lpsm_ArgVec2Handle` ending in `S`
- New functions:

```c
char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
char* lpsm_GenerateTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
char* lpsm_GenerateParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
char* lpsm_GenerateSentencesS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateMarkdownLinkS(const char*, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool);
char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                     lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool);
char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool);
char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 const char*, int, bool);
```

### 0.3.6 (2026-02-01)

- Markdown functions can now generate HTML
- Switch from `.gitignore`d `compile.sh` to a `Makefile` to run CMake
- Switch from broken generator-expressions back to `list(APPEND ...)` in CMake
- Move script `format.sh` (running `clang-format`) into CMake
- New functions:

```cpp
std::string lpsm::GenerateSlug(const lpsm::ArgVec2&, char);
std::string lpsm::GenerateSlugX(int, int, char);

char* lpsm_GenerateSlug(int, int, char);
char* lpsm_GenerateSlugS(lpsm_ArgVec2Handle, char, bool);
```

- Changed functions:

```cpp
std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&)
std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&)
std::string lpsm::GenerateMarkdownLink(const std::string&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateMarkdownLink(const std::string&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&)
std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&)
std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                            const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool, bool);
// from std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                                  const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool)
std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool, bool);
// from std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
//                                                   const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
//                                                   const std::string&, bool)
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       const std::string&, int, bool);
// from std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             const std::string&, int)

std::string lpsm::GenerateMarkdownHeaderX(int, int, int, bool);
// from std::string lpsm::GenerateMarkdownHeaderX(int, int, int)
std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int, bool);
// from std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int)
std::string lpsm::GenerateMarkdownLinkX(const std::string&, int, int, int, int, int, int, bool);
// from std::string lpsm::GenerateMarkdownLinkX(const std::string&, int, int, int, int, int, int)
std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int, bool);
// from std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int)


char* lpsm_GenerateMarkdownHeader(int, int, int, bool);
// from char* lpsm_GenerateMarkdownHeader(int, int, int)
char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int, bool);
// from char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int)
char* lpsm_GenerateMarkdownLink(const char*, int, int, int, int, int, int, bool);
// from char* lpsm_GenerateMarkdownLink(const char*, int, int, int, int, int, int)
char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int, bool);
// from char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int)

char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool, bool);
// from char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
// from char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateMarkdownLinkS(const char*, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
// from char* lpsm_GenerateMarkdownLinkS(const char*, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
// from char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                      lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool, bool);
// from char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
//                                            lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool)
char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                            lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool, bool);
// from char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                             lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool)
char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                 lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 const char*, int, bool, bool);
// from char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                       const char*, int, bool)
```

- Removed functions:

```cpp
std::string lpsm::HTMLify(const char*);
std::string lpsm::HTMLify(const std::string&);

char* lpsm_HTMLify(const char*);
```

- New examples:

```
GenerateMarkdownLink.cpp
GenerateMarkdownList.cpp
GenerateMarkdownParagraph.cpp
GenerateMarkdownParagraphs.cpp
GenerateMarkdownText.cpp
GenerateSlug.cpp
```

### 0.3.7 (2026-02-07)

- Add random URL generation
- New functions:

```cpp 
std::string lpsm::internal::GenerateTLD();
std::string lpsm::GenerateURL(const lpsm::ArgVec2&);
std::string lpsm::GenerateURLX(int, int);

char* lpsm_GenerateURL(int, int);
char* lpsm_GenerateURLS(lpsm_ArgVec2Handle, bool);
```

- Changed functions:

```cpp
std::string lpsm::GenerateMarkdownLink(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool);
// from std::string lpsm::GenerateMarkdownLink(const std::string&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                            const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool);
// from std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                                  const lpsm::ArgVec2&, const lpsm::ArgVec2&, const std::string&, bool, bool)
std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool);
// from std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
//                                                   const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
//                                                   const std::string&, bool, bool)
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       int, bool);
// from std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             const std::string&, int, bool)

std::string lpsm::GenerateMarkdownLinkX(int, int, int, int, int, int, bool);
// from std::string lpsm::GenerateMarkdownLinkX(const std::string&, int, int, int, int, int, int, bool)

char* lpsm_GenerateMarkdownLink(int, int, int, int, int, int, bool);
// from char* lpsm_GenerateMarkdownLink(const char*, int, int, int, int, int, int, bool)

char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool);
// from char* lpsm_GenerateMarkdownLinkS(const char*, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                      lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, bool);
// from char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                            lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool, bool)
char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                            lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, bool);
// from char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                             lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, const char*, bool, bool, bool)
char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                 lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 int, bool, bool);
// from char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
//                                       const char*, int, bool, bool)
```

- New examples:

```
GenerateURL.cpp
```

### 0.3.8 (2026-02-20)

- Remove mention of `lpsm::HTMLify()` in Doxygen comments
- New functions:

```cpp
int lpsm::CountWords(const std::string&);

int lpsm_CountWords(const char*);
```

### 0.3.9 (2026-03-14)

- Switch non-standard GCC-specific extension of including a file within a function (used in `lpsm::GenerateWord`) to
  standard C++ global inclusion
- Switch some internal `lpsm::ArgVec2`s to `lpsm::internal::RandomNumber`
- Switch [`sample.inl`](./src/lipsum/core/sample.inl) to 
  `static constexpr std::array<const char*, N>`, from `std::vector<std::string>`
- `lpsm::GenerateURL()` now adds `lpsmcpp-` prefix to URLs to avoid generating real URLs
- New functions:

```cpp
std::string lpsm::GeneratePlainURL();
std::string lpsm::GenerateScramble(int, char, char);

char* lpsm_GeneratePlainURL(void);
char* lpsm_GenerateScramble(int, char, char);
```

- Changed functions:

```cpp
template <typename T> T lpsm::internal::RandomNumber(T, T);
template <> char lpsm::internal::RandomNumber(char, char);
template <> bool lpsm::internal::RandomNumber(bool, bool);
// from int lpsm::internal::RandomNumber(int, int)
```

## 0.4.x

### 0.4.0 (2026-03-21)

- Make `lpsm::internal::RandomNumber()` more thread-safe
- Change style of `.inl`s to have `namespace lipsum` around entire implementation
- Add multi-source lorem-ipsum generation support, with functions now having an extra `lpsm::Source` argument
- New features:

```cpp
class lpsm::Source;
lpsm::Source::Source();
lpsm::Source::Source(const std::string&);
std::string lpsm::Source::RandomWord() const;
inline constexpr int LIPSUM_CPP_VERSION_MAJOR;
inline constexpr int LIPSUM_CPP_VERSION_MINOR;
inline constexpr int LIPSUM_CPP_VERSION_PATCH;

#define LIPSUM_CPP_VERSION_MAJOR_C
#define LIPSUM_CPP_VERSION_MINOR_C
#define LIPSUM_CPP_VERSION_PATCH_C
typedef void* lpsm_SourceHandle;
lpsm_SourceHandle lpsm_Source(const char*);
void lpsm_SourceDestroy(lpsm_SourceHandle);
```

- Changed features:

```cpp
inline constexpr const char* LIPSUM_CPP_VERSION;
// from #define LIPSUM_CPP_VERSION
std::string lpsm::GenerateWord(const lpsm::Source&);
// from std::string lpsm::GenerateWord()
std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&, const lpsm::Source&);
// from std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&)
std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::Source&);
// from std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&)
std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                               bool, const lpsm::Source&);
// from std::string lpsm::GenerateText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                     bool)
std::string lpsm::GenerateWords(int, const lpsm::Source&);
// from std::string lpsm::GenerateWords(int)
std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GeneratePlainURL(const lpsm::Source&);
// from std::string lpsm::GeneratePlainURL()
std::string lpsm::GenerateURL(const lpsm::ArgVec2&, const lpsm::Source&);
// from std::string lpsm::GenerateURL(const lpsm::ArgVec2&)
std::string lpsm::GenerateSlug(const lpsm::ArgVec2&, char, const lpsm::Source&);
// from std::string lpsm::GenerateSlug(const lpsm::ArgVec2&, char)
std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateMarkdownLink(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownLink(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool)
std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                            const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
//                                                  const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool)
std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, 
                                             bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                                   const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool)
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
                                       const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
//                                             int, bool)

std::string lpsm::GenerateSentenceFragmentX(int, int, const lpsm::Source&);
// from std::string lpsm::GenerateSentenceFragmentX(int, int)
std::string lpsm::GenerateSentenceX(int, int, int, int, const lpsm::Source&);
// from std::string lpsm::GenerateSentenceX(int, int, int, int)
std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool)
std::string lpsm::GenerateTextX(int, int, int, int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateTextX(int, int, int, int, int, int, int, int, bool)
std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool)
std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool)
std::string lpsm::GenerateURLX(int, int, const lpsm::Source&);
// from std::string lpsm::GenerateURLX(int, int)
std::string lpsm::GenerateSlugX(int, int, char, const lpsm::Source&);
// from std::string lpsm::GenerateSlugX(int, int, char)
std::string lpsm::GenerateMarkdownHeaderX(int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownHeaderX(int, int, int, bool)
std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int, bool)
std::string lpsm::GenerateMarkdownLinkX(int, int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownLinkX(int, int, int, int, int, int, bool)
std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int, bool, const lpsm::Source&);
// from std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int, bool)

char* lpsm_GenerateWord(lpsm_SourceHandle);
// from char* lpsm_GenerateWord()
char* lpsm_GenerateSentenceFragment(int, int, lpsm_SourceHandle);
// from char* lpsm_GenerateSentenceFragment(int, int)
char* lpsm_GenerateSentence(int, int, int, int, lpsm_SourceHandle);
// from char* lpsm_GenerateSentence(int, int, int, int)
char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool)
char* lpsm_GenerateText(int, int, int, int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateText(int, int, int, int, int, int, int, int, bool)
char* lpsm_GenerateWords(int, lpsm_SourceHandle);
// from char* lpsm_GenerateWords(int)
char* lpsm_GenerateSentences(int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateSentences(int, int, int, int, int, bool)
char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool)
char* lpsm_GeneratePlainURL(lpsm_SourceHandle);
// from char* lpsm_GeneratePlainURL(void)
char* lpsm_GenerateURL(int, int, lpsm_SourceHandle);
// from char* lpsm_GenerateURL(int, int)
char* lpsm_GenerateSlug(int, int, char, lpsm_SourceHandle);
// from char* lpsm_GenerateSlug(int, int, char)
char* lpsm_GenerateMarkdownHeader(int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateMarkdownHeader(int, int, int, bool)
char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int, bool)
char* lpsm_GenerateMarkdownLink(int, int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateMarkdownLink(int, int, int, int, int, int, bool)
char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int, bool, lpsm_SourceHandle);
// from char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int, bool)

char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool)
char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateSentencesS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateSentencesS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool)
char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                      lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
//                                            lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, bool)
char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
//                                             lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, bool)
char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                 lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 int, bool, lpsm_SourceHandle, bool);
// from char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
//                                       int, bool, bool)
```

- Removed features:

```
std::string lpsm::LipsumVersion();

#define lpsm_LipsumVersion()
```

### 0.4.1 (2026-03-22)

- Change folder structure (i.e. move some files to `src/lipsum/core/`)
- Split C wrapper into multiple files
- Add multi-source lorem-ipsum generation support in `lpsm::Generator`
- New functions:

```cpp
lpsm::Generator::Generator() = default; // now explicitly declared
lpsm::Generator::Generator(const std::string&);
void lpsm::Source::Load(const std::string&);
```

### 0.4.2 (2026-04-12)

- Automatic version numbering via CMake
- More consistent naming scheme (see [`src/README.md`](./src/README.md) for details)
- Add [`CONTRIBUTING.md`](./CONTRIBUTING.md)
- `clang-tidy` support and modernize code to follow it
- Switch manual macros in `lipsum_h.cpp` to variadic templates
- Use both `#pragma once` and standard C-style include-guards
- Make code more structured
- Formalize some language (i.e. remove profanities)
- New features:

```cpp
template <typenname... Args> void lpsm::internal::LogWarn(const Args&...);
inline constexpr const char* LIPSUM_CPP_VERSION_COMMIT;
inline constexpr const char* LIPSUM_CPP_VERSION_FULL;

#define LIPSUM_CPP_VERSION_COMMIT_C
#define LIPSUM_CPP_VERSION_FULL_C
```

- Changed functions:

```cpp
int lpsm::ArgVec2::roll() const;
// from int lpsm::ArgVec2::Roll() const
void lpsm::Source::load(const std::string&);
// from void lpsm::Source::Load(const std::string&)
std::string lpsm::Source::random_word() const;
// from std::string lpsm::Source::RandomWord() const

int lpsm_ArgVec2_roll(lpsm_ArgVec2Handle);
// from int lpsm_ArgVec2Roll(lpsm_ArgVec2Handle)
int lpsm_ArgVec2_min(lpsm_ArgVec2Handle);
// from int lpsm_ArgVec2GetMin(lpsm_ArgVec2Handle)
int lpsm_ArgVec2_max(lpsm_ArgVec2Handle);
// from int lpsm_ArgVec2GetMax(lpsm_ArgVec2Handle)
```

### 0.4.3 (2026-04-17)

- Add `make help` support
- Add `make install` support and CPack packaging
- Make `lpsm::internal::GenerateTLD()` less repetitive
- More built-in lorem-ipsum sources
    - `cat` - cat ipsum
    - `dog`/`doggo` - dog ipsum
    - `corpo`/`corporate` - corporate ipsum
    - `default`/`lorem` - traditional lorem-ipsum
- CI/CD with GitHub Actions
- Fix compilation on MSVC
- New functions:

```cpp
int lpsm::internal::WeightedRandomIdx(const std::vector<int>&);
```

### 0.4.4 (2026-04-26)

- Add JSON and XML generation support
- Expose `lpsm::Generator` via opaque pointers
- Add customizable settings in `lpsm::Generator`
- Add more documentation of `lpsm::internal` functions
- New features:

```cpp
std::string lpsm::GenerateXMLDocument(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONString(const lpsm::Source&);
std::string lpsm::GenerateJSONNumber();
std::string lpsm::GenerateJSONObject(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONArray(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONValue(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateXMLDocumentX(int, int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONObjectX(int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONArrayX(int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONValueX(int, int, int, int, const lpsm::Source&);
void lpsm::Generator::change_setting(const std::string&, const lpsm::ArgVec2&);
void lpsm::Generator::change_setting(const std::string&, int, int);
std::string lpsm::Generator::text(bool);
std::string lpsm::Generator::html_paragraph(int, bool);
std::string lpsm::Generator::html_text(int);
std::string lpsm::Generator::xml(int);
std::string lpsm::Generator::json(int, bool);

char* lpsm_GenerateXMLDocument(int, int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONString(lpsm_SourceHandle);
char* lpsm_GenerateJSONNumber(void);
char* lpsm_GenerateJSONObject(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONArray(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONValue(int, int, int, int, lpsm_SourceHandle);

char* lpsm_GenerateXMLDocumentS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONObjectS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONArrayS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONValueS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);

typedef void* lpsm_GeneratorHandle;
lpsm_GeneratorHandle lpsm_Generator(const char*);
void lpsm_GeneratorDestroy(lpsm_GeneratorHandle);
char* lpsm_Generator_word(lpsm_GeneratorHandle, int);
char* lpsm_Generator_sentence_fragment(lpsm_GeneratorHandle);
char* lpsm_Generator_sentence(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_paragraph(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_text(lpsm_GeneratorHandle, bool);
char* lpsm_Generator_md_paragraph(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_md_text(lpsm_GeneratorHandle, int);
char* lpsm_Generator_html_paragraph(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_html_text(lpsm_GeneratorHandle, int);
char* lpsm_Generator_xml(lpsm_GeneratorHandle, int);
char* lpsm_Generator_json(lpsm_GeneratorHandle, int, bool);
```

- Removed features:

```c
char* lpsm_gen_word(int);
char* lpsm_gen_sentence_fragment(void);
char* lpsm_gen_sentence(int, bool);
char* lpsm_gen_paragraph(int, bool);
char* lpsm_gen_md_paragraph(int, bool);
char* lpsm_gen_md_text(int);
```

- New examples:

```
Generator.cpp
GeneratorFormats.cpp
```

- Removed examples:

```
Basic.cpp
GenerateDefaultLipsumSentence.cpp
GenerateURL.cpp
GenerateMarkdownEmphasis.cpp
GenerateMarkdownHeader.cpp
GenerateMarkdownList.cpp
GenerateMarkdownLink.cpp
GenerateMarkdownParagraph.cpp
GenerateMarkdownParagraphs.cpp
GenerateMarkdownText.cpp
```

### 0.4.5 (2026-05-03)

- Split settings in `lpsm::Generator` to new struct
- New CLI tool `lpsmcpp-cli`
- CPack packaging now includes `README.md`s and `LICENSE.md`, `WIX` and `RPM` package generation
- New features:

```cpp
struct lpsm::GeneratorSettings;
void lpsm::GeneratorSettings::change_setting(const std::string&, const lpsm::ArgVec2&);
std::string lpsm::Generator::scramble(int, char, char);
std::string lpsm::Generator::slug(char);
std::string lpsm::Generator::url();
std::string lpsm::Generator::plain_url();
void lpsm::Generator::load_source(const std::string&);

void lpsm_Generator_change_setting(lpsm_GeneratorHandle, const char*, int, int);
char* lpsm_Generator_scramble(lpsm_GeneratorHandle, int, char, char);
char* lpsm_Generator_slug(lpsm_GeneratorHandle, char);
char* lpsm_Generator_url(lpsm_GeneratorHandle);
char* lpsm_Generator_plain_url(lpsm_GeneratorHandle);
void lpsm_Generator_load_source(lpsm_GeneratorHandle, const char*);
```

### 0.4.6 (2026-05-28)

- Add more descriptive error handling in CLI tool
- Add better help command in CLI tool
- Add CMake `find_package()` support
- Add unit tests and benchmarking
- Add Arch Linux package support
- Ensure no possibility of duplicate keys in JSON
- Make `lpsm::CountWords()` "smarter"
- Switch some functions in `lpsm::internal` to C++20 concepts
- Add XML attributes in generated XML
- Allow 1 or 0 elements in `lpsm::GenerateMarkdownText()`, and warn on negative elements
- Fix bugs:
    - `std::bad_alloc` from `lpsm::GenerateSentenceFragment()` when the number of words is <= 0
    - Segmentation fault in `lpsm::internal::RandomNumber()` when min > max
- Add Doxygen docs to packages
- Add this `CHANGELOG.md`
- New features:

```cpp
inline constexpr const char* LIPSUM_CPP_VERSION_TIME;
inline constexpr bool LIPSUM_CPP_VERSION_ISDEV;
inline constexpr const char* LIPSUM_CPP_VERSION_DATE;
template <typename T> concept lpsm::internal::ToStringable;
template <typename T> concept lpsm::internal::Streamable;
template <typename T> concept lpsm::internal::IsInt;
template <typename T> concept lpsm::internal::UniformDistributionType;
template <typename T> T lpsm::internal::ToType(const std::string&);
std::string lpsm::Generator::md_header(int, bool);
std::string lpsm::Generator::md_emphasis(bool, bool);
std::string lpsm::Generator::md_link(bool);
std::string lpsm::Generator::md_list(bool, bool);
int lpsm::CountSentenceFragments(const std::string&);
int lpsm::CountParagraphs(const std::string&, int);

#define LIPSUM_CPP_VERSION_TIME_C;
#define LIPSUM_CPP_VERSION_ISDEV_C;
#define LIPSUM_CPP_VERSION_DATE_C;
char* lpsm_Generator_md_header(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_md_emphasis(lpsm_GeneratorHandle, bool, bool);
char* lpsm_Generator_md_link(lpsm_GeneratorHandle, bool);
char* lpsm_Generator_md_list(lpsm_GeneratorHandle, bool, bool);
int lpsm_CountSentenceFragments(const char*);
int lpsm_CountParagraphs(const char*, int);
```

- Changed functions:

```cpp
template <UniformDistributionType T> std::string lpsm::internal::RandomNumber(T, T);
// from template <typename T> std::string lpsm::internal::RandomNumber(T, T)
char lpsm::internal::RandomNumber(char, char);
// from template <> char lpsm::internal::RandomNumber(char, char)
bool lpsm::internal::RandomNumber(bool, bool);
// from template <> bool lpsm::internal::RandomNumber(bool, bool)
template <Streamable T> std::string lpsm::internal::ToString(const T&);
template <ToStringable T> std::string lpsm::internal::ToString(const T&);
// from template <typename T> std::string lpsm::internal::ToString(const T&);
std::string lpsm::Generator::fragment();
// from std::string lpsm::Generator::sentence_fragment()
std::string lpsm::Generator::md_paragraph(int, bool, bool);
// from std::string lpsm::Generator::md_paragraph(int, bool);
std::string lpsm::Generator::md_text(int, bool);
// from std::string lpsm::Generator::md_text(int);

char* lpsm_Generator_fragment(lpsm_GeneratorHandle);
// from char* lpsm_Generator_sentence_fragment(lpsm_GeneratorHandle)
char* lpsm_Generator_md_paragraph(lpsm_GeneratorHandle, int, bool, bool);
// from char* lpsm_Generator_md_paragraph(lpsm_GeneratorHandle, int, bool)
char* lpsm_Generator_md_text(lpsm_GeneratorHandle, int, bool);
// from char* lpsm_Generator_md_text(lpsm_GeneratorHandle, int)
```

- Removed functions:

```cpp
std::string lpsm::Generator::html_paragraph(int, bool);
std::string lpsm::Generator::html_text(int);

char* lpsm_Generator_html_paragraph(lpsm_GeneratorHandle, int, bool);
char* lpsm_Generator_html_text(lpsm_GeneratorHandle, int);
```

## 0.5.x

### 0.5.0 (2026-06 TBD)

- Move most free function logic into `lpsm::Generator`
- Add seed options to `lpsm::Generator`
- Get benchmarks on a low-end computer
- New features:

```cpp
enum lpsm::GeneratorFlags;
enum class lpsm::CountParaMethod;
lpsm::Generator::Generator(int);
lpsm::Generator::Generator(const std::string&, int);
std::string lpsm::Generator::single_sentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&); // private
std::string lpsm::Generator::single_paragraph(bool); // private
std::string lpsm::Generator::single_md_paragraph(bool, bool); // private
std::string lpsm::Generator::json_string(); // private
std::string lpsm::Generator::json_number(); // private
template <lpsm::internal::UniformDistributionType> T lpsm::Generator::random_number(T, T); // private
char lpsm::Generator::random_number(char, char); // private
bool lpsm::Generator::random_number(bool, bool); // private
int lpsm::Generator::weighted_random_idx(const std::vector<int>&); // private
std::string lpsm::Generator::tld(); // private
void lpsm::Generator::load_seed(int);
std::string lpsm::Generator::json_value(int, int);

#define LPSM_USELIPSUM
#define LPSM_NO_USELIPSUM
#define LPSM_HTML
#define LPSM_MARKDOWN
#define LPSM_OBJECT
#define LPSM_ARRAY
#define LPSM_BOLD
#define LPSM_ITALIC
#define LPSM_ORDERED
#define LPSM_UNORDERED
typedef enum lpsm_CountParaMethod lpsm_CountParaMethod;
lpsm_GeneratorHandle lpsm_GeneratorSeeded(const char*, int);
char* lpsm_Generator_json_value(lpsm_GeneratorHandle, int, int);
void lpsm_Generator_load_seed(lpsm_GeneratorHandle, int);
```

- Changed functions:

```cpp
std::string lpsm::ArgVec2::roll(std::mt19937&) const;
// from std::string lpsm::ArgVec2::roll() const;
std::string lpsm::Source::random_word(std::mt19937&) const;
// from std::string lpsm::Source::random_word() const;
std::string lpsm::Generator::json(int, int, bool);
// from std::string lpsm::Generator::json(int, bool)
std::string lpsm::CountParagraphs(const std::string&, lpsm::CountParaMethod);
// from std::string lpsm::CountParagraphs(const std::string&, int)

char* lpsm_Generator_json(lpsm_GeneratorHandle, int, int, bool);
// from std::string lpsm_Generator_json(lpsm_GeneratorHandle, int, bool)
char* lpsm_CountParagraphs(const char*, lpsm_CountParaMethod);
// from char* lpsm_CountParagraphs(const char*, int)
```

- Removed features:
```cpp
template <lpsm::internal::UniformDistributionType> T lpsm::internal::RandomNumber(T, T);
char lpsm::internal::RandomNumber(char, char);
bool lpsm::internal::RandomNumber(bool, bool);
int lpsm::internal::WeightedRandomIdx(const std::vector<int>&);
std::string lpsm::internal::GenerateTLD();
std::string lpsm::GenerateWord(const lpsm::Source&);
std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateSentence(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                               bool, const lpsm::Source&);
std::string lpsm::GenerateWords(int, const lpsm::Source&);
std::string lpsm::GenerateSentences(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GeneratePlainURL(const lpsm::Source&);
std::string lpsm::GenerateURL(const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateSlug(const lpsm::ArgVec2&, char, const lpsm::Source&);
std::string lpsm::GenerateScramble(int, char, char);
std::string lpsm::GenerateMarkdownHeader(int, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownEmphasis(bool, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownLink(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownList(bool, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                            const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownParagraphs(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                             const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, bool, 
                                             bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, 
                                       const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::ArgVec2&,
                                       int, bool, const lpsm::Source&);
std::string lpsm::GenerateXMLDocument(int, const lpsm::ArgVec2&, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONString(const lpsm::Source&);
std::string lpsm::GenerateJSONNumber();
std::string lpsm::GenerateJSONObject(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONArray(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateJSONValue(int, int, const lpsm::ArgVec2&, const lpsm::Source&);
std::string lpsm::GenerateSentenceFragmentX(int, int, const lpsm::Source&);
std::string lpsm::GenerateSentenceX(int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateTextX(int, int, int, int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateURLX(int, int, const lpsm::Source&);
std::string lpsm::GenerateSlugX(int, int, char, const lpsm::Source&);
std::string lpsm::GenerateMarkdownHeaderX(int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownEmphasisX(bool, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownLinkX(int, int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateMarkdownListX(bool, int, int, int, int, int, int, bool, const lpsm::Source&);
std::string lpsm::GenerateXMLDocumentX(int, int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONObjectX(int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONArrayX(int, int, int, int, const lpsm::Source&);
std::string lpsm::GenerateJSONValueX(int, int, int, int, const lpsm::Source&);

char* lpsm_GenerateWord(lpsm_SourceHandle);
char* lpsm_GenerateSentenceFragment(int, int, lpsm_SourceHandle);
char* lpsm_GenerateSentence(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateParagraph(int, int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateText(int, int, int, int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateWords(int, lpsm_SourceHandle);
char* lpsm_GenerateSentences(int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateParagraphs(int, int, int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GeneratePlainURL(lpsm_SourceHandle);
char* lpsm_GenerateURL(int, int, lpsm_SourceHandle);
char* lpsm_GenerateSlug(int, int, char, lpsm_SourceHandle);
char* lpsm_GenerateMarkdownHeader(int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateMarkdownEmphasis(bool, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateMarkdownLink(int, int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateMarkdownList(bool, int, int, int, int, int, int, bool, lpsm_SourceHandle);
char* lpsm_GenerateXMLDocument(int, int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONString(lpsm_SourceHandle);
char* lpsm_GenerateJSONNumber(void);
char* lpsm_GenerateJSONObject(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONArray(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateJSONValue(int, int, int, int, lpsm_SourceHandle);
char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateSentencesS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownHeaderS(int, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownEmphasisS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownListS(bool, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                      lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownParagraphsS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                       lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, bool, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, 
                                 lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle,
                                 int, bool, lpsm_SourceHandle, bool);
char* lpsm_GenerateXMLDocumentS(int, lpsm_ArgVec2Handle, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONObjectS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONArrayS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
char* lpsm_GenerateJSONValueS(int, int, lpsm_ArgVec2Handle, lpsm_SourceHandle, bool);
int lpsm_ArgVec2_roll(lpsm_ArgVec2Handle);
int lpsm_ArgVec2_min(lpsm_ArgVec2Handle);
int lpsm_ArgVec2_max(lpsm_ArgVec2Handle);
typedef void* lpsm_SourceHandle;
lpsm_SourceHandle lpsm_Source(const char*);
void lpsm_SourceDestroy(lpsm_SourceHandle);
```

- New examples:

```
ParserStressTest.cpp
FontViewer.html
WebInterface.html
```

- Removed examples:

```
GenerateWord.cpp
GenerateWords.cpp
GenerateSentenceFragment.cpp
GenerateSentence.cpp
GenerateSentences.cpp
GenerateParagraph.cpp
GenerateParagraphs.cpp
GenerateText.cpp
Formats.cpp
```

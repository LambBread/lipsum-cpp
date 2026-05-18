# lipsum-cpp Changelog

For a more brief overview, see [`TODO.md`](./TODO.md).

*This changelog is still work-in-progress.*

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
GenerateParagraphList.cpp -> GenerateParagraphs.cpp
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

- Changed functions

```cpp
// all changed functions of 0.2.0 reverted
std::string lpsm::Generator::words(int);
// from std::string lpsm::Generator::word()
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

### 0.4.1 (2026-03-22)

### 0.4.2 (2026-04-12)

### 0.4.3 (2026-04-17)

### 0.4.4 (2026-04-26)

### 0.4.5 (2026-05-03)

### 0.4.6 (2026-05/06 TBD)

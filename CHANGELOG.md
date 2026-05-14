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

### 0.3.1 (2025-12-31)

### 0.3.2 (2026-01-01)

### 0.3.3 (2026-01-12)

### 0.3.4 (2026-01-23)

### 0.3.5 (2026-01-24)

### 0.3.6 (2026-02-01)

### 0.3.7 (2026-02-07)

### 0.3.8 (2026-02-20)

### 0.3.9 (2026-03-14)

## 0.4.x

### 0.4.0 (2026-03-21)

### 0.4.1 (2026-03-22)

### 0.4.2 (2026-04-12)

### 0.4.3 (2026-04-17)

### 0.4.4 (2026-04-26)

### 0.4.5 (2026-05-03)

### 0.4.6 (2026-05 TBD)

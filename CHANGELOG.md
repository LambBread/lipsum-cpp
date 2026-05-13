# lipsum-cpp Changelog

For a more brief overview, see [`TODO.md`](./TODO.md).

## 0.0.x

### 0.0.1

- Start project
- New functions:

```cpp
std::string lipsum::GenerateSentence(int, int);
std::string lipsum::GenerateParagraph(int, int, int, int);
```

### 0.0.2

- Add (broken) C wrapper
- New functions:

```cpp
std::string lipsum::GenerateParagraphList(int, int, int, int, int);

const char* lpsm_GenerateSentence(int, int);
const char* lpsm_GenerateParagraph(int, int, int, int);
const char* lpsm_GenerateParagraphList(int, int, int, int, int);
```

### 0.0.3

- Add [`examples/`](./examples/) folder
- More `README.md`s (in [`scripts/`](./scripts/) and [`examples/`](./examples/))
- New functions:

```cpp
std::string lipsum::GenerateWord();

const char* lpsm_GenerateWord(void);
```

### 0.0.4

- Add option `LPSM_BUILD_ASHTML` for WebAssembly builds

### 0.0.5

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

### 0.0.6

- New functions:

```cpp
std::string lipsum::internal::HandleHTMLEntity(const std::string&);
std::string lipsum::HTMLify(const std::string&);

const char* lpsm_HTMLify(const char*);
```

### 0.0.7

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

### 0.0.8

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

## 0.1.x

### 0.1.0

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

### 0.1.1

- Add `X` functions not taking `ArgVec2`
- New functions:

```cpp
std::string lpsm::GenerateSentenceFragmentX(int, int);
std::string lpsm::GenerateSentenceX(int, int, int, int);
std::string lpsm::GenerateParagraphX(int, int, int, int, int, int, bool);
std::string lpsm::GenerateParagraphsX(int, int, int, int, int, int, int, bool);
std::string lpsm::GenerateSentencesX(int, int, int, int, int, bool);
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

### 0.1.2

- Add shared library build support enabled via CMake option `LPSM_BUILD_SHARED`
- Add MinGW toolchain for Linux cross-compilation to Windows

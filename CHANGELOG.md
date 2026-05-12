# lipsum-cpp Changelog

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
- Update README

### 0.0.5

- Doxygen support, enabled with `LPSM_BUILD_DOCS` with target `doc`
- Add `useLipsum` param to certain functions
- New functions:

```cpp
std::string lipsum::GenerateDefaultLipsumSentence();
std::string lipsum::GeneerateSentences();

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


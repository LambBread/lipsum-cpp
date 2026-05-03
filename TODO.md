# lipsum-cpp Todo

## Complete

### 0.0.x

- [x] Start project (0.0.1)
- [x] Static library builds (0.0.2)
- [x] Doxygen support (0.0.5)
- [x] Fix C wrapper major bug (0.0.8)

### 0.1.x

- [x] Replace min/max arguments with `lpsm::ArgVec2` (0.1.0)
- [x] `X` functions (0.1.1)
- [x] Shared library builds (0.1.2)

### 0.2.x

- [x] Add `lpsm::Generator` for easier generation (0.2.0)
- [x] `clang-format` (0.2.2)

### 0.3.x

- [x] Markdown generation (0.3.0)
- [x] Deprecate `lpsm::HTMLify()` (0.3.0)
- [x] Split `lipsum.hpp` into multiple files (0.3.1)
- [x] JS binding via Embind (0.3.2)
- [x] Expose `lpsm::ArgVec2` in C wrapper (0.3.3)
- [x] `X` variants of Markdown functions (0.3.4)
- [x] More Markdown functions in C wrapper (0.3.4)
- [x] More examples (0.3.4)
- [x] `S` variants in the C wrapper for functions using `lpsm::ArgVec2` (0.3.5)
- [x] Remove `lpsm::HTMLify()` (0.3.6)

### 0.4.x

- [x] Multi-source generation (0.4.0)
- [x] Automatic version numbering using CMake (0.4.2)
- [x] Switch manual macros in `lipsum_h.cpp` to variadic templates (0.4.2)
- [x] Better logging (0.4.2)
- [x] Git commit tag in `version.hpp` (0.4.2)
- [x] `clang-tidy` (0.4.2)
- [x] `make help` (0.4.3)
- [x] `make install`, CMake install rules (0.4.3)
- [x] CPack packaging (0.4.3)
- [x] Make `lpsm::internal::GenerateTLD()` less repetitive (0.4.3)
- [x] More built-in lorem-ipsum sources (0.4.3)
- [x] CI/CD with GitHub Actions (0.4.3)
- [x] XML generation (0.4.4)
- [x] More documentation for `lpsm::internal` functions (0.4.4)
- [x] JSON generation (0.4.4)
- [x] More `lpsm::Generator` functions (0.4.4)
- [x] Merge smaller examples (0.4.4)
- [x] Customizable settings in `lpsm::Generator` (0.4.4)
- [x] Expose `lpsm::Generator` traditionally in C wrapper (0.4.4)

## Upcoming

- [ ] Move some of the free functions' logic into `lpsm::Generator` (planned 0.5.0)
- [ ] Unit tests (planned 0.5.x)
- [ ] CLI tool (planned 0.4.5)
    - [x] Subcommands for all `lpsm::Generator` generation functions (0.4.5)
    - [x] Add install rules (0.4.5)
    - [x] Options for all `lpsm::Generator` settings (0.4.5)
    - [x] Help command, documentation (0.4.5)
    - [ ] Multi-source functionality


# lipsum-cpp source code

This is the main source directory of lipsum-cpp.

## Overview of folders

- This current folder: main headers and source files
- [lipsumc](./lipsumc/): some former portions of [`lipsum_h.cpp`](//lipsum_h.cpp) and [`lipsum.h`](./lipsum.h) split into separate files
- [lipsum](./lipsum/): main code of lipsum-cpp
    - [lipsum/core](./lipsum/core/): core parts of lipsum-cpp such as `lpsm::internal`, the version constants, and some classes
- [jsbind](./jsbind/): the JavaScript binding
- [cli](./cli/): the CLI tool
- [test](./test/): unit tests

## Naming convention

- Classes, structs, enums: `PascalCase`
- Free functions: `PascalCase`
- Class functions and CLI subcommands: `snake_case`
- Unit tests: `snake_case`
- Python: `snake_case`
- Macros, `constexpr` constants, enum values (excluding enum class): `SHOUTY_CASE`
- Enum class values: `PascalCase`
- CMake variables: `SHOUTY_CASE`
- Internal variables and function arguments: `camelCase`
- Lambdas: `camelCase`
- If a variable name conflicts with a keyword, prefer another name or append an underscore, e.g. `case_`

### C wrapper

- C++'s `::` is replaced with `_`
- Binded class constructors are the name of the class
- Enum class values are `LPSM_` with the abbreviated enum class name, and the value name, in `SHOUTY_CASE`.
    - e.g. `lpsm::CountParaMethod::Plain` -> `LPSM_CPM_PLAIN`
- Binded class handles are the name of the class with `Handle` appended at the end
- Binded class destructors are the name of the class with `Destroy` appended at the end

## Minimum, Quiet, & Verbose build modes

The changes between "minimum build" mode and normal mode is that the only functionality that is available is the
core plain text generation functions. Commas and periods are the only punctuation symbols available, many unneeded settings
are stripped, some C++20 `lpsm::internal` concepts are stripped, and `lpsm::internal::ToString()` and
`lpsm::internal::ToType()` only use basic `std::stringstream` conversion. Multi-source lorem-ipsum 
functionality is stripped and log messages do not contain colour. Quiet mode disables logging from `lpsm::internal::LogWarn()`.
Verbose mode enables verbose log messages from lipsum-cpp. If both verbose and quiet mode are enabled, treat as simply
quiet mode.

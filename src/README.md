# lipsum-cpp source code

This is the main source directory of lipsum-cpp.

## Overview of folders

- This current folder: main headers and source files
- [lipsumc](./lipsumc/): some former portions of [`lipsum_h.cpp`](//lipsum_h.cpp) and [`lipsum.h`](./lipsum.h) split into separate files
- [lipsum](./lipsum/): main code of lipsum-cpp
    - [lipsum/core](./lipsum/core/): core parts of lipsum-cpp such as `lpsm::internal`, the version constants, and some classes
- [jsbind](./jsbind/): the JavaScript binding

## Naming convention

- Classes: `PascalCase`
- Free functions: `PascalCase`
- Class functions: `snake_case`
- Macros and `constexpr` constants: `SHOUTY_CASE`
- Internal variables and function arguments: `camelCase`

### C wrapper

- C++'s `::` is replaced with `_`
- Binded class constructors are the name of the class
- Binded class handles are the name of the class with `Handle` appended at the end
- Binded class destructors are the name of the class with `Destroy` appended at the end

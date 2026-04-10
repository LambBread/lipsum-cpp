# lipsum-cpp C wrapper

The C wrapper provides a lower-level native C API over lipsum-cpp for integration into C projects.

The differences between the C++ and C API are that:

- Namespace `lpsm` is replaced with prefix `lpsm_`.
- Most usage of C++ `::` is replaced with `_`.
- Class `lpsm::Generator` is replaced with functions starting in `lpsm_gen`.
- Arguments explicitly provided to functions, such as `lpsm_GenerateParagraphs(5, 4, 9, 1, 3, 5, 8, true, source)` replacing `lpsm::GenerateParagraphs()`.
- Explicit creation of a `lpsm_SourceHandle`.

Internal functions such as `lpsm::internal::RandomNumber` are not available in the C wrapper, and the binded `lpsm::Generator` currently cannot use custom lorem-ipsum sources.

When using the C wrapper, remember to use `lpsm_DeleteString()`, `lpsm_ArgVec2Destroy()`, and `lpsm_SourceDestroy()` to avoid memory leaks!

# lipsum-cpp C wrapper

The C wrapper provides a lower-level C API over lipsum-cpp for integration into C projects.

The differences between the C++ and C API are that:

- Namespace `lpsm` is replaced with prefix `lpsm_`.
- Most usage of C++ `::` is replaced with `_`.
- Arguments explicitly provided to functions, such as `lpsm_Generator_paragraph(handle, 1, true)`
  replacing `lpsm::Generator::paragraph()`.
- Explicit creation of a `lpsm_SourceHandle` when using free functions.

Internal functions such as `lpsm::internal::HandleHTMLEntity()` are not available in the C wrapper, as well as some internal classes
like `lpsm::Source` and `lpsm::ArgVec2`.

When using the C wrapper, remember to use `lpsm_DeleteString()` and `lpsm_GeneratorDestroy()` to avoid memory leaks!

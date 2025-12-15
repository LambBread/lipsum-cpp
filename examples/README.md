# lipsum-cpp examples

For each example, C is similar but with:

- Namespace `lpsm` replaced with prefix `lpsm_`
- Class `lpsm::Generator` replaced with functions starting in `lpsm_gen`
- `lipsum.hpp` replaced with `lipsum.h`
- Arguments explicitly provided to functions, such as `lpsm_GenerateParagraphs(5, 4, 9, 1, 3, 5, 8, true, 0)` replacing `lpsm::GenerateParagraphs()`

When using the C wrapper, remember to use `lpsm_DeleteString()` to avoid memory leaks!

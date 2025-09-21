# lipsum-cpp examples

For each example, C is similar but with namespace `lipsum` replaced with prefix `lpsm_`, `lipsum.hpp` replaced with `lipsum.h`, and arguments explicitly provided to functions, such as `lpsm_GenerateParagraphs(5, 5, 8, 4, 12, true, 0.75f)` replacing `lipsum::GenerateParagraphs()`. When using the C wrapper, remember to use `lpsm_DeleteString()` to avoid memory leaks!

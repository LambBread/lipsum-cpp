#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate bold sentence of 1-2 sentence fragments of 4-8 words, in
    // Markdown (default)
    std::cout << lpsm::GenerateMarkdownEmphasis() << '\n';

    // generate italic sentence of 3-6 sentence fragments of 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownEmphasis(false,
                                                lpsm::ArgVec2(6, 9),
                                                lpsm::ArgVec2(3, 6),
                                                true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownEmphasisX(false, 6, 9, 3, 6, true)
              << '\n';
    return 0;
}

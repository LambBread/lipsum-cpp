#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate bold sentence of 1-2 sentence fragments of 4-8 words (default)
    std::cout << lpsm::GenerateMarkdownEmphasis();

    // generate italic sentence of 3-6 sentence fragments of 6-9 words
    std::cout << lpsm::GenerateMarkdownEmphasis(false,
                                                lpsm::ArgVec2(6, 9),
                                                lpsm::ArgVec2(3, 6));

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownEmphasisX(false, 6, 9, 3, 6);
    return 0;
}

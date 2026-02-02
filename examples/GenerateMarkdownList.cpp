#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate unordered list of 3-5 points of 1-2 sentence fragments of 4-8
    // words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownList();

    // generate ordered list of 5-12 points of 3-6 sentence fragments of 6-9
    // words, in HTML
    std::cout << lpsm::GenerateMarkdownList(true,
                                            lpsm::ArgVec2(6, 9),
                                            lpsm::ArgVec2(3, 6),
                                            lpsm::ArgVec2(5, 12),
                                            true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownListX(true, 6, 9, 3, 6, 5, 12, true)
              << '\n';
    return 0;
}

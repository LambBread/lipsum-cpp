#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate link with 1-2 sentence fragments of 4-8
    // words and URL ending in 2-5 words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownLink() << '\n';

    // generate link with 3-6 sentence fragments of 7-10
    // words and URL ending in 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownLink(lpsm::ArgVec2(7, 10),
                                            lpsm::ArgVec2(3, 6),
                                            lpsm::ArgVec2(6, 9),
                                            true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownLinkX(7, 10, 3, 6, 6, 9, true) << '\n';
    return 0;
}

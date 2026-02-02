#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate main title header with 2-5 words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownHeader();

    // generate subtitle header with 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownHeader(2, lpsm::ArgVec2(6, 9), true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownHeaderX(2, 6, 9, true) << '\n';
    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate main title header with 2-5 words (default)
    std::cout << lpsm::GenerateMarkdownHeader();

    // generate subtitle header with 6-9 words
    std::cout << lpsm::GenerateMarkdownHeader(2, lpsm::ArgVec2(6, 9));

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownHeaderX(2, 6, 9);
    return 0;
}

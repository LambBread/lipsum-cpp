#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate 5 paragraphs
    // of 5-8 sentences
    // of 1-3 sentence fragments
    // of 4-9 words,
    // starting with "Lorem ipsum..." (default)
    std::cout << lpsm::GenerateParagraphs();
    // generate 10 paragraphs
    // of 7-10 sentences
    // of 3-6 sentence fragments
    // of 6-9 words,
    // not starting with "Lorem ipsum..."
    std::cout << lpsm::GenerateParagraphs(10,
                                          lpsm::ArgVec2(6, 9),
                                          lpsm::ArgVec2(3, 6),
                                          lpsm::ArgVec2(7, 10),
                                          false);
    // equivalent statement
    std::cout << lpsm::GenerateParagraphsX(10, 6, 9, 3, 6, 7, 10, false);
    return 0;
}

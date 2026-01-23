#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate a text with 1-4 paragraphs
    // of 5-8 sentences
    // of 1-3 sentence fragments
    // of 4-9 words,
    // starting with "Lorem ipsum..." (default)
    std::cout << lpsm::GenerateText();

    // generate a text with 2-9 paragraphs
    // of 7-10 sentences
    // or 3-6 sentence fragments
    // of 6-9 words,
    // not starting with "Lorem ipsum..."
    std::cout << lpsm::GenerateText(lpsm::ArgVec2(6, 9),
                                    lpsm::ArgVec2(3, 6),
                                    lpsm::ArgVec2(7, 10),
                                    lpsm::ArgVec2(2, 9),
                                    false);

    // equivalent statement
    std::cout << lpsm::GenerateTextX(6, 9, 3, 6, 7, 10, 2, 9, false);
    return 0;
}

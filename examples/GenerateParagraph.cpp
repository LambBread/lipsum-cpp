#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate 5-8 sentences of 1-3 sentence fragments of 4-9 words, starting with "Lorem ipsum..." (default)
    std::cout << lpsm::GenerateParagraph();
    //generate 7-10 sentences of 3-6 sentence fragments of 6-9 words, not starting with "Lorem ipsum..."
    std::cout << lpsm::GenerateParagraph(lpsm::ArgVec2(6, 9), lpsm::ArgVec2(3, 6), lpsm::ArgVec2(7, 10), false);
    return 0;
}

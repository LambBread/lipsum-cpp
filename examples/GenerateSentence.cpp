#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for header-only usage
#endif
#include "lipsum.hpp"
#include <iostream>

int main()
{
    //generate a sentence with 1-3 sentence fragments
    //of 4-9 words (default)
    std::cout << lpsm::GenerateSentence() << '\n';
    //generate a sentence with 3-6 sentence fragments 
    //of 6-9 words
    std::cout << 
        lpsm::GenerateSentence(
            lpsm::ArgVec2(6, 9),
            lpsm::ArgVec2(3, 6)
    ) << '\n';
    return 0;
}

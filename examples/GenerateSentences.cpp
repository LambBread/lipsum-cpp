#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for header-only usage
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generates 6 sentences 
    //with 1-3 sentence fragments 
    //of 4-9 words,
    //starting with "Lorem ipsum..." and random seed (default)
    std::cout << lpsm::GenerateSentences() << '\n';
    //generates 4 sentences 
    //with 3-6 sentence fragments 
    //of 6-9 words, 
    //not starting with "Lorem ipsum..." and seed 69
    std::cout << lpsm::GenerateSentences(
         4, 
         lpsm::ArgVec2(6, 9),
         lpsm::ArgVec2(3, 6),
         false, 69
    ) << '\n';
    return 0;
}

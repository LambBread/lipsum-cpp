#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for header-only usage
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate 5-8 sentences 
    //of 1-3 sentence fragments
    //of 4-9 words,
    //starting with "Lorem ipsum...", random seed
    std::cout << lpsm::GenerateParagraphX();
    //generate 7-10 sentences 
    //of 3-6 sentence fragments 
    //of 6-9 words,
    //not starting with "Lorem ipsum...", seed 69
    std::cout << lpsm::GenerateParagraphX(
        6, 9,
        3, 6,
        7, 10, 
        false, 69
    );
    return 0;
}

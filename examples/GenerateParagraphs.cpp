#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate 5 paragraphs of 5-8 sentences and 4-12 words per sentence, starting with "Lorem ipsum..."
    std::cout << lipsum::GenerateParagraphs();
    //generate 100 paragraphs of 7-10 sentences and 8-20 words per sentence, not starting with "Lorem ipsum...", see docs for last parameter
    std::cout << lipsum::GenerateParagraphs(100, 7, 10, 8, 20, false, 0.6f);
    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#endif
#include "lipsum.hpp"
#include <iostream>

int main()
{
    //generate a sentence with 4-12 words (default)
    std::cout << lipsum::GenerateSentence() << '\n';
    //generate a sentence with 8-20 words, see docs for last parameter
    std::cout << lipsum::GenerateSentence(8, 20, 0.6f) << '\n';
    return 0;
}

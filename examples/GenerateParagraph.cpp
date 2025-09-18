#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate 5-8 sentences of 4-12 words, starting with "Lorem ipsum..." (default)
    std::cout << lipsum::GenerateParagraph();
    //generate 7-10 sentences of 8-20 words, not starting with "Lorem ipsum...", see docs for last parameter
    std::cout << lipsum::GenerateParagraph(7, 10, 8, 20, false, 0.6f);
    return 0;
}

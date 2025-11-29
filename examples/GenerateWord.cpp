#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for header-only usage
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate a random word with random seed
    std::cout << lpsm::GenerateWord() << '\n';
    //generate a random word with seed 69
    std::cout << lpsm::GenerateWord(69) << '\n';
    return 0;
}

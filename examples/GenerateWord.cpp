#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //generate a random word
    std::cout << lpsm::GenerateWord() << '\n';
    return 0;
}

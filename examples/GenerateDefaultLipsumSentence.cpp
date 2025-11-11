#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for single-header usage
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //prints "Lorem ipsum dolor sit amet..."
    std::cout << lpsm::GenerateDefaultLipsumSentence() << '\n';
    return 0;
}

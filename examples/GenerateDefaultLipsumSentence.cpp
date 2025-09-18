#define LIPSUM_IMPLEMENTATION //only for single-header usage
#include "lipsum.hpp"
#include <iostream>
int main()
{
    //prints "Lorem ipsum dolor sit amet..."
    std::cout << lipsum::GenerateDefaultLipsumSentence() << '\n';
    return 0;
}

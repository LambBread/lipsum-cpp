#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // prints default "Lorem ipsum..." sentence
    std::cout << lpsm::GenerateDefaultLipsumSentence() << '\n';
    return 0;
}

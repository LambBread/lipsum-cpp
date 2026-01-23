#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate a random word
    std::cout << lpsm::GenerateWord() << '\n';
    return 0;
}

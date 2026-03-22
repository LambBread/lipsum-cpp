#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate 5 words
    std::cout << lpsm::GenerateWords(5) << '\n';
    return 0;
}

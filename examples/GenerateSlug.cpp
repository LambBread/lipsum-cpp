#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate slug of 2-5 words, separated by hyphen (default)
    std::cout << lpsm::GenerateSlug() << '\n';
    // generate slug of 6-9 words, separated by underscore
    std::cout << lpsm::GenerateSlug(lpsm::ArgVec2(6, 9), '_') << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateSlugX(6, 9, '_') << '\n';
    return 0;
}

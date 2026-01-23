#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"
int main()
{
    // generate sentence fragment of 4-9 words (default)
    std::cout << lpsm::GenerateSentenceFragment() << '\n';
    // generate sentence fragment of 6-9 words
    std::cout << lpsm::GenerateSentenceFragment(lpsm::ArgVec2(6, 9)) << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateSentenceFragmentX(6, 9) << '\n';
    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include "lipsum.hpp"

int main()
{
    // generate a URL with 2-5 words at the end (default)
    std::cout << lpsm::GenerateURL() << '\n';

    // generate a URL with 6-9 words at the end
    std::cout << lpsm::GenerateURL(lpsm::ArgVec2(6, 9)) << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateURLX(6, 9) << '\n';
    return 0;
}

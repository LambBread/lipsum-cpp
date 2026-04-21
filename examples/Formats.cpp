#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    std::cout << lpsm::GenerateXMLDocument() << '\n';

    std::cout << lpsm::GenerateJSONObject() << '\n';
    return 0;
}

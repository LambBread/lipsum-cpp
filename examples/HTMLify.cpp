#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include <iostream>

#include "lipsum.hpp"
int main()
{
    std::cout << lpsm::HTMLify(
            "This is a paragraph.\n&&This is another paragraph.");
    std::cout << lpsm::HTMLify(lpsm::GenerateParagraphs());
    return 0;
}

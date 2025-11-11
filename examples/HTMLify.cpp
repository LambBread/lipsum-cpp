#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only necessary for single-header usage
#endif
#include "lipsum.hpp"
#include <iostream>
int main()
{
    std::cout << lpsm::HTMLify("This is a paragraph.\n&&This is another paragraph.");
    std::cout << lpsm::HTMLify(lpsm::GenerateParagraphs());
    return 0;
}

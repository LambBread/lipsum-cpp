#define LIPSUM_IMPLEMENTATION //only necessary for single-header usage
#include "lipsum.hpp"
int main()
{
    std::cout << lipsum::HTMLify("This is a paragraph.\nThis is another paragraph.");
    std::cout << lipsum::HTMLify(lipsum::GenerateParagraphs());
    return 0;
}

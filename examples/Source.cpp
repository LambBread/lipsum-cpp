// just testing if this is working lmao
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include "lipsum.hpp"

int main()
{
    lpsm::Source src("../../examples/catipsum_example.txt");
    std::cout << lpsm::GenerateParagraph(lpsm::ArgVec2(4, 9),
                                         lpsm::ArgVec2(1, 3),
                                         lpsm::ArgVec2(5, 8),
                                         false,
                                         src);
    lpsm::Generator gen("../../examples/catipsum_example.txt");
    std::cout << gen.md_text(20);
    return 0;
}

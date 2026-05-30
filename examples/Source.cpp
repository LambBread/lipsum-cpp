#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    lpsm::Generator gen("cat");
    std::cout << gen.md_text(20);
    return 0;
}

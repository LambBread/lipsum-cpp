#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // print current version of lipsum-cpp
    std::cout << lpsm::LipsumVersion() << '\n';

    // should be 4
    std::cout << lpsm::CountSentences("Yes this is a test. [Testing "
                                      "123.](https://example.com/foo-bar) "
                                      "Testing 123. Foobar test.")
              << '\n';

    return 0;
}

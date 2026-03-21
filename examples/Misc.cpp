#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // print current version of lipsum-cpp
    std::cout << LIPSUM_CPP_VERSION << '\n';
    std::cout << "major " << LIPSUM_CPP_VERSION_MAJOR << " minor "
              << LIPSUM_CPP_VERSION_MINOR << " patch "
              << LIPSUM_CPP_VERSION_PATCH << '\n';

    // should be 4
    std::cout << lpsm::CountSentences("Yes this is a test. [Testing "
                                      "123.](https://example.com/foo-bar) "
                                      "Testing 123. Foobar test.")
              << '\n';
    std::cout << lpsm::CountWords("Hello World, Foo bar baz qux quuz. "
                                  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA. Lorem ipsum "
                                  "dolor sit amet, aaaaaaaaaaaaaaaaaa")
              << '\n';
    std::cout << "this is a plain URL: " << lpsm::GeneratePlainURL() << '\n';
    std::cout << "your generated password is "
              << lpsm::GenerateScramble(24, ' ', '~') << '\n';

    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    lpsm::Generator gen;
    // print current version of lipsum-cpp
    std::cout << LIPSUM_CPP_VERSION << '\n';
    std::cout << "major " << LIPSUM_CPP_VERSION_MAJOR << " minor "
              << LIPSUM_CPP_VERSION_MINOR << " patch "
              << LIPSUM_CPP_VERSION_PATCH << " commit "
              << LIPSUM_CPP_VERSION_COMMIT << '\n';

    // should be 4
    std::cout << lpsm::CountSentences("Yes this is a test. [Testing "
                                      "123.](https://example.com/foo-bar) "
                                      "Testing 123. Foobar test.")
              << '\n';

    std::cout << lpsm::CountSentenceFragments(
                         "This is a test, and this is a test; testing - test, "
                         "test, test. "
                         "Lorem ipsum, dolor sit, amet.\n\n"
                         "- This is a list, first letter not be counted.\n"
                         "- Foo bar; baz - qux. (This, is not counted.)")
              << '\n';

    std::cout << lpsm::CountParagraphs(gen.md_text(50, true), 1) << '\n';
    std::cout << lpsm::CountParagraphs(gen.paragraph(50)) << '\n';

    std::cout << lpsm::CountWords("Hello World, Foo bar baz qux quuz. "
                                  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA. Lorem ipsum "
                                  "dolor sit amet, aaaaaaaaaaaaaaaaaa")
              << "\n\n";
    std::cout << "this is a plain URL: " << lpsm::GeneratePlainURL() << '\n';

    // generate a URL with 2-5 words at the end (default)
    std::cout << lpsm::GenerateURL() << '\n';

    // generate a URL with 6-9 words at the end
    std::cout << lpsm::GenerateURL(lpsm::ArgVec2(6, 9)) << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateURLX(6, 9) << "\n\n";

    std::cout << "your generated password is "
              << lpsm::GenerateScramble(24, ' ', '~') << '\n';

    // prints default "Lorem ipsum..." sentence
    std::cout << lpsm::GenerateDefaultLipsumSentence() << "\n\n";

    // generate slug of 2-5 words, separated by hyphen (default)
    std::cout << lpsm::GenerateSlug() << '\n';

    // generate slug of 6-9 words, separated by underscore
    std::cout << lpsm::GenerateSlug(lpsm::ArgVec2(6, 9), '_') << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateSlugX(6, 9, '_') << '\n';

    return 0;
}

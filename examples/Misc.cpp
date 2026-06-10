#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    lpsm::Generator gen;

    // Print the current version of lipsum-cpp.
    std::cout << LIPSUM_CPP_VERSION << '\n';
    std::cout << "major " << LIPSUM_CPP_VERSION_MAJOR << " minor "
              << LIPSUM_CPP_VERSION_MINOR << " patch "
              << LIPSUM_CPP_VERSION_PATCH << " commit "
              << LIPSUM_CPP_VERSION_COMMIT << " time "
              << LIPSUM_CPP_VERSION_TIME << " date " << LIPSUM_CPP_VERSION_DATE
              << '\n';

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

    std::cout << lpsm::CountParagraphs(gen.fmt_text(50, lpsm::HTML),
                                       lpsm::CountParaMethod::Markdown)
              << '\n';
    std::cout << lpsm::CountParagraphs(gen.paragraph(50)) << '\n';

    std::cout << lpsm::CountWords("Hel+lo World, Foo bar baz - qux-quuz. "
                                  "AAAAAAAAAAAAAA'AAAAAAAAAAAAAAA. Lorem ipsum "
                                  "dolor sit amet, aaaaaaaaaaaaaaaaaa\n\n## "
                                  "This is a subtitle")
              << "\n\n";
    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate a paragraph of 5-8 sentences of 1-3 sentence fragments of 4-9
    // words, with formatted sentences of 1-2 sentence fragments of 4-8 words
    // with 2-5 words at the end of a URL, with URLs starting at
    // https://example.com, starting with "Lorem ipsum...", in Markdown
    // (default)
    std::cout << lpsm::GenerateMarkdownParagraph();

    // generate a paragraph of 7-10 sentences of 3-6 sentence fragments of 6-9
    // words, with formatted sentences of 3-5 sentence fragments of 6-8 words
    // with 6-10 words at the end of a URL, with URLs starting at
    // https://google.com, not starting with "Lorem ipsum...", in HTML
    std::cout << lpsm::GenerateMarkdownParagraph(lpsm::ArgVec2(6, 9),
                                                 lpsm::ArgVec2(3, 6),
                                                 lpsm::ArgVec2(7, 10),
                                                 lpsm::ArgVec2(6, 8),
                                                 lpsm::ArgVec2(3, 5),
                                                 lpsm::ArgVec2(6, 10),
                                                 std::string(
                                                         "https://google.com/"),
                                                 false,
                                                 true);
    return 0;
}

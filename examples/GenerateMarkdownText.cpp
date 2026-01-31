#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate a document with paragraphs of 5-8 sentences of 1-3 sentence
    // fragments of 4-9 words, with formatted sentences of 1-2 sentence
    // fragments of 4-8 words with 2-5 words at the end of a URL, with URLs
    // starting at https://example.com, with random headings of level 2-4 and
    // lists with 3-5 points, with a total of 15 elements (default)
    std::cout << lpsm::GenerateMarkdownText();

    // generate a document with paragraphs of 7-10 sentences of 3-6 sentence
    // fragments of 6-9 words, with formatted sentences of 3-5 sentence
    // fragments of 6-8 words with 6-10 words at the end of a URL, with URLs
    // starting at https://google.com, with random headings of level 1-6 and
    // lists with 5-12 points, with a total of 30 elements
    std::cout << lpsm::GenerateMarkdownText(lpsm::ArgVec2(6, 9),
                                            lpsm::ArgVec2(3, 6),
                                            lpsm::ArgVec2(7, 10),
                                            lpsm::ArgVec2(5, 12),
                                            lpsm::ArgVec2(6, 8),
                                            lpsm::ArgVec2(3, 5),
                                            lpsm::ArgVec2(6, 10),
                                            lpsm::ArgVec2(1, 6),
                                            std::string("https://google.com/"),
                                            30);
    return 0;
}

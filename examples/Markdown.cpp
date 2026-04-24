#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <memory>
#ifdef __EMSCRIPTEN__
#    include <emscripten.h>
#endif
#include "lipsum.hpp"

int main()
{
    lpsm::Generator gen;

    // generate bold sentence of 1-2 sentence fragments of 4-8 words, in
    // Markdown (default)
    std::cout << lpsm::GenerateMarkdownEmphasis() << '\n';

    // generate italic sentence of 3-6 sentence fragments of 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownEmphasis(false,
                                                lpsm::ArgVec2(6, 9),
                                                lpsm::ArgVec2(3, 6),
                                                true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownEmphasisX(false, 6, 9, 3, 6, true)
              << "\n\n";

    // generate main title header with 2-5 words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownHeader();

    // generate subtitle header with 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownHeader(2, lpsm::ArgVec2(6, 9), true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownHeaderX(2, 6, 9, true) << "\n\n";

    // generate link with 1-2 sentence fragments of 4-8
    // words and URL ending in 2-5 words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownLink() << '\n';

    // generate link with 3-6 sentence fragments of 7-10
    // words and URL ending in 6-9 words, in HTML
    std::cout << lpsm::GenerateMarkdownLink(lpsm::ArgVec2(7, 10),
                                            lpsm::ArgVec2(3, 6),
                                            lpsm::ArgVec2(6, 9),
                                            true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownLinkX(7, 10, 3, 6, 6, 9, true) << "\n\n";

    // generate unordered list of 3-5 points of 1-2 sentence fragments of 4-8
    // words, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownList();

    // generate ordered list of 5-12 points of 3-6 sentence fragments of 6-9
    // words, in HTML
    std::cout << lpsm::GenerateMarkdownList(true,
                                            lpsm::ArgVec2(6, 9),
                                            lpsm::ArgVec2(3, 6),
                                            lpsm::ArgVec2(5, 12),
                                            true)
              << '\n';

    // equivalent statement
    std::cout << lpsm::GenerateMarkdownListX(true, 6, 9, 3, 6, 5, 12, true)
              << "\n\n";

    // generate a paragraph of 5-8 sentences of 1-3 sentence fragments of 4-9
    // words, with formatted sentences of 1-2 sentence fragments of 4-8 words
    // with 2-5 words at the end of a URL, starting with "Lorem ipsum...", in
    // Markdown (default)
    std::cout << lpsm::GenerateMarkdownParagraph();

    // generate a paragraph of 7-10 sentences of 3-6 sentence fragments of 6-9
    // words, with formatted sentences of 3-5 sentence fragments of 6-8 words
    // with 6-10 words at the end of a URL, not starting with "Lorem ipsum...",
    // in HTML
    std::cout << lpsm::GenerateMarkdownParagraph(lpsm::ArgVec2(6, 9),
                                                 lpsm::ArgVec2(3, 6),
                                                 lpsm::ArgVec2(7, 10),
                                                 lpsm::ArgVec2(6, 8),
                                                 lpsm::ArgVec2(3, 5),
                                                 lpsm::ArgVec2(6, 10),
                                                 false,
                                                 true)
              << '\n';

    // generate 5 paragraphs of 5-8 sentences of 1-3 sentence fragments of 4-9
    // words, with formatted sentences of 1-2 sentence fragments of 4-8 words
    // with 2-5 words at the end of a URL, starting with "Lorem ipsum...", in
    // Markdown (default)
    std::cout << lpsm::GenerateMarkdownParagraphs();

    // generate 10 paragraphs of 7-10 sentences of 3-6 sentence fragments of 6-9
    // words, with formatted sentences of 3-5 sentence fragments of 6-8 words
    // with 6-10 words at the end of a URL, not starting with "Lorem ipsum...",
    // in HTML
    std::cout << lpsm::GenerateMarkdownParagraphs(10,
                                                  lpsm::ArgVec2(6, 9),
                                                  lpsm::ArgVec2(3, 6),
                                                  lpsm::ArgVec2(7, 10),
                                                  lpsm::ArgVec2(6, 8),
                                                  lpsm::ArgVec2(3, 5),
                                                  lpsm::ArgVec2(6, 10),
                                                  false,
                                                  true)
              << '\n';

    // generate a document with paragraphs of 5-8 sentences of 1-3 sentence
    // fragments of 4-9 words, with formatted sentences of 1-2 sentence
    // fragments of 4-8 words with 2-5 words at the end of a URL, with random
    // headings of level 2-4 and lists with 3-5 points, with a total of 15
    // elements, in Markdown (default)
    std::cout << lpsm::GenerateMarkdownText();

    // generate a document with paragraphs of 7-10 sentences of 3-6 sentence
    // fragments of 6-9 words, with formatted sentences of 3-5 sentence
    // fragments of 6-8 words with 6-10 words at the end of a URL, with random
    // headings of level 1-6 and lists with 5-12 points, with a total of 30
    // elements, in HTML
    std::string text = lpsm::GenerateMarkdownText(lpsm::ArgVec2(6, 9),
                                                  lpsm::ArgVec2(3, 6),
                                                  lpsm::ArgVec2(7, 10),
                                                  lpsm::ArgVec2(5, 12),
                                                  lpsm::ArgVec2(6, 8),
                                                  lpsm::ArgVec2(3, 5),
                                                  lpsm::ArgVec2(6, 10),
                                                  lpsm::ArgVec2(1, 6),
                                                  30,
                                                  true);

    std::cout << text << "\n\n";
    // clang-format off
#ifdef __EMSCRIPTEN__
    // js to put text in document
    EM_ASM({
        const htmlText   = UTF8ToString($0);
        const contentElem = document.createElement("div");
        contentElem.innerHTML = htmlText;
        document.querySelector("body").appendChild(contentElem);
    }, text.c_str());
#endif
    // clang-format on
    return 0;
}

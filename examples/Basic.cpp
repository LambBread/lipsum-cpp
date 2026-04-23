#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"

int main()
{
    // Create a generator.
    lpsm::Generator generator;

    // Generate 3 paragraphs.
    std::cout << generator.paragraph(3, true);

    // Generate 6 sentences.
    std::cout << generator.sentence(6, true) << '\n';

    // Generate a sentence fragment.
    std::cout << generator.sentence_fragment() << '\n';

    // Generate 5 words.
    std::cout << generator.word(5) << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << generator.md_paragraph(5, true);

    // Generate a Markdown document with 20 elements.
    std::cout << generator.md_text(20);

    // Generate 5 HTML paragraphs.
    std::cout << generator.html_paragraph(5, true);

    // Generate an HTML document with 20 elements.
    std::cout << generator.html_text(20);

    // Generate an XML document with 40 "choices"
    std::cout << generator.xml(40) << '\n';

    // Generate a JSON object with a max recursion of 5
    std::cout << generator.json(5, true) << '\n';

    return 0;
}

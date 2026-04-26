#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"

int main()
{
    // Create a generator.
    lpsm::Generator gen;

    // Generate 5 words.
    std::cout << gen.word(5) << '\n';

    // Generate a sentence fragment.
    std::cout << gen.sentence_fragment() << '\n';

    // Generate 6 sentences.
    std::cout << gen.sentence(6, true) << '\n';

    // Generate 3 paragraphs.
    std::cout << gen.paragraph(3, true);

    // Generate a text.
    std::cout << gen.text(true);

    return 0;
}

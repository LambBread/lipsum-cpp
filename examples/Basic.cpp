#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION //only for header-only usage
#endif
#include "lipsum.hpp"
#include <iostream>

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
    std::cout << generator.words(5) << '\n';
    
    return 0;
}

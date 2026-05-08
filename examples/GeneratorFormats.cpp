#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include "lipsum.hpp"

int main()
{
    // Create a generator using corporate ipsum.
    lpsm::Generator gen("corpo");

    // Change to 6-9 words per sentence fragment,
    // 3-6 sentence fragments per sentence,
    // 6-9 items in JSON arrays/objects
    gen.change_setting("word", 6, 9);
    gen.change_setting("frag", 3, 6);
    gen.change_setting("jsonLength", 6, 9);

    // Generate a URL.
    std::cout << gen.url() << '\n';

    // Generate a plain URL.
    std::cout << gen.plain_url() << '\n';

    // Generate a slug.
    std::cout << gen.slug('_') << '\n';

    // Generate a scramble.
    std::cout << gen.scramble(24, 'a', 'z') << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << gen.md_paragraph(5, true, false);

    // Generate a Markdown document with 20 elements.
    std::cout << gen.md_text(20, false);

    // Generate 5 HTML paragraphs.
    std::cout << gen.md_paragraph(5, true, true);

    // Generate an HTML document with 20 elements.
    std::cout << gen.md_text(20, true);

    // Generate an XML document with 40 "choices".
    std::cout << gen.xml(40) << '\n';

    // Generate a JSON object with a max recursion of 5.
    std::cout << gen.json(5, true) << '\n';

    return 0;
}

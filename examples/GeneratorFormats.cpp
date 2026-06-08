#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

int main()
{
    // Create a generator using corporate ipsum and the specified seed.
    lpsm::Generator gen("corpo", 1234);

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

    // Generate an email.
    std::cout << gen.email() << '\n';

    // Generate a slug.
    std::cout << gen.slug('_') << '\n';

    // Generate a scramble.
    std::cout << gen.scramble(24, 'a', 'z') << '\n';

    // Generate 5 Markdown paragraphs.
    std::cout << gen.md_paragraph(5, lpsm::USELIPSUM, lpsm::MARKDOWN);

    // Generate a Markdown document with 20 elements.
    std::cout << gen.md_text(20, lpsm::MARKDOWN);

    // Generate a Markdown subtitle.
    std::cout << gen.md_header(2, lpsm::MARKDOWN);

    // Generate an italic Markdown sentence.
    std::cout << gen.md_emphasis(lpsm::ITALIC, lpsm::MARKDOWN) << '\n';

    // Generate a Markdown link.
    std::cout << gen.md_link(lpsm::MARKDOWN) << '\n';

    // Generate an ordered Markdown list.
    std::cout << gen.md_list(lpsm::ORDERED, lpsm::MARKDOWN);

    // Generate 5 HTML paragraphs.
    std::cout << gen.md_paragraph(5, lpsm::USELIPSUM, lpsm::HTML);

    // Generate an HTML document with 20 elements.
    std::cout << gen.md_text(20, lpsm::HTML);

    // Generate an XML document with 40 "choices".
    std::cout << gen.xml(40) << '\n';

    // Generate a JSON object with a max recursion of 5.
    std::cout << gen.json(0, 5, lpsm::OBJECT) << '\n';

    // Generate a JSON value with a max recursion of 5.
    std::cout << gen.json_value(0, 5) << '\n';

    return 0;
}

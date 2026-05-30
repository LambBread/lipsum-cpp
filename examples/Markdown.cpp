#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif

#include <lipsum.hpp>

#ifdef __EMSCRIPTEN__
#    include <emscripten.h>
#endif

int main()
{
    lpsm::Generator gen;

    // Change some settings.
    gen.change_setting("word", 6, 9);
    gen.change_setting("frag", 3, 6);
    gen.change_setting("sent", 7, 10);
    gen.change_setting("point", 5, 12);
    gen.change_setting("wordFmt", 6, 8);
    gen.change_setting("fragFmt", 3, 5);
    gen.change_setting("wordURL", 3, 5);
    gen.change_setting("level", 1, 6);

    // Generate an HTML document with 30 elements.
    std::string text = gen.md_text(30, true);
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

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <memory>
#ifdef __EMSCRIPTEN__
#    include <emscripten.h>
#endif
#include "lipsum.hpp"
#include "maddy/parser.h"

int main()
{
    lpsm::Generator gen;
    // generate markdown document with 20 elements
    std::string text = gen.md_text(20);
    std::cout << text;
    // clang-format off
#ifdef __EMSCRIPTEN__
    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>();
    std::stringstream textStream = std::stringstream(text);
    std::string htmlOutput = parser->Parse(textStream);
    // js to put text in document
    EM_ASM({
        const htmlText   = UTF8ToString($0);
        const contentElem = document.createElement("div");
        contentElem.innerHTML = htmlText;
        document.querySelector("body").appendChild(contentElem);
    }, htmlOutput.c_str());
#endif
    // clang-format on
    return 0;
}

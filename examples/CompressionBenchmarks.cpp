#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include <lipsum.hpp>
#include <zlib.h>

int main()
{
    lpsm::Generator gen;
    std::string     text = gen.md_text(100000);
    // std::string text;
    // text.reserve(1000000);
    // for(int i = 0; i < 1000; ++i)
    //{
    //     text += "A";
    // }
    // std::cout << text << "\n\n";
    uLong                      textLen = text.size();
    uLong                      compLen = compressBound(textLen);
    std::vector<unsigned char> comp(compLen);
    if (compress(comp.data(),
                 &compLen,
                 reinterpret_cast<const Bytef*>(text.data()),
                 textLen) != Z_OK)
    {
        return -1;
    }

    while (comp.back() == 0)
    {
        comp.pop_back();
    }

    // for(const auto& letter : comp)
    //{
    //     std::cout << letter;
    // }
    // std::cout << '\n';

    std::cout << "Original size: " << text.size() << '\n';
    std::cout << "Compressed size: " << comp.size() << '\n';
    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <lipsum.hpp>
#include <limits>

#define GET_ARG(varName, idx, type)                                            \
    if (commandOpts.size() >= idx)                                             \
    {                                                                          \
        varName = ToType<type>(commandOpts.at(idx - 1));                       \
    }

template <typename T> T ToType(const std::string& str)
{
    std::stringstream ss(str);
    T                 ret;
    ss >> std::boolalpha >> ret;
    return ret;
}

constexpr bool InCharRange(int num)
{
    return (num > std::numeric_limits<char>::min()) &&
           (num < std::numeric_limits<char>::max());
}

void ErrorMessage(const std::string& str)
{
#ifdef __EMSCRIPTEN__
    emscripten_console_error(str.c_str());
#elif defined(_WIN32)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 4);
    std::cerr << str;
    SetConsoleTextAttribute(hConsole, 7);
#else
    std::cerr << "\033[31m" << str << "\033[0m";
#endif
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 0;
    }

    std::vector<std::string> options;
    std::vector<std::string> commandOpts;

    for (int i = 1; i < argc; ++i)
    {
        std::string realArg = argv[i];
        if (realArg.starts_with("--")) // using a c++20 feature!
        {
            options.push_back(realArg);
        }
        else
        {
            commandOpts.push_back(realArg);
        }
    }

    for (const auto& option : options)
    {
        std::cout << option << '\n';
    }

    for (const auto& option : commandOpts)
    {
        std::cout << option << '\n';
    }

    lpsm::Generator gen;

    // no subcommand
    // TODO: add help command
    if (commandOpts.size() <= 0)
    {
        return 0;
    }

    std::string subcommand = commandOpts.at(0);

    if (subcommand == "word")
    {
        int num = 1;

        GET_ARG(num, 2, int)
        std::cout << gen.word(num);
    }
    else if (subcommand == "sentence_fragment")
    {
        std::cout << gen.sentence_fragment();
    }
    else if (subcommand == "sentence")
    {
        int  num       = 1;
        bool useLipsum = true;
        GET_ARG(num, 2, int)
        GET_ARG(useLipsum, 3, bool)
        std::cout << gen.sentence(num, useLipsum);
    }
    else if (subcommand == "paragraph")
    {
        int  num       = 1;
        bool useLipsum = true;
        GET_ARG(num, 2, int)
        GET_ARG(useLipsum, 3, bool)
        std::cout << gen.paragraph(num, useLipsum);
    }
    else if (subcommand == "text")
    {
        bool useLipsum = true;
        GET_ARG(useLipsum, 2, bool)
        std::cout << gen.text(useLipsum);
    }
    else if (subcommand == "scramble")
    {
        int length  = 16;
        int minChar = static_cast<int>(' ');
        int maxChar = static_cast<int>('~');

        GET_ARG(length, 2, int)
        GET_ARG(minChar, 3, int)
        GET_ARG(maxChar, 4, int)

        if (!InCharRange(minChar) || !InCharRange(maxChar))
        {
            ErrorMessage("Error: number out of range of char. Please use "
                         "numbers between 0 and 127.\n");
            return -1;
        }
        std::cout << gen.scramble(length,
                                  static_cast<char>(minChar),
                                  static_cast<char>(maxChar));
    }
    else if (subcommand == "url")
    {
        std::cout << gen.url();
    }
    else if (subcommand == "plain_url")
    {
        std::cout << gen.plain_url();
    }
    else if (subcommand == "slug")
    {
        char separator = '-';

        GET_ARG(separator, 2, char)

        std::cout << gen.slug(separator);
    }
    else if (subcommand == "md_paragraph")
    {
        int  num       = 1;
        bool useLipsum = true;
        GET_ARG(num, 2, int)
        GET_ARG(useLipsum, 3, bool)
        std::cout << gen.md_paragraph(num, useLipsum);
    }
    else if (subcommand == "md_text")
    {
        int numElements = 15;
        GET_ARG(numElements, 2, int)
        std::cout << gen.md_text(numElements);
    }
    else if (subcommand == "html_paragraph")
    {
        int  num       = 1;
        bool useLipsum = true;
        GET_ARG(num, 2, int)
        GET_ARG(useLipsum, 3, bool)
        std::cout << gen.html_paragraph(num, useLipsum);
    }
    else if (subcommand == "html_text")
    {
        int numElements = 15;
        GET_ARG(numElements, 2, int)
        std::cout << gen.html_text(numElements);
    }
    else if (subcommand == "xml")
    {
        int choices = 30;
        GET_ARG(choices, 2, int)
        std::cout << gen.xml(choices);
    }
    else if (subcommand == "json")
    {
        int  maxDepth = 3;
        bool isObject = true;
        GET_ARG(maxDepth, 2, int)
        GET_ARG(isObject, 3, bool)
        std::cout << gen.json(maxDepth, isObject);
    }
    else
    {
        ErrorMessage("Error: unknown subcommand\n");
        return -1;
    }

    std::cout << '\n';

    return 0;
}

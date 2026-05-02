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

#define NUM_AND_USELIPSUM_SUBCOMMAND(name)                                     \
    if (subcommand == #name)                                                   \
    {                                                                          \
        int  num       = 1;                                                    \
        bool useLipsum = true;                                                 \
        GET_ARG(num, 2, int);                                                  \
        GET_ARG(useLipsum, 3, bool);                                           \
        std::cout << gen.name(num, useLipsum);                                 \
    }
#define SINGLE_ARG_SUBCOMMAND(name, argName, defaultVal, type)                 \
    if (subcommand == #name)                                                   \
    {                                                                          \
        type argName = defaultVal;                                             \
        GET_ARG(argName, 2, type)                                              \
        std::cout << gen.name(argName);                                        \
    }

#define NO_ARG_SUBCOMMAND(name)                                                \
    if (subcommand == #name)                                                   \
    {                                                                          \
        std::cout << gen.name();                                               \
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

lpsm::ArgVec2 ParseAv2(const std::string& str)
{
    size_t pos = str.find(',');

    lpsm::ArgVec2 ret{0, 0};
    if (pos != std::string::npos)
    {
        ret.min = ToType<int>(str.substr(0, pos));
        ret.max = ToType<int>(str.substr(pos + 1));
    }
    else
    {
        ErrorMessage("Error: invalid format of argument\nMust be in format: "
                     "<min>,<max>");
    }

    return ret;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 0;
    }

    std::vector<std::string> options;
    std::vector<std::string> commandOpts;

    lpsm::Generator gen;

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
        if (option.starts_with("--help"))
        {
            // see other todo
            return 0;
        }
        else if (option.starts_with("--word"))
        {
            size_t pos = option.find('=');
            if (pos != std::string::npos)
            {
                std::string   value = option.substr(pos + 1);
                lpsm::ArgVec2 word  = ParseAv2(value);
                gen.change_setting("word", word);
            }
            else
            {
                ErrorMessage("Error: must be in format --option=value\n");
            }
        }
        std::cout << option << '\n';
    }

    for (const auto& option : commandOpts)
    {
        std::cout << option << '\n';
    }

    // no subcommand
    // TODO: add help command
    if (commandOpts.size() <= 0)
    {
        return 0;
    }

    std::string subcommand = commandOpts.at(0);

    // clang-format off
    SINGLE_ARG_SUBCOMMAND(word, num, 1, int)
    else NO_ARG_SUBCOMMAND(sentence_fragment) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(sentence) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(paragraph) 
    else SINGLE_ARG_SUBCOMMAND(text, useLipsum, true, bool) 
    else if (subcommand == "scramble")
    // clang-format on
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
    // clang-format off
    else NO_ARG_SUBCOMMAND(url)
    else NO_ARG_SUBCOMMAND(plain_url) 
    else SINGLE_ARG_SUBCOMMAND(slug, separator, '-', char) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(md_paragraph)
    else SINGLE_ARG_SUBCOMMAND(md_text, numElements, 15, int) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(html_paragraph) 
    else SINGLE_ARG_SUBCOMMAND(html_text, numElements, 15, int)
    else SINGLE_ARG_SUBCOMMAND(xml, choices, 30, int)
    else if (subcommand == "json")
    // clang-format on
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

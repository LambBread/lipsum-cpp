#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <lipsum.hpp>
#include <limits>

// various macros to avoid repetition
// maybe not best practice?

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

#define SETTING_OPTION(name)                                                   \
    if (option.starts_with(std::string("--") + #name))                         \
    {                                                                          \
        SettingOption(option, #name, gen);                                     \
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

void SettingOption(const std::string& option,
                   const std::string& name,
                   lpsm::Generator&   gen)
{
    size_t pos = option.find('=');
    if (pos != std::string::npos)
    {
        std::string   value = option.substr(pos + 1);
        lpsm::ArgVec2 av2   = ParseAv2(value);
        gen.change_setting(name, av2);
    }
    else
    {
        ErrorMessage("Error: must be in format --option=value\n");
    }
}

void Help()
{
    std::cout
            << "Usage: lpsmcpp-cli <subcommand> [<arguments>] [<options>]\n\n";
    std::cout << "Valid options include:\n";
    std::cout << "  --help - Show this help\n";
    std::cout << "  --word=<min,max> - The min and max words per sentence "
                 "fragment.\n";
    std::cout << "  --frag=<min,max> - The min and max sentence fragments per "
                 "sentence.\n";
    std::cout << "  --sent=<min,max> - The min and max sentences per "
                 "paragraph.\n";
    std::cout << "  --para=<min,max> - The min and max paragraphs per text.\n";
    std::cout << "  --point=<min,max> - The min and max points per list.\n";
    std::cout << "  --wordURL=<min,max> - The min and max words in headings, "
                 "in slugs, and at the end of URLs.\n";
    std::cout << "  --wordFmt=<min,max> - The min and max words per formatted "
                 "sentence fragment.\n";
    std::cout << "  --fragFmt=<min,max> - The min and max sentence fragments "
                 "per formatted sentence.\n";
    std::cout << "  --level=<min,max> - The min and max levels of headings.\n";
    std::cout << "  --jsonLength=<min,max> - The min and max amount of items "
                 "in JSON objects.\n\n";
    std::cout << "Valid subcommands include:\n";
    std::cout << "  help - Show this help.\n\n";
    std::cout << "  word [<num = 1>] - Generate words.\n";
    std::cout << "    num - The number of words.\n\n";
    std::cout << "  sentence_fragment - Generate a sentence fragment.\n\n";
    std::cout << "  sentence [<num = 1>] [<useLipsum = true>] - Generate "
                 "sentences.\n";
    std::cout << "    num - The number of sentences.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "sentences.\n\n";
    std::cout << "  paragraph [<num = 1>] [<useLipsum = true>] - Generate "
                 "paragraphs.\n";
    std::cout << "    num - The number of paragraphs.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  text [<useLipsum = true>] - Generate a text.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  scramble [<length = 16>] [<minChar = 32>] [<maxChar = "
                 "126>] - Generate a character scramble.\n";
    std::cout << "    length - The number of characters.\n";
    std::cout << "    minChar - The lowest ASCII value possible.\n";
    std::cout << "    maxChar - The highest ASCII value possible.\n\n";
    std::cout << "  url - Generate a URL.\n\n";
    std::cout << "  plain_url - Generate a plain URL.\n\n";
    std::cout << "  slug [<separator = '-'>] - Generate a slug.\n";
    std::cout << "    separator - The separator to use.\n\n";
    std::cout << "  md_paragraph [<num = 1>] [<useLipsum = true>] - Generate a "
                 "Markdown paragraph.\n";
    std::cout << "    num - The number of paragraphs.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  md_text [<numElements = 15>] - Generate a Markdown "
                 "document\n";
    std::cout << "    numElements - The number of elements.\n\n";
    std::cout << "  html_paragraph [<num = 1>] [<useLipsum = true>] - Generate "
                 "an HTML paragraph.\n";
    std::cout << "    num - The number of paragraphs.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  html_text [<numElements = 15>] - Generate an HTML "
                 "document.\n";
    std::cout << "    numElements - The number of elements.\n\n";
    std::cout << "  xml [<choices = 30>] - Generate an XML document.\n";
    std::cout << "    choices - The number of 'choices' to make.\n\n";
    std::cout << "  json [<maxDepth = 3>] [<isObject = true>] - Generate a "
                 "JSON object or array.\n";
    std::cout << "    maxDepth - The maximum recursion depth.\n";
    std::cout
            << "    isObject - Whether the output is an object or an array.\n";
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        Help();
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
            Help();
            return 0;
        }

        // clang-format off
        SETTING_OPTION(word)
        else SETTING_OPTION(frag)
        else SETTING_OPTION(sent)
        else SETTING_OPTION(para)
        else SETTING_OPTION(point)
        else SETTING_OPTION(wordURL)
        else SETTING_OPTION(wordFmt)
        else SETTING_OPTION(fragFmt)
        else SETTING_OPTION(level)
        else SETTING_OPTION(jsonLength)
        else
        // clang-format on
        {
            ErrorMessage("Error: unknown option\n");
        }
        //std::cout << option << '\n';
    }

    //for (const auto& option : commandOpts)
    //{
    //    std::cout << option << '\n';
    //}

    // no subcommand
    if (commandOpts.empty())
    {
        Help();
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
    else if (subcommand == "help")
    {
        Help();
        return 0;
    }
    else
    {
        ErrorMessage("Error: unknown subcommand\n");
        return -1;
    }

    std::cout << '\n';

    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <limits>
#include <lipsum.hpp>

// various macros to avoid repetition
// maybe not best practice?

#define GET_ARG(varName, idx, type)                                            \
    if (commandOpts.size() >= idx)                                             \
    {                                                                          \
        varName = lpsm::internal::ToType<type>(commandOpts.at(idx - 1));       \
    }

#define NUM_AND_USELIPSUM_SUBCOMMAND(name)                                     \
    DOUBLE_ARG_SUBCOMMAND(name, int, 1, bool, true)
//    if (subcommand == #name)
//    {
//        int  num       = 1;
//        bool useLipsum = true;
//        GET_ARG(num, 2, int);
//        GET_ARG(useLipsum, 3, bool);
//        std::cout << gen.name(num, useLipsum);
//    }

#define SINGLE_ARG_SUBCOMMAND(name, type, defaultVal)                          \
    if (subcommand == #name)                                                   \
    {                                                                          \
        type argName = defaultVal;                                             \
        GET_ARG(argName, 2, type);                                             \
        std::cout << gen.name(argName);                                        \
    }
#define DOUBLE_ARG_SUBCOMMAND(name, type1, defaultVal1, type2, defaultVal2)    \
    if (subcommand == #name)                                                   \
    {                                                                          \
        type1 argName1 = defaultVal1;                                          \
        type2 argName2 = defaultVal2;                                          \
        GET_ARG(argName1, 2, type1);                                           \
        GET_ARG(argName2, 3, type2);                                           \
        std::cout << gen.name(argName1, argName2);                             \
    }

#define NO_ARG_SUBCOMMAND(name)                                                \
    if (subcommand == #name)                                                   \
    {                                                                          \
        std::cout << gen.name();                                               \
    }

#define SETTING_OPTION(name, shorth)                                           \
    if (OPTION_COND(name, shorth))                                             \
    {                                                                          \
        SettingOption(option, #name, gen);                                     \
    }

#define OPTION_COND(name, shorth)                                              \
    (option.starts_with(std::string("--") + #name) ||                          \
     option.starts_with(shorth))

constexpr bool InCharRange(int num)
{
    return (num >= std::numeric_limits<char>::min()) &&
           (num <= std::numeric_limits<char>::max());
}

template <typename... Args> void ErrorMessage(const Args&... args)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 4);
    ((std::cerr << args), ...);
    SetConsoleTextAttribute(hConsole, 7);
#else
    std::cerr << "\033[31m";
    ((std::cerr << args), ...);
    std::cerr << "\033[0m";
#endif
}

lpsm::ArgVec2 ParseAv2(const std::string& str)
{
    size_t pos = str.find(',');

    lpsm::ArgVec2 ret{0, 0};
    if (pos != std::string::npos)
    {
        ret.min = lpsm::internal::ToType<int>(str.substr(0, pos));
        ret.max = lpsm::internal::ToType<int>(str.substr(pos + 1));
    }
    else
    {
        ErrorMessage("Error: invalid format of argument\nMust be in format: "
                     "<min>,<max>\nGot: ",
                     str,
                     '\n');
        exit(-1);
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
        ErrorMessage("Error: must be in format --option=value\nGot: ",
                     option,
                     '\n');
    }
}

void Help()
{
    //clang-format off
    std::cout
            << "Usage: lpsmcpp-cli <subcommand> [<arguments>] [<options>]\n\n";
    std::cout << "Valid options include:\n";
    std::cout << "  --help, -h - Show this help\n";
    std::cout << "  --version, -v - Show the current version of lipsum-cpp.\n";
    std::cout << "  --word=<min,max>, -w - The min and max words per sentence "
                 "fragment.\n";
    std::cout << "  --frag=<min,max>, -f - The min and max sentence fragments "
                 "per sentence.\n";
    std::cout << "  --sent=<min,max>, -s - The min and max sentences per "
                 "paragraph.\n";
    std::cout << "  --para=<min,max>, -p - The min and max paragraphs per "
                 "text.\n";
    std::cout << "  --point=<min,max>, -P - The min and max points per list.\n";
    std::cout << "  --wordURL=<min,max>, -u - The min and max words in "
                 "headings, in slugs, and at the end of URLs.\n";
    std::cout << "  --wordFmt=<min,max>, -W - The min and max words per "
                 "formatted sentence fragment.\n";
    std::cout << "  --fragFmt=<min,max>, -F - The min and max sentence "
                 "fragments per formatted sentence.\n";
    std::cout << "  --level=<min,max>, -l - The min and max levels of "
                 "headings.\n";
    std::cout << "  --jsonLength=<min,max>, -j - The min and max amount of "
                 "items in JSON objects.\n";
    std::cout << "  --source=<source>, -S - Load specified source.\n";
    std::cout << "      <source> may be a filepath to a file or a built-in "
                 "source.\n";
    std::cout << "      Built in sources include: default/lorem, cat, "
                 "dog/doggo, corpo/corporate.\n\n";
    std::cout << "Valid subcommands include:\n";
    std::cout << "  help - Show this help.\n\n";
    std::cout << "  word <num = 1> - Generate words.\n";
    std::cout << "    num - The number of words.\n\n";
    std::cout << "  fragment - Generate a sentence fragment.\n\n";
    std::cout << "  sentence <num = 1> <useLipsum = true> - Generate "
                 "sentences.\n";
    std::cout << "    num - The number of sentences.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "sentences.\n\n";
    std::cout << "  paragraph <num = 1> <useLipsum = true> - Generate "
                 "paragraphs.\n";
    std::cout << "    num - The number of paragraphs.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  text <useLipsum = true> - Generate a text.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n\n";
    std::cout << "  scramble <length = 16> <minChar = 32> <maxChar = 126> - "
                 "Generate a character scramble.\n";
    std::cout << "    length - The number of characters.\n";
    std::cout << "    minChar - The lowest ASCII value possible.\n";
    std::cout << "    maxChar - The highest ASCII value possible.\n\n";
    std::cout << "  url - Generate a URL.\n\n";
    std::cout << "  plain_url - Generate a plain URL.\n\n";
    std::cout << "  slug <separator = '-'> - Generate a slug.\n";
    std::cout << "    separator - The separator to use.\n\n";
    std::cout << "  md_paragraph <num = 1> <useLipsum = true> <useHtml = "
                 "false> - Generate Markdown paragraphs.\n";
    std::cout << "    num - The number of paragraphs.\n";
    std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the "
                 "first sentence.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  md_text <numElements = 15> <useHtml = false> - Generate a "
                 "Markdown document\n";
    std::cout << "    numElements - The number of elements.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  md_header <level = 1> <useHtml = false> - Generate a "
                 "Markdown header.\n";
    std::cout << "    level - The level of the heading.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  md_emphasis <isBold = true> <useHtml = false> - Generate "
                 "an emphasized Markdown sentence.\n";
    std::cout << "    isBold - Whether the sentence is bold or italic.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  md_link <useHtml = false> - Generate a Markdown link.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  md_list <ordered = false> <useHtml = false> - Generate a "
                 "Markdown list.\n";
    std::cout << "    ordered - Whether the list is ordered.\n";
    std::cout << "    useHtml - Whether HTML should be outputted instead of "
                 "Markdown.\n\n";
    std::cout << "  xml <choices = 30> - Generate an XML document.\n";
    std::cout << "    choices - The number of 'choices' to make.\n\n";
    std::cout << "  json <maxDepth = 3> <isObject = true> - Generate a JSON "
                 "object or array.\n";
    std::cout << "    maxDepth - The maximum recursion depth.\n";
    std::cout << "    isObject - Whether the output is an object or an "
                 "array.\n\n";
    //clang-format on
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
        if (realArg.starts_with("-")) // using a c++20 feature!
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
        if (OPTION_COND(help, "-h"))
        {
            Help();
            return 0;
        }

        if (OPTION_COND(version, "-v"))
        {
            std::cout << LIPSUM_CPP_VERSION_FULL << '\n';
            std::cout << LIPSUM_CPP_VERSION_TIME << '\n';
            return 0;
        }

        // clang-format off
        SETTING_OPTION(word, "-w")
        else SETTING_OPTION(frag, "-f")
        else SETTING_OPTION(sent, "-s")
        else SETTING_OPTION(para, "-p")
        else SETTING_OPTION(point, "-P")
        else SETTING_OPTION(wordURL, "-u")
        else SETTING_OPTION(wordFmt, "-W")
        else SETTING_OPTION(fragFmt, "-F")
        else SETTING_OPTION(level, "-l")
        else SETTING_OPTION(jsonLength, "-j")
        else if(OPTION_COND(source, "-S"))
        // clang-format on
        {
            size_t pos = option.find('=');
            if (pos != std::string::npos)
            {
                std::string value = option.substr(pos + 1);
                gen.load_source(value);
            }
            else
            {
                ErrorMessage("Error: must be in format --option=value\nGot: ",
                             option);
                return -1;
            }
        }
        else
        {
            ErrorMessage("Error: unknown option ", option, '\n');
            return -1;
        }
    }

    // no subcommand
    if (commandOpts.empty())
    {
        Help();
        return 0;
    }

    std::string subcommand = commandOpts.at(0);

    // clang-format off
    SINGLE_ARG_SUBCOMMAND(word, int, 1)
    else NO_ARG_SUBCOMMAND(fragment) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(sentence) 
    else NUM_AND_USELIPSUM_SUBCOMMAND(paragraph) 
    else SINGLE_ARG_SUBCOMMAND(text, bool, true) 
    else NO_ARG_SUBCOMMAND(url)
    else NO_ARG_SUBCOMMAND(plain_url) 
    else SINGLE_ARG_SUBCOMMAND(slug, int, '-') 
    else SINGLE_ARG_SUBCOMMAND(xml, int, 30)
    else DOUBLE_ARG_SUBCOMMAND(json, int, 3, bool, true)
    else DOUBLE_ARG_SUBCOMMAND(md_text, int, 15, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(md_header, int, 1, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(md_emphasis, bool, true, bool, false)
    else SINGLE_ARG_SUBCOMMAND(md_link, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(md_list, bool, false, bool, false)
    else if(subcommand == "md_paragraph")
    // clang-format on
    {
        int  num       = 1;
        bool useLipsum = true;
        bool useHtml   = false;
        GET_ARG(num, 2, int);
        GET_ARG(useLipsum, 3, bool);
        GET_ARG(useHtml, 4, bool);
        std::cout << gen.md_paragraph(num, useLipsum, useHtml);
    }
    else if (subcommand == "scramble")
    {
        int length  = 16;
        int minChar = static_cast<int>(' ');
        int maxChar = static_cast<int>('~');

        GET_ARG(length, 2, int);
        GET_ARG(minChar, 3, int);
        GET_ARG(maxChar, 4, int);

        if (!InCharRange(minChar) || !InCharRange(maxChar))
        {
            ErrorMessage("Error: number out of range of char. Please use "
                         "numbers between 0 and 127.\nGot minChar=",
                         minChar,
                         ", maxChar=",
                         maxChar,
                         '\n');
            return -1;
        }
        std::cout << gen.scramble(length,
                                  static_cast<char>(minChar),
                                  static_cast<char>(maxChar));
    }
    else if (subcommand == "help")
    {
        Help();
        return 0;
    }
    else
    {
        ErrorMessage("Error: unknown subcommand ", subcommand, '\n');
        return -1;
    }

    std::cout << '\n';

    return 0;
}

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif

#include <fstream>
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

#define SINGLE_ARG_SUBCOMMAND(name, type, defaultVal)                          \
    if (subcommand == #name)                                                   \
    {                                                                          \
        type argName = defaultVal;                                             \
        GET_ARG(argName, 2, type);                                             \
        (*ostr) << gen.name(argName);                                          \
    }
#define DOUBLE_ARG_SUBCOMMAND(name, type1, defaultVal1, type2, defaultVal2)    \
    if (subcommand == #name)                                                   \
    {                                                                          \
        type1 argName1 = defaultVal1;                                          \
        type2 argName2 = defaultVal2;                                          \
        GET_ARG(argName1, 2, type1);                                           \
        GET_ARG(argName2, 3, type2);                                           \
        (*ostr) << gen.name(argName1, argName2);                               \
    }

#define NO_ARG_SUBCOMMAND(name)                                                \
    if (subcommand == #name)                                                   \
    {                                                                          \
        (*ostr) << gen.name();                                                 \
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
        lpsm::internal::
                LogWarn(lpsm::internal::LogType::Error,
                        "invalid format of argument\nMust be in format: "
                        "<min>,<max>\nGot: ",
                        str);
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
        lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                "must be in format --option=value\nGot: ",
                                option);
    }
}

void Help(const std::string& page)
{
    // clang-format off
    if (page == "home")
    {
        std::cout << "Usage: lpsmcpp-cli <subcommand> [<arguments>] [<options>]\n\n";
        std::cout << "Options include:\n";
        std::cout << "  --help, -h - Show this help\n";
        std::cout << "  --version, -v - Show the current version of lipsum-cpp.\n";
        std::cout << "  --seed=<seed>, -E - Load specified seed.\n";
        std::cout << "  --output=<file>, -o - Output to the specified file.\n";
        std::cout << "  --source=<source>, -S - Load specified source.\n";
        std::cout << "      <source> may be a path to a file or a built-in source.\n";
        std::cout << "      Built in sources include: default/lorem, cat, dog/doggo, corpo/corporate.\n\n";
        std::cout << "  --word=<min,max>, -w - The min and max words per sentence fragment.\n";
        std::cout << "  --frag=<min,max>, -f - The min and max sentence fragments per sentence.\n";
        std::cout << "  --sent=<min,max>, -s - The min and max sentences per paragraph.\n";
        std::cout << "  --para=<min,max>, -p - The min and max paragraphs per text.\n";
        std::cout << "  --point=<min,max>, -P - The min and max points per list.\n";
        std::cout << "  --wordURL=<min,max>, -u - The min and max words in headings, in slugs, and at the end of URLs.\n";
        std::cout << "  --wordFmt=<min,max>, -W - The min and max words per formatted sentence fragment.\n";
        std::cout << "  --fragFmt=<min,max>, -F - The min and max sentence fragments per formatted sentence.\n";
        std::cout << "  --level=<min,max>, -l - The min and max levels of headings.\n";
        std::cout << "  --jsonLength=<min,max>, -j - The min and max amount of items in JSON objects.\n";
        std::cout << "  --csvRows=<min,max>, -R - The min and max number of rows in CSV documents.\n";
        std::cout << "  --csvCols=<min,max>, -C - The min and max number of columns in CSV documents.\n";
        std::cout << "Subcommands include:\n";
        std::cout << "  help, word, fragment, sentence, paragraph, text,\n";
        std::cout << "  url, plain_url, email, slug, scramble, case_slug, code, \n";
        std::cout << "  fmt_paragraph, fmt_text, fmt_header, fmt_emphasis, fmt_link, fmt_list, \n";
        std::cout << "  xml, json, json_value, csv\n\n";
        std::cout << "For more information, type lpsmcpp-cli help <subcommand>.\n";
    }
    if (page == "help")
    {
        std::cout << "  help <subcommand = 'main'> - Show this help.\n\n";
    }
    if (page == "word")
    {
        std::cout << "  word <num = 1> - Generate words.\n";
        std::cout << "    num - The number of words.\n\n";
    }
    if (page == "fragment")
    {
        std::cout << "  fragment - Generate a sentence fragment.\n\n";
    }
    if (page == "sentence")
    {
        std::cout << "  sentence <num = 1> <useLipsum = true> - Generate sentences.\n";
        std::cout << "    num - The number of sentences.\n";
        std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.\n\n";
    }
    if (page == "paragraph")
    {
        std::cout << "  paragraph <num = 1> <useLipsum = true> - Generate paragraphs.\n";
        std::cout << "    num - The number of paragraphs.\n";
        std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.\n\n";
    }
    if (page == "text")
    {
        std::cout << "  text <useLipsum = true> - Generate a text.\n";
        std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.\n\n";
    }
    if (page == "scramble")
    {
        std::cout << "  scramble <length = 16> <minChar = 32> <maxChar = 126> - Generate a character scramble.\n";
        std::cout << "    length - The number of characters.\n";
        std::cout << "    minChar - The lowest ASCII value possible.\n";
        std::cout << "    maxChar - The highest ASCII value possible.\n\n";
    }
    if (page == "url")
    {
        std::cout << "  url - Generate a URL.\n\n";
    }
    if (page == "plain_url")
    {
        std::cout << "  plain_url - Generate a plain URL.\n\n";
    }
    if (page == "email")
    {
        std::cout << "  email - Generate an email.\n";
    }
    if (page == "slug")
    {
        std::cout << "  slug <separator = '-'> - Generate a slug.\n";
        std::cout << "    separator - The separator to use.\n\n";
    }
    if (page == "case_slug")
    {
        std::cout << "  case_slug <case = 0> - Generate a case slug.\n";
        std::cout << "    case - The case to use.\n";
        std::cout << "      0 - camelCase, 1 - PascalCase, 2 - snake_case\n";
        std::cout << "      3 - SHOUTY_CASE, 4 - kebab-case, 5 - TRAIN-CASE\n\n";
    }
    if (page == "code")
    {
        std::cout << "  code <lang = 0> - Generate a code block.\n";
        std::cout << "    lang - The language to use.\n";
        std::cout << "      0 - C++, 1 - Python, 2 - Rust, 3 - C, 4 - JavaScript\n\n";
    }
    if (page == "fmt_paragraph")
    {
        std::cout << "  fmt_paragraph <num = 1> <useLipsum = true> <useHtml = false> - Generate Markdown or HTML paragraphs.\n";
        std::cout << "    num - The number of paragraphs.\n";
        std::cout << "    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "fmt_text")
    {
        std::cout << "  fmt_text <numElements = 15> <useHtml = false> - Generate a Markdown or HTML document.\n";
        std::cout << "    numElements - The number of elements.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "fmt_header")
    {
        std::cout << "  fmt_header <level = 1> <useHtml = false> - Generate a Markdown ot HTML header.\n";
        std::cout << "    level - The level of the heading.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "fmt_emphasis")
    {
        std::cout << "  fmt_emphasis <isBold = true> <useHtml = false> - Generate an emphasized Markdown or HTML sentence.\n";
        std::cout << "    isBold - Whether the sentence is bold or italic.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "fmt_link")
    {
        std::cout << "  fmt_link <useHtml = false> - Generate a Markdown or HTML link.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "fmt_list")
    {
        std::cout << "  fmt_list <ordered = false> <useHtml = false> - Generate a Markdown or HTML list.\n";
        std::cout << "    ordered - Whether the list is ordered.\n";
        std::cout << "    useHtml - Whether HTML should be outputted instead of Markdown.\n\n";
    }
    if (page == "xml")
    {
        std::cout << "  xml <choices = 30> - Generate an XML document.\n";
        std::cout << "    choices - The number of 'choices' to make.\n\n";
    }
    if (page == "json")
    {
        std::cout << "  json <maxDepth = 3> <isObject = true> - Generate a JSON object or array.\n";
        std::cout << "    maxDepth - The maximum recursion depth.\n";
        std::cout << "    isObject - Whether the output is an object or an array.\n\n";
    }
    if (page == "json_value")
    {
        std::cout << "  json_value <maxDepth = 3> - Generate a JSON value.\n";
        std::cout << "    maxDepth - The maximum recursion depth.\n\n";
    }
    if (page == "csv")
    {
        std::cout << "  csv - Generate a CSV document.\n\n";
    }
    // clang-format on
}

int main(int argc, char** argv)
{

    // lpsm::internal::LogWarn(lpsm::internal::LogType::Trace, "foo");
    // lpsm::internal::LogWarn(lpsm::internal::LogType::Info, "bar");
    // lpsm::internal::LogWarn(lpsm::internal::LogType::Warn, "baz");
    // lpsm::internal::LogWarn(lpsm::internal::LogType::Error, "qux");
    // lpsm::internal::LogWarn(lpsm::internal::LogType::Critical, "corge");
    if (argc < 2)
    {
        Help("home");
        return 0;
    }

    std::vector<std::string> options;
    std::vector<std::string> commandOpts;

    std::ostream* ostr = &std::cout;
    std::ofstream fileStream;

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
            Help("home");
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
        else SETTING_OPTION(csvRows, "-R")
        else SETTING_OPTION(csvCols, "-C")
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
                lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                        "must be in format "
                                        "--option=value\nGot: ",
                                        option);
                return -1;
            }
        }
        else if (OPTION_COND(seed, "-E"))
        {
            size_t pos = option.find('=');
            if (pos != std::string::npos)
            {
                std::string value = option.substr(pos + 1);
                int         seed  = lpsm::internal::ToType<int>(value);
                gen.load_seed(seed);
            }
            else
            {
                lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                        "must be in format "
                                        "--option=value\nGot: ",
                                        option);
            }
        }
        else if (OPTION_COND(output, "-o"))
        {

            size_t pos = option.find('=');
            if (pos != std::string::npos)
            {
                std::string value = option.substr(pos + 1);
                fileStream.open(value);
                ostr = &fileStream;
            }
            else
            {
                lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                        "must be in format "
                                        "--option=value\nGot: ",
                                        option);
                return -1;
            }
        }
        else
        {
            lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                    "unknown option ",
                                    option);
            return -1;
        }
    }

    // no subcommand
    if (commandOpts.empty())
    {
        Help("home");
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
    else NO_ARG_SUBCOMMAND(email)
    else SINGLE_ARG_SUBCOMMAND(xml, int, 30)
    else SINGLE_ARG_SUBCOMMAND(json_value, int, 3)
    else DOUBLE_ARG_SUBCOMMAND(json, int, 3, bool, true)
    else DOUBLE_ARG_SUBCOMMAND(fmt_text, int, 15, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(fmt_header, int, 1, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(fmt_emphasis, bool, true, bool, false)
    else SINGLE_ARG_SUBCOMMAND(fmt_link, bool, false)
    else DOUBLE_ARG_SUBCOMMAND(fmt_list, bool, false, bool, false)
    else NO_ARG_SUBCOMMAND(csv)
    else if(subcommand == "fmt_paragraph")
    // clang-format on
    {
        int  num       = 1;
        bool useLipsum = true;
        bool useHtml   = false;
        GET_ARG(num, 2, int);
        GET_ARG(useLipsum, 3, bool);
        GET_ARG(useHtml, 4, bool);
        (*ostr) << gen.fmt_paragraph(num, useLipsum, useHtml);
    }
    else if (subcommand == "slug")
    {
        int separator = static_cast<int>('-');
        GET_ARG(separator, 2, int);
        if (!InCharRange(separator))
        {
            lpsm::internal::
                    LogWarn(lpsm::internal::LogType::Error,
                            "number out of range of char. Please use"
                            " numbers between 0 and 127.\nGot separator=",
                            separator);
        }
        (*ostr) << gen.slug(static_cast<char>(separator));
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
            lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                    "number out of range of char. Please use "
                                    "numbers between 0 and 127.\nGot minChar=",
                                    minChar,
                                    ", maxChar=",
                                    maxChar);
            return -1;
        }
        (*ostr) << gen.scramble(length,
                                static_cast<char>(minChar),
                                static_cast<char>(maxChar));
    }
    else if (subcommand == "case_slug")
    {
        int case_ = 0;
        GET_ARG(case_, 2, int);
        if (case_ < 0 || case_ > 5)
        {
            lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                    "case slug out of range. Please use number "
                                    "between 0 and 5.\nGot case_=",
                                    case_);
        }
        (*ostr) << gen.case_slug(static_cast<lpsm::CaseSlugCase>(case_));
    }
    else if (subcommand == "code")
    {
        int lang = 0;
        GET_ARG(lang, 2, int);
        if (lang < 0 || lang > 4)
        {
            lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                    "language chosen out of range. Please use "
                                    "number between 0 and 4.\nGot lang=",
                                    lang);
        }
        (*ostr) << gen.code(static_cast<lpsm::CodeLanguage>(lang));
    }
    else if (subcommand == "help")
    {
        std::string page = "home";
        GET_ARG(page, 2, std::string);
        Help(page);
        return 0;
    }
    else
    {
        lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                "unknown subcommand ",
                                subcommand);
        return -1;
    }

    (*ostr) << '\n';
    std::cout << '\n';

    return 0;
}

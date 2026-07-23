#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif

#include <limits>
#include <lipsum.hpp>

constexpr bool InCharRange(int num)
{
    return (num >= std::numeric_limits<char>::min()) &&
           (num <= std::numeric_limits<char>::max());
}

int main()
{
    auto askBool = [](bool& val, const std::string& msg)
    {
        std::cout << msg << " (Y,n)\n>>> ";
        std::string temp;
        std::cin >> temp;
        if (!temp.empty() && (temp.at(0) == 'n' || temp.at(0) == 'N'))
        {
            val = false;
        }
        else
        {
            val = true;
        }
    };
    lpsm::Generator gen;
    bool            doSettings;

    std::cout << "lipsum-cpp version " << LIPSUM_CPP_VERSION_FULL << '\n';
    std::cout << "Version info last modified " << LIPSUM_CPP_VERSION_TIME
              << '\n';
    askBool(doSettings, "Choose settings or skip to generation?");
    if (doSettings)
    {
        std::vector<std::string> options = {"word",
                                            "frag",
                                            "sent",
                                            "para",
                                            "point",
                                            "wordURL",
                                            "wordFmt",
                                            "fragFmt",
                                            "level",
                                            "jsonLength",
                                            "csvRows",
                                            "csvCols"};
        std::cout << "What source to use?\n";
        std::cout << "    default, lorem\n";
        std::cout << "    cat\n";
        std::cout << "    dog, doggo\n";
        std::cout << "    corpo, corporate\n";
        std::cout << "    ...your own file\n>>> ";
        std::string choice;
        std::cin >> choice;
        gen.load_source(choice);

        std::cout << "What seed to use? (N for random)\n>>> ";
        std::string seedStr;
        std::cin >> seedStr;

        if (!(!seedStr.empty() &&
              (seedStr.at(0) == 'N' || seedStr.at(0) == 'n')))
        {
            gen.load_seed(lpsm::internal::ToType<int>(seedStr));
        }

        while (true)
        {
            std::cout << "What options to change?\n";
            std::cout << "    0. Quit changing options\n";
            std::cout << "    1. Words per sentence fragment\n";
            std::cout << "    2. Sentence fragments per sentence\n";
            std::cout << "    3. Sentences per paragraph\n";
            std::cout << "    4. Paragraphs per text\n";
            std::cout << "    5. Number of points per list\n";
            std::cout << "    6. Number of words at the end of URLs, in slugs, "
                         "etc.\n";
            std::cout << "    7. Number of words per sentence fragment in "
                         "formatted sentences\n";
            std::cout << "    8. Number of sentence fragments per formatted "
                         "sentences\n";
            std::cout << "    9. Level of headings\n";
            std::cout << "    10. Number of items per object in JSON\n";
            std::cout << "    11. Number of rows in CSV\n";
            std::cout << "    12. Number of columns in CSV\n";
            std::cout << ">>> ";
            int optIdx;
            std::cin >> optIdx;
            if (optIdx < 0 || optIdx > 12)
            {
                lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                        "invalid option ",
                                        optIdx,
                                        ": expected between 0 and 12.");
            }
            else
            {
                if (optIdx == 0)
                {
                    break;
                }
                int minOpt;
                int maxOpt;
                std::cout << "Enter minimum value...\n>>> ";
                std::cin >> minOpt;
                std::cout << "Enter maximum value...\n>>> ";
                std::cin >> maxOpt;

                gen.change_setting(options.at(optIdx - 1), minOpt, maxOpt);
            }
        }
    }

    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "Choose an operation...\n";
        std::cout << "    0. Quit\n";
        std::cout << "    1. Generate words.\n";
        std::cout << "    2. Generate a sentence fragment.\n";
        std::cout << "    3. Generate sentences.\n";
        std::cout << "    4. Generate paragraphs.\n";
        std::cout << "    5. Generate a text.\n";
        std::cout << "    6. Generate a URL.\n";
        std::cout << "    7. Generate a plain URL.\n";
        std::cout << "    8. Generate an email.\n";
        std::cout << "    9. Generate a slug.\n";
        std::cout << "    10. Generate a character scramble.\n";
        std::cout << "    11. Generate a case slug.\n";
        std::cout << "    12. Generate a code block.\n";
        std::cout << "    13. Generate an IP address.\n";
        std::cout << "    14. Generate a phone number.\n";
        std::cout << "    15. Generate formatted paragraphs.\n";
        std::cout << "    16. Generate a formatted document.\n";
        std::cout << "    17. Generate a formatted header.\n";
        std::cout << "    18. Generate a formatted sentence.\n";
        std::cout << "    19. Generate a formatted link.\n";
        std::cout << "    20. Generate a formatted list.\n";
        std::cout << "    21. Generate an XML document.\n";
        std::cout << "    22. Generate a JSON array or object.\n";
        std::cout << "    23. Generate a JSON value.\n";
        std::cout << "    24. Generate a CSV document.\n";
        std::cout << ">>> ";

        int  subcommand;
        int  num;
        bool useLipsum;
        bool useHtml;
        std::cin >> subcommand;

        auto askNum = [&]()
        {
            std::cout << "How many?\n>>> ";
            std::cin >> num;
        };

        switch (subcommand)
        {
            case 0:
            {
                isRunning = false;
                continue;
                break;
            }
            case 1:
            {
                askNum();
                std::cout << gen.word(num);
                break;
            }
            case 2:
            {
                std::cout << gen.fragment();
                break;
            }
            case 3:
            {
                askNum();
                askBool(useLipsum, "Start with \"Lorem ipsum...\"?");
                std::cout << gen.sentence(num, useLipsum);
                break;
            }
            case 4:
            {
                askNum();
                askBool(useLipsum, "Start with \"Lorem ipsum...\"?");
                std::cout << gen.paragraph(num, useLipsum);
                break;
            }
            case 5:
            {
                askBool(useLipsum, "Start with \"Lorem ipsum...\"?");
                std::cout << gen.text(useLipsum);
                break;
            }
            case 6:
            {
                std::cout << gen.url();
                break;
            }
            case 7:
            {
                std::cout << gen.plain_url();
                break;
            }
            case 8:
            {
                std::cout << gen.email();
                break;
            }
            case 9:
            {
                std::cout << "What character? (ASCII value)\n>>> ";
                std::cin >> num;
                if (!InCharRange(num))
                {
                    lpsm::internal::
                            LogWarn(lpsm::internal::LogType::Error,
                                    "number out of range of char. Please "
                                    "use numbers between "
                                    "0 and 127.\nGot num=",
                                    num);
                }
                std::cout << gen.slug(static_cast<char>(num));
                break;
            }
            case 10:
            {
                int minChar;
                int maxChar;
                std::cout << "How many characters?\n>>> ";
                std::cin >> num;
                std::cout << "What minimum character? (ASCII value)\n>>> ";
                std::cin >> minChar;
                std::cout << "What maximum character? (ASCII value)\n>>> ";
                std::cin >> maxChar;
                if (!InCharRange(minChar) || !InCharRange(maxChar))
                {
                    lpsm::internal::
                            LogWarn(lpsm::internal::LogType::Error,
                                    "number out of range of char. Please "
                                    "use numbers between "
                                    "0 and 127.\nGot minChar=",
                                    minChar,
                                    ", maxChar=",
                                    maxChar);
                }
                std::cout << gen.scramble(num,
                                          static_cast<char>(minChar),
                                          static_cast<char>(maxChar));
                break;
            }
            case 11:
            {
                std::cout << "What case?\n";
                std::cout << "    0 - camelCase\n";
                std::cout << "    1 - PascalCase\n";
                std::cout << "    2 - snake_case\n";
                std::cout << "    3 - SHOUTY_CASE\n";
                std::cout << "    4 - kebab-case\n";
                std::cout << "    5 - TRAIN-CASE\n>>> ";
                std::cin >> num;
                if (num < 0 || num > 5)
                {
                    lpsm::internal::
                            LogWarn(lpsm::internal::LogType::Error,
                                    "case slug out of range. Please use number "
                                    "between 0 and 5.\nGot num=",
                                    num);
                }
                std::cout << gen.case_slug(
                        static_cast<lpsm::CaseSlugCase>(num));
                break;
            }
            case 12:
            {
                std::cout << "What language?\n";
                std::cout << "    0 - C++\n";
                std::cout << "    1 - Python\n";
                std::cout << "    2 - Rust\n";
                std::cout << "    3 - C\n";
                std::cout << "    4 - JavaScript\n>>> ";
                std::cin >> num;
                if (num < 0 || num > 4)
                {
                    lpsm::internal::
                            LogWarn(lpsm::internal::LogType::Error,
                                    "language chosen out of range. Please use "
                                    "number between 0 and 4.\nGot num=",
                                    num);
                }
                std::cout << gen.code(static_cast<lpsm::CodeLanguage>(num));
                break;
            }
            case 13:
            {
                askBool(useLipsum, "Use IPv6 (Y) or IPv4 (n)?");
                askBool(useHtml, "Add a port?");
                std::cout << gen.ip_addr(useLipsum, useHtml);
                break;
            }
            case 14:
            {
                std::cout << gen.phone_number();
                break;
            }
            case 15:
            {
                askNum();
                askBool(useLipsum, "Start with \"Lorem ipsum...\"?");
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_paragraph(num, useLipsum, useHtml);
                break;
            }
            case 16:
            {
                std::cout << "How many elements?\n>>> ";
                std::cin >> num;
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_text(num, useHtml);
                break;
            }
            case 17:
            {
                std::cout << "What header level? (1-6)\n>>> ";
                std::cin >> num;
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_header(num, useHtml);
                break;
            }
            case 18:
            {
                askBool(useLipsum, "Is the sentence bold?");
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_emphasis(useLipsum, useHtml);
                break;
            }
            case 19:
            {
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_link(useHtml);
                break;
            }
            case 20:
            {
                askBool(useLipsum, "Is the list ordered?");
                askBool(useHtml, "Use HTML (Y) or Markdown (n)?");
                std::cout << gen.fmt_list(useLipsum, useHtml);
                break;
            }
            case 21:
            {
                std::cout << "How many \"choices\"?\n>>> ";
                std::cin >> num;
                std::cout << gen.xml(num);
                break;
            }
            case 22:
            {
                std::cout << "How many maximum recursions?\n>>> ";
                std::cin >> num;
                askBool(useLipsum, "Is it an object (Y) or array (n)?");
                std::cout << gen.json(num, useLipsum);
                break;
            }
            case 23:
            {
                std::cout << "How many maximum recursions?\n>>> ";
                std::cin >> num;
                std::cout << gen.json_value(num);
                break;
            }
            case 24:
            {
                std::cout << gen.csv();
                break;
            }
            default:
            {
                lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                        "invalid subcommand ",
                                        subcommand,
                                        ": expected between 1 and 22.");
                break;
            }
        }
        std::cout << '\n';
    }
    return 0;
}

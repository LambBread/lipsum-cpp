#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif

#include <lipsum.hpp>

int main()
{
    lpsm::Generator gen;

    std::cout << "lipsum-cpp version " << LIPSUM_CPP_VERSION_FULL << '\n';
    std::cout << "Version info last modified " << LIPSUM_CPP_VERSION_TIME
              << '\n';

    std::cout << "Choose an operation...\n";
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
    std::cout << "    13. Generate formatted paragraphs.\n";
    std::cout << "    14. Generate a formatted document.\n";
    std::cout << "    15. Generate a formatted header.\n";
    std::cout << "    16. Generate a formatted sentence.\n";
    std::cout << "    17. Generate a formatted link.\n";
    std::cout << "    18. Generate a formatted list.\n";
    std::cout << "    19. Generate an XML document.\n";
    std::cout << "    20. Generate a JSON array or object.\n";
    std::cout << "    21. Generate a JSON value.\n";
    std::cout << "    22. Generate a CSV document.\n";
    std::cout << ">>> ";
    int subcommand;
    std::cin >> subcommand;
    switch (subcommand)
    {
        case 1:
        {
            std::cout << gen.word();
            break;
        }
        case 2:
        {
            std::cout << gen.fragment();
            break;
        }
        case 3:
        {
            std::cout << gen.sentence();
            break;
        }
        case 4:
        {
            std::cout << gen.paragraph();
            break;
        }
        case 5:
        {
            std::cout << gen.text();
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
            std::cout << gen.slug();
            break;
        }
        case 10:
        {
            std::cout << gen.scramble();
            break;
        }
        case 11:
        {
            std::cout << gen.case_slug();
            break;
        }
        case 12:
        {
            std::cout << gen.code();
            break;
        }
        case 13:
        {
            std::cout << gen.fmt_paragraph();
            break;
        }
        case 14:
        {
            std::cout << gen.fmt_text();
            break;
        }
        case 15:
        {
            std::cout << gen.fmt_header();
            break;
        }
        case 16:
        {
            std::cout << gen.fmt_emphasis();
            break;
        }
        case 17:
        {
            std::cout << gen.fmt_link();
            break;
        }
        case 18:
        {
            std::cout << gen.fmt_list();
            break;
        }
        case 19:
        {
            std::cout << gen.xml();
            break;
        }
        case 20:
        {
            std::cout << gen.json();
            break;
        }
        case 21:
        {
            std::cout << gen.json_value();
            break;
        }
        case 22:
        {
            std::cout << gen.csv();
            break;
        }
        default:
        {
            lpsm::internal::LogWarn(lpsm::internal::LogType::Error,
                                    "Invalid subcommand ",
                                    subcommand,
                                    " expected between 1 and 22.");
            break;
        }
    }
    std::cout << '\n';
    return 0;
}

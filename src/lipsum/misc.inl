
/**
 * @file lipsum/misc.inl
 *
 * @brief Miscellaneous functions of lipsum-cpp
 *
 * This defines miscellaneous functions in lipsum-cpp,
 * such as CountSentences() and deprecated HTMLify(). This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
int lpsm::CountSentences(const std::string& str)
{
    int res    = 0;
    int urlNum = 0;
    for (const char& c : str)
    {
        if (c == '(')
        {
            ++urlNum;
        }
        if (c == ')')
        {
            --urlNum;
        }
        if (c == '.' && urlNum == 0)
        {
            ++res;
        }
    }
    return res;
}

std::string lpsm::HTMLify(const char* str)
{
    return lpsm::HTMLify(std::string(str));
}

std::string lpsm::HTMLify(const std::string& str)
{
    std::stringstream ss(str);
    std::string       line;
    std::string       result;
    while (std::getline(ss, line))
    {
        if (!line.empty())
        {
            result += std::string("<p>") +=
                    lpsm::internal::HandleHTMLEntity(line) +=
                    std::string("</p>\n");
        }
    }
    return result;
}

std::string lpsm::LipsumVersion()
{
    return std::string(LIPSUM_CPP_VERSION);
}

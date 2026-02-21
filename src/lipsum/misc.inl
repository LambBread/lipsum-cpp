
/**
 * @file lipsum/misc.inl
 *
 * @brief Miscellaneous functions of lipsum-cpp
 *
 * This defines miscellaneous functions in lipsum-cpp,
 * such as CountSentences(). This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

int lpsm::CountWords(const std::string& str)
{
    std::stringstream ss(str);
    int               count = 0;
    std::string       tmp;
    while (ss >> tmp)
    {
        ++count;
    }
    return count;
}

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

std::string lpsm::LipsumVersion()
{
    return std::string(LIPSUM_CPP_VERSION);
}

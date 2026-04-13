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

#ifndef LIPSUM_MISC_INL
#    define LIPSUM_MISC_INL

namespace lipsum
{

    int CountWords(const std::string& str)
    {
        std::istringstream iss(str);
        int                count = 0;
        std::string        tmp;
        while (iss >> tmp)
        {
            ++count;
        }
        return count;
    }

    int CountSentences(const std::string& str)
    {
        int res    = 0;
        int urlNum = 0;
        for (const char& letter : str)
        {
            if (letter == '(')
            {
                ++urlNum;
            }
            if (letter == ')')
            {
                --urlNum;
            }
            if (letter == '.' && urlNum == 0)
            {
                ++res;
            }
        }
        return res;
    }

} // namespace lipsum
#endif

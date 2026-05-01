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

#    include "core/internal.hpp"
#    include "core_funcs.hpp"

namespace lipsum
{

    /*
     * MISC
     * ----------------
     */

    std::string GenerateDefaultLipsumSentence()
    {
        return {"Lorem ipsum dolor sit amet, consectetur adipiscing elit."};
    }

    std::string GenerateScramble(int length, char min, char max)
    {
        std::string ret;
        if (length < 0)
        {
            internal::LogWarn("lpsm::GenerateScramble(): expected length >= 0, "
                              "got ",
                              length);
        }
        for (int i = 0; i < length; ++i)
        {
            ret.push_back(internal::RandomNumber<char>(min, max));
        }
        return ret;
    }

    std::string GeneratePlainURL(const Source& source)
    {
        return std::string("lpsmcpp-") + GenerateWord(source) +
               internal::GenerateTLD();
    }

    std::string GenerateURL(const ArgVec2& word, const Source& source)
    {
        return std::string("https://") + GeneratePlainURL(source) +
               std::string("/#") + GenerateSlug(word, '-', source);
    }

    std::string
    GenerateSlug(const ArgVec2& word, char separator, const Source& source)
    {
        std::string ret = GenerateSentenceFragment(word, source);
        std::replace(ret.begin(), ret.end(), ' ', separator);
        return ret;
    }

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

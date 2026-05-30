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

static int
LipsumMiscInlFind(int count, const std::string& str, const std::string& check)
{
    size_t pos = 0;
    while ((pos = str.find(check, pos)) != std::string::npos)
    {
        ++count;
        pos += check.size();
    }
    return count;
}

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

    int CountWords(const std::string& str)
    {
        int  count      = 0;
        int  urlNum     = 0;
        bool inWord     = false;
        char lastLetter = '\0';
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

            bool isWordChar =
                    static_cast<bool>(
                            std::isalnum(static_cast<unsigned char>(letter))) ||
                    (letter == '-' && lastLetter != '\n' &&
                     lastLetter != ' ') ||
                    (letter == '+' && lastLetter != '\n' &&
                     lastLetter != ' ') ||
                    (letter == '\'' && lastLetter != '\n' && lastLetter != ' ');
            // if not in parens
            if (urlNum <= 0)
            {
                if (isWordChar && !inWord)
                {
                    inWord = true;
                    ++count;
                }
                if (!isWordChar)
                {
                    inWord = false;
                }
            }

            lastLetter = letter;
        }
        return count;
    }

    int CountSentenceFragments(const std::string& str)
    {
        if (str.empty())
        {
            return 0;
        }
        int  res        = 0;
        int  urlNum     = 0;
        char lastLetter = '\0';
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

            // if not in parens
            if (urlNum <= 0)
            {
                if (letter == ',')
                {
                    ++res;
                }
                if (letter == ';')
                {
                    ++res;
                }
                if (letter == '.')
                {
                    ++res;
                }
                if (letter == '-' && lastLetter != '\n')
                {
                    ++res;
                }
            }
            lastLetter = letter;
        }
        return res;
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
            if (letter == '.' && urlNum <= 0)
            {
                ++res;
            }
        }
        return res;
    }

    int CountParagraphs(const std::string& str, int format)
    {
        switch (format)
        {
            case 0:
            {
                return std::count(str.begin(), str.end(), '\t');
            }
            case 1:
            {
                int count = LipsumMiscInlFind(0, str, "\n\n");
                return count;
            }
            case 2:
            {
                int count = LipsumMiscInlFind(0, str, "<p>");
                count     = LipsumMiscInlFind(count, str, "<ol>");
                count     = LipsumMiscInlFind(count, str, "<ul>");
                count     = LipsumMiscInlFind(count, str, "<h1>");
                count     = LipsumMiscInlFind(count, str, "<h2>");
                count     = LipsumMiscInlFind(count, str, "<h3>");
                count     = LipsumMiscInlFind(count, str, "<h4>");
                count     = LipsumMiscInlFind(count, str, "<h5>");
                count     = LipsumMiscInlFind(count, str, "<h6>");
                return count;
            }
            default:
            {
                internal::LogWarn("lpsm::CountParagraphs(): unknown format ",
                                  format);
                return 0;
            }
        }
    }

} // namespace lipsum
#endif

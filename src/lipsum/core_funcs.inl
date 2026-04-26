/**
 * @file lipsum/core_funcs.inl
 *
 * @brief Core functions of lipsum-cpp
 *
 * This defines core functions in lipsum-cpp around generation of words,
 * sentences, paragraphs, etc. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_FUNCS_INL
#    define LIPSUM_CORE_FUNCS_INL

#    include "core/internal.hpp"
#    include "misc.hpp"

namespace lipsum
{
    /*
     * BULK
     * ----------------
     */

    std::string GenerateWords(int wordCount, const Source& source)
    {
        std::string ret;

        if (wordCount < 0)
        {
            internal::LogWarn("lpsm::GenerateWords(): expected wordCount >= 0, "
                              "got ",
                              wordCount);
        }

        for (int i = 0; i < wordCount; ++i)
        {
            ret += GenerateWord(source) += " ";
        }
        ret.pop_back();
        return ret;
    }

    std::string GenerateSentences(int            sentCount,
                                  const ArgVec2& word,
                                  const ArgVec2& frag,
                                  bool           useLipsum,
                                  const Source&  source)
    {
        std::string result;

        if (sentCount < 0)
        {
            internal::LogWarn("lpsm::GenerateSentences(): expected sentCount "
                              ">= 0, got",
                              sentCount);
        }

        for (int i = 0; i < sentCount; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateDefaultLipsumSentence() + " ";
            }
            else
            {
                result += GenerateSentence(word, frag, source) += " ";
            }
        }
        return result;
    }

    std::string GenerateParagraphs(int            paraCount,
                                   const ArgVec2& word,
                                   const ArgVec2& frag,
                                   const ArgVec2& sent,
                                   bool           useLipsum,
                                   const Source&  source)
    {
        std::string result;

        if (paraCount < 0)
        {
            internal::LogWarn("lpsm::GenerateParagraphs(): expected paraCount "
                              ">= 0, got ",
                              paraCount);
        }

        for (int i = 0; i < paraCount; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateParagraph(word, frag, sent, true, source);
            }
            else
            {
                result += GenerateParagraph(word, frag, sent, false, source);
            }
        }
        return result;
    }

    /*
     * CORE
     * ----------------
     */

    std::string GenerateWord(const Source& source)
    {
        return source.random_word();
    }

    std::string GenerateSentenceFragment(const ArgVec2& word,
                                         const Source&  source)
    {
        std::string result;
        int         numWords = word.roll();
        for (int i = 0; i < numWords; ++i)
        {
            result += GenerateWord(source) += " ";
        }
        result.pop_back(); // remove trailing space
        return result;
    }

    std::string GenerateSentence(const ArgVec2& word,
                                 const ArgVec2& frag,
                                 const Source&  source)
    {
        constexpr int CHANCE_COMMA = 88;
        constexpr int CHANCE_SEMI  = 9;
        std::string   result;
        int           frags = frag.roll();
        for (int i = 0; i < frags; ++i)
        {
            result += GenerateSentenceFragment(word, source);
            int check = internal::RandomNumber<int>(0, 99);
            // don't do if only one fragment
            if (i != frags - 1)
            {
                // 9% chance
                if (check < CHANCE_SEMI)
                {
                    result += "; ";
                }
                // 88% chance
                else if (check < CHANCE_SEMI + CHANCE_COMMA)
                {
                    result += ", ";
                }
                // 3% chance
                else
                {
                    result += " - ";
                }
            }
        }
        result += ".";
        result.at(0) = static_cast<char>(
                std::toupper(static_cast<unsigned char>(result.at(0))));
        return result;
    }

    std::string GenerateParagraph(const ArgVec2& word,
                                  const ArgVec2& frag,
                                  const ArgVec2& sent,
                                  bool           useLipsum,
                                  const Source&  source)
    {
        std::string result = "\t";
        int         sents  = sent.roll();
        for (int i = 0; i < sents; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateDefaultLipsumSentence() += " ";
            }
            else
            {
                result += GenerateSentence(word, frag, source) += " ";
            }
        }

        // remove trailing space
        result.pop_back();
        result += "\n";
        return result;
    }

    std::string GenerateText(const ArgVec2& word,
                             const ArgVec2& frag,
                             const ArgVec2& sent,
                             const ArgVec2& para,
                             bool           useLipsum,
                             const Source&  source)
    {
        std::string ret;
        int         paras = para.roll();
        for (int i = 0; i < paras; ++i)
        {
            if (i == 0 && useLipsum)
            {
                ret += GenerateParagraph(word, frag, sent, true, source);
            }
            else
            {
                ret += GenerateParagraph(word, frag, sent, false, source);
            }
            ret += "\n";
        }
        return ret;
    }
} // namespace lipsum
#endif

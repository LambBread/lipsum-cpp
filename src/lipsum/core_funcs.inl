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

// #include "sample.inl"

namespace lipsum
{

    std::string GeneratePlainURL()
    {
        return std::string("lpsmcpp-") + GenerateWord() +
               internal::GenerateTLD();
    }

    std::string GenerateScramble(int length, char min, char max)
    {
        std::string ret;
        for (int i = 0; i < length; ++i)
        {
            ret.push_back(internal::RandomNumber<char>(min, max));
        }
        return ret;
    }

    std::string GenerateURL(const ArgVec2& word)
    {
        return std::string("https://") + GeneratePlainURL() +
               std::string("/#") + GenerateSlug(word, '-');
    }

    std::string GenerateSlug(const ArgVec2& word, char separator)
    {
        std::string ret = GenerateSentenceFragment(word);
        std::replace(ret.begin(), ret.end(), ' ', separator);
        return ret;
    }

    std::string GenerateWords(int wordCount)
    {
        std::string ret;
        for (int i = 0; i < wordCount; ++i)
        {
            ret += GenerateWord() += " ";
        }
        ret.pop_back();
        return ret;
    }

    std::string GenerateSentences(int            sentCount,
                                  const ArgVec2& word,
                                  const ArgVec2& frag,
                                  bool           useLipsum)
    {
        std::string result;
        if (useLipsum)
        {
            result += GenerateDefaultLipsumSentence() += " ";
            for (int i = 0; i < sentCount - 1; ++i)
            {
                result += GenerateSentence(word, frag) += " ";
            }
        }
        else
        {
            for (int i = 0; i < sentCount; ++i)
            {
                result += GenerateSentence(word, frag) += " ";
            }
        }
        return result;
    }

    std::string GenerateDefaultLipsumSentence()
    {
        return std::string(
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    std::string GenerateWord(const Source& source)
    {
        // int randomIdx = internal::RandomNumber<int>(0, LIPSUM_VEC.size() -
        // 1); return std::string(LIPSUM_VEC.at(randomIdx));
        return source.RandomWord();
    }

    std::string GenerateSentenceFragment(const ArgVec2& word)
    {
        std::string result;
        int         numWords = word.Roll();
        for (int i = 0; i < numWords; ++i)
        {
            result += GenerateWord() += " ";
        }
        result.pop_back(); // remove trailing space
        return result;
    }

    std::string GenerateSentence(const ArgVec2& word, const ArgVec2& frag)
    {
        constexpr int CHANCE_COMMA = 88;
        constexpr int CHANCE_SEMI  = 9;
        std::string   result;
        int           words = word.Roll();
        int           frags = frag.Roll();
        for (int i = 0; i < frags; ++i)
        {
            result += GenerateSentenceFragment(word);
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
                                  bool           useLipsum)
    {
        std::string result = "\t";
        int         sents  = sent.Roll();
        if (!useLipsum)
        {
            for (int i = 0; i < sents; ++i)
            {
                result += GenerateSentence(word, frag) += " ";
            }
        }
        else
        {
            result += GenerateDefaultLipsumSentence() += " ";
            for (int i = 0; i < sents - 1; ++i)
            {
                result += GenerateSentence(word, frag) += " ";
            }
        }
        // remove trailing space
        result.pop_back();
        result += "\n";
        return result;
    }

    std::string GenerateParagraphs(int            paraCount,
                                   const ArgVec2& word,
                                   const ArgVec2& frag,
                                   const ArgVec2& sent,
                                   bool           useLipsum)
    {
        std::string result;
        if (!useLipsum)
        {

            for (int i = 0; i < paraCount; ++i)
            {
                result += GenerateParagraph(word, frag, sent, false);
            }
        }
        else
        {
            result += GenerateParagraph(word, frag, sent, true);
            for (int i = 0; i < paraCount - 1; ++i)
            {
                result += GenerateParagraph(word, frag, sent, false);
            }
        }
        return result;
    }

    std::string GenerateText(const ArgVec2& word,
                             const ArgVec2& frag,
                             const ArgVec2& sent,
                             const ArgVec2& para,
                             bool           useLipsum)
    {
        std::string ret;
        int         paras = para.Roll();
        for (int i = 0; i < paras; ++i)
        {
            if (i == 0 && useLipsum)
            {
                ret += GenerateParagraph(word, frag, sent, true);
            }
            else
            {
                ret += GenerateParagraph(word, frag, sent, false);
            }
            ret += "\n";
        }
        return ret;
    }
} // namespace lipsum

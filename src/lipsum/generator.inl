/**
 * @file lipsum/generator.inl
 *
 * @brief Definition of lipsum::Generator
 *
 * This defines the functions in lipsum::Generator. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_GENERATOR_INL
#    define LIPSUM_GENERATOR_INL

#    include "core/internal.hpp"
#    include "generatorcore.inl"
#    include "generatorformats.inl"

static std::string ClearApostrAndCh(char letter, const std::string& str)
{
    std::string ret;
    ret.reserve(str.size());
    for (const char& let : str)
    {
        if (let != '\'' && let != letter)
        {
            ret.push_back(let);
        }
    }
    return ret;
}

static std::string
ClearApostrAndCh(char let1, char let2, const std::string& str)
{
    std::string ret;
    ret.reserve(str.size());
    for (const char& let : str)
    {
        if (let != '\'' && let != let1 && let != let2)
        {
            ret.push_back(let);
        }
    }
    return ret;
}

static std::string CapitalizeStr(const std::string& str)
{
    std::string ret = str;
    for (auto& letter : ret)
    {
        letter = LPSM_SAFE_CCTYPE(char, std::toupper, letter);
    }
    return ret;
}

namespace lipsum
{

    /*
     * CORE
     */

    std::string Generator::word(int num)
    {

        std::string ret;

        if (num < 0)
        {
            internal::LogWarn("lpsm::Generator::word(): expected num >= 0, "
                              "got ",
                              num);
        }

        for (int i = 0; i < num; ++i)
        {
            ret += m_Source.random_word(m_Gen) += " ";
        }

        if (!ret.empty())
        {
            ret.pop_back();
        }
        return ret;
    }

    std::string Generator::fragment()
    {
        int numWords = m_Settings.word.roll(m_Gen);
        return word(numWords);
    }

    std::string Generator::sentence(int num, bool useLipsum)
    {
        std::string result;

        if (num < 0)
        {
            internal::LogWarn("lpsm::Generator::sentence(): expected num "
                              ">= 0, got ",
                              num);
        }

        for (int i = 0; i < num; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateDefaultLipsumSentence() + " ";
            }
            else
            {
                result += single_sentence(m_Settings.word, m_Settings.frag) +=
                        " ";
            }
        }
        return result;
    }

    std::string Generator::paragraph(int num, bool useLipsum)
    {
        std::string result;

        if (num < 0)
        {
            internal::LogWarn("lpsm::Generator::paragraph(): expected num "
                              ">= 0, got ",
                              num);
        }

        for (int i = 0; i < num; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += single_paragraph(USELIPSUM);
            }
            else
            {
                result += single_paragraph(NO_USELIPSUM);
            }
        }
        return result;
    }

    std::string Generator::text(bool useLipsum)
    {
        int num = m_Settings.para.roll(m_Gen);
        return paragraph(num, useLipsum);
    }

    /*
     * MISC
     */

    std::string Generator::scramble(int length, char minChar, char maxChar)
    {
        std::string ret;
        if (length < 0)
        {
            internal::LogWarn("lpsm::Generator::scramble(): expected length >= "
                              "0, "
                              "got ",
                              length);
        }
        else
        {
            ret.reserve(length);
        }
        for (int i = 0; i < length; ++i)
        {
            ret.push_back(random_number(minChar, maxChar));
        }
        return ret;
    }

    std::string Generator::url()
    {
        return std::string("https://") + plain_url() + std::string("/#") +
               slug('-');
    }

    std::string Generator::plain_url()
    {
        return std::string("lpsmcpp-") + m_Source.random_word(m_Gen) + tld();
    }

    std::string Generator::email()
    {
        return m_Source.random_word(m_Gen) + std::string(".") +
               m_Source.random_word(m_Gen) + std::string("@") + plain_url();
    }

    std::string Generator::slug(char separator)
    {
        std::string result;
        int         numWords = m_Settings.wordURL.roll(m_Gen);
        result               = word(numWords);
        std::replace(result.begin(), result.end(), ' ', separator);
        return result;
    }

    std::string Generator::case_slug(CaseSlugCase case_)
    {
        std::string ret;
        std::string innerWord;
        int         numWords = -2;
        switch (case_)
        {
            case CaseSlugCase::CamelCase:
            {
                numWords = m_Settings.wordURL.roll(m_Gen);
                ret += m_Source.random_word(m_Gen);
                --numWords;
                [[fallthrough]];
            }
            case CaseSlugCase::PascalCase:
            {
                if (numWords == -2)
                {
                    numWords = m_Settings.wordURL.roll(m_Gen);
                }
                for (int i = 0; i < numWords; ++i)
                {
                    innerWord       = ClearApostrAndCh('-',
                                                 '_',
                                                 m_Source.random_word(m_Gen));
                    innerWord.at(0) = LPSM_SAFE_CCTYPE(char,
                                                       std::toupper,
                                                       innerWord.at(0));
                    ret += innerWord;
                }
                break;
            }
            case CaseSlugCase::SnakeCase:
            {
                ret = ClearApostrAndCh('-', slug('_'));
                break;
            }
            case CaseSlugCase::ShoutyCase:
            {
                ret = CapitalizeStr(ClearApostrAndCh('-', slug('_')));
                break;
            }
            case CaseSlugCase::KebabCase:
            {
                ret = ClearApostrAndCh('_', slug('-'));
                break;
            }
            case CaseSlugCase::TrainCase:
            {
                ret = CapitalizeStr(ClearApostrAndCh('_', slug('-')));
                break;
            }
        }
        return ret;
    }

} // namespace lipsum
#endif

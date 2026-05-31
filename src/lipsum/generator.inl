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
                result += single_paragraph(true);
            }
            else
            {
                result += single_paragraph(false);
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

    std::string Generator::slug(char separator)
    {
        std::string result;
        int         numWords = m_Settings.wordURL.roll(m_Gen);
        result               = word(numWords);
        std::replace(result.begin(), result.end(), ' ', separator);
        return result;
    }

} // namespace lipsum
#endif

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
#    include "core_funcs.hpp"
#    include "formats.hpp"
#    include "markdown.hpp"

#    define LPSM_ASSIGN_CHECK(name)                                            \
        isChecked = !isChecked ? assignSetting(#name, name) : true

namespace lipsum
{
    void GeneratorSettings::change_setting(const std::string& setting,
                                           const ArgVec2&     value)
    {
        auto assignSetting = [&](const char* name, ArgVec2& target) -> bool
        {
            if (setting == name)
            {
                target = value;
                return true;
            }
            return false;
        };
        bool isChecked = false;

        LPSM_ASSIGN_CHECK(word);
        LPSM_ASSIGN_CHECK(frag);
        LPSM_ASSIGN_CHECK(sent);
        LPSM_ASSIGN_CHECK(para);
        LPSM_ASSIGN_CHECK(point);
        LPSM_ASSIGN_CHECK(wordFmt);
        LPSM_ASSIGN_CHECK(fragFmt);
        LPSM_ASSIGN_CHECK(wordURL);
        LPSM_ASSIGN_CHECK(level);
        LPSM_ASSIGN_CHECK(jsonLength);
        if (!isChecked)
        {
            internal::LogWarn("lpsm::GeneratorSettings::change_setting(): "
                              "unknown "
                              "setting ",
                              setting,
                              ", ignoring");
        }
    }

    Generator::Generator(const std::string& path)
    {
        load_source(path);
    }

    void Generator::load_source(const std::string& path)
    {
        m_Source.load(path);
    }

    void Generator::change_setting(const std::string& setting,
                                   const ArgVec2&     value)
    {
        m_Settings.change_setting(setting, value);
    }

    void Generator::change_setting(const std::string& setting,
                                   int                minValue,
                                   int                maxValue)
    {
        change_setting(setting, ArgVec2(minValue, maxValue));
    }

    std::string Generator::single_sentence()
    {
        static const std::vector<int> weights = {88, 9, 3};
        std::string                   result;
        int                           frags = m_Settings.frag.roll();
        for (int i = 0; i < frags; ++i)
        {
            result += fragment();
            int check = internal::WeightedRandomIdx(weights);
            // don't do if only one fragment
            if (i != frags - 1)
            {
                switch (check)
                {
                    case 0:
                    {
                        result += ", ";
                        break;
                    }
                    case 1:
                    {
                        result += "; ";
                        break;
                    }
                    case 2:
                    {
                        result += " - ";
                        break;
                    }
                }
            }
        }
        result += ".";
        result.at(0) = static_cast<char>(
                std::toupper(static_cast<unsigned char>(result.at(0))));
        return result;
    }

    std::string Generator::single_paragraph(bool useLipsum)
    {
        std::string result = "\t";
        int         sents  = m_Settings.sent.roll();
        for (int i = 0; i < sents; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateDefaultLipsumSentence() += " ";
            }
            else
            {
                result += single_sentence() += " ";
            }
        }

        if (!result.empty())
        {
            // remove trailing space
            result.pop_back();
        }
        result += "\n";
        return result;
    }

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
            ret += m_Source.random_word() += " ";
        }

        if (!ret.empty())
        {
            ret.pop_back();
        }
        return ret;

        // return GenerateWords(num, m_Source);
    }

    std::string Generator::fragment()
    {
        std::string result;
        int         numWords = m_Settings.word.roll();
        for (int i = 0; i < numWords; ++i)
        {
            result += m_Source.random_word() += " ";
        }

        if (!result.empty())
        {
            result.pop_back(); // remove trailing space
        }
        return result;
        // return GenerateSentenceFragment(m_Settings.word, m_Source);
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
                result += single_sentence() += " ";
            }
        }
        return result;
        // return GenerateSentences(num,
        //                          m_Settings.word,
        //                          m_Settings.frag,
        //                          useLipsum,
        //                          m_Source);
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

        // return GenerateParagraphs(num,
        //                           m_Settings.word,
        //                           m_Settings.frag,
        //                           m_Settings.sent,
        //                           useLipsum,
        //                           m_Source);
    }

    std::string Generator::text(bool useLipsum)
    {
        int num = m_Settings.para.roll();
        return paragraph(num, useLipsum);
        // return GenerateText(m_Settings.word,
        //                     m_Settings.frag,
        //                     m_Settings.sent,
        //                     m_Settings.para,
        //                     useLipsum,
        //                     m_Source);
    }

    // TODO: scrambles, markdown, etc.
    // remove free functions

    std::string
    Generator::scramble(int length, char minChar, char maxChar) // NOLINT
    {
        return GenerateScramble(length, minChar, maxChar);
    }

    std::string Generator::url()
    {
        return GenerateURL(m_Settings.word, m_Source);
    }

    std::string Generator::plain_url()
    {
        return GeneratePlainURL(m_Source);
    }

    std::string Generator::slug(char separator)
    {
        return GenerateSlug(m_Settings.word, separator, m_Source);
    }

    std::string Generator::md_paragraph(int num, bool useLipsum, bool useHtml)
    {
        return GenerateMarkdownParagraphs(num,
                                          m_Settings.word,
                                          m_Settings.frag,
                                          m_Settings.sent,
                                          m_Settings.wordFmt,
                                          m_Settings.fragFmt,
                                          m_Settings.wordURL,
                                          useLipsum,
                                          useHtml,
                                          m_Source);
    }

    std::string Generator::md_text(int numElements, bool useHtml)
    {
        return GenerateMarkdownText(m_Settings.word,
                                    m_Settings.frag,
                                    m_Settings.sent,
                                    m_Settings.point,
                                    m_Settings.wordFmt,
                                    m_Settings.fragFmt,
                                    m_Settings.wordURL,
                                    m_Settings.level,
                                    numElements,
                                    useHtml,
                                    m_Source);
    }

    std::string Generator::md_header(int level, bool useHtml)
    {
        return GenerateMarkdownHeader(level,
                                      m_Settings.wordURL,
                                      useHtml,
                                      m_Source);
    }

    std::string Generator::md_emphasis(bool isBold, bool useHtml)
    {
        return GenerateMarkdownEmphasis(isBold,
                                        m_Settings.wordFmt,
                                        m_Settings.fragFmt,
                                        useHtml,
                                        m_Source);
    }

    std::string Generator::md_link(bool useHtml)
    {
        return GenerateMarkdownLink(m_Settings.wordFmt,
                                    m_Settings.fragFmt,
                                    m_Settings.wordURL,
                                    useHtml,
                                    m_Source);
    }

    std::string Generator::md_list(bool ordered, bool useHtml)
    {
        return GenerateMarkdownList(ordered,
                                    m_Settings.wordFmt,
                                    m_Settings.fragFmt,
                                    m_Settings.point,
                                    useHtml,
                                    m_Source);
    }

    std::string Generator::xml(int choices)
    {
        return GenerateXMLDocument(choices,
                                   m_Settings.word,
                                   m_Settings.frag,
                                   m_Source);
    }

    std::string Generator::json(int maxDepth, bool isObject)
    {
        if (isObject)
        {
            return GenerateJSONObject(0,
                                      maxDepth,
                                      m_Settings.jsonLength,
                                      m_Source);
        }
        return GenerateJSONArray(0, maxDepth, m_Settings.jsonLength, m_Source);
    }

} // namespace lipsum
#endif

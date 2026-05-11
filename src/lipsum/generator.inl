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

    std::string Generator::word(int num)
    {
        return GenerateWords(num, m_Source);
    }

    std::string Generator::fragment()
    {
        return GenerateSentenceFragment(m_Settings.word, m_Source);
    }

    std::string Generator::sentence(int num, bool useLipsum)
    {
        return GenerateSentences(num,
                                 m_Settings.word,
                                 m_Settings.frag,
                                 useLipsum,
                                 m_Source);
    }

    std::string Generator::paragraph(int num, bool useLipsum)
    {
        return GenerateParagraphs(num,
                                  m_Settings.word,
                                  m_Settings.frag,
                                  m_Settings.sent,
                                  useLipsum,
                                  m_Source);
    }

    std::string Generator::text(bool useLipsum)
    {
        return GenerateText(m_Settings.word,
                            m_Settings.frag,
                            m_Settings.sent,
                            m_Settings.para,
                            useLipsum,
                            m_Source);
    }

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

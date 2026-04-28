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

#    define LPSM_CHANGE_SETTING_BRANCH(name)                                   \
        if (setting == #name)                                                  \
        {                                                                      \
            name = value;                                                      \
        }

namespace lipsum
{
    void GeneratorSettings::change_setting(const std::string& setting,
                                           const ArgVec2&     value)
    {
        // clang-format off
        LPSM_CHANGE_SETTING_BRANCH(word)
        else LPSM_CHANGE_SETTING_BRANCH(frag) 
        else LPSM_CHANGE_SETTING_BRANCH(sent) 
        else LPSM_CHANGE_SETTING_BRANCH(para)
        else LPSM_CHANGE_SETTING_BRANCH(point)
        else LPSM_CHANGE_SETTING_BRANCH(wordFmt) 
        else LPSM_CHANGE_SETTING_BRANCH(fragFmt) 
        else LPSM_CHANGE_SETTING_BRANCH(wordURL)
        else LPSM_CHANGE_SETTING_BRANCH(level)
        else LPSM_CHANGE_SETTING_BRANCH(jsonLength)
        else
        // clang-format on
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

    std::string Generator::sentence_fragment()
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

    std::string Generator::md_paragraph(int num, bool useLipsum)
    {
        return GenerateMarkdownParagraphs(num,
                                          m_Settings.word,
                                          m_Settings.frag,
                                          m_Settings.sent,
                                          m_Settings.wordFmt,
                                          m_Settings.fragFmt,
                                          m_Settings.wordURL,
                                          useLipsum,
                                          false,
                                          m_Source);
    }

    std::string Generator::md_text(int numElements)
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
                                    false,
                                    m_Source);
    }

    std::string Generator::html_paragraph(int num, bool useLipsum)
    {
        return GenerateMarkdownParagraphs(num,
                                          m_Settings.word,
                                          m_Settings.frag,
                                          m_Settings.sent,
                                          m_Settings.wordFmt,
                                          m_Settings.fragFmt,
                                          m_Settings.wordURL,
                                          useLipsum,
                                          true,
                                          m_Source);
    }

    std::string Generator::html_text(int numElements)
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
                                    true,
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

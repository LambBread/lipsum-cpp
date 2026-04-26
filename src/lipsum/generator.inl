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

namespace lipsum
{

    Generator::Generator(const std::string& path)
    {
        m_Source.load(path);
    }

    std::string Generator::md_paragraph(int num, bool useLipsum)
    {
        return GenerateMarkdownParagraphs(num,
                                          m_Word,
                                          m_Frag,
                                          m_Sent,
                                          m_WordFmt,
                                          m_FragFmt,
                                          m_WordURL,
                                          useLipsum,
                                          false,
                                          m_Source);
    }

    void Generator::change_setting(const std::string& setting,
                                   const ArgVec2&     value)
    {
        if (setting == "word")
        {
            m_Word = value;
        }
        else if (setting == "frag")
        {
            m_Frag = value;
        }
        else if (setting == "sent")
        {
            m_Sent = value;
        }
        else if (setting == "para")
        {
            m_Para = value;
        }
        else if (setting == "point")
        {
            m_Point = value;
        }
        else if (setting == "wordFmt")
        {
            m_WordFmt = value;
        }
        else if (setting == "fragFmt")
        {
            m_FragFmt = value;
        }
        else if (setting == "wordURL")
        {
            m_WordURL = value;
        }
        else if (setting == "level")
        {
            m_Level = value;
        }
        else if (setting == "jsonLength")
        {
            m_JsonLength = value;
        }
        else
        {
            internal::LogWarn("lpsm::Generator::change_setting(): unknown "
                              "setting ",
                              setting,
                              ", ignoring");
        }
    }

    void Generator::change_setting(const std::string& setting,
                                   int                minValue,
                                   int                maxValue)
    {
        change_setting(setting, ArgVec2(minValue, maxValue));
    }

    std::string Generator::md_text(int numElements)
    {
        return GenerateMarkdownText(m_Word,
                                    m_Frag,
                                    m_Sent,
                                    m_Point,
                                    m_WordFmt,
                                    m_FragFmt,
                                    m_WordURL,
                                    m_Level,
                                    numElements,
                                    false,
                                    m_Source);
    }

    std::string Generator::html_paragraph(int num, bool useLipsum)
    {
        return GenerateMarkdownParagraphs(num,
                                          m_Word,
                                          m_Frag,
                                          m_Sent,
                                          m_WordFmt,
                                          m_FragFmt,
                                          m_WordURL,
                                          useLipsum,
                                          true,
                                          m_Source);
    }

    std::string Generator::html_text(int numElements)
    {
        return GenerateMarkdownText(m_Word,
                                    m_Frag,
                                    m_Sent,
                                    m_Point,
                                    m_WordFmt,
                                    m_FragFmt,
                                    m_WordURL,
                                    m_Level,
                                    numElements,
                                    true,
                                    m_Source);
    }

    std::string Generator::xml(int choices)
    {
        return GenerateXMLDocument(choices, m_Word, m_Frag, m_Source);
    }

    std::string Generator::json(int maxDepth, bool isObject)
    {
        if (isObject)
        {
            return GenerateJSONObject(0, maxDepth, m_JsonLength, m_Source);
        }
        return GenerateJSONArray(0, maxDepth, m_JsonLength, m_Source);
    }

    std::string Generator::word(int num)
    {
        return GenerateWords(num, m_Source);
    }
    std::string Generator::sentence(int num, bool useLipsum)
    {
        return GenerateSentences(num, m_Word, m_Frag, useLipsum, m_Source);
    }
    std::string Generator::sentence_fragment()
    {
        return GenerateSentenceFragment(m_Word, m_Source);
    }
    std::string Generator::paragraph(int num, bool useLipsum)
    {
        return GenerateParagraphs(num,
                                  m_Word,
                                  m_Frag,
                                  m_Sent,
                                  useLipsum,
                                  m_Source);
    }

    std::string Generator::text(bool useLipsum)
    {
        return GenerateText(m_Word,
                            m_Frag,
                            m_Sent,
                            m_Para,
                            useLipsum,
                            m_Source);
    }
} // namespace lipsum
#endif

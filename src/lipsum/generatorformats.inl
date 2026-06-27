/**
 * @file lipsum/generatorformats.inl
 *
 * @brief Definition of lipsum::Generator functions for formats
 *
 * This defines Markdown, HTML, JSON and XML generation functions in
 * lipsum::Generator. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUM_GENERATORFORMATS_INL
#    define LIPSUM_GENERATORFORMATS_INL

#    include "core/internal.hpp"

namespace lipsum
{

#    ifndef LIPSUM_MIN_BUILD

    /*
     * FORMATS
     */

    std::string Generator::fmt_paragraph(int num, bool useLipsum, bool useHtml)
    {
        std::string ret;

        if (num < 0)
        {
            internal::LogWarn("lpsm::Generator::fmt_paragraph(): expected "
                              "num >= 0, got ",
                              num);
        }

        for (int i = 0; i < num; ++i)
        {
            if (i == 0 && useLipsum)
            {
                ret += single_fmt_paragraph(USELIPSUM, useHtml);
            }
            else
            {
                ret += single_fmt_paragraph(NO_USELIPSUM, useHtml);
            }
        }
        return ret;
    }

    std::string Generator::fmt_text(int numElements, bool useHtml)
    {
        std::string ret;
        if (numElements < 0)
        {
            internal::LogWarn("lpsm::Generator::fmt_text(): cannot generate "
                              "negative number of elements.");
            return ret;
        }
        if (numElements >= 1)
        {
            ret += fmt_header(1, useHtml);
        }
        if (numElements >= 2)
        {
            ret += single_fmt_paragraph(NO_USELIPSUM, useHtml);
        }

        numElements -= 2;
        int  lastRand = 0;
        int  rand     = 0;
        bool ordered;
        while (numElements > 0)
        {
            rand = random_number<int>(0, 2);
            if ((lastRand == 1 && rand == 1) || numElements == 1)
            {
                rand = 0;
            }
            ordered = LPSM_FLIP_COIN;
            switch (rand)
            {
                case 0:
                {
                    ret += single_fmt_paragraph(NO_USELIPSUM, useHtml);
                    break;
                }
                case 1:
                {
                    ret += fmt_header(m_Settings.level.roll(m_Gen), useHtml);
                    break;
                }
                case 2:
                {
                    ret += fmt_list(ordered, useHtml);
                    break;
                }
            }
            --numElements;
            lastRand = rand;
        }
        return ret;
    }

    std::string Generator::fmt_header(int level, bool useHtml)
    {
        if (level > 6 || level < 1)
        {
            internal::LogWarn("lpsm::Generator::fmt_header(): invalid header "
                              "level ",
                              level,
                              ", expected from 1 to 6");
        }
        std::string ret;
        int         numWords = m_Settings.wordURL.roll(m_Gen);
        std::string words    = word(numWords);
        if (!words.empty())
        {
            words.at(0) = LPSM_SAFE_CCTYPE(char, std::toupper, words.at(0));
        }
        if (!useHtml)
        {
            for (int i = 0; i < level; ++i)
            {
                ret += "#";
            }
            ret += " ";
            ret += words += "\n\n";
        }
        else
        {
            ret += std::string("<h") + internal::ToString(level) + ">";
            ret += words +=
                    std::string("</h") + internal::ToString(level) + ">\n\n";
        }
        return ret;
    }

    std::string Generator::fmt_emphasis(bool isBold, bool useHtml)
    {
        std::string ret;
        std::string sent =
                single_sentence(m_Settings.wordFmt, m_Settings.fragFmt);

        if (!useHtml)
        {
            ret += (isBold ? "**" : "*");
        }
        else
        {
            ret += (isBold ? "<strong>" : "<em>");
        }

        ret += sent;

        if (!useHtml)
        {
            ret += (isBold ? "**" : "*");
        }
        else
        {
            ret += (isBold ? "</strong>" : "</em>");
        }
        return ret;
    }

    std::string Generator::fmt_link(bool useHtml)
    {
        std::string link = url();
        std::string sentence =
                single_sentence(m_Settings.wordFmt, m_Settings.fragFmt);
        if (!useHtml)
        {
            return std::string("[") + sentence + std::string("](") + link + ")";
        }
        return std::string("<a href=\"") + link + std::string("\">") +
               sentence + "</a>";
    }

    std::string Generator::fmt_list(bool ordered, bool useHtml)
    {
        std::string ret;
        int         points = m_Settings.point.roll(m_Gen);
        if (useHtml)
        {
            ret += (ordered ? "<ol>" : "<ul>");
        }
        for (int i = 0; i < points; ++i)
        {
            if (!useHtml)
            {
                if (ordered)
                {
                    ret += internal::ToString(i + 1) + ". ";
                }
                else
                {
                    ret += "- ";
                }
            }
            else
            {
                ret += "<li>";
            }
            ret += single_sentence(m_Settings.wordFmt, m_Settings.fragFmt);
            ret += (useHtml ? "</li>" : "\n");
        }
        if (useHtml)
        {
            ret += (ordered ? "</ol>\n" : "</ul>\n");
        }
        ret += "\n";
        return ret;
    }

    std::string Generator::xml(int choices)
    {
        std::string ret = R"(<?xml version="1.0" encoding="UTF-8"?>)";
        std::vector<std::string> tagStack;
        std::string              root = m_Source.random_word(m_Gen);
        ret += std::string("<") + root + ">";

        int choice;

        for (int i = 0; i < choices; ++i)
        {
            choice = random_number<int>(0, 2);
            switch (choice)
            {
                case 0:
                {
                    std::string toAdd       = m_Source.random_word(m_Gen);
                    std::string attrib      = m_Source.random_word(m_Gen);
                    std::string attribValue = m_Source.random_word(m_Gen);
                    bool        useAttrib   = LPSM_FLIP_COIN;
                    if (useAttrib)
                    {
                        ret += std::string("<") + toAdd + std::string(" ") +
                               attrib + std::string("=\"") + attribValue +
                               std::string("\">");
                    }
                    else
                    {
                        ret += std::string("<") + toAdd + ">";
                    }
                    tagStack.push_back(toAdd);
                    break;
                }

                case 1:
                {
                    std::string toAdd = m_Source.random_word(m_Gen);
                    ret += std::string("<") + toAdd + std::string(">") +
                           single_sentence(m_Settings.word, m_Settings.frag) +
                           std::string("</") + toAdd + ">";
                    // ret += toAdd += "";
                    break;
                }

                default:
                {
                    if (!tagStack.empty())
                    {
                        ret += std::string("</") + tagStack.back() + ">";
                        tagStack.pop_back();
                    }
                    break;
                }
            }
        }

        while (!tagStack.empty())
        {
            ret += std::string("</") + tagStack.back() + ">";
            tagStack.pop_back();
        }

        ret += std::string("</") + root + ">";

        return ret;
    }

    std::string Generator::json(int maxDepth, bool isObject)
    {
        int         count = m_Settings.jsonLength.roll(m_Gen);
        std::string ret   = (isObject ? "{" : "[");
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                ret += ",";
            }

            if (isObject)
            {

                std::string key = std::string("\"") +
                                  m_Source.random_word(m_Gen) +
                                  internal::ToString(i) + "\"";
                ret += key + std::string(":") + json_value(maxDepth - 1);
            }
            else
            {

                ret += json_value(maxDepth - 1);
            }
        }
        ret += (isObject ? "}" : "]");
        return ret;
    }

    std::string Generator::json_value(int maxDepth)
    {
        int           choice;
        constexpr int JSON_VALUE_WARN_DEPTH = 50;
        if (maxDepth >= JSON_VALUE_WARN_DEPTH)
        {
            internal::LogWarn("lpsm::Generator::json_value(): got maxDepth = ",
                              maxDepth,
                              ", which is"
                              "greater than the recommended maximum depth ",
                              JSON_VALUE_WARN_DEPTH,
                              ".");
        }
        if (maxDepth <= 0)
        {
            choice = random_number(0, 3);
            switch (choice)
            {
                case 0:
                {
                    return json_string();
                }
                case 1:
                {
                    return json_number();
                }
                case 2:
                {
                    return LPSM_FLIP_COIN ? "true" : "false";
                }
                default:
                {
                    return "null";
                }
            }
        }

        choice = random_number(0, 5);
        switch (choice)
        {

            case 0:
            {
                return json_string();
            }
            case 1:
            {
                return json_number();
            }
            case 2:
            {
                return LPSM_FLIP_COIN ? "true" : "false";
            }
            case 3:
            {
                return "null";
            }
            case 4:
            {
                return json(maxDepth, ARRAY);
            }
            default:
            {
                return json(maxDepth, OBJECT);
            }
        }
    }

    std::string Generator::csv()
    {
        constexpr float CSV_NUMBER_MIN = -1000.0f;
        constexpr float CSV_NUMBER_MAX = 1000.0f;
        enum class CsvTypes : int
        {
            Int = 0,
            Float,
            Sentence,
            Word,
            Email,
            Scramble
        };

        int                   numRows = m_Settings.csvRows.roll(m_Gen);
        int                   numCols = m_Settings.csvCols.roll(m_Gen);
        std::vector<CsvTypes> cols;
        std::string           ret;
        cols.reserve(numCols);
        for (int i = 0; i < numCols; ++i)
        {
            cols.push_back(static_cast<CsvTypes>(random_number<int>(0, 5)));
            ret += m_Source.random_word(m_Gen) + ",";
        }
        // remove trailing comma
        if (!ret.empty())
        {
            ret.pop_back();
        }
        ret += "\n";

        auto csvTypeLogic = [&](CsvTypes type)
        {
            switch (type)
            {
                case CsvTypes::Int:
                {
                    ret += json_number() + ",";
                    break;
                }
                case CsvTypes::Float:
                {
                    ret += internal::ToString(
                                   random_number<float>(CSV_NUMBER_MIN,
                                                        CSV_NUMBER_MAX)) +
                           ",";
                    break;
                }
                case CsvTypes::Sentence:
                {
                    ret += std::string("\"") +
                           single_sentence(m_Settings.wordFmt,
                                           m_Settings.fragFmt) +
                           "\",";
                    break;
                }
                case CsvTypes::Word:
                {
                    ret += m_Source.random_word(m_Gen) + ",";
                    break;
                }
                case CsvTypes::Email:
                {
                    ret += email() + ",";
                    break;
                }
                case CsvTypes::Scramble:
                {
                    ret += scramble(16, 'a', 'z') + ",";
                    break;
                }
            }
        };

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                csvTypeLogic(cols.at(j));
            }
            // remove trailing comma
            if (!ret.empty())
            {
                ret.pop_back();
            }
            ret += "\n";
        }
        return ret;
    }
#    else
    // placeholders

    std::string Generator::fmt_paragraph(int, bool, bool)
    {
        return "";
    }
    std::string Generator::fmt_text(int, bool)
    {
        return "";
    }
    std::string Generator::fmt_header(int, bool)
    {
        return "";
    }
    std::string Generator::fmt_emphasis(bool, bool)
    {
        return "";
    }
    std::string Generator::fmt_link(bool)
    {
        return "";
    }
    std::string Generator::fmt_list(bool, bool)
    {
        return "";
    }
    std::string Generator::xml(int)
    {
        return "";
    }
    std::string Generator::json(int, bool)
    {
        return "";
    }
    std::string Generator::json_value(int)
    {
        return "";
    }
    std::string Generator::csv()
    {
        return "";
    }
#    endif
} // namespace lipsum

#endif

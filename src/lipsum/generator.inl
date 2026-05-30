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

    /*
     * SETUP
     */

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

    /*
     * PRIVATE
     */

    std::string Generator::single_sentence(const ArgVec2& wordArg,
                                           const ArgVec2& frag)
    {
        static const std::vector<int>         weights = {88, 9, 3};
        static const std::vector<std::string> mapped  = {", ", "; ", " - "};
        std::string                           result;
        int                                   words;
        int                                   frags = frag.roll();
        for (int i = 0; i < frags; ++i)
        {
            words = wordArg.roll();
            result += word(words);
            int check = internal::WeightedRandomIdx(weights);
            // don't do if only one fragment
            if (i != frags - 1)
            {
                result += mapped.at(check);
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
                result += single_sentence(m_Settings.word, m_Settings.frag) +=
                        " ";
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

    std::string Generator::single_md_paragraph(bool useLipsum, bool useHtml)
    {
        std::string ret;
        int         sents = m_Settings.sent.roll();
        int         fmtRoll;
        bool        addLink;
        bool        isBold;
        if (useHtml)
        {
            ret += "<p>";
        }
        for (int i = 0; i < sents; ++i)
        {
            fmtRoll = m_Settings.sent.roll();
            addLink = LPSM_FLIP_COIN;
            isBold  = LPSM_FLIP_COIN;
            if (i == 0 && useLipsum)
            {
                ret += GenerateDefaultLipsumSentence();
            }
            else if ((fmtRoll == m_Settings.sent.min) && addLink)
            {
                ret += md_link(useHtml);
            }
            else if ((fmtRoll == m_Settings.sent.min) && !addLink)
            {
                ret += md_emphasis(isBold, useHtml);
            }
            else
            {
                ret += single_sentence(m_Settings.word, m_Settings.frag);
            }
            ret += " ";
        }
        if (useHtml)
        {
            ret += "</p>";
        }
        ret += "\n\n";
        return ret;
    }

    std::string Generator::json_string()
    {
        return std::string("\"") + m_Source.random_word() + "\"";
    }

    std::string Generator::json_number() // NOLINT
    {
        constexpr int JSON_NUMBER_MIN = -1000;
        constexpr int JSON_NUMBER_MAX = 1000;
        return internal::ToString(
                internal::RandomNumber(JSON_NUMBER_MIN, JSON_NUMBER_MAX));
    }

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
            ret += m_Source.random_word() += " ";
        }

        if (!ret.empty())
        {
            ret.pop_back();
        }
        return ret;
    }

    std::string Generator::fragment()
    {
        int numWords = m_Settings.word.roll();
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
        int num = m_Settings.para.roll();
        return paragraph(num, useLipsum);
    }

    /*
     * MISC
     */

    std::string
    Generator::scramble(int length, char minChar, char maxChar) // NOLINT
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
            ret.push_back(internal::RandomNumber(minChar, maxChar));
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
        return std::string("lpsmcpp-") + m_Source.random_word() +
               internal::GenerateTLD();
    }

    std::string Generator::slug(char separator)
    {
        std::string result;
        int         numWords = m_Settings.wordURL.roll();
        result               = word(numWords);
        std::replace(result.begin(), result.end(), ' ', separator);
        return result;
    }

    /*
     * FORMATS
     */

    std::string Generator::md_paragraph(int num, bool useLipsum, bool useHtml)
    {
        std::string ret;

        if (num < 0)
        {
            internal::LogWarn("lpsm::Generator::md_paragraph(): expected "
                              "num >= 0, got ",
                              num);
        }

        for (int i = 0; i < num; ++i)
        {
            if (i == 0 && useLipsum)
            {
                ret += single_md_paragraph(true, useHtml);
            }
            else
            {
                ret += single_md_paragraph(false, useHtml);
            }
        }
        return ret;
    }

    std::string Generator::md_text(int numElements, bool useHtml)
    {
        std::string ret;
        if (numElements < 0)
        {
            internal::LogWarn("lpsm::Generator::md_text(): cannot generate "
                              "negative number of elements.");
            return ret;
        }
        if (numElements >= 1)
        {
            ret += md_header(1, useHtml);
        }
        if (numElements >= 2)
        {
            ret += single_md_paragraph(false, useHtml);
        }

        numElements -= 2;
        int  rand;
        bool ordered;
        while (numElements > 0)
        {
            rand    = internal::RandomNumber<int>(0, 2);
            ordered = LPSM_FLIP_COIN;
            switch (rand)
            {
                case 0:
                {
                    ret += single_md_paragraph(false, useHtml);
                    break;
                }
                case 1:
                {
                    ret += md_header(m_Settings.level.roll(), useHtml);
                    break;
                }
                case 2:
                {
                    ret += md_list(ordered, useHtml);
                    break;
                }
            }
            --numElements;
        }
        return ret;
    }

    std::string Generator::md_header(int level, bool useHtml)
    {
        if (level > 6 || level < 1)
        {
            internal::LogWarn("lpsm::Generator::md_header(): invalid header "
                              "level ",
                              level,
                              ", expected from 1 to 6");
        }
        std::string ret;
        int         numWords = m_Settings.wordURL.roll();
        std::string words    = word(numWords);
        if (!words.empty())
        {
            words.at(0) = static_cast<char>(
                    std::toupper(static_cast<unsigned char>(words.at(0))));
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

    std::string Generator::md_emphasis(bool isBold, bool useHtml)
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

    std::string Generator::md_link(bool useHtml)
    {
        std::string ret;
        std::string link = url();
        std::string sentence =
                single_sentence(m_Settings.wordFmt, m_Settings.fragFmt);
        if (!useHtml)
        {
            ret += std::string("[") += sentence += std::string("](") += link +=
                    ")";
        }
        else
        {
            ret += std::string("<a href=\"") + link + std::string("\">") +
                   sentence + "</a>";
        }
        return ret;
    }

    std::string Generator::md_list(bool ordered, bool useHtml)
    {
        std::string ret;
        int         points = m_Settings.point.roll();
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
                    ret += internal::ToString(i + 1) += ". ";
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
        std::string              root = m_Source.random_word();
        ret += std::string("<") + root + ">";

        int choice;

        for (int i = 0; i < choices; ++i)
        {
            choice = internal::RandomNumber<int>(0, 2);
            switch (choice)
            {
                case 0:
                {
                    std::string toAdd       = m_Source.random_word();
                    std::string attrib      = m_Source.random_word();
                    std::string attribValue = m_Source.random_word();
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
                    std::string toAdd = m_Source.random_word();
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

    std::string Generator::json(int depth, int maxDepth, bool isObject)
    {
        int         count = m_Settings.jsonLength.roll();
        std::string ret   = (isObject ? "{" : "[");
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                ret += ",";
            }

            if (isObject)
            {

                std::string key = std::string("\"") + m_Source.random_word() +
                                  internal::ToString(i) + "\"";
                ret += key + std::string(":") + json_value(depth + 1, maxDepth);
            }
            else
            {

                ret += json_value(depth + 1, maxDepth);
            }
        }
        ret += (isObject ? "}" : "]");
        return ret;
    }

    std::string Generator::json_value(int depth, int maxDepth)
    {
        int choice;
        if (depth > maxDepth)
        {
            choice = internal::RandomNumber(0, 3);
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

        choice = internal::RandomNumber(0, 5);
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
                return json(depth, maxDepth, false);
            }
            default:
            {
                return json(depth, maxDepth, true);
            }
        }
    }

} // namespace lipsum
#endif

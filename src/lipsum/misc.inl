/**
 * @file lipsum/misc.inl
 *
 * @brief Miscellaneous functions of lipsum-cpp
 *
 * This defines miscellaneous functions in lipsum-cpp,
 * such as CountSentences(). This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#include "core/internal.hpp"

static int
LipsumMiscInlFind(int count, const std::string& str, const std::string& check)
{
    size_t pos = 0;
    while ((pos = str.find(check, pos)) != std::string::npos)
    {
        ++count;
        pos += check.size();
    }
    return count;
}

namespace lipsum
{

    /*
     * MISC
     * ----------------
     */

    std::string GenerateDefaultLipsumSentence()
    {
        return {"Lorem ipsum dolor sit amet, consectetur adipiscing elit."};
    }

    int CountWords(const std::string& str)
    {
        int  count      = 0;
        int  urlNum     = 0;
        bool inWord     = false;
        char lastLetter = '\0';
        for (const char& letter : str)
        {
            if (letter == '(')
            {
                ++urlNum;
            }
            if (letter == ')')
            {
                --urlNum;
            }

            bool isWordChar =
                    static_cast<bool>(
                            std::isalnum(static_cast<unsigned char>(letter))) ||
                    (letter == '-' && lastLetter != '\n' &&
                     lastLetter != ' ') ||
                    (letter == '+' && lastLetter != '\n' &&
                     lastLetter != ' ') ||
                    (letter == '\'' && lastLetter != '\n' && lastLetter != ' ');
            // if not in parens
            if (urlNum <= 0)
            {
                if (isWordChar && !inWord)
                {
                    inWord = true;
                    ++count;
                }
                if (!isWordChar)
                {
                    inWord = false;
                }
            }

            lastLetter = letter;
        }
        LPSM_VERBOSE_LOG(Trace, "Counting words, got ", count);
        return count;
    }

    int CountSentenceFragments(const std::string& str)
    {
        if (str.empty())
        {
            return 0;
        }
        int  res        = 0;
        int  urlNum     = 0;
        char lastLetter = '\0';
        for (const char& letter : str)
        {
            if (letter == '(')
            {
                ++urlNum;
            }
            if (letter == ')')
            {
                --urlNum;
            }

            // if not in parens
            if (urlNum <= 0)
            {
                if (letter == ',' || letter == ';' || letter == ':' ||
                    letter == '.' || letter == '?' || letter == '!')
                {
                    ++res;
                }
                if (letter == '-' && lastLetter != '\n')
                {
                    ++res;
                }
            }
            lastLetter = letter;
        }
        LPSM_VERBOSE_LOG(Trace, "Counting sentence fragments, got ", res);
        return res;
    }

    int CountSentences(const std::string& str)
    {
        int res    = 0;
        int urlNum = 0;
        for (const char& letter : str)
        {
            if (letter == '(')
            {
                ++urlNum;
            }
            if (letter == ')')
            {
                --urlNum;
            }
            if ((letter == '.' || letter == '?' || letter == '!') &&
                urlNum <= 0)
            {
                ++res;
            }
        }
        LPSM_VERBOSE_LOG(Trace, "Counting sentences, got ", res);
        return res;
    }

    int CountParagraphs(const std::string& str, Format format)
    {
        switch (format)
        {
            case Format::Plain:
            {
                return static_cast<int>(
                        std::count(str.begin(), str.end(), '\t'));
            }
            case Format::Markdown:
            {
                int count = LipsumMiscInlFind(0, str, "\n\n");
                return count;
            }
            case Format::HTML:
            {
                int count = LipsumMiscInlFind(0, str, "<p>");
                count     = LipsumMiscInlFind(count, str, "<ol>");
                count     = LipsumMiscInlFind(count, str, "<ul>");
                count     = LipsumMiscInlFind(count, str, "<h1>");
                count     = LipsumMiscInlFind(count, str, "<h2>");
                count     = LipsumMiscInlFind(count, str, "<h3>");
                count     = LipsumMiscInlFind(count, str, "<h4>");
                count     = LipsumMiscInlFind(count, str, "<h5>");
                count     = LipsumMiscInlFind(count, str, "<h6>");
                return count;
            }
            default:
            {
                internal::LogWarn(internal::LogType::Warn,
                                  "lpsm::CountParagraphs(): invalid format for "
                                  "conversion: ",
                                  static_cast<int>(format));
                return 0;
            }
        }
    }

#ifndef LIPSUM_MIN_BUILD

#    define LIPSUM_MD_PLAIN_CONT                                               \
        lastLetter = letter;                                                   \
        continue

    // NOLINTBEGIN(readability-function-cognitive-complexity)

    static std::string LipsumMiscInlMarkdownToPlain(const std::string& str)
    {
        LPSM_VERBOSE_LOG(Trace, "Using Markdown->Plain.");
        std::string ret;
        ret.reserve(str.size());
        char        lastLetter        = '\0';
        bool        inUrlText         = false;
        bool        inUrl             = false;
        bool        toAddTab          = true;
        int         numListCharsToDel = 0;
        std::string urlText;
        for (const auto& letter : str)
        {

            if (letter == '\n' && lastLetter == '\n')
            {
                // ret += "\t";
                toAddTab = true;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (!inUrl &&
                (letter == '#' || (letter == '-' && lastLetter == '\n')))
            {
                toAddTab          = true;
                numListCharsToDel = 1;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter >= '0' && letter <= '9' && lastLetter == '\n')
            {
                toAddTab          = true;
                numListCharsToDel = 2;
                LIPSUM_MD_PLAIN_CONT;
            }

            // skip emphasis
            if (letter == '*')
            {
                // std::cout << "skipping emphasis or heading\n";
                LIPSUM_MD_PLAIN_CONT;
            }

            // end url link
            if (letter == ')' && inUrl)
            {
                // std::cout << "ending url link\n";
                inUrl = false;
                LIPSUM_MD_PLAIN_CONT;
            }

            // start url link
            if (letter == '(' && lastLetter == ']')
            {
                // std::cout << "starting url link\n";
                inUrl = true;
                LIPSUM_MD_PLAIN_CONT;
            }

            // start url text
            if (letter == '[')
            {
                // std::cout << "starting url text\n";
                inUrlText = true;
                LIPSUM_MD_PLAIN_CONT;
            }

            // end url text
            if (letter == ']' && inUrlText)
            {
                // std::cout << "ending url text\n";
                inUrlText = false;
                ret += urlText;
                urlText.clear();
                LIPSUM_MD_PLAIN_CONT;
            }

            // skip url link
            if (inUrl)
            {
                // std::cout << "skipping url link\n";
                LIPSUM_MD_PLAIN_CONT;
            }

            if (inUrlText)
            {
                // std::cout << "adding letter from url text\n";
                urlText += letter;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (toAddTab)
            {
                ret += "\t";
                toAddTab = false;
            }
            if (numListCharsToDel <= 0)
            {
                ret += letter;
            }
            else
            {
                --numListCharsToDel;
            }
            // std::cout << letter;
            lastLetter = letter;
        }
        return internal::StripHTMLEntity(ret, Format::Markdown);
    }

    static std::string LipsumMiscInlMarkdownToHtml(const std::string& str)
    {
        LPSM_VERBOSE_LOG(Trace, "Using Markdown->HTML.");
        std::string ret;
        ret.reserve(str.size());
        std::string urlText;
        std::string urlLink;
        char        lastLetter      = '\0';
        int         boldLevel       = 0;
        bool        inHeader        = false;
        bool        nextCharEscaped = false;
        bool        inUrlText       = false;
        bool        inUrlLink       = false;
        bool        inOrderedList   = false;
        bool        inUnorderedList = false;
        // bool inListElem = false;
        int headerLevel = 0;

        // TODO: Fix numbers and spaces remaining from lists.
        for (const auto& letter : str)
        {
            if (letter == '\\')
            {
                nextCharEscaped = true;
                continue;
            }
            if (nextCharEscaped)
            {
                ret += internal::HandleHTMLEntity(letter, Format::HTML);
                nextCharEscaped = false;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == '*' && lastLetter == '*')
            {
                if (boldLevel == 0)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Inserting bold");
                    boldLevel = 2;
                    ret += "<strong>";
                    // std::cout << "<strong>";
                }
                else if (boldLevel == 2)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Ending bold");
                    boldLevel = 3;
                    ret += "</strong>";
                    // std::cout << "</strong>";
                }
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter != '*' && lastLetter == '*' && boldLevel != 3)
            {
                if (boldLevel == 0)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Inserting italic");
                    boldLevel = 1;
                    ret += "<em>";
                    // std::cout << "<em>";
                }
                else if (boldLevel == 1)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Ending italic");
                    boldLevel = 0;
                    ret += "</em>";
                    // std::cout << "</em>";
                }
            }

            if (boldLevel == 3)
            {
                boldLevel = 0;
            }

            if (((letter == '-' && lastLetter == '\n') ||
                 (letter == '.' &&
                  LPSM_SAFE_CCTYPE(bool, std::isdigit, lastLetter))) &&
                (inUnorderedList || inOrderedList))
            {
                // LPSM_VERBOSE_LOG(Debug, "Adding list item");
                ret += "<li>";
                LIPSUM_MD_PLAIN_CONT;
            }
            if (letter == '\n' && lastLetter == '\n')
            {
                if (inUnorderedList)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Ending unordered list");
                    inUnorderedList = false;
                    inOrderedList   = false;
                    ret += "</ul>\n";
                    LIPSUM_MD_PLAIN_CONT;
                }
                if (inOrderedList)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Ending ordered list");
                    inOrderedList   = false;
                    inUnorderedList = false;
                    ret += "</ol>\n";
                    LIPSUM_MD_PLAIN_CONT;
                }
            }
            if (letter == '\n' && (inUnorderedList || inOrderedList))
            {
                // LPSM_VERBOSE_LOG(Debug, "Ending list item");
                ret += "</li>";
            }
            if (letter == '-' && lastLetter == '\n' && !inUnorderedList)
            {
                // LPSM_VERBOSE_LOG(Debug, "Starting unordered list");
                inUnorderedList = true;
                ret += "<ul><li>";
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == '.' &&
                LPSM_SAFE_CCTYPE(bool, std::isdigit, lastLetter) &&
                !inOrderedList)
            {
                // LPSM_VERBOSE_LOG(Debug, "Starting ordered list");
                inOrderedList = true;
                ret += "<ol><li>";
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == '[')
            {
                // LPSM_VERBOSE_LOG(Debug, "Starting link text");
                inUrlText = true;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (lastLetter == ']' && letter == '(')
            {
                // LPSM_VERBOSE_LOG(Debug, "Ending link text, starting link
                // URL");
                inUrlText = false;
                inUrlLink = true;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == ')' && inUrlLink)
            {
                // LPSM_VERBOSE_LOG(Debug, "Ending link URL");
                inUrlLink = false;
                inUrlText = false;
                ret += "<a href=\"" + urlLink + "\">" + urlText + "</a>";
                // std::cout << "<a href=\"" << urlLink << "\">" << urlText
                //           << "</a>";
                urlLink.clear();
                urlText.clear();
                LIPSUM_MD_PLAIN_CONT;
            }

            if (inUrlText && letter != ']')
            {
                urlText.push_back(letter);
                LIPSUM_MD_PLAIN_CONT;
            }

            if (inUrlLink)
            {
                urlLink.push_back(letter);
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == '#')
            {
                // LPSM_VERBOSE_LOG(Debug, "Increasing header level");
                //  inHeader = true;
                ++headerLevel;
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == ' ' && lastLetter == '#')
            {
                // LPSM_VERBOSE_LOG(Debug, "Inserting header");
                inHeader = true;
                ret += "<h" + internal::ToString(headerLevel) + ">";
                // std::cout << "<h" << headerLevel << ">";
                LIPSUM_MD_PLAIN_CONT;
            }

            if (letter == '\n' && lastLetter == '\n')
            {
                if (inHeader)
                {
                    // LPSM_VERBOSE_LOG(Debug, "Ending header");
                    inHeader = false;
                    ret += "</h" + internal::ToString(headerLevel) + ">\n";
                    // std::cout << "</h" << headerLevel << ">\n";
                    headerLevel = 0;
                    LIPSUM_MD_PLAIN_CONT;
                }
            }

            if (letter != '*' && (letter != '\n' || !inHeader) && letter != ']')
            {
                ret += internal::HandleHTMLEntity(letter, Format::HTML);
                // std::cout << internal::HandleHTMLEntity(letter,
                // Format::HTML);
            }

            lastLetter = letter;
        }
        return ret;
    }

    std::string
    ConvertFormat(const std::string& str, Format format1, Format format2)
    {
        auto plainConvs = [&]() -> std::string
        {
            LPSM_VERBOSE_LOG(Trace,
                             "Format is Plain. Attempting conversion...");
            std::string ret;
            ret.reserve(str.size());
            switch (format2)
            {
                case Format::Markdown:
                {
                    for (const auto& letter : str)
                    {
                        if (letter == '\t')
                        {
                            ret += "\n\n";
                        }
                        else
                        {
                            ret += internal::HandleHTMLEntity(letter,
                                                              Format::Markdown);
                        }
                    }
                    LPSM_VERBOSE_LOG(Trace, "Using Plain->Markdown.");
                    return ret;
                }
                case Format::XML:
                {
                    LPSM_VERBOSE_LOG(Trace, "Using Plain->XML.");
                    ret += R"(<?xml version="1.0" encoding="UTF-8"?>)";
                    [[fallthrough]];
                }
                case Format::HTML:
                {
                    LPSM_VERBOSE_LOG(Trace, "Using Plain->HTML.");
                    for (const auto& letter : str)
                    {
                        if (letter == '\t')
                        {
                            ret += "<p>";
                        }
                        ret += internal::HandleHTMLEntity(letter, Format::HTML);
                        if (letter == '\n')
                        {
                            ret += "</p>";
                        }
                    }
                    return ret;
                }
                case Format::JSON:
                {
                    LPSM_VERBOSE_LOG(Trace, "Using Plain->JSON.");
                    ret += R"({"text": ")";
                    for (const auto& letter : str)
                    {
                        ret += internal::HandleHTMLEntity(letter, Format::JSON);
                    }
                    ret += "\"}";
                    return ret;
                }
                default:
                {
                    internal::LogWarn(internal::LogType::Error,
                                      "lpsm::ConvertFormat(): Format option ",
                                      static_cast<int>(format2),
                                      " is out of range.");
                    return "";
                }
            }
        };

        auto mdConvs = [&]() -> std::string
        {
            LPSM_VERBOSE_LOG(Trace,
                             "Format is Markdown. Attempting conversion...");
            std::string ret;
            ret.reserve(str.size());
            switch (format2)
            {
                case Format::Plain:
                {
                    return LipsumMiscInlMarkdownToPlain(str);
                }
                case Format::HTML:
                {
                    return LipsumMiscInlMarkdownToHtml(str);
                }
                case Format::JSON:
                {
                    LPSM_VERBOSE_LOG(Trace, "Using Markdown->JSON.");
                    return ConvertFormat(str, Format::Plain, Format::JSON);
                }
                default:
                {
                    internal::
                            LogWarn(internal::LogType::Error,
                                    "lpsm::ConvertFormat(): Unknown route from "
                                    "format ",
                                    static_cast<int>(format1),
                                    " to ",
                                    static_cast<int>(format2));
                    return "";
                }
            }
        };

        LPSM_VERBOSE_LOG(Trace, "Converting between formats...");
        if (format1 == format2)
        {
            LPSM_VERBOSE_LOG(Trace,
                             "Converting between two formats of the same type. "
                             "Ignoring...");
            return str;
        }
        // std::cout << str;
        switch (format1)
        {
            case Format::Plain:
            {
                return plainConvs();
            }
            case Format::Markdown:
            {
                return mdConvs();
            }
            default:
            {
                internal::LogWarn(internal::LogType::Error,
                                  "lpsm::ConvertFormat(): Unknown route from "
                                  "format ",
                                  static_cast<int>(format1),
                                  " to ",
                                  static_cast<int>(format2));
                return "";
            }
        }
    }
    // NOLINTEND(readability-function-cognitive-complexity)
#else
    std::string ConvertFormat(const std::string& str, Format, Format)
    {
        LPSM_VERBOSE_MINLOG;
        return str;
    }
#endif

} // namespace lipsum

/**
 * @file lipsum/markdown.inl
 *
 * @brief Markdown functions of lipsum-cpp
 *
 * This defines functions in lipsum-cpp around generation of Markdown text.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_MARKDOWN_INL
#    define LIPSUM_MAKRDOWN_INL

#    include "core/internal.hpp"
#    include "core_funcs.hpp"
#    include "misc.hpp"

namespace lipsum
{

    std::string GenerateMarkdownText(const ArgVec2& word,
                                     const ArgVec2& frag,
                                     const ArgVec2& sent,
                                     const ArgVec2& point,
                                     const ArgVec2& wordFmt,
                                     const ArgVec2& fragFmt,
                                     const ArgVec2& wordHead,
                                     const ArgVec2& level,
                                     int            numElements,
                                     bool           useHtml,
                                     const Source&  source)
    {
        std::string ret;
        ret += GenerateMarkdownHeader(1, wordHead, useHtml, source);
        ret += GenerateMarkdownParagraph(word,
                                         frag,
                                         sent,
                                         wordFmt,
                                         fragFmt,
                                         wordHead,
                                         false,
                                         useHtml,
                                         source);
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
                    ret += GenerateMarkdownParagraph(word,
                                                     frag,
                                                     sent,
                                                     wordFmt,
                                                     fragFmt,
                                                     wordHead,
                                                     false,
                                                     useHtml,
                                                     source);
                    break;
                }
                case 1:
                {
                    ret += GenerateMarkdownHeader(level.roll(),
                                                  wordHead,
                                                  useHtml,
                                                  source);
                    break;
                }
                case 2:
                {
                    ret += GenerateMarkdownList(ordered,
                                                wordFmt,
                                                fragFmt,
                                                point,
                                                useHtml,
                                                source);
                    break;
                }
            }
            --numElements;
        }
        return ret;
    }

    std::string GenerateMarkdownList(bool           ordered,
                                     const ArgVec2& word,
                                     const ArgVec2& frag,
                                     const ArgVec2& point,
                                     bool           useHtml,
                                     const Source&  source)
    {
        std::string ret;
        int         points = point.roll();
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
            ret += GenerateSentence(word, frag, source);
            ret += (useHtml ? "</li>" : "\n");
        }
        if (useHtml)
        {
            ret += (ordered ? "</ol>" : "</ul>");
        }
        ret += "\n";
        return ret;
    }

    std::string GenerateMarkdownParagraph(const ArgVec2& word,
                                          const ArgVec2& frag,
                                          const ArgVec2& sent,
                                          const ArgVec2& wordFmt,
                                          const ArgVec2& fragFmt,
                                          const ArgVec2& wordLink,
                                          bool           useLipsum,
                                          bool           useHtml,
                                          const Source&  source)
    {
        std::string ret;
        int         sents = sent.roll();
        int         fmtRoll;
        bool        addLink;
        bool        isBold;
        if (useHtml)
        {
            ret += "<p>";
        }
        for (int i = 0; i < sents; ++i)
        {
            fmtRoll = sent.roll();
            addLink = LPSM_FLIP_COIN;
            isBold  = LPSM_FLIP_COIN;
            if (i == 0 && useLipsum)
            {
                ret += GenerateDefaultLipsumSentence();
            }
            else if ((fmtRoll == sent.min) && addLink)
            {
                ret += GenerateMarkdownLink(wordFmt,
                                            fragFmt,
                                            wordLink,
                                            useHtml,
                                            source);
            }
            else if ((fmtRoll == sent.min) && !addLink)
            {
                ret += GenerateMarkdownEmphasis(isBold,
                                                wordFmt,
                                                fragFmt,
                                                useHtml,
                                                source);
            }
            else
            {
                ret += GenerateSentence(word, frag, source);
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

    std::string GenerateMarkdownLink(const ArgVec2& word,
                                     const ArgVec2& frag,
                                     const ArgVec2& wordURL,
                                     bool           useHtml,
                                     const Source&  source)
    {
        std::string ret;
        std::string link     = GenerateURL(wordURL, source);
        std::string sentence = GenerateSentence(word, frag, source);
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

    std::string GenerateMarkdownEmphasis(bool           isBold,
                                         const ArgVec2& word,
                                         const ArgVec2& frag,
                                         bool           useHtml,
                                         const Source&  source)
    {
        std::string ret;
        std::string sent = GenerateSentence(word, frag, source);

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

    std::string GenerateMarkdownHeader(int            level,
                                       const ArgVec2& word,
                                       bool           useHtml,
                                       const Source&  source)
    {
        if (level > 6 || level < 1)
        {
            internal::LogWarn("lpsm::GenerateMarkdownHeader(): invalid header "
                              "level ",
                              level,
                              ", expected from 1 to 6");
        }
        std::string ret;
        std::string words = GenerateSentenceFragment(word, source);
        words.at(0)       = static_cast<char>(
                std::toupper(static_cast<unsigned char>(words.at(0))));
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
                    std::string("</h") + internal::ToString(level) + ">";
        }
        return ret;
    }
    std::string GenerateMarkdownParagraphs(int            paraCount,
                                           const ArgVec2& word,
                                           const ArgVec2& frag,
                                           const ArgVec2& sent,
                                           const ArgVec2& wordFmt,
                                           const ArgVec2& fragFmt,
                                           const ArgVec2& wordLink,
                                           bool           useLipsum,
                                           bool           useHtml,
                                           const Source&  source)
    {
        std::string ret;

        if (paraCount < 0)
        {
            internal::LogWarn("lpsm::GenerateMarkdownParagraphs(): expected "
                              "paraCount >= 0, got ",
                              paraCount);
        }

        for (int i = 0; i < paraCount; ++i)
        {
            if (i == 0 && useLipsum)
            {
                ret += GenerateMarkdownParagraph(word,
                                                 frag,
                                                 sent,
                                                 wordFmt,
                                                 fragFmt,
                                                 wordLink,
                                                 true,
                                                 useHtml,
                                                 source);
            }
            else
            {
                ret += GenerateMarkdownParagraph(word,
                                                 frag,
                                                 sent,
                                                 wordFmt,
                                                 fragFmt,
                                                 wordLink,
                                                 false,
                                                 useHtml,
                                                 source);
            }
        }
        return ret;
    }
} // namespace lipsum
#endif

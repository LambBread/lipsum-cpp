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
std::string lpsm::GenerateMarkdownText(const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& sent,
                                       const lpsm::ArgVec2& point,
                                       const lpsm::ArgVec2& wordFmt,
                                       const lpsm::ArgVec2& fragFmt,
                                       const lpsm::ArgVec2& wordHead,
                                       const lpsm::ArgVec2& level,
                                       int                  numElements,
                                       bool                 useHtml)
{
    std::string ret;
    ret += lpsm::GenerateMarkdownHeader(1, wordHead, useHtml);
    ret += lpsm::GenerateMarkdownParagraph(word,
                                           frag,
                                           sent,
                                           wordFmt,
                                           fragFmt,
                                           wordHead,
                                           false,
                                           useHtml);
    numElements -= 2;
    int           rand;
    bool          ordered;
    lpsm::ArgVec2 elem  = ArgVec2(0, 2);
    lpsm::ArgVec2 order = ArgVec2(0, 1);
    while (numElements > 0)
    {
        rand    = elem.Roll();
        ordered = static_cast<bool>(order.Roll());
        switch (rand)
        {
            case 0:
            {
                ret += lpsm::GenerateMarkdownParagraph(word,
                                                       frag,
                                                       sent,
                                                       wordFmt,
                                                       fragFmt,
                                                       wordHead,
                                                       false,
                                                       useHtml);
                break;
            }
            case 1:
            {
                ret += lpsm::GenerateMarkdownHeader(level.Roll(),
                                                    wordHead,
                                                    useHtml);
                break;
            }
            case 2:
            {
                ret += lpsm::GenerateMarkdownList(ordered,
                                                  wordFmt,
                                                  fragFmt,
                                                  point,
                                                  useHtml);
                break;
            }
        }
        --numElements;
    }
    return ret;
}

std::string lpsm::GenerateMarkdownList(bool                 ordered,
                                       const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& point,
                                       bool                 useHtml)
{
    std::string ret;
    int         points = point.Roll();
    if (useHtml)
    {
        if (ordered)
        {
            ret += "<ol>";
        }
        else
        {
            ret += "<ul>";
        }
    }
    for (int i = 0; i < points; ++i)
    {
        if (!useHtml)
        {
            if (ordered)
            {
                ret += lpsm::internal::ToString(i + 1) += ". ";
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
        ret += lpsm::GenerateSentence(word, frag);
        if (useHtml)
        {
            ret += "</li>";
        }
        else
        {
            ret += "\n";
        }
    }
    if (useHtml)
    {
        if (ordered)
        {
            ret += "</ol>";
        }
        else
        {
            ret += "</ul>";
        }
    }
    ret += "\n";
    return ret;
}

std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2& word,
                                            const lpsm::ArgVec2& frag,
                                            const lpsm::ArgVec2& sent,
                                            const lpsm::ArgVec2& wordFmt,
                                            const lpsm::ArgVec2& fragFmt,
                                            const lpsm::ArgVec2& wordLink,
                                            bool                 useLipsum,
                                            bool                 useHtml)
{
    std::string   ret;
    int           sents = sent.Roll();
    int           fmtRoll;
    bool          addLink;
    bool          isBold;
    lpsm::ArgVec2 linkEmph = ArgVec2(0, 1);
    lpsm::ArgVec2 boldItal = ArgVec2(0, 1);
    if (useHtml)
    {
        ret += "<p>";
    }
    for (int i = 0; i < sents; ++i)
    {
        fmtRoll = sent.Roll();
        addLink = static_cast<bool>(linkEmph.Roll());
        isBold  = static_cast<bool>(boldItal.Roll());
        if (i == 0 && useLipsum)
        {
            ret += lpsm::GenerateDefaultLipsumSentence();
        }
        else if ((fmtRoll == sent.min) && addLink)
        {
            ret += lpsm::GenerateMarkdownLink(wordFmt,
                                              fragFmt,
                                              wordLink,
                                              useHtml);
        }
        else if ((fmtRoll == sent.min) && !addLink)
        {
            ret += lpsm::GenerateMarkdownEmphasis(isBold,
                                                  wordFmt,
                                                  fragFmt,
                                                  useHtml);
        }
        else
        {
            ret += lpsm::GenerateSentence(word, frag);
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

std::string lpsm::GenerateMarkdownLink(const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& wordURL,
                                       bool                 useHtml)
{
    std::string ret;
    // std::string link =
    //         url + std::string("#") + lpsm::GenerateSlug(wordURL, '-');
    std::string link     = lpsm::GenerateURL(wordURL);
    std::string sentence = lpsm::GenerateSentence(word, frag);
    if (!useHtml)
    {
        ret += std::string("[") += sentence += std::string("](") += link += ")";
    }
    else
    {
        ret += std::string("<a href=\"") + link + std::string("\">") +
               sentence + "</a>";
    }
    return ret;
}

std::string lpsm::GenerateMarkdownEmphasis(bool                 isBold,
                                           const lpsm::ArgVec2& word,
                                           const lpsm::ArgVec2& frag,
                                           bool                 useHtml)
{
    std::string ret;
    std::string sent = lpsm::GenerateSentence(word, frag);

    if (!useHtml)
    {
        ret += "*";
        if (isBold)
        {
            ret += "*";
        }
    }
    else
    {
        if (isBold)
        {
            ret += "<strong>";
        }
        else
        {
            ret += "<em>";
        }
    }

    ret += sent;

    if (!useHtml)
    {
        ret += "*";
        if (isBold)
        {
            ret += "*";
        }
    }
    else
    {
        if (isBold)
        {
            ret += "</strong>";
        }
        else
        {
            ret += "</em>";
        }
    }
    return ret;
}

std::string
lpsm::GenerateMarkdownHeader(int level, const lpsm::ArgVec2& word, bool useHtml)
{
    if (level > 6 || level < 1)
    {
        std::cerr << "lipsum-cpp warning: invalid header level " << level
                  << ", expected from 1 to 6\n";
    }
    std::string ret;
    std::string words = lpsm::GenerateSentenceFragment(word);
    words.at(0)       = std::toupper(words.at(0));
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
        ret += std::string("<h") + lpsm::internal::ToString(level) + ">";
        ret += words +=
                std::string("</h") + lpsm::internal::ToString(level) + ">";
    }
    return ret;
}
std::string lpsm::GenerateMarkdownParagraphs(int                  paraCount,
                                             const lpsm::ArgVec2& word,
                                             const lpsm::ArgVec2& frag,
                                             const lpsm::ArgVec2& sent,
                                             const lpsm::ArgVec2& wordFmt,
                                             const lpsm::ArgVec2& fragFmt,
                                             const lpsm::ArgVec2& wordLink,
                                             bool                 useLipsum,
                                             bool                 useHtml)
{
    std::string ret;
    for (int i = 0; i < paraCount; ++i)
    {
        if (i == 0 && useLipsum)
        {
            ret += lpsm::GenerateMarkdownParagraph(word,
                                                   frag,
                                                   sent,
                                                   wordFmt,
                                                   fragFmt,
                                                   wordLink,
                                                   true,
                                                   useHtml);
        }
        else
        {
            ret += lpsm::GenerateMarkdownParagraph(word,
                                                   frag,
                                                   sent,
                                                   wordFmt,
                                                   fragFmt,
                                                   wordLink,
                                                   false,
                                                   useHtml);
        }
    }
    return ret;
}

/**
 * @file lipsum/markdown.inl
 *
 * @brief Markdown functions of lipsum-cpp
 *
 * This defines functions in lipsum-cpp around generation of Markdown text.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
std::string lpsm::GenerateMarkdownText(const ArgVec2&     word,
                                       const ArgVec2&     frag,
                                       const ArgVec2&     sent,
                                       const ArgVec2&     point,
                                       const ArgVec2&     wordFmt,
                                       const ArgVec2&     fragFmt,
                                       const ArgVec2&     wordHead,
                                       const ArgVec2&     level,
                                       const std::string& linkURL,
                                       int                numElements)
{
    std::string ret;
    ret += lpsm::GenerateMarkdownHeader(1, wordHead);
    ret += lpsm::GenerateMarkdownParagraph(word,
                                           frag,
                                           sent,
                                           wordFmt,
                                           fragFmt,
                                           wordHead,
                                           linkURL,
                                           false);
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
                                                       linkURL,
                                                       false);
                break;
            }
            case 1:
            {
                ret += lpsm::GenerateMarkdownHeader(level.Roll(), wordHead);
                break;
            }
            case 2:
            {
                ret += lpsm::GenerateMarkdownList(ordered,
                                                  wordFmt,
                                                  fragFmt,
                                                  point);
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
                                       const lpsm::ArgVec2& point)
{
    std::string ret;
    int         points = point.Roll();
    for (int i = 0; i < points; ++i)
    {
        if (ordered)
        {
            ret += lpsm::internal::ToString(i + 1) += ". ";
        }
        else
        {
            ret += "- ";
        }
        ret += lpsm::GenerateSentence(word, frag) += "\n";
    }
    ret += "\n";
    return ret;
}

std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2& word,
                                            const lpsm::ArgVec2& frag,
                                            const lpsm::ArgVec2& sent,
                                            const ArgVec2&       wordFmt,
                                            const ArgVec2&       fragFmt,
                                            const ArgVec2&       wordLink,
                                            const std::string&   linkURL,
                                            bool                 useLipsum)
{
    std::string   ret;
    int           sents = sent.Roll();
    int           fmtRoll;
    bool          addLink;
    bool          isBold;
    lpsm::ArgVec2 linkEmph = ArgVec2(0, 1);
    lpsm::ArgVec2 boldItal = ArgVec2(0, 1);
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
            ret += lpsm::GenerateMarkdownLink(linkURL,
                                              wordFmt,
                                              fragFmt,
                                              wordLink);
        }
        else if ((fmtRoll == sent.min) && !addLink)
        {
            ret += lpsm::GenerateMarkdownEmphasis(isBold, wordFmt, fragFmt);
        }
        else
        {
            ret += lpsm::GenerateSentence(word, frag);
        }
        ret += " ";
    }
    ret += "\n\n";
    return ret;
}

std::string lpsm::GenerateMarkdownLink(const std::string&   url,
                                       const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& wordURL)
{
    std::string ret;
    ret += std::string("[") += lpsm::GenerateSentence(word, frag) +=
            std::string("](") += url;
    std::string words = lpsm::GenerateSentenceFragment(wordURL);
    for (char& c : words)
    {
        if (c == ' ')
        {
            c = '-';
        }
    }
    ret += std::string("#") += words += ")";
    return ret;
}

std::string lpsm::GenerateMarkdownEmphasis(bool                 isBold,
                                           const lpsm::ArgVec2& word,
                                           const lpsm::ArgVec2& frag)
{
    std::string ret;
    ret += "*";
    if (isBold)
    {
        ret += "*";
    }
    ret += lpsm::GenerateSentence(word, frag);
    ret += "*";
    if (isBold)
    {
        ret += "*";
    }
    return ret;
}

std::string lpsm::GenerateMarkdownHeader(int level, const lpsm::ArgVec2& word)
{
    std::string ret;
    for (int i = 0; i < level; ++i)
    {
        ret += "#";
    }
    ret += " ";
    std::string words = lpsm::GenerateSentenceFragment(word);
    words.at(0)       = std::toupper(words.at(0));
    ret += words += "\n\n";
    return ret;
}
std::string lpsm::GenerateMarkdownParagraphs(int                  paraCount,
                                             const lpsm::ArgVec2& word,
                                             const lpsm::ArgVec2& frag,
                                             const lpsm::ArgVec2& sent,
                                             const lpsm::ArgVec2& wordFmt,
                                             const lpsm::ArgVec2& fragFmt,
                                             const lpsm::ArgVec2& wordLink,
                                             const std::string&   linkURL,
                                             bool                 useLipsum)
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
                                                   linkURL,
                                                   true);
        }
        else
        {
            ret += lpsm::GenerateMarkdownParagraph(word,
                                                   frag,
                                                   sent,
                                                   wordFmt,
                                                   fragFmt,
                                                   wordLink,
                                                   linkURL,
                                                   false);
        }
    }
    return ret;
}

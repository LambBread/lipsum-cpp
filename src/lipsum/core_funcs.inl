/**
 * @file lipsum/core_funcs.inl
 *
 * @brief Core functions of lipsum-cpp
 *
 * This defines core functions in lipsum-cpp around generation of words,
 * sentences, paragraphs, etc. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

std::string lpsm::GenerateWords(int wordCount)
{
    std::string ret;
    for (int i = 0; i < wordCount; ++i)
    {
        ret += lpsm::GenerateWord() += " ";
    }
    ret.pop_back();
    return ret;
}

std::string lpsm::GenerateSentences(int                  sentCount,
                                    const lpsm::ArgVec2& word,
                                    const lpsm::ArgVec2& frag,
                                    bool                 useLipsum)
{
    std::string result;
    if (useLipsum)
    {
        result += lpsm::GenerateDefaultLipsumSentence() += " ";
        for (int i = 0; i < sentCount - 1; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        for (int i = 0; i < sentCount; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    return result;
}

std::string lpsm::GenerateDefaultLipsumSentence()
{
    return "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
}

std::string lpsm::GenerateWord()
{
#include "sample.inl"
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(0, lipsumVec.size() - 1);
    int randomIdx = lpsm::internal::RandomNumber(0, lipsumVec.size() - 1);
    return lipsumVec.at(randomIdx);
}

std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2& word)
{
    std::string result;
    int         numWords = word.Roll();
    for (int i = 0; i < numWords; ++i)
    {
        result += lpsm::GenerateWord() += " ";
    }
    result.pop_back(); // remove trailing space
    return result;
}

std::string lpsm::GenerateSentence(const lpsm::ArgVec2& word,
                                   const lpsm::ArgVec2& frag)
{
    constexpr int CHANCE_COMMA = 97;
    constexpr int CHANCE_SEMI  = 9;
    std::string   result;
    int           words = word.Roll();
    int           frags = frag.Roll();
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(0, 100);
    for (int i = 0; i < frags; ++i)
    {
        result += lpsm::GenerateSentenceFragment(word);
        int check = lpsm::internal::RandomNumber(0, 100);
        // don't do if only one fragment
        if (i != frags - 1)
        {
            if (check < CHANCE_SEMI)
            {
                result += "; ";
            }
            else if (check < CHANCE_COMMA)
            {
                result += ", ";
            }
            else
            {
                result += " - ";
            }
        }
    }
    result += ".";
    result.at(0) = std::toupper(result.at(0));
    return result;
}

std::string lpsm::GenerateParagraph(const lpsm::ArgVec2& word,
                                    const lpsm::ArgVec2& frag,
                                    const lpsm::ArgVec2& sent,
                                    bool                 useLipsum)
{
    std::string result = "\t";
    int         sents  = sent.Roll();
    if (!useLipsum)
    {
        for (int i = 0; i < sents; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for (int i = 0; i < sents - 1; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    // remove trailing space
    result.pop_back();
    result += "\n";
    return result;
}

std::string lpsm::GenerateParagraphs(int                  paraCount,
                                     const lpsm::ArgVec2& word,
                                     const lpsm::ArgVec2& frag,
                                     const lpsm::ArgVec2& sent,
                                     bool                 useLipsum)
{
    std::string result;
    if (!useLipsum)
    {

        for (int i = 0; i < paraCount; ++i)
        {
            result += lpsm::GenerateParagraph(word, frag, sent, false);
        }
    }
    else
    {
        result += lpsm::GenerateParagraph(word, frag, sent, true);
        for (int i = 0; i < paraCount - 1; ++i)
        {
            result += lpsm::GenerateParagraph(word, frag, sent, false);
        }
    }
    return result;
}

std::string lpsm::GenerateText(const ArgVec2& word,
                               const ArgVec2& frag,
                               const ArgVec2& sent,
                               const ArgVec2& para,
                               bool           useLipsum)
{
    std::string ret;
    int         paras = para.Roll();
    for (int i = 0; i < paras; ++i)
    {
        if (i == 0 && useLipsum)
        {
            ret += lpsm::GenerateParagraph(word, frag, sent, true);
        }
        else
        {
            ret += lpsm::GenerateParagraph(word, frag, sent, false);
        }
        ret += "\n";
    }
    return ret;
}

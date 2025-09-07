#pragma once
#ifndef __cplusplus
#error lipsum-cpp only supports C++, did you mean lipsum.h?
#endif
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <cctype>
namespace lipsum
{
//Generate a random word.
std::string GenerateWord();
//Generate a random sentence.
//Takes in an int minWord and an int maxWord, which are by default 4 and 12.
//minWord : minimum number of words, maxWord : maximum number of words
std::string GenerateSentence(int minWord = 4, int maxWord = 12);
//Generate a random paragraph.
//Takes in four ints: minSent, maxSent, minWord, and maxWord.
//By default 5, 8, 4, and 12.
//minSent : minimum number of sentences
//maxSent : maximum number of sentences
//minWord : minimum number of words per sentence
//maxWord : maximum number of words per sentence
std::string GenerateParagraph(int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12);
//Generate multiple paragraphs
//Takes in five ints: paraCount, minSent, maxSent, minWord, and maxWord.
//By default 5, 5, 8, 4, and 12.
//paraCount : number of paragraphs
//rest explained in above function
std::string GenerateParagraphList(int paraCount = 5, int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12);
}
#ifdef LIPSUM_IMPLEMENTATION
std::string lipsum::GenerateWord()
{
#include "lipsum.inl"
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, lipsumVec.size() - 1);
    return lipsumVec.at(dist(gen));
}
std::string lipsum::GenerateSentence(int minWord, int maxWord)
{
    std::string result;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist2(minWord, maxWord);
    int words = dist2(gen);
    bool includecomma = (words >= (maxWord * 4) / 5);
    for(int i = 0; i < words; ++i)
    {
        result += lipsum::GenerateWord();
        if(includecomma && i == (words / 2) - 1)
        {
            result += ",";
        }
        if(i != words - 1)
        {
            result += " ";
        }
    }
    result += ".";
    result.at(0) = std::toupper(result.at(0));
    return result;
}
std::string lipsum::GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord)
{
    std::string result = "\t";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minSent, maxSent);
    int sents = dist(gen);
    for(int i = 0; i < sents; ++i)
    {
        result += GenerateSentence(minWord, maxWord) += " ";
    }
    result += "\n";
    return result;
}
std::string lipsum::GenerateParagraphList(int paraCount, int minSent, int maxSent, int minWord, int maxWord)
{
    std::string result;
    for(int i = 0; i < paraCount; ++i)
    {
        result += lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord);
    }
    return result;
}
#endif

/** @file lipsum.hpp
 * @brief Main header of lipsum-cpp
 *
 * This contains the declarations of functions as well as definitions
 * if LIPSUM_IMPLEMENTATION is defined
 *
 * @author LambBread from github.com
 */
#pragma once
#ifndef __cplusplus
#error lipsum.hpp only supports C++, did you mean lipsum.h?
#endif
#include <vector>
#include <sstream>
#include <string>
#include <random>
#include <cctype>
namespace lipsum
{
    namespace internal
    {
        std::string HandleHTMLEntity(const std::string& str);
    }
/**
 * @brief Generate a random word.
 *
 * This function generates a random word from a predefined list.
 *
 * @return std::string Returns the random word.
 */
std::string GenerateWord();
/**
 * @brief Generate a random sentence.
 *
 * This function generates a sentence starting with a capital letter
 * and ending with a period, sometimes containing a comma.
 *
 * @return std::string Returns the random sentence.
 *
 * @param minWord Minimum number of words in the sentence. By default set to 4.
 * 
 * @param maxWord Maximum number of words in the sentence. By default set to 12.
 * 
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence. By default set to 0.75
 */
std::string GenerateSentence(int minWord = 4, int maxWord = 12, float ratio = 0.75f);
/**
 * @brief Generate a random paragraph.
 *
 * This function generates a random paragraph starting with a tab character and ending in a
 * line break, with each sentence separated by a space.
 *
 * @return std::string Returns the random paragraph.
 *
 * @param minSent Minimum number of sentences in the paragraph. By default set to 5.
 * 
 * @param maxSent Maximum number of sentences in the paragraph. By default set to 8.
 *
 * @param minWord Minimum number of words in each sentence. By default set to 4.
 *
 * @param maxWord Maximum number of words in each sentence. By default set to 12.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the paragraph. By default set to true.
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence. By default set to 0.75.
 */
std::string GenerateParagraph(int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12, bool useLipsum = true, float ratio = 0.75f);
/**
 * @brief Generate several random paragraphs at once.
 *
 * This function generates several random paragraphs, each separated by a line break. Formerly known as lipsum::GenerateParagraphList().
 * 
 * @return std::string Returns the random paragraphs.
 *
 * @param paraCount The number of paragraphs. By default set to 5.
 *
 * @param minSent The minimum number of sentences per paragraph. By default set to 5.
 *
 * @param maxSent The maximum number of sentences per paragraph. By default set to 8.
 *
 * @param minWord The minimum number of words per sentence. By default set to 4.
 *
 * @param maxWord The maximum number of words per sentence. By default set to 12.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the first paragraph. By default set to true.
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence. By default set to 0.75
 */
std::string GenerateParagraphs(int paraCount = 5, int minSent = 5, int maxSent = 8, int minWord = 4, int maxWord = 12, bool useLipsum = true, float ratio = 0.75f);

/**
 * @brief Generate the beginning Lorem Ipsum sentence.
 * 
 * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
 *
 * @return std::string Returns the default Lorem Ipsum sentence.
 */
std::string GenerateDefaultLipsumSentence();
/**
 * @brief Generate multiple random sentences at once.
 *
 * Generate multiple random sentences separated with spaces. Does not add a tab character before the sentences
 * nor a line break after.
 *
 * @return std::string Returns the random sentences.
 *
 * @param sentCount The number of sentences. By default set to 6.
 *
 * @param minWord The minimum number of words per sentence. By default set to 4.
 *
 * @param maxWord The maximum number of words per sentence. By default set to 12.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." sentence should be the first sentence. By default set to true.
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence. By default set to 0.75.
 */
std::string GenerateSentences(int sentCount = 6, int minWord = 4, int maxWord = 12, bool useLipsum = true, float ratio = 0.75f);
/**
 * @brief Turn a string into HTML paragraph tags.
 *
 * Add <p> and </p> around the paragraphs and
 * handle HTML entities like &, <, >, etc.
 *
 * @return std::string The HTML-ified string.
 *
 * @param str The string inputted.
 */
std::string HTMLify(const std::string& str);
}
#ifdef LIPSUM_IMPLEMENTATION
std::string lipsum::internal::HandleHTMLEntity(const std::string& str)
{
    std::string result;
    for(const auto& c : str)
    {
        switch(c)
        {
            case '&':
            {
                result += "&amp;";
                break;
            }
            case '<':
            {
                result += "&lt;";
                break;
            }
            case '>':
            {
                result += "&gt;";
                break;
            }
            case '"':
            {
                result += "&quot;";
                break;
            }
            case '\'':
            {
                result += "&apos;";
                break;
            }
            default:
            {
                result.push_back(c);
            }
        }
    }
    return result;
}
std::string lipsum::HTMLify(const std::string& str)
{
    std::stringstream ss(str);
    std::string line;
    std::string result;
    while(std::getline(ss, line))
    {
        if(!line.empty())
        {
            result += std::string("<p>") += lipsum::internal::HandleHTMLEntity(line) += std::string("</p>\n");
        }
    }
    return result;
}
std::string lipsum::GenerateSentences(int sentCount, int minWord, int maxWord, bool useLipsum, float ratio)
{
    std::string result;
    if(useLipsum)
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for(int i = 0; i < sentCount - 1; ++i)
        {
            result += lipsum::GenerateSentence(minWord, maxWord, ratio) += " ";
        }
    }
    else
    {
        for(int i = 0; i < sentCount; ++i)
        {
            result += lipsum::GenerateSentence(minWord, maxWord, ratio) += " ";
        }
    }
    return result;
}
std::string lipsum::GenerateDefaultLipsumSentence()
{
    return "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
}
std::string lipsum::GenerateWord()
{
#include "lipsum.inl"
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, lipsumVec.size() - 1);
    return lipsumVec.at(dist(gen));
}
std::string lipsum::GenerateSentence(int minWord, int maxWord, float ratio)
{
    std::string result;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist2(minWord, maxWord);
    int words = dist2(gen);
    bool includecomma = (words >= (maxWord * ratio));
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
std::string lipsum::GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    std::string result = "\t";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minSent, maxSent);
    int sents = dist(gen);
    if(!useLipsum)
    {
        for(int i = 0; i < sents; ++i)
        {
            result += lipsum::GenerateSentence(minWord, maxWord, ratio) += " ";
        }
    }
    else
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for(int i = 0; i < sents - 1; ++i)
        {
            result += lipsum::GenerateSentence(minWord, maxWord, ratio) += " ";
        }
    }
    result += "\n";
    return result;
}
std::string lipsum::GenerateParagraphs(int paraCount, int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    std::string result;
    if(!useLipsum)
    {

        for(int i = 0; i < paraCount; ++i)
        {
            result += lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, false, ratio);
        }
    }
    else
    {
        result += lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, true);
        for(int i = 0; i < paraCount - 1; ++i)
        {
            result += lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, false, ratio);
        }
    }
    return result;
}
#endif

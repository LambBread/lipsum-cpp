/** @file lipsum_h.cpp
 * 
 * @brief Contains the definitions of all the C wrapper's functions.
 *
 * This file defines all the functions from lipsum.h
 *
 * @author LambBread from github.com
 */
#include "lipsum.h"
#include "lipsum.hpp"
const char* lpsm_GenerateSentence(int minWord, int maxWord, float ratio)
{
    return lipsum::GenerateSentence(minWord, maxWord, ratio).c_str();
}
const char* lpsm_GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, useLipsum, ratio).c_str();
}
const char* lpsm_GenerateParagraphs(int paraCount, int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return lipsum::GenerateParagraphs(paraCount, minSent, maxSent, minWord, maxWord, useLipsum, ratio).c_str();
}
const char* lpsm_GenerateWord(void)
{
    return lipsum::GenerateWord().c_str();
}
const char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return lipsum::GenerateDefaultLipsumSentence().c_str();
}
const char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return lipsum::GenerateSentences(sentCount, minWord, maxWord, useLipsum, ratio).c_str();
}
const char* lpsm_HTMLify(const char* str)
{
    return lipsum::HTMLify(std::string(str)).c_str();
}

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
#include <string.h>
static char* ConvertToCstr(const std::string& str)
{
    std::string result = str;
    char* cstr = new char[result.size() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}
extern "C" char* lpsm_GenerateSentence(int minWord, int maxWord, float ratio)
{
    return ConvertToCstr(lipsum::GenerateSentence(minWord, maxWord, ratio));
}
extern "C" char* lpsm_GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return ConvertToCstr(lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, useLipsum, ratio));
}
extern "C" char* lpsm_GenerateParagraphs(int paraCount, int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return ConvertToCstr(lipsum::GenerateParagraphs(paraCount, minSent, maxSent, minWord, maxWord, useLipsum, ratio));
}
extern "C" char* lpsm_GenerateWord(void)
{
    return ConvertToCstr(lipsum::GenerateWord());
}
extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lipsum::GenerateDefaultLipsumSentence());
}
extern "C" char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, bool useLipsum, float ratio)
{
    return ConvertToCstr(lipsum::GenerateSentences(sentCount, minWord, maxWord, useLipsum, ratio));
}
extern "C" char* lpsm_HTMLify(char* str)
{
    return ConvertToCstr(lipsum::HTMLify(std::string(str)));
}
extern "C" void lpsm_DeleteString(char* str)
{
    delete[] str;
}

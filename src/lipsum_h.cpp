/**
 * @file lipsum_h.cpp
 * 
 * @brief Contains the definitions of all the C wrapper's functions.
 * 
 * This file defines all the functions declared in lipsum.h.
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

extern "C" char* lpsm_GenerateSentence(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return ConvertToCstr(lipsum::GenerateSentence(lipsum::ArgVec2(minWord, maxWord), lipsum::ArgVec2(minFrag, maxFrag)));
}

extern "C" char* lpsm_GenerateParagraph(int minWord, int maxWord, int minFrag, int maxFrag, int minSent, int maxSent, bool useLipsum)
{
    return ConvertToCstr(lipsum::GenerateParagraph(lipsum::ArgVec2(minWord, maxWord), lipsum::ArgVec2(minFrag, maxFrag), lipsum::ArgVec2(minSent, maxSent), useLipsum));
}

extern "C" char* lpsm_GenerateParagraphs(int paraCount, int minWord, int maxWord, int minFrag, int maxFrag, int minSent, 
        int maxSent, bool useLipsum)
{
    return ConvertToCstr(lipsum::GenerateParagraphs(paraCount, lipsum::ArgVec2(minWord, maxWord), lipsum::ArgVec2(minFrag, maxFrag),
                lipsum::ArgVec2(minSent, maxSent), useLipsum));
}

extern "C" char* lpsm_GenerateWord(void)
{
    return ConvertToCstr(lipsum::GenerateWord());
}

extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lipsum::GenerateDefaultLipsumSentence());
}

extern "C" char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, int minFrag, int maxFrag, bool useLipsum)
{
    return ConvertToCstr(lipsum::GenerateSentences(sentCount, lipsum::ArgVec2(minWord, maxWord),
                lipsum::ArgVec2(minFrag, maxFrag),useLipsum));
}

extern "C" char* lpsm_HTMLify(const char* str)
{
    return ConvertToCstr(lipsum::HTMLify(std::string(str)));
}

extern "C" void lpsm_DeleteString(char* str)
{
    delete[] str;
}

extern "C" char* lpsm_GenerateSentenceFragment(int minWord, int maxWord)
{
    return ConvertToCstr(lipsum::GenerateSentenceFragment(lipsum::ArgVec2(minWord, maxWord)));
}

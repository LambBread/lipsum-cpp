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

extern "C" char* lpsm_GenerateSentence(
        int minWord, int maxWord, 
        int minFrag, int maxFrag, 
        int seed)
{
    return ConvertToCstr
        (
            lipsum::GenerateSentenceX
            (
                minWord, maxWord,
                minFrag, maxFrag,
                seed
            )
        );
}

extern "C" char* lpsm_GenerateParagraph(
        int minWord, int maxWord,
        int minFrag, int maxFrag, 
        int minSent, int maxSent, 
        bool useLipsum, int seed)
{
    return ConvertToCstr
        (
            lipsum::GenerateParagraphX
            (
                minWord, maxWord,
                minFrag, maxFrag,
                minSent, maxSent,
                useLipsum, seed
            )
        );
}

extern "C" char* lpsm_GenerateParagraphs(
        int paraCount,
        int minWord, int maxWord,
        int minFrag, int maxFrag,
        int minSent, int maxSent,
        bool useLipsum, int seed)
{
    return ConvertToCstr
        (
            lipsum::GenerateParagraphsX
            (
                paraCount, 
                minWord, maxWord, 
                minFrag, maxFrag,
                minSent, maxSent,
                useLipsum, seed
            )
        );
}

extern "C" char* lpsm_GenerateWord(int seed)
{
    return ConvertToCstr(lipsum::GenerateWord(seed));
}

extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lipsum::GenerateDefaultLipsumSentence());
}

extern "C" char* lpsm_GenerateSentences(
        int sentCount,
        int minWord, int maxWord,
        int minFrag, int maxFrag,
        bool useLipsum, int seed)
{
    return ConvertToCstr
        (
            lipsum::GenerateSentencesX
            (
                sentCount, 
                minWord, maxWord,
                minFrag, maxFrag,
                useLipsum, seed
            )
        );
}

extern "C" char* lpsm_HTMLify(const char* str)
{
    return ConvertToCstr(lipsum::HTMLify(str));
}

extern "C" void lpsm_DeleteString(char* str)
{
    delete[] str;
}

extern "C" char* lpsm_GenerateSentenceFragment(int minWord, int maxWord, int seed)
{
    return ConvertToCstr
        (
            lipsum::GenerateSentenceFragmentX
            (
                minWord, maxWord,
                seed
            )
        );
}

/**
 * @file lipsum_h.cpp
 *
 * @brief Contains the definitions of all the C wrapper's functions.
 *
 * This file defines all the functions declared in lipsum.h.
 *
 * @author LambBread from github.com
 */
#include <string.h>

#include "lipsum.h"
#include "lipsum.hpp"
static char* ConvertToCstr(const std::string& str)
{
    std::string result = str;
    char*       cstr   = new char[result.size() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}

extern "C" char* lpsm_gen_word(int num)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.word(num));
}

extern "C" char* lpsm_gen_sentence(int num, bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.sentence(num, useLipsum));
}

extern "C" char* lpsm_gen_sentence_fragment(void)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.sentence_fragment());
}

extern "C" char* lpsm_gen_paragraph(int num, bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.paragraph(num, useLipsum));
}

extern "C" char*
lpsm_GenerateSentence(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return ConvertToCstr(
            lpsm::GenerateSentenceX(minWord, maxWord, minFrag, maxFrag));
}

extern "C" char* lpsm_GenerateParagraph(int  minWord,
                                        int  maxWord,
                                        int  minFrag,
                                        int  maxFrag,
                                        int  minSent,
                                        int  maxSent,
                                        bool useLipsum)
{
    return ConvertToCstr(lpsm::GenerateParagraphX(minWord,
                                                  maxWord,
                                                  minFrag,
                                                  maxFrag,
                                                  minSent,
                                                  maxSent,
                                                  useLipsum));
}

extern "C" char* lpsm_GenerateParagraphs(int  paraCount,
                                         int  minWord,
                                         int  maxWord,
                                         int  minFrag,
                                         int  maxFrag,
                                         int  minSent,
                                         int  maxSent,
                                         bool useLipsum)
{
    return ConvertToCstr(lpsm::GenerateParagraphsX(paraCount,
                                                   minWord,
                                                   maxWord,
                                                   minFrag,
                                                   maxFrag,
                                                   minSent,
                                                   maxSent,
                                                   useLipsum));
}

extern "C" char* lpsm_GenerateWord(void)
{
    return ConvertToCstr(lpsm::GenerateWord());
}

extern "C" char* lpsm_GenerateWords(int wordCount)
{
    return ConvertToCstr(lpsm::GenerateWords(wordCount));
}

extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lpsm::GenerateDefaultLipsumSentence());
}

extern "C" char* lpsm_GenerateSentences(int  sentCount,
                                        int  minWord,
                                        int  maxWord,
                                        int  minFrag,
                                        int  maxFrag,
                                        bool useLipsum)
{
    return ConvertToCstr(lpsm::GenerateSentencesX(sentCount,
                                                  minWord,
                                                  maxWord,
                                                  minFrag,
                                                  maxFrag,
                                                  useLipsum));
}

extern "C" char* lpsm_HTMLify(const char* str)
{
    return ConvertToCstr(lpsm::HTMLify(str));
}

extern "C" void lpsm_DeleteString(char* str)
{
    delete[] str;
}

extern "C" char* lpsm_GenerateSentenceFragment(int minWord, int maxWord)
{
    return ConvertToCstr(lpsm::GenerateSentenceFragmentX(minWord, maxWord));
}

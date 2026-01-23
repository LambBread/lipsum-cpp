/**
 * @file lipsum_h.cpp
 *
 * @brief Contains the definitions of all the C wrapper's functions.
 *
 * This file defines all the functions declared in lipsum.h. This file is under
 * the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#include <cstring>

#include "lipsum.h"
#include "lipsum.hpp"
static char* ConvertToCstr(const std::string& str)
{
    std::string result = str;
    char*       cstr   = new char[result.size() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}

extern "C" char*
lpsm_GenerateMarkdownHeader(int level, int minWord, int maxWord)
{
    return ConvertToCstr(
            lpsm::GenerateMarkdownHeaderX(level, minWord, maxWord));
}

extern "C" char* lpsm_GenerateMarkdownEmphasis(
        bool isBold, int minWord, int maxWord, int minFrag, int maxFrag)
{
    return ConvertToCstr(lpsm::GenerateMarkdownEmphasisX(isBold,
                                                         minWord,
                                                         maxWord,
                                                         minFrag,
                                                         maxFrag));
}

extern "C" char* lpsm_GenerateMarkdownLink(const char* url,
                                           int         minWord,
                                           int         maxWord,
                                           int         minFrag,
                                           int         maxFrag,
                                           int         minWordURL,
                                           int         maxWordURL)
{
    return ConvertToCstr(lpsm::GenerateMarkdownLinkX(url,
                                                     minWord,
                                                     maxWord,
                                                     minFrag,
                                                     maxFrag,
                                                     minWordURL,
                                                     maxWordURL));
}

extern "C" char* lpsm_GenerateMarkdownList(bool ordered,
                                           int  minWord,
                                           int  maxWord,
                                           int  minFrag,
                                           int  maxFrag,
                                           int  minPoint,
                                           int  maxPoint)
{
    return ConvertToCstr(lpsm::GenerateMarkdownListX(ordered,
                                                     minWord,
                                                     maxWord,
                                                     minFrag,
                                                     maxFrag,
                                                     minPoint,
                                                     maxPoint));
}

extern "C" lpsm_ArgVec2Handle lpsm_ArgVec2(int min, int max)
{
    return reinterpret_cast<lpsm_ArgVec2Handle>(new lpsm::ArgVec2(min, max));
}

extern "C" void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle av2)
{
    lpsm::ArgVec2* realAv2 = reinterpret_cast<lpsm::ArgVec2*>(av2);
    delete realAv2;
}

extern "C" int lpsm_ArgVec2Roll(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->Roll();
}

extern "C" int lpsm_ArgVec2GetMin(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->min;
}

extern "C" int lpsm_ArgVec2GetMax(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->max;
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

extern "C" char* lpsm_gen_md_paragraph(bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.md_paragraph(useLipsum));
}

extern "C" char* lpsm_gen_md_text(int numElements)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.md_text(numElements));
}

extern "C" char*
lpsm_GenerateSentence(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return ConvertToCstr(
            lpsm::GenerateSentenceX(minWord, maxWord, minFrag, maxFrag));
}

extern "C" int lpsm_CountSentences(const char* str)
{
    return lpsm::CountSentences(std::string(str));
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

extern "C" char* lpsm_GenerateText(int  minWord,
                                   int  maxWord,
                                   int  minFrag,
                                   int  maxFrag,
                                   int  minSent,
                                   int  maxSent,
                                   int  minPara,
                                   int  maxPara,
                                   bool useLipsum)
{
    return ConvertToCstr(lpsm::GenerateTextX(minWord,
                                             maxWord,
                                             minFrag,
                                             maxFrag,
                                             minSent,
                                             maxSent,
                                             minPara,
                                             maxPara,
                                             useLipsum));
}

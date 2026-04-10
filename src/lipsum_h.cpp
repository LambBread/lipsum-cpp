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

// angle brackets to stop quom from doing stuff
#include <lipsum.h>
#include <lipsum.hpp>

#define LPSM_CPPIFY(x) (*(reinterpret_cast<lpsm::ArgVec2*>((x))))
#define LPSM_SRC_CPPIFY(x) (*(reinterpret_cast<lpsm::Source*>((x))))

static char* ConvertToCstr(const std::string& str)
{
    std::string result = str;
    char*       cstr   = new char[result.size() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}

#include "lipsumc/binded.inl"
#include "lipsumc/sfuncs.inl"

/*
 * BULK
 * ----------------
 */

extern "C" char* lpsm_GenerateWords(int wordCount, lpsm_SourceHandle source)
{
    return ConvertToCstr(
            lpsm::GenerateWords(wordCount, LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateSentences(int               sentCount,
                                        int               minWord,
                                        int               maxWord,
                                        int               minFrag,
                                        int               maxFrag,
                                        bool              useLipsum,
                                        lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateSentencesX(sentCount,
                                                  minWord,
                                                  maxWord,
                                                  minFrag,
                                                  maxFrag,
                                                  useLipsum,
                                                  LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateParagraphs(int               paraCount,
                                         int               minWord,
                                         int               maxWord,
                                         int               minFrag,
                                         int               maxFrag,
                                         int               minSent,
                                         int               maxSent,
                                         bool              useLipsum,
                                         lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateParagraphsX(paraCount,
                                                   minWord,
                                                   maxWord,
                                                   minFrag,
                                                   maxFrag,
                                                   minSent,
                                                   maxSent,
                                                   useLipsum,
                                                   LPSM_SRC_CPPIFY(source)));
}

/*
 * MISC
 * ----------------
 */

extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lpsm::GenerateDefaultLipsumSentence());
}

extern "C" char* lpsm_GenerateScramble(int length, char min, char max)
{
    return ConvertToCstr(lpsm::GenerateScramble(length, min, max));
}

extern "C" char* lpsm_GeneratePlainURL(lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GeneratePlainURL(LPSM_SRC_CPPIFY(source)));
}

extern "C" char*
lpsm_GenerateURL(int minWord, int maxWord, lpsm_SourceHandle source)
{
    return ConvertToCstr(
            lpsm::GenerateURLX(minWord, maxWord, LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateSlug(int               minWord,
                                   int               maxWord,
                                   char              separator,
                                   lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateSlugX(minWord,
                                             maxWord,
                                             separator,
                                             LPSM_SRC_CPPIFY(source)));
}

extern "C" int lpsm_CountWords(const char* str)
{
    return lpsm::CountWords(std::string(str));
}

extern "C" int lpsm_CountSentences(const char* str)
{
    return lpsm::CountSentences(std::string(str));
}

extern "C" void lpsm_DeleteString(char* str)
{
    delete[] str;
}

/*
 * CORE
 * ----------------
 */

extern "C" char* lpsm_GenerateWord(lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateWord(LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateSentenceFragment(int               minWord,
                                               int               maxWord,
                                               lpsm_SourceHandle source)
{
    return ConvertToCstr(
            lpsm::GenerateSentenceFragmentX(minWord,
                                            maxWord,
                                            LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateSentence(int               minWord,
                                       int               maxWord,
                                       int               minFrag,
                                       int               maxFrag,
                                       lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateSentenceX(minWord,
                                                 maxWord,
                                                 minFrag,
                                                 maxFrag,
                                                 LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateParagraph(int               minWord,
                                        int               maxWord,
                                        int               minFrag,
                                        int               maxFrag,
                                        int               minSent,
                                        int               maxSent,
                                        bool              useLipsum,
                                        lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateParagraphX(minWord,
                                                  maxWord,
                                                  minFrag,
                                                  maxFrag,
                                                  minSent,
                                                  maxSent,
                                                  useLipsum,
                                                  LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateText(int               minWord,
                                   int               maxWord,
                                   int               minFrag,
                                   int               maxFrag,
                                   int               minSent,
                                   int               maxSent,
                                   int               minPara,
                                   int               maxPara,
                                   bool              useLipsum,
                                   lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateTextX(minWord,
                                             maxWord,
                                             minFrag,
                                             maxFrag,
                                             minSent,
                                             maxSent,
                                             minPara,
                                             maxPara,
                                             useLipsum,
                                             LPSM_SRC_CPPIFY(source)));
}

/*
 * MARKDOWN
 * ----------------
 */

extern "C" char* lpsm_GenerateMarkdownHeader(int               level,
                                             int               minWord,
                                             int               maxWord,
                                             bool              useHtml,
                                             lpsm_SourceHandle source)
{
    return ConvertToCstr(
            lpsm::GenerateMarkdownHeaderX(level,
                                          minWord,
                                          maxWord,
                                          useHtml,
                                          LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateMarkdownEmphasis(bool              isBold,
                                               int               minWord,
                                               int               maxWord,
                                               int               minFrag,
                                               int               maxFrag,
                                               bool              useHtml,
                                               lpsm_SourceHandle source)
{
    return ConvertToCstr(
            lpsm::GenerateMarkdownEmphasisX(isBold,
                                            minWord,
                                            maxWord,
                                            minFrag,
                                            maxFrag,
                                            useHtml,
                                            LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateMarkdownLink(int               minWord,
                                           int               maxWord,
                                           int               minFrag,
                                           int               maxFrag,
                                           int               minWordURL,
                                           int               maxWordURL,
                                           bool              useHtml,
                                           lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateMarkdownLinkX(minWord,
                                                     maxWord,
                                                     minFrag,
                                                     maxFrag,
                                                     minWordURL,
                                                     maxWordURL,
                                                     useHtml,
                                                     LPSM_SRC_CPPIFY(source)));
}

extern "C" char* lpsm_GenerateMarkdownList(bool              ordered,
                                           int               minWord,
                                           int               maxWord,
                                           int               minFrag,
                                           int               maxFrag,
                                           int               minPoint,
                                           int               maxPoint,
                                           bool              useHtml,
                                           lpsm_SourceHandle source)
{
    return ConvertToCstr(lpsm::GenerateMarkdownListX(ordered,
                                                     minWord,
                                                     maxWord,
                                                     minFrag,
                                                     maxFrag,
                                                     minPoint,
                                                     maxPoint,
                                                     useHtml,
                                                     LPSM_SRC_CPPIFY(source)));
}

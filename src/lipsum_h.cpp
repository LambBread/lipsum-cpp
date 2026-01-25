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
#define LPSM_CPPIFY(x) (*(reinterpret_cast<lpsm::ArgVec2*>((x))))

// macro shit go!!!
#define LPSM_AV2_DESTROY_1(x)                                                  \
    if (del)                                                                   \
    {                                                                          \
        lpsm_ArgVec2Destroy(x);                                                \
    }
#define LPSM_AV2_DESTROY_2(x, y) LPSM_AV2_DESTROY_1(x) LPSM_AV2_DESTROY_1(y)
#define LPSM_AV2_DESTROY_3(x, y, z)                                            \
    LPSM_AV2_DESTROY_2(x, y) LPSM_AV2_DESTROY_1(z)
#define LPSM_AV2_DESTROY_4(x, y, z, w)                                         \
    LPSM_AV2_DESTROY_3(x, y, z) LPSM_AV2_DESTROY_1(w)
#define LPSM_AV2_DESTROY_5(x, y, z, w, v)                                      \
    LPSM_AV2_DESTROY_4(x, y, z, w) LPSM_AV2_DESTROY_1(v)
#define LPSM_AV2_DESTROY_6(x, y, z, w, v, u)                                   \
    LPSM_AV2_DESTROY_5(x, y, z, w, v) LPSM_AV2_DESTROY_1(u)
#define LPSM_AV2_DESTROY_7(x, y, z, w, v, u, t)                                \
    LPSM_AV2_DESTROY_6(x, y, z, w, v, u) LPSM_AV2_DESTROY_1(t)
#define LPSM_AV2_DESTROY_8(x, y, z, w, v, u, t, s)                             \
    LPSM_AV2_DESTROY_7(x, y, z, w, v, u, t) LPSM_AV2_DESTROY_1(s)
#define LPSM_AV2_DESTROY(n, ...) LPSM_AV2_DESTROY_##n(__VA_ARGS__)

static char* ConvertToCstr(const std::string& str)
{
    std::string result = str;
    char*       cstr   = new char[result.size() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}

extern "C" char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle word,
                                                bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateSentenceFragment(LPSM_CPPIFY(word)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}

extern "C" char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle word,
                                        lpsm_ArgVec2Handle frag,
                                        bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateSentence(LPSM_CPPIFY(word), LPSM_CPPIFY(frag)));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}
extern "C" char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         lpsm_ArgVec2Handle sent,
                                         bool               useLipsum,
                                         bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateParagraph(LPSM_CPPIFY(word),
                                                      LPSM_CPPIFY(frag),
                                                      LPSM_CPPIFY(sent),
                                                      useLipsum));
    LPSM_AV2_DESTROY(3, word, frag, sent)
    return ret;
}
extern "C" char* lpsm_GenerateParagraphsS(int                paraCount,
                                          lpsm_ArgVec2Handle word,
                                          lpsm_ArgVec2Handle frag,
                                          lpsm_ArgVec2Handle sent,
                                          bool               useLipsum,
                                          bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateParagraphs(paraCount,
                                                       LPSM_CPPIFY(word),
                                                       LPSM_CPPIFY(frag),
                                                       LPSM_CPPIFY(sent),
                                                       useLipsum));
    LPSM_AV2_DESTROY(3, word, frag, sent)
    return ret;
}
extern "C" char* lpsm_GenerateSentencesS(int                sentCount,
                                         lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         bool               useLipsum,
                                         bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateSentences(sentCount,
                                                      LPSM_CPPIFY(word),
                                                      LPSM_CPPIFY(frag),
                                                      useLipsum));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}
extern "C" char* lpsm_GenerateTextS(lpsm_ArgVec2Handle word,
                                    lpsm_ArgVec2Handle frag,
                                    lpsm_ArgVec2Handle sent,
                                    lpsm_ArgVec2Handle para,
                                    bool               useLipsum,
                                    bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateText(LPSM_CPPIFY(word),
                                                 LPSM_CPPIFY(frag),
                                                 LPSM_CPPIFY(sent),
                                                 LPSM_CPPIFY(para),
                                                 useLipsum));
    LPSM_AV2_DESTROY(4, word, frag, sent, para)
    return ret;
}

extern "C" char*
lpsm_GenerateMarkdownHeaderS(int level, lpsm_ArgVec2Handle word, bool del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateMarkdownHeader(level, LPSM_CPPIFY(word)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownEmphasisS(bool               isBold,
                                                lpsm_ArgVec2Handle word,
                                                lpsm_ArgVec2Handle frag,
                                                bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateMarkdownEmphasis(isBold,
                                                         LPSM_CPPIFY(word),
                                                         LPSM_CPPIFY(frag)));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownLinkS(const char*        url,
                                            lpsm_ArgVec2Handle word,
                                            lpsm_ArgVec2Handle frag,
                                            lpsm_ArgVec2Handle wordURL,
                                            bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateMarkdownLink(std::string(url),
                                                         LPSM_CPPIFY(word),
                                                         LPSM_CPPIFY(frag),
                                                         LPSM_CPPIFY(wordURL)));
    LPSM_AV2_DESTROY(3, word, frag, wordURL)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownListS(bool               ordered,
                                            lpsm_ArgVec2Handle word,
                                            lpsm_ArgVec2Handle frag,
                                            lpsm_ArgVec2Handle point,
                                            bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateMarkdownList(ordered,
                                                         LPSM_CPPIFY(word),
                                                         LPSM_CPPIFY(frag),
                                                         LPSM_CPPIFY(point)));
    LPSM_AV2_DESTROY(3, word, frag, point)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle word,
                                                 lpsm_ArgVec2Handle frag,
                                                 lpsm_ArgVec2Handle sent,
                                                 lpsm_ArgVec2Handle wordFmt,
                                                 lpsm_ArgVec2Handle fragFmt,
                                                 lpsm_ArgVec2Handle wordLink,
                                                 const char*        linkURL,
                                                 bool               useLipsum,
                                                 bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateMarkdownParagraph(LPSM_CPPIFY(word),
                                                          LPSM_CPPIFY(frag),
                                                          LPSM_CPPIFY(sent),
                                                          LPSM_CPPIFY(wordFmt),
                                                          LPSM_CPPIFY(fragFmt),
                                                          LPSM_CPPIFY(wordLink),
                                                          std::string(linkURL),
                                                          useLipsum));
    LPSM_AV2_DESTROY(6, word, frag, sent, wordFmt, fragFmt, wordLink)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownParagraphsS(int                paraCount,
                                                  lpsm_ArgVec2Handle word,
                                                  lpsm_ArgVec2Handle frag,
                                                  lpsm_ArgVec2Handle sent,
                                                  lpsm_ArgVec2Handle wordFmt,
                                                  lpsm_ArgVec2Handle fragFmt,
                                                  lpsm_ArgVec2Handle wordLink,
                                                  const char*        linkURL,
                                                  bool               useLipsum,
                                                  bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateMarkdownParagraphs(paraCount,
                                             LPSM_CPPIFY(word),
                                             LPSM_CPPIFY(frag),
                                             LPSM_CPPIFY(sent),
                                             LPSM_CPPIFY(wordFmt),
                                             LPSM_CPPIFY(fragFmt),
                                             LPSM_CPPIFY(wordLink),
                                             std::string(linkURL),
                                             useLipsum));
    LPSM_AV2_DESTROY(6, word, frag, sent, wordFmt, fragFmt, wordLink)
    return ret;
}
extern "C" char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle word,
                                            lpsm_ArgVec2Handle frag,
                                            lpsm_ArgVec2Handle sent,
                                            lpsm_ArgVec2Handle point,
                                            lpsm_ArgVec2Handle wordFmt,
                                            lpsm_ArgVec2Handle fragFmt,
                                            lpsm_ArgVec2Handle wordHead,
                                            lpsm_ArgVec2Handle level,
                                            const char*        linkURL,
                                            int                numElements,
                                            bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateMarkdownText(LPSM_CPPIFY(word),
                                                         LPSM_CPPIFY(frag),
                                                         LPSM_CPPIFY(sent),
                                                         LPSM_CPPIFY(point),
                                                         LPSM_CPPIFY(wordFmt),
                                                         LPSM_CPPIFY(fragFmt),
                                                         LPSM_CPPIFY(wordHead),
                                                         LPSM_CPPIFY(level),
                                                         std::string(linkURL),
                                                         numElements));
    LPSM_AV2_DESTROY(8,
                     word,
                     frag,
                     sent,
                     point,
                     wordFmt,
                     fragFmt,
                     wordHead,
                     level)
    return ret;
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
    return ConvertToCstr(lpsm::GenerateMarkdownLinkX(std::string(url),
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

/**
 * @file lipsumc/sfuncs.h
 *
 * @brief S functions of lipsum-cpp C wrapper
 *
 * This defines the &quot;S&quot; variants of functions in lipsum-cpp's C
 * wrapper. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

/*
 * BULK
 * ----------------
 */

extern "C" char* lpsm_GenerateSentencesS(int                sentCount,
                                         lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         bool               useLipsum,
                                         lpsm_SourceHandle  source,
                                         bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateSentences(sentCount,
                                                      LPSM_CPPIFY(word),
                                                      LPSM_CPPIFY(frag),
                                                      useLipsum,
                                                      LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}

extern "C" char* lpsm_GenerateParagraphsS(int                paraCount,
                                          lpsm_ArgVec2Handle word,
                                          lpsm_ArgVec2Handle frag,
                                          lpsm_ArgVec2Handle sent,
                                          bool               useLipsum,
                                          lpsm_SourceHandle  source,
                                          bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateParagraphs(paraCount,
                                                   LPSM_CPPIFY(word),
                                                   LPSM_CPPIFY(frag),
                                                   LPSM_CPPIFY(sent),
                                                   useLipsum,
                                                   LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(3, word, frag, sent)
    return ret;
}

/*
 * MISC
 * ----------------
 */

extern "C" char*
lpsm_GenerateURLS(lpsm_ArgVec2Handle word, lpsm_SourceHandle source, bool del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateURL(LPSM_CPPIFY(word), LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}

extern "C" char* lpsm_GenerateSlugS(lpsm_ArgVec2Handle word,
                                    char               separator,
                                    lpsm_SourceHandle  source,
                                    bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateSlug(LPSM_CPPIFY(word),
                                                 separator,
                                                 LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}

/*
 * CORE
 * ----------------
 */

extern "C" char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle word,
                                                lpsm_SourceHandle  source,
                                                bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateSentenceFragment(LPSM_CPPIFY(word),
                                           LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}

extern "C" char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle word,
                                        lpsm_ArgVec2Handle frag,
                                        lpsm_SourceHandle  source,
                                        bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateSentence(LPSM_CPPIFY(word),
                                                     LPSM_CPPIFY(frag),
                                                     LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}

extern "C" char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         lpsm_ArgVec2Handle sent,
                                         bool               useLipsum,
                                         lpsm_SourceHandle  source,
                                         bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateParagraph(LPSM_CPPIFY(word),
                                                      LPSM_CPPIFY(frag),
                                                      LPSM_CPPIFY(sent),
                                                      useLipsum,
                                                      LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(3, word, frag, sent)
    return ret;
}

extern "C" char* lpsm_GenerateTextS(lpsm_ArgVec2Handle word,
                                    lpsm_ArgVec2Handle frag,
                                    lpsm_ArgVec2Handle sent,
                                    lpsm_ArgVec2Handle para,
                                    bool               useLipsum,
                                    lpsm_SourceHandle  source,
                                    bool               del)
{
    char* ret = ConvertToCstr(lpsm::GenerateText(LPSM_CPPIFY(word),
                                                 LPSM_CPPIFY(frag),
                                                 LPSM_CPPIFY(sent),
                                                 LPSM_CPPIFY(para),
                                                 useLipsum,
                                                 LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(4, word, frag, sent, para)
    return ret;
}

/*
 * MARKDOWN
 * ----------------
 */

extern "C" char* lpsm_GenerateMarkdownHeaderS(int                level,
                                              lpsm_ArgVec2Handle word,
                                              bool               useHtml,
                                              lpsm_SourceHandle  source,
                                              bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateMarkdownHeader(level,
                                         LPSM_CPPIFY(word),
                                         useHtml,
                                         LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(1, word)
    return ret;
}

extern "C" char* lpsm_GenerateMarkdownEmphasisS(bool               isBold,
                                                lpsm_ArgVec2Handle word,
                                                lpsm_ArgVec2Handle frag,
                                                bool               useHtml,
                                                lpsm_SourceHandle  source,
                                                bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateMarkdownEmphasis(isBold,
                                           LPSM_CPPIFY(word),
                                           LPSM_CPPIFY(frag),
                                           useHtml,
                                           LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(2, word, frag)
    return ret;
}

extern "C" char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle word,
                                            lpsm_ArgVec2Handle frag,
                                            lpsm_ArgVec2Handle wordURL,
                                            bool               useHtml,
                                            lpsm_SourceHandle  source,
                                            bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateMarkdownLink(LPSM_CPPIFY(word),
                                                     LPSM_CPPIFY(frag),
                                                     LPSM_CPPIFY(wordURL),
                                                     useHtml,
                                                     LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(3, word, frag, wordURL)
    return ret;
}

extern "C" char* lpsm_GenerateMarkdownListS(bool               ordered,
                                            lpsm_ArgVec2Handle word,
                                            lpsm_ArgVec2Handle frag,
                                            lpsm_ArgVec2Handle point,
                                            bool               useHtml,
                                            lpsm_SourceHandle  source,
                                            bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateMarkdownList(ordered,
                                                     LPSM_CPPIFY(word),
                                                     LPSM_CPPIFY(frag),
                                                     LPSM_CPPIFY(point),
                                                     useHtml,
                                                     LPSM_SRC_CPPIFY(source)));
    LPSM_AV2_DESTROY(3, word, frag, point)
    return ret;
}

extern "C" char* lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle word,
                                                 lpsm_ArgVec2Handle frag,
                                                 lpsm_ArgVec2Handle sent,
                                                 lpsm_ArgVec2Handle wordFmt,
                                                 lpsm_ArgVec2Handle fragFmt,
                                                 lpsm_ArgVec2Handle wordLink,
                                                 bool               useLipsum,
                                                 bool               useHtml,
                                                 lpsm_SourceHandle  source,
                                                 bool               del)
{
    char* ret = ConvertToCstr(
            lpsm::GenerateMarkdownParagraph(LPSM_CPPIFY(word),
                                            LPSM_CPPIFY(frag),
                                            LPSM_CPPIFY(sent),
                                            LPSM_CPPIFY(wordFmt),
                                            LPSM_CPPIFY(fragFmt),
                                            LPSM_CPPIFY(wordLink),
                                            useLipsum,
                                            useHtml,
                                            LPSM_SRC_CPPIFY(source)));
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
                                                  bool               useLipsum,
                                                  bool               useHtml,
                                                  lpsm_SourceHandle  source,
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
                                             useLipsum,
                                             useHtml,
                                             LPSM_SRC_CPPIFY(source)));
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
                                            int                numElements,
                                            bool               useHtml,
                                            lpsm_SourceHandle  source,
                                            bool               del)
{
    char* ret =
            ConvertToCstr(lpsm::GenerateMarkdownText(LPSM_CPPIFY(word),
                                                     LPSM_CPPIFY(frag),
                                                     LPSM_CPPIFY(sent),
                                                     LPSM_CPPIFY(point),
                                                     LPSM_CPPIFY(wordFmt),
                                                     LPSM_CPPIFY(fragFmt),
                                                     LPSM_CPPIFY(wordHead),
                                                     LPSM_CPPIFY(level),
                                                     numElements,
                                                     useHtml,
                                                     LPSM_SRC_CPPIFY(source)));
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

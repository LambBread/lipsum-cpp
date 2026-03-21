
/**
 * @file lipsum/xfuncs.inl
 *
 * @brief X functions of lipsum-cpp
 *
 * This defines the &quot;X&quot; variants of functions in lipsum-cpp. This file
 * is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

namespace lipsum
{

    std::string GenerateURLX(int minWord, int maxWord)
    {
        return GenerateURL(ArgVec2(minWord, maxWord));
    }
    std::string GenerateSlugX(int minWord, int maxWord, char separator)
    {
        return GenerateSlug(ArgVec2(minWord, maxWord), separator);
    }

    std::string
    GenerateMarkdownHeaderX(int level, int minWord, int maxWord, bool useHtml)
    {
        return GenerateMarkdownHeader(level,
                                      ArgVec2(minWord, maxWord),
                                      useHtml);
    }

    std::string GenerateMarkdownEmphasisX(bool isBold,
                                          int  minWord,
                                          int  maxWord,
                                          int  minFrag,
                                          int  maxFrag,
                                          bool useHtml)
    {
        return GenerateMarkdownEmphasis(isBold,
                                        lpsm::ArgVec2(minWord, maxWord),
                                        lpsm::ArgVec2(minFrag, maxFrag),
                                        useHtml);
    }

    std::string GenerateMarkdownLinkX(int  minWord,
                                      int  maxWord,
                                      int  minFrag,
                                      int  maxFrag,
                                      int  minWordURL,
                                      int  maxWordURL,
                                      bool useHtml)
    {
        return GenerateMarkdownLink(ArgVec2(minWord, maxWord),
                                    ArgVec2(minFrag, maxFrag),
                                    ArgVec2(minWordURL, maxWordURL),
                                    useHtml);
    }

    std::string GenerateMarkdownListX(bool ordered,
                                      int  minWord,
                                      int  maxWord,
                                      int  minFrag,
                                      int  maxFrag,
                                      int  minPoint,
                                      int  maxPoint,
                                      bool useHtml)
    {
        return GenerateMarkdownList(ordered,
                                    ArgVec2(minWord, maxWord),
                                    ArgVec2(minFrag, maxFrag),
                                    ArgVec2(minPoint, maxPoint),
                                    useHtml);
    }

    std::string GenerateSentencesX(int  sentCount,
                                   int  minWord,
                                   int  maxWord,
                                   int  minFrag,
                                   int  maxFrag,
                                   bool useLipsum)
    {
        return GenerateSentences(sentCount,
                                 ArgVec2(minWord, maxWord),
                                 ArgVec2(minFrag, maxFrag),
                                 useLipsum);
    }

    std::string GenerateParagraphsX(int  paraCount,
                                    int  minWord,
                                    int  maxWord,
                                    int  minFrag,
                                    int  maxFrag,
                                    int  minSent,
                                    int  maxSent,
                                    bool useLipsum)
    {
        return GenerateParagraphs(paraCount,
                                  ArgVec2(minWord, maxWord),
                                  ArgVec2(minFrag, maxFrag),
                                  ArgVec2(minSent, maxSent),
                                  useLipsum);
    }

    std::string GenerateParagraphX(int  minWord,
                                   int  maxWord,
                                   int  minFrag,
                                   int  maxFrag,
                                   int  minSent,
                                   int  maxSent,
                                   bool useLipsum)
    {
        return GenerateParagraph(ArgVec2(minWord, maxWord),
                                 ArgVec2(minFrag, maxFrag),
                                 ArgVec2(minSent, maxSent),
                                 useLipsum);
    }

    std::string
    GenerateSentenceX(int minWord, int maxWord, int minFrag, int maxFrag)
    {
        return GenerateSentence(ArgVec2(minWord, maxWord),
                                ArgVec2(minFrag, maxFrag));
    }

    std::string GenerateSentenceFragmentX(int minWord, int maxWord)
    {
        return GenerateSentenceFragment(ArgVec2(minWord, maxWord));
    }

    std::string GenerateTextX(int  minWord,
                              int  maxWord,
                              int  minFrag,
                              int  maxFrag,
                              int  minSent,
                              int  maxSent,
                              int  minPara,
                              int  maxPara,
                              bool useLipsum)
    {
        return GenerateText(ArgVec2(minWord, maxWord),
                            ArgVec2(minFrag, maxFrag),
                            ArgVec2(minSent, maxSent),
                            ArgVec2(minPara, maxPara),
                            useLipsum);
    }
} // namespace lipsum

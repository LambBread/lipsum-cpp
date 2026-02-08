
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

std::string lpsm::GenerateURLX(int minWord, int maxWord)
{
    return lpsm::GenerateURL(lpsm::ArgVec2(minWord, maxWord));
}
std::string lpsm::GenerateSlugX(int minWord, int maxWord, char separator)
{
    return lpsm::GenerateSlug(lpsm::ArgVec2(minWord, maxWord), separator);
}

std::string
lpsm::GenerateMarkdownHeaderX(int level, int minWord, int maxWord, bool useHtml)
{
    return lpsm::GenerateMarkdownHeader(level,
                                        lpsm::ArgVec2(minWord, maxWord),
                                        useHtml);
}

std::string lpsm::GenerateMarkdownEmphasisX(bool isBold,
                                            int  minWord,
                                            int  maxWord,
                                            int  minFrag,
                                            int  maxFrag,
                                            bool useHtml)
{
    return lpsm::GenerateMarkdownEmphasis(isBold,
                                          lpsm::ArgVec2(minWord, maxWord),
                                          lpsm::ArgVec2(minFrag, maxFrag),
                                          useHtml);
}

std::string lpsm::GenerateMarkdownLinkX(int  minWord,
                                        int  maxWord,
                                        int  minFrag,
                                        int  maxFrag,
                                        int  minWordURL,
                                        int  maxWordURL,
                                        bool useHtml)
{
    return lpsm::GenerateMarkdownLink(lpsm::ArgVec2(minWord, maxWord),
                                      lpsm::ArgVec2(minFrag, maxFrag),
                                      lpsm::ArgVec2(minWordURL, maxWordURL),
                                      useHtml);
}

std::string lpsm::GenerateMarkdownListX(bool ordered,
                                        int  minWord,
                                        int  maxWord,
                                        int  minFrag,
                                        int  maxFrag,
                                        int  minPoint,
                                        int  maxPoint,
                                        bool useHtml)
{
    return lpsm::GenerateMarkdownList(ordered,
                                      lpsm::ArgVec2(minWord, maxWord),
                                      lpsm::ArgVec2(minFrag, maxFrag),
                                      lpsm::ArgVec2(minPoint, maxPoint),
                                      useHtml);
}

std::string lpsm::GenerateSentencesX(int  sentCount,
                                     int  minWord,
                                     int  maxWord,
                                     int  minFrag,
                                     int  maxFrag,
                                     bool useLipsum)
{
    return lpsm::GenerateSentences(sentCount,
                                   lpsm::ArgVec2(minWord, maxWord),
                                   lpsm::ArgVec2(minFrag, maxFrag),
                                   useLipsum);
}

std::string lpsm::GenerateParagraphsX(int  paraCount,
                                      int  minWord,
                                      int  maxWord,
                                      int  minFrag,
                                      int  maxFrag,
                                      int  minSent,
                                      int  maxSent,
                                      bool useLipsum)
{
    return lpsm::GenerateParagraphs(paraCount,
                                    lpsm::ArgVec2(minWord, maxWord),
                                    lpsm::ArgVec2(minFrag, maxFrag),
                                    lpsm::ArgVec2(minSent, maxSent),
                                    useLipsum);
}

std::string lpsm::GenerateParagraphX(int  minWord,
                                     int  maxWord,
                                     int  minFrag,
                                     int  maxFrag,
                                     int  minSent,
                                     int  maxSent,
                                     bool useLipsum)
{
    return lpsm::GenerateParagraph(lpsm::ArgVec2(minWord, maxWord),
                                   lpsm::ArgVec2(minFrag, maxFrag),
                                   lpsm::ArgVec2(minSent, maxSent),
                                   useLipsum);
}

std::string
lpsm::GenerateSentenceX(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return lpsm::GenerateSentence(lpsm::ArgVec2(minWord, maxWord),
                                  lpsm::ArgVec2(minFrag, maxFrag));
}

std::string lpsm::GenerateSentenceFragmentX(int minWord, int maxWord)
{
    return lpsm::GenerateSentenceFragment(lpsm::ArgVec2(minWord, maxWord));
}

std::string lpsm::GenerateTextX(int  minWord,
                                int  maxWord,
                                int  minFrag,
                                int  maxFrag,
                                int  minSent,
                                int  maxSent,
                                int  minPara,
                                int  maxPara,
                                bool useLipsum)
{
    return lpsm::GenerateText(lpsm::ArgVec2(minWord, maxWord),
                              lpsm::ArgVec2(minFrag, maxFrag),
                              lpsm::ArgVec2(minSent, maxSent),
                              lpsm::ArgVec2(minPara, maxPara),
                              useLipsum);
}


/**
 * @file lipsum/core_xfuncs.inl
 *
 * @brief Core "X" functions of lipsum-cpp
 *
 * This defines the "X" varieties of core functions in lipsum-cpp around
 * generation of words, sentences, paragraphs, etc. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
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

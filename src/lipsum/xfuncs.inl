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

#ifndef LIPSUM_XFUNCS_INL
#    define LIPSUM_XFUNCS_INL

#    include "core/argvec2.hpp"
#    include "core_funcs.hpp"
#    include "formats.hpp"
#    include "markdown.hpp"

namespace lipsum
{
    /*
     * BULK
     * ----------------
     */

    std::string GenerateSentencesX(int           sentCount,
                                   int           minWord,
                                   int           maxWord,
                                   int           minFrag,
                                   int           maxFrag,
                                   bool          useLipsum,
                                   const Source& source)
    {
        return GenerateSentences(sentCount,
                                 ArgVec2(minWord, maxWord),
                                 ArgVec2(minFrag, maxFrag),
                                 useLipsum,
                                 source);
    }

    std::string GenerateParagraphsX(int           paraCount,
                                    int           minWord,
                                    int           maxWord,
                                    int           minFrag,
                                    int           maxFrag,
                                    int           minSent,
                                    int           maxSent,
                                    bool          useLipsum,
                                    const Source& source)
    {
        return GenerateParagraphs(paraCount,
                                  ArgVec2(minWord, maxWord),
                                  ArgVec2(minFrag, maxFrag),
                                  ArgVec2(minSent, maxSent),
                                  useLipsum,
                                  source);
    }

    /*
     * MISC
     * ----------------
     */

    std::string GenerateURLX(int minWord, int maxWord, const Source& source)
    {
        return GenerateURL(ArgVec2(minWord, maxWord), source);
    }

    std::string GenerateSlugX(int           minWord,
                              int           maxWord,
                              char          separator,
                              const Source& source)
    {
        return GenerateSlug(ArgVec2(minWord, maxWord), separator, source);
    }

    /*
     * CORE
     * ----------------
     */

    std::string
    GenerateSentenceFragmentX(int minWord, int maxWord, const Source& source)
    {
        return GenerateSentenceFragment(ArgVec2(minWord, maxWord), source);
    }

    std::string GenerateSentenceX(int           minWord,
                                  int           maxWord,
                                  int           minFrag,
                                  int           maxFrag,
                                  const Source& source)
    {
        return GenerateSentence(ArgVec2(minWord, maxWord),
                                ArgVec2(minFrag, maxFrag),
                                source);
    }

    std::string GenerateParagraphX(int           minWord,
                                   int           maxWord,
                                   int           minFrag,
                                   int           maxFrag,
                                   int           minSent,
                                   int           maxSent,
                                   bool          useLipsum,
                                   const Source& source)
    {
        return GenerateParagraph(ArgVec2(minWord, maxWord),
                                 ArgVec2(minFrag, maxFrag),
                                 ArgVec2(minSent, maxSent),
                                 useLipsum,
                                 source);
    }

    std::string GenerateTextX(int           minWord,
                              int           maxWord,
                              int           minFrag,
                              int           maxFrag,
                              int           minSent,
                              int           maxSent,
                              int           minPara,
                              int           maxPara,
                              bool          useLipsum,
                              const Source& source)
    {
        return GenerateText(ArgVec2(minWord, maxWord),
                            ArgVec2(minFrag, maxFrag),
                            ArgVec2(minSent, maxSent),
                            ArgVec2(minPara, maxPara),
                            useLipsum,
                            source);
    }

    /*
     * MARKDOWN
     * ----------------
     */

    std::string GenerateMarkdownHeaderX(int           level,
                                        int           minWord,
                                        int           maxWord,
                                        bool          useHtml,
                                        const Source& source)
    {
        return GenerateMarkdownHeader(level,
                                      ArgVec2(minWord, maxWord),
                                      useHtml,
                                      source);
    }

    std::string GenerateMarkdownEmphasisX(bool          isBold,
                                          int           minWord,
                                          int           maxWord,
                                          int           minFrag,
                                          int           maxFrag,
                                          bool          useHtml,
                                          const Source& source)
    {
        return GenerateMarkdownEmphasis(isBold,
                                        lpsm::ArgVec2(minWord, maxWord),
                                        lpsm::ArgVec2(minFrag, maxFrag),
                                        useHtml,
                                        source);
    }

    std::string GenerateMarkdownLinkX(int           minWord,
                                      int           maxWord,
                                      int           minFrag,
                                      int           maxFrag,
                                      int           minWordURL,
                                      int           maxWordURL,
                                      bool          useHtml,
                                      const Source& source)
    {
        return GenerateMarkdownLink(ArgVec2(minWord, maxWord),
                                    ArgVec2(minFrag, maxFrag),
                                    ArgVec2(minWordURL, maxWordURL),
                                    useHtml,
                                    source);
    }

    std::string GenerateMarkdownListX(bool          ordered,
                                      int           minWord,
                                      int           maxWord,
                                      int           minFrag,
                                      int           maxFrag,
                                      int           minPoint,
                                      int           maxPoint,
                                      bool          useHtml,
                                      const Source& source)
    {
        return GenerateMarkdownList(ordered,
                                    ArgVec2(minWord, maxWord),
                                    ArgVec2(minFrag, maxFrag),
                                    ArgVec2(minPoint, maxPoint),
                                    useHtml,
                                    source);
    }

    /*
     * FORMATS
     */

    std::string GenerateXMLDocumentX(int           choices,
                                     int           minWord,
                                     int           maxWord,
                                     int           minFrag,
                                     int           maxFrag,
                                     const Source& source)
    {
        return GenerateXMLDocument(choices,
                                   ArgVec2(minWord, maxWord),
                                   ArgVec2(minFrag, maxFrag),
                                   source);
    }
} // namespace lipsum
#endif


/**
 * @file lipsumc/sfuncs.h
 *
 * @brief S functions of lipsum-cpp C wrapper
 *
 * This declares the &quot;S&quot; variants of functions in lipsum-cpp's C
 * wrapper. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#ifndef LIPSUM_SFUNCS_H
#define LIPSUM_SFUNCS_H

#include "core.h"
#include "binded.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /*
     * BULK
     * ----------------
     */

    /**
     * @brief Generate multiple random sentences at once.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @return char* The random sentences.
     *
     * @param sentCount The number of sentences.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateSentencesS(int                sentCount,
                                              lpsm_ArgVec2Handle word,
                                              lpsm_ArgVec2Handle frag,
                                              bool               useLipsum,
                                              lpsm_SourceHandle  source,
                                              bool               del);

    /**
     * @brief Generate several random paragraphs at once.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @return char* The random paragraphs.
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param word The minimum and maximum total number of words in a sentence
     * fragment.
     * @param frag The minimum and maximum total number of sentence fragments in
     * a sentence.
     * @param sent The minimum and maximum total number of sentences in a
     * paragraph.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphsS(int                paraCount,
                                               lpsm_ArgVec2Handle word,
                                               lpsm_ArgVec2Handle frag,
                                               lpsm_ArgVec2Handle sent,
                                               bool               useLipsum,
                                               lpsm_SourceHandle  source,
                                               bool               del);

    /*
     * MISC
     * ----------------
     */

    /**
     * @brief Generate a random URL.
     *
     * @since 0.3.7
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words at the end
     * of the URL.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param source The source for words.
     *
     * @return char* The URL.
     */
    LIPSUMC_API char* lpsm_GenerateURLS(lpsm_ArgVec2Handle word,
                                        lpsm_SourceHandle  source,
                                        bool               del);

    /**
     * @brief Generate a slug joined by a specified character.
     *
     * @since 0.3.6
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words in the slug.
     * @param separator The separator character.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param source The source for words.
     *
     * @return char* The slug.
     */
    LIPSUMC_API char* lpsm_GenerateSlugS(lpsm_ArgVec2Handle word,
                                         char               separator,
                                         lpsm_SourceHandle  source,
                                         bool               del);

    /*
     * CORE
     * ----------------
     */

    /**
     * @brief Generate a fragment of a sentence without punctuation.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words in a
     * fragment.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param source The source for words.
     *
     * @return char* The random sentence fragment.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle word,
                                                     lpsm_SourceHandle  source,
                                                     bool               del);

    /**
     * @brief Generate a random sentence.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @return char* The random sentence.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle word,
                                             lpsm_ArgVec2Handle frag,
                                             lpsm_SourceHandle  source,
                                             bool               del);

    /**
     * @brief Generate a random paragraph.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @return char* The random paragraph.
     *
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph. By default true.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle word,
                                              lpsm_ArgVec2Handle frag,
                                              lpsm_ArgVec2Handle sent,
                                              bool               useLipsum,
                                              lpsm_SourceHandle  source,
                                              bool               del);

    /**
     * @brief Generate a random number of random paragraphs.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @return char* The random text.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param sent The minimum and maximum possible number of sentences in a
     * paragraph.
     * @param para The minimum and maximum possible number of paragraphs in the
     * text.
     * @param useLipsum Whether "Lorem ipsum..." should start the first
     * paragraph.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateTextS(lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         lpsm_ArgVec2Handle sent,
                                         lpsm_ArgVec2Handle para,
                                         bool               useLipsum,
                                         lpsm_SourceHandle  source,
                                         bool               del);

    /*
     * MARKDOWN
     * ----------------
     */

    /**
     * @brief Generate a random Markdown header.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param level The level of the heading.
     * @param word The minimum and maximum possible number of words in the
     * heading.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random heading.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownHeaderS(int                level,
                                                   lpsm_ArgVec2Handle word,
                                                   bool               useHtml,
                                                   lpsm_SourceHandle  source,
                                                   bool               del);

    /**
     * @brief Generate a random emphasized sentence.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param isBold Whether the sentence is bold or italic.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param source The source for words.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random emphasized sentence.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownEmphasisS(bool               isBold,
                                                     lpsm_ArgVec2Handle word,
                                                     lpsm_ArgVec2Handle frag,
                                                     bool               useHtml,
                                                     lpsm_SourceHandle  source,
                                                     bool               del);

    /**
     * @brief Generate a random Markdown link.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence.
     * @param wordURL The minimum and maximum possible number of words at the
     * end of the URL.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random link.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownLinkS(lpsm_ArgVec2Handle word,
                                                 lpsm_ArgVec2Handle frag,
                                                 lpsm_ArgVec2Handle wordURL,
                                                 bool               useHtml,
                                                 lpsm_SourceHandle  source,
                                                 bool               del);

    /**
     * @brief Generate a random Markdown list.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param ordered Whether the list is ordered or unordered.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a point.
     * @param point The minimum and maximum possible number of points in the
     * list.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown list.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownListS(bool               ordered,
                                                 lpsm_ArgVec2Handle word,
                                                 lpsm_ArgVec2Handle frag,
                                                 lpsm_ArgVec2Handle point,
                                                 bool               useHtml,
                                                 lpsm_SourceHandle  source,
                                                 bool               del);

    /**
     * @brief Generate a random formatted paragraph.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence.
     * @param wordLink The minimum and maximum possible number of words in a
     * link URL.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     *
     * @return char* The random paragraph.
     */
    LIPSUMC_API char*
    lpsm_GenerateMarkdownParagraphS(lpsm_ArgVec2Handle word,
                                    lpsm_ArgVec2Handle frag,
                                    lpsm_ArgVec2Handle sent,
                                    lpsm_ArgVec2Handle wordFmt,
                                    lpsm_ArgVec2Handle fragFmt,
                                    lpsm_ArgVec2Handle wordLink,
                                    bool               useLipsum,
                                    bool               useHtml,
                                    lpsm_SourceHandle  source,
                                    bool               del);

    /**
     * @brief Generate multiple random formatted paragraphs.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param paraCount The number of paragraphs.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence.
     * @param wordLink The minimum and maximum possible number of words in a
     * link URL.
     * @param useLipsum Whether "Lorem ipsum..." should start the first
     * paragraph.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     * @param source The source for words.
     *
     * @return char* The random paragraph.
     */
    LIPSUMC_API char*
    lpsm_GenerateMarkdownParagraphsS(int                paraCount,
                                     lpsm_ArgVec2Handle word,
                                     lpsm_ArgVec2Handle frag,
                                     lpsm_ArgVec2Handle sent,
                                     lpsm_ArgVec2Handle wordFmt,
                                     lpsm_ArgVec2Handle fragFmt,
                                     lpsm_ArgVec2Handle wordLink,
                                     bool               useLipsum,
                                     bool               useHtml,
                                     lpsm_SourceHandle  source,
                                     bool               del);

    /**
     * @brief Generate a random Markdown document.
     *
     * @since 0.3.5
     *
     * @sovload
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence.
     * @param sent The minimum and maximum possible number of sentences in a
     * paragraph.
     * @param point The minimum and maximum possible number of points in a list.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence.
     * @param wordHead The minimum and maximum possible number of words in a
     * link URL or heading.
     * @param level The minimum and maximum possible heading levels, excluding
     * the main heading.
     * @param numElements The number of paragraphs, headings, and lists total.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     * @param source The source for words.
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     *
     * @return char* The random Markdown document.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownTextS(lpsm_ArgVec2Handle word,
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
                                                 bool               del);
#ifdef __cplusplus
}
#endif

#endif

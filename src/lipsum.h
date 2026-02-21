/**
 * @file lipsum.h
 *
 * @brief C wrapper over lipsum-cpp
 *
 * This contains the C wrapper over lipsum-cpp. It requires being built
 * as a static or shared library in order to function. This file is under the
 * BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 *
 * @example CWrapper.c
 */

#ifndef LIPSUM_H
#define LIPSUM_H

/**
 * @brief Macro for shared libraries
 *
 * @since 0.1.2
 *
 * This macro helps with shared libraries on Windows by exporting
 * or importing functions.
 */
#ifdef LIPSUM_BUILD_SHARED
#    ifdef _WIN32
#        ifdef LIPSUM_EXPORT_SHARED
#            define LIPSUMC_API __declspec(dllexport)
#        else
#            define LIPSUMC_API __declspec(dllimport)
#        endif
#    else
#        define LIPSUMC_API
#    endif
#else
#    define LIPSUMC_API
#endif
#ifndef LIPSUM_BUILD_STATIC
#    error Cannot use C wrapper without building a static or shared library.
#endif

/**
 * @brief The current version of lipsum-cpp.
 *
 * @since 0.2.1
 *
 * This macro stores the current version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION_C "0.3.8"

/**
 * @brief Return the current version of lipsum-cpp
 *
 * @since 0.3.2
 *
 * This macro function simply expands to LIPSUM_CPP_VERSION_C.
 */
#define lpsm_LipsumVersion() LIPSUM_CPP_VERSION_C

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief A handle to a lpsm::ArgVec2
 *
 * @since 0.3.3
 *
 * This is a typedef of a pointer to a lpsm::ArgVec2.
 */
typedef void* lpsm_ArgVec2Handle;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Count the number of words in a string.
     *
     * Count the number of words in a string using a naive approach. It counts
     * some Markdown formatting as words.
     *
     * @since 0.3.8
     *
     * @param str The string inputted.
     *
     * @return int The number of words.
     */
    LIPSUMC_API int lpsm_CountWords(const char* str);

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
     *
     * @return char* The URL.
     */
    LIPSUMC_API char* lpsm_GenerateURLS(lpsm_ArgVec2Handle word, bool del);

    /**
     * @brief Generate a random URL.
     *
     * @since 0.3.7
     *
     * Generate a URL starting in https://, followed by a random word, followed
     * by a random TLD, followed by a slash and a random HTML id as a slug
     * separated by hyphens.
     *
     * @param minWord The minimum possible number of words at the end
     * of the URL.
     * @param maxWord The maximum possible number of words at the end of the
     * URL.
     *
     * @return char* The URL.
     */
    LIPSUMC_API char* lpsm_GenerateURL(int minWord, int maxWord);

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
     *
     * @return char* The slug.
     */
    LIPSUMC_API char*
    lpsm_GenerateSlugS(lpsm_ArgVec2Handle word, char separator, bool del);

    /**
     * @brief Generate a slug joined by a specified character.
     *
     * @since 0.3.6
     *
     * Generates a sentence fragment with spaces replaced with the specified
     * separator character.
     *
     * @param minWord The minimum possible number of words in the slug.
     * @param maxWord The maximum possible number of words in the slug.
     * @param separator The separator character.
     *
     * @return char* The slug.
     */
    LIPSUMC_API char*
    lpsm_GenerateSlug(int minWord, int maxWord, char separator);

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
     *
     * @return char* The random sentence fragment.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceFragmentS(lpsm_ArgVec2Handle word,
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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceS(lpsm_ArgVec2Handle word,
                                             lpsm_ArgVec2Handle frag,
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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphS(lpsm_ArgVec2Handle word,
                                              lpsm_ArgVec2Handle frag,
                                              lpsm_ArgVec2Handle sent,
                                              bool               useLipsum,
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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphsS(int                paraCount,
                                               lpsm_ArgVec2Handle word,
                                               lpsm_ArgVec2Handle frag,
                                               lpsm_ArgVec2Handle sent,
                                               bool               useLipsum,
                                               bool               del);

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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateSentencesS(int                sentCount,
                                              lpsm_ArgVec2Handle word,
                                              lpsm_ArgVec2Handle frag,
                                              bool               useLipsum,
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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     */
    LIPSUMC_API char* lpsm_GenerateTextS(lpsm_ArgVec2Handle word,
                                         lpsm_ArgVec2Handle frag,
                                         lpsm_ArgVec2Handle sent,
                                         lpsm_ArgVec2Handle para,
                                         bool               useLipsum,
                                         bool               del);

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
     * @param del Whether the ArgVec2 handles should be deleted after the
     * function is called.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random heading.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownHeaderS(int                level,
                                                   lpsm_ArgVec2Handle word,
                                                   bool               useHtml,
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
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random emphasized sentence.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownEmphasisS(bool               isBold,
                                                     lpsm_ArgVec2Handle word,
                                                     lpsm_ArgVec2Handle frag,
                                                     bool               useHtml,
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
                                                 bool               del);

    /**
     * @brief Generate a random Markdown header.
     *
     * @since 0.3.4
     *
     * Generate a random Markdown header.
     *
     * @param level The level of the heading.
     * @param minWord The minimum possible number of words in the
     * heading.
     * @param maxWord The maximum possible number of words in the heading.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random heading.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownHeader(int  level,
                                                  int  minWord,
                                                  int  maxWord,
                                                  bool useHtml);

    /**
     * @brief Generate a random emphasized sentence.
     *
     * @since 0.3.4
     *
     * Generate a random sentence in Markdown format that is either bold or
     * italic.
     *
     * @param isBold Whether the sentence is bold or italic.
     * @param minWord The minimum possible number of words in a
     * sentence fragment.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment.
     * @param minFrag The minimum possible number of sentence fragments
     * in the sentence.
     * @param maxFrag The maximum possible number of sentence fragments in the
     * sentence.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random emphasized sentence.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownEmphasis(bool isBold,
                                                    int  minWord,
                                                    int  maxWord,
                                                    int  minFrag,
                                                    int  maxFrag,
                                                    bool useHtml);

    /**
     * @brief Generate a random Markdown link.
     *
     * @since 0.3.4
     *
     * Generate a random link in Markdown format.
     *
     * @param minWord The minimum possible number of words in a
     * sentence fragment.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment.
     * @param minFrag The minimum possible number of sentence fragments
     * in the sentence.
     * @param maxFrag The maximum possible number of sentence fragments in the
     * sentence.
     * @param minWordURL The minimum possible number of words at the
     * end of the URL.
     * @param maxWordURL The maximum possible number of words at the end of the
     * URL.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random link.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownLink(int  minWord,
                                                int  maxWord,
                                                int  minFrag,
                                                int  maxFrag,
                                                int  minWordURL,
                                                int  maxWordURL,
                                                bool useHtml);

    /**
     * @brief Generate a random Markdown list.
     *
     * @since 0.3.4
     *
     * Generate a random ordered or unordered list in Markdown format.
     *
     * @param ordered Whether the list is ordered or unordered.
     * @param minWord The minimum possible number of words in a
     * sentence fragment.
     * @param maxWord The maximum possible number of words in a
     * sentence fragment.
     * @param minFrag The minimum possible number of sentence fragments
     * in a point.
     * @param maxFrag The maximum possible number of sentence fragments
     * in a point.
     * @param minPoint The minimum possible number of points in the
     * list.
     * @param maxPoint The maximum possible number of points in the
     * list.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown list.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownList(bool ordered,
                                                int  minWord,
                                                int  maxWord,
                                                int  minFrag,
                                                int  maxFrag,
                                                int  minPoint,
                                                int  maxPoint,
                                                bool useHtml);

    /**
     * @brief Create a lpsm::ArgVec2.
     *
     * @since 0.3.3
     *
     * This function creates a pointer pointing to a lpsm::ArgVec2.
     *
     * @param min Value to enter into the minimum value
     * @param max Value to enter into the maximum value
     *
     * @return lpsm_ArgVec2Handle The lpsm::ArgVec2.
     */
    LIPSUMC_API lpsm_ArgVec2Handle lpsm_ArgVec2(int min, int max);

    /**
     * @brief Delete a lpsm::ArgVec2.
     *
     * @since 0.3.3
     *
     * This function deletes a lpsm::ArgVec2 allocated with
     * lpsm_ArgVec2.
     *
     * @param av2 The lpsm::ArgVec2.
     */
    LIPSUMC_API void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle av2);

    /**
     * @brief Run lpsm::ArgVec2::Roll.
     *
     * @since 0.3.3
     *
     * This function calls lpsm::ArgVec2::Roll().
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The random number.
     */
    LIPSUMC_API int lpsm_ArgVec2Roll(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::min
     *
     * @since 0.3.3
     *
     * This function retrieves the min property of a lpsm::ArgVec2.
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The min value
     */
    LIPSUMC_API int lpsm_ArgVec2GetMin(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::max
     *
     * @since 0.3.3
     *
     * This function retrieves the max property of a lpsm::ArgVec2.
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The max value
     */
    LIPSUMC_API int lpsm_ArgVec2GetMax(lpsm_ArgVec2Handle av2);

    /**
     * @brief Generate words.
     *
     * @since 0.2.3
     *
     * This function generates multiple words.
     *
     * @param num The number of words.
     *
     * @return char* The random word.
     */
    LIPSUMC_API char* lpsm_gen_word(int num);

    /**
     * @brief Generate sentences.
     *
     * @since 0.2.3
     *
     * This function generates multiple sentences with default arguments.
     *
     * @param num The number of sentences.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * sentence(s).
     *
     * @return char* The random sentence(s).
     */
    LIPSUMC_API char* lpsm_gen_sentence(int num, bool useLipsum);

    /**
     * @brief Generate a sentence fragment.
     *
     * @since 0.2.3
     *
     * This function generates a sentence fragment with default arguments.
     *
     * @return char* The random sentence fragment.
     */
    LIPSUMC_API char* lpsm_gen_sentence_fragment(void);

    /**
     * @brief Generate paragraphs.
     *
     * @since 0.2.3
     *
     * This function generates multiple paragraphs with default arguments.
     *
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * paragraph(s).
     *
     * @return char* The random paragraph(s).
     */
    LIPSUMC_API char* lpsm_gen_paragraph(int num, bool useLipsum);

    /**
     * @brief Generate a Markdown paragraph.
     *
     * @since 0.3.0
     *
     * This function generates multiple paragraphs in Markdown format with
     * default arguments.
     *
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return char* The random Markdown paragraph.
     */
    LIPSUMC_API char* lpsm_gen_md_paragraph(bool useLipsum);

    /**
     * @brief Generate a Markdown document.
     *
     * @since 0.3.0
     *
     * This function generates a document in Markdown format with default
     * arguments.
     *
     * @param numElements The number of elements (paragraph, list, heading) in
     * the document.
     *
     * @return char* The random Markdown document.
     */
    LIPSUMC_API char* lpsm_gen_md_text(int numElements);

    /**
     * @brief Generate a random sentence fragment.
     *
     * @since 0.1.0
     *
     * @return char* The random sentence fragment.
     *
     * @param minWord Minimum number of words in the fragment.
     * @param maxWord Maximum number of words in the fragment.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceFragment(int minWord, int maxWord);

    /**
     * @brief Generate a random sentence.
     *
     * @since 0.0.2
     *
     * This function generates a sentence starting with a capital letter
     * and ending with a period, sometimes containing a comma.
     *
     * @return char* The random sentence.
     *
     * @param minWord Minimum number of words in the sentence fragment.
     * @param maxWord Maximum number of words in the sentence fragment.
     * @param minFrag Minimum number of sentence fragments in the sentence.
     * @param maxFrag Maximum number of sentence fragments in the sentence.
     */
    LIPSUMC_API char*
    lpsm_GenerateSentence(int minWord, int maxWord, int minFrag, int maxFrag);

    /**
     * @brief Generate a random paragraph.
     *
     * @since 0.0.2
     *
     * This function generates a random paragraph starting with a tab character
     * and ending in a line break, with each sentence separated by a space.
     *
     * @return char* The random paragraph.
     *
     * @param minSent Minimum number of sentences in the paragraph.
     * @param maxSent Maximum number of sentences in the paragraph.
     * @param minWord Minimum number of words in each sentence fragment.
     * @param maxWord Maximum number of words in each sentence fragment.
     * @param minFrag Minimum number of sentence fragments in each sentence.
     * @param maxFrag Maximum number of sentence fragments in each sentence.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph.
     */
    LIPSUMC_API char* lpsm_GenerateParagraph(int  minWord,
                                             int  maxWord,
                                             int  minFrag,
                                             int  maxFrag,
                                             int  minSent,
                                             int  maxSent,
                                             bool useLipsum);

    /**
     * @brief Generate several random paragraphs at once.
     *
     * @since 0.0.2
     *
     * This function generates several random paragraphs, each separated by a
     * line break. Formerly known as lpsm_GenerateParagraphList().
     *
     * @return char* The random paragraphs.
     *
     * @param paraCount The number of paragraphs.
     * @param minSent Minimum number of sentences in each paragraph.
     * @param maxSent Maximum number of sentences in each paragraph.
     * @param minWord Minimum number of words in each sentence fragment.
     * @param maxWord Maximum number of words in each sentence fragment.
     * @param minFrag Minimum number of sentence fragments in each sentence.
     * @param maxFrag Maximum number of sentence fragments in each sentence.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphs(int  paraCount,
                                              int  minWord,
                                              int  maxWord,
                                              int  minFrag,
                                              int  maxFrag,
                                              int  minSent,
                                              int  maxSent,
                                              bool useLipsum);

    /**
     * @brief Generate a random word.
     *
     * @since 0.0.3
     *
     * This function generates a random word from a predefined list.
     *
     * @return char* The random word.
     */
    LIPSUMC_API char* lpsm_GenerateWord(void);

    /**
     * @brief Generate a specified number of random words.
     *
     * @since 0.2.2
     *
     * This function generates a sentence fragment with exactly wordCount words.
     *
     * @param wordCount The number of words.
     *
     * @return char* The random words.
     */
    LIPSUMC_API char* lpsm_GenerateWords(int wordCount);

    /**
     * @brief Generate the beginning Lorem Ipsum sentence.
     *
     * @since 0.0.5
     *
     * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing
     * elit."
     *
     * @return char* The default Lorem Ipsum sentence.
     */
    LIPSUMC_API char* lpsm_GenerateDefaultLipsumSentence(void);

    /**
     * @brief Generate multiple random sentences at once.
     *
     * @since 0.0.5
     *
     * Generate multiple random sentences separated with spaces. Does not add a
     * tab character before the sentences nor a line break after.
     *
     * @return char* The random sentences.
     *
     * @param sentCount The number of sentences.
     * @param minWord Minimum number of words in each sentence fragment.
     * @param maxWord Maximum number of words in each sentence fragment.
     * @param minFrag Minimum number of sentence fragments in each sentence.
     * @param maxFrag Maximum number of sentence fragments in each sentence.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence.
     */
    LIPSUMC_API char* lpsm_GenerateSentences(int  sentCount,
                                             int  minWord,
                                             int  maxWord,
                                             int  minFrag,
                                             int  maxFrag,
                                             bool useLipsum);

    /**
     * @brief Count the number of sentences in a string.
     *
     * @since 0.3.0
     *
     * Count the number of periods in a string, ignoring usage in Markdown URLs.
     *
     * @param str The string inputted.
     *
     * @return int The number of sentences.
     */
    LIPSUMC_API int lpsm_CountSentences(const char* str);

    /**
     * @brief Delete a string returned by a function.
     *
     * @since 0.0.8
     *
     * Since pointers allocated with new[] cannot be deallocated with free(),
     * this function handles the deallocation.
     *
     * @param str The string to delete.
     */
    LIPSUMC_API void lpsm_DeleteString(char* str);

    /**
     * @brief Generate a random number of random paragraphs.
     *
     * @since 0.3.2
     *
     * @return char* The random text.
     *
     * @param minWord The minimum possible number of words in a sentence
     * fragment.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence.
     * @param minSent The minimum possible number of sentences in a paragraph.
     * @param maxSent The maximum possible number of sentences in a paragraph.
     * @param minPara The minimum possible number of paragraphs in the text.
     * @param maxPara The maximum possible number of paragraphs in the text.
     * @param useLipsum Whether "Lorem ipsum..." should start the first
     * paragraph.
     */
    LIPSUMC_API char* lpsm_GenerateText(int  minWord,
                                        int  maxWord,
                                        int  minFrag,
                                        int  maxFrag,
                                        int  minSent,
                                        int  maxSent,
                                        int  minPara,
                                        int  maxPara,
                                        bool useLipsum);

#ifdef __cplusplus
}
#endif

#endif

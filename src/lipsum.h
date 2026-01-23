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
#define LIPSUM_CPP_VERSION_C "0.3.4"

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
     *
     * @return char* The random heading.
     */
    LIPSUMC_API char*
    lpsm_GenerateMarkdownHeader(int level, int minWord, int maxWord);

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
     *
     * @return char* The random emphasized sentence.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownEmphasis(
            bool isBold, int minWord, int maxWord, int minFrag, int maxFrag);

    /**
     * @brief Generate a random Markdown link.
     *
     * @since 0.3.4
     *
     * Generate a random link in Markdown format.
     *
     * @param url The URL to base the link off of.
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
     *
     * @return char* The random link.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownLink(const char* url,
                                                int         minWord,
                                                int         maxWord,
                                                int         minFrag,
                                                int         maxFrag,
                                                int         minWordURL,
                                                int         maxWordURL);

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
     *
     * @return char* The random Markdown list.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownList(bool ordered,
                                                int  minWord,
                                                int  maxWord,
                                                int  minFrag,
                                                int  maxFrag,
                                                int  minPoint,
                                                int  maxPoint);

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
     * @brief Turn a string into HTML paragraph tags.
     *
     * @since 0.0.6
     *
     * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
     * handle HTML entities like &amp;, &lt;, &gt;, etc. This function is
     * deprecated.
     *
     * @deprecated Use a Markdown parser instead.
     *
     * @return char* The HTML-ified string.
     *
     * @param str The string inputted.
     */
    LIPSUMC_API char* lpsm_HTMLify(const char* str);

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

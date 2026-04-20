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

#pragma once

#ifndef LIPSUM_H
#    define LIPSUM_H

#    include <stdbool.h>
#    include <stdio.h>

#    include "lipsumc/binded.h"
#    include "lipsumc/sfuncs.h"

#    ifdef __cplusplus
extern "C"
{
#    endif

    /*
     * BULK
     * ----------------
     */

    /**
     * @brief Generate a specified number of random words.
     *
     * @since 0.2.2
     *
     * This function generates a sentence fragment with exactly wordCount words.
     *
     * @param wordCount The number of words.
     * @param source The source for words.
     *
     * @return char* The random words.
     */
    LIPSUMC_API char* lpsm_GenerateWords(int               wordCount,
                                         lpsm_SourceHandle source);

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
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateSentences(int               sentCount,
                                             int               minWord,
                                             int               maxWord,
                                             int               minFrag,
                                             int               maxFrag,
                                             bool              useLipsum,
                                             lpsm_SourceHandle source);

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
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateParagraphs(int               paraCount,
                                              int               minWord,
                                              int               maxWord,
                                              int               minFrag,
                                              int               maxFrag,
                                              int               minSent,
                                              int               maxSent,
                                              bool              useLipsum,
                                              lpsm_SourceHandle source);

    /*
     * MISC
     * ----------------
     */

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
     * @brief Generate a random character scramble
     *
     * @since 0.3.9
     *
     * Generate a random string of text with random characters.
     *
     * @param length The number of characters.
     * @param min The lowest-valued ASCII character that can appear.
     * @param max The highest-valued ASCII character than can appear.
     *
     * @return char* The character scramble
     */
    LIPSUMC_API char* lpsm_GenerateScramble(int length, char min, char max);

    /**
     * @brief Generate a random plain URL
     *
     * @since 0.3.9
     *
     * Generate a URL with a random word followed by a random TLD.
     *
     * @param source The source for words.
     *
     * @return char* The plain URL
     */
    LIPSUMC_API char* lpsm_GeneratePlainURL(lpsm_SourceHandle source);

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
     * @param source The source for words.
     *
     * @return char* The URL.
     */
    LIPSUMC_API char*
    lpsm_GenerateURL(int minWord, int maxWord, lpsm_SourceHandle source);

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
     * @param source The source for words.
     *
     * @return char* The slug.
     */
    LIPSUMC_API char* lpsm_GenerateSlug(int               minWord,
                                        int               maxWord,
                                        char              separator,
                                        lpsm_SourceHandle source);

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

    /*
     * CORE
     * ----------------
     */

    /**
     * @brief Generate a random word.
     *
     * @since 0.0.3
     *
     * This function generates a random word from a predefined list.
     *
     * @param source The source for words.
     *
     * @return char* The random word.
     */
    LIPSUMC_API char* lpsm_GenerateWord(lpsm_SourceHandle source);

    /**
     * @brief Generate a random sentence fragment.
     *
     * @since 0.1.0
     *
     * @return char* The random sentence fragment.
     *
     * @param minWord Minimum number of words in the fragment.
     * @param maxWord Maximum number of words in the fragment.
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateSentenceFragment(int               minWord,
                                                    int               maxWord,
                                                    lpsm_SourceHandle source);

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
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateSentence(int               minWord,
                                            int               maxWord,
                                            int               minFrag,
                                            int               maxFrag,
                                            lpsm_SourceHandle source);

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
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateParagraph(int               minWord,
                                             int               maxWord,
                                             int               minFrag,
                                             int               maxFrag,
                                             int               minSent,
                                             int               maxSent,
                                             bool              useLipsum,
                                             lpsm_SourceHandle source);
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
     * @param source The source for words.
     */
    LIPSUMC_API char* lpsm_GenerateText(int               minWord,
                                        int               maxWord,
                                        int               minFrag,
                                        int               maxFrag,
                                        int               minSent,
                                        int               maxSent,
                                        int               minPara,
                                        int               maxPara,
                                        bool              useLipsum,
                                        lpsm_SourceHandle source);

    /*
     * CORE
     * ----------------
     */

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
     * @param source The source for words.
     *
     * @return char* The random heading.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownHeader(int               level,
                                                  int               minWord,
                                                  int               maxWord,
                                                  bool              useHtml,
                                                  lpsm_SourceHandle source);

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
     * @param source The source for words.
     *
     * @return char* The random emphasized sentence.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownEmphasis(bool              isBold,
                                                    int               minWord,
                                                    int               maxWord,
                                                    int               minFrag,
                                                    int               maxFrag,
                                                    bool              useHtml,
                                                    lpsm_SourceHandle source);

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
     * @param source The source for words.
     *
     * @return char* The random link.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownLink(int               minWord,
                                                int               maxWord,
                                                int               minFrag,
                                                int               maxFrag,
                                                int               minWordURL,
                                                int               maxWordURL,
                                                bool              useHtml,
                                                lpsm_SourceHandle source);

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
     * @param source The source for words.
     *
     * @return char* The random Markdown list.
     */
    LIPSUMC_API char* lpsm_GenerateMarkdownList(bool              ordered,
                                                int               minWord,
                                                int               maxWord,
                                                int               minFrag,
                                                int               maxFrag,
                                                int               minPoint,
                                                int               maxPoint,
                                                bool              useHtml,
                                                lpsm_SourceHandle source);

    /*
     * FORMATS
     */

    /**
     * @brief Generate a random XML document.
     *
     * @since 0.4.4
     *
     * @xovload
     *
     * @param choices The number of choices to make.
     * @param minWord The minimum total number of words in a sentence
     * fragment.
     * @param maxWord The maximum total number of words in a sentence
     * fragment.
     * @param minFrag The minimum total number of sentence fragments in
     * a sentence.
     * @param maxFrag The maximum total number of sentence fragments in
     * a sentence.
     * @param source The source for words.
     *
     * @return char* The XML document.
     */
    LIPSUMC_API char* lpsm_GenerateXMLDocument(int               choices,
                                               int               minWord,
                                               int               maxWord,
                                               int               minFrag,
                                               int               maxFrag,
                                               lpsm_SourceHandle source);

#    ifdef __cplusplus
}
#    endif

#endif

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

// NOLINTBEGIN
/**
 * @brief Types of formats.
 *
 * @since 0.4.6
 *
 * Types of formats used in lpsm_CountParagraphs() and lpsm_ConvertFormat(). In
 * lpsm_CountParagraphs(), LPSM_FMT_PLAIN is counting plain text,
 * LPSM_FMT_MARKDOWN is counting Markdown or HTML, and LPSM_FMT_HTML is counting
 * HTML explicitly. Formerly known as lpsm_CountParaMethod.
 */
typedef enum lpsm_Format
{
    LPSM_FMT_PLAIN = 0,
    LPSM_FMT_MARKDOWN,
    LPSM_FMT_HTML,
    LPSM_FMT_JSON,
    LPSM_FMT_XML
} lpsm_Format;

// NOLINTEND

#    ifdef __cplusplus
extern "C"
{
#    endif

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
     * @cstrnote
     *
     * @return char* The default Lorem Ipsum sentence.
     */
    LIPSUMC_API char* lpsm_GenerateDefaultLipsumSentence(void);

    /**
     * @brief Return the current version of lipsum-cpp.
     *
     * @since 0.5.4
     *
     * Return the current version of lipsum-cpp, intended for wrappers.
     *
     * @return const char* The version of lipsum-cpp.
     */
    LIPSUMC_API const char* lpsm_internal_Version__();

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
     * @brief Count the number of sentence fragments in a string.
     *
     * @since 0.4.6
     *
     * Count the number of commas, semicolons, and hyphens in a string,
     * excluding usage in Markdown. (i.e. hyphen at start of line, or in
     * parentheses)
     *
     * @param str The string inputted.
     *
     * @return int The number of sentence fragments.
     */
    LIPSUMC_API int lpsm_CountSentenceFragments(const char* str);

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
     * @brief Count the number of paragraphs or elements in a string.
     *
     * @since 0.4.6
     *
     * Count the number of tab characters in a non-formatted string, double
     * newlines in Markdown/HTML strings, and elements in HTML strings.
     *
     * @param str The string inputted.
     * @param format The format the string is in.
     *
     * @return int The number of paragraphs.
     */
    LIPSUMC_API int lpsm_CountParagraphs(const char* str, lpsm_Format format);

    /**
     * @brief Delete a string returned by a function.
     *
     * @since 0.0.8
     *
     * Since pointers allocated with new[] cannot be deallocated with free(),
     * this function handles the deallocation.
     *
     * @warning Do not call this function twice on the same string or use the
     * string after deleting, as that would cause a double free or
     * use-after-free and potentially crash the program.
     *
     * @param str The string to delete.
     */
    LIPSUMC_API void lpsm_DeleteString(char* str);

#    ifdef __cplusplus
}
#    endif

#endif

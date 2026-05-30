/**
 * @file lipsum/misc.hpp
 *
 * @brief Miscellaneous functions of lipsum-cpp
 *
 * This declares miscellaneous functions in lipsum-cpp,
 * such as CountSentences(). This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_MISC_HPP
#    define LIPSUM_MISC_HPP

#    include "core/argvec2.hpp"
#    include "core/core.hpp"
#    include "core/source.hpp"

namespace lipsum
{

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
     * @return std::string The default Lorem Ipsum sentence.
     */
    LIPSUM_API std::string GenerateDefaultLipsumSentence();

    /**
     * @brief Count the number of words in a string.
     *
     * @since 0.3.8
     *
     * Count the number of words in a string using alphanumeric characters,
     * hyphens, plus-signs, and apostrophes, excluding words within parentheses.
     *
     * @param str The string inputted.
     *
     * @return int The number of words.
     */
    LIPSUM_API int CountWords(const std::string& str);

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
    LIPSUM_API int CountSentenceFragments(const std::string& str);

    /**
     * @brief Count the number of sentences in a string.
     *
     * @since 0.3.0
     *
     * Count the number of periods in a string, ignoring usage in Markdown URLs.
     * (i.e. in parentheses)
     *
     * @param str The string inputted.
     *
     * @return int The number of sentences.
     */
    LIPSUM_API int CountSentences(const std::string& str);

    /**
     * @brief Count the number of paragraphs or elements in a string.
     *
     * @since 0.4.6
     *
     * Count the number of tab characters in a non-formatted string, double
     * newlines in Markdown/HTML strings, and elements in HTML strings.
     *
     * @param str The string inputted.
     * @param format The format the string is in. By default 0. (non-formatted)
     * Valid options include 0 (non-formatted), 1 (Markdown/HTML), and 2. (HTML)
     *
     * @return int The number of paragraphs.
     */
    LIPSUM_API int CountParagraphs(const std::string& str, int format = 0);

} // namespace lipsum
#endif

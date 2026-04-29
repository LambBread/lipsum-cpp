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

#    include "core/core.hpp"
#    include "core/argvec2.hpp"
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
     * @brief Generate a random character scramble.
     *
     * @since 0.3.9
     *
     * Generate a random string of text with random characters.
     *
     * @param length The number of characters. By default 16.
     * @param min The lowest-valued ASCII character that can appear. By default
     * a space.
     * @param max The highest-valued ASCII character than can appear. By default
     * a tilde.
     *
     * @return std::string The character scramble.
     */
    LIPSUM_API std::string
    GenerateScramble(int length = 16, char min = ' ', char max = '~');

    /**
     * @brief Generate a random plain URL
     *
     * @since 0.3.9
     *
     * Generate a URL with a random word followed by a random TLD.
     *
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The plain URL.
     */
    LIPSUM_API std::string GeneratePlainURL(const Source& source = Source());

    /**
     * @brief Generate a random URL.
     *
     * @since 0.3.7
     *
     * Generate a URL starting in https://, followed by a random word, followed
     * by a random TLD, followed by a slash and a random HTML id as a slug
     * separated by hyphens.
     *
     * @param word The minimum and maximum possible number of words at the end
     * of the URL. By default 2 to 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The URL.
     */
    LIPSUM_API std::string GenerateURL(const ArgVec2& word   = ArgVec2(2, 5),
                                       const Source&  source = Source());

    /**
     * @brief Generate a slug joined by a specified character.
     *
     * @since 0.3.6
     *
     * Generate a sentence fragment with spaces replaced with the specified
     * separator character.
     *
     * @param word The minimum and maximum possible number of words in the slug.
     * By default 2 to 5.
     * @param separator The separator character. By default a hyphen.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The slug.
     */
    LIPSUM_API std::string GenerateSlug(const ArgVec2& word = ArgVec2(2, 5),
                                        char           separator = '-',
                                        const Source&  source    = Source());

    /**
     * @brief Count the number of words in a string.
     *
     * @since 0.3.8
     *
     * Count the number of words in a string using a naive approach.
     *
     * @note Some formatting will be counted as words.
     *
     * @param str The string inputted.
     *
     * @return int The number of words.
     */
    LIPSUM_API int CountWords(const std::string& str);

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

} // namespace lipsum
#endif

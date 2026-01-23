/**
 * @file lipsum/md_xfuncs.hpp
 *
 * @brief Markdown "X" functions of lipsum-cpp
 *
 * This declares &quot;X&quot; variants of some Markdown functions in
 * lipsum-cpp. This file is under the BSD Zero Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

namespace lipsum
{

    /**
     * @brief Generate a random Markdown header.
     *
     * @since 0.3.4
     *
     * @xovload
     *
     * @param level The level of the heading. By default 1.
     * @param minWord The minimum possible number of words in the
     * heading. By default 2.
     * @param maxWord The maximum possible number of words in the heading. By
     * default 5.
     *
     * @return std::string The random heading.
     */
    LIPSUM_API std::string
    GenerateMarkdownHeaderX(int level = 1, int minWord = 2, int maxWord = 5);

    /**
     * @brief Generate a random emphasized sentence.
     *
     * @since 0.3.4
     *
     * @xovload
     *
     * @param isBold Whether the sentence is bold or italic. By default true.
     * (bold)
     * @param minWord The minimum possible number of words in a
     * sentence fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 8.
     * @param minFrag The minimum possible number of sentence fragments
     * in the sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in the
     * sentence. By default 2.
     *
     * @return std::string The random emphasized sentence.
     */
    LIPSUM_API std::string GenerateMarkdownEmphasisX(bool isBold  = true,
                                                     int  minWord = 4,
                                                     int  maxWord = 8,
                                                     int  minFrag = 1,
                                                     int  maxFrag = 2);

    /**
     * @brief Generate a random Markdown link.
     *
     * @since 0.3.4
     *
     * @xovload
     *
     * @param url The URL to base the link off of. By default
     * https://example.com/.
     * @param minWord The minimum possible number of words in a
     * sentence fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 8.
     * @param minFrag The minimum possible number of sentence fragments
     * in the sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in the
     * sentence. By default 2.
     * @param minWordURL The minimum possible number of words at the
     * end of the URL. By default 2.
     * @param maxWordURL The maximum possible number of words at the end of the
     * URL. By default 5.
     *
     * @return std::string The random link.
     */
    LIPSUM_API std::string GenerateMarkdownLinkX(
            const std::string& url        = std::string("https://example.com/"),
            int                minWord    = 4,
            int                maxWord    = 8,
            int                minFrag    = 1,
            int                maxFrag    = 2,
            int                minWordURL = 2,
            int                maxWordURL = 5);

    /**
     * @brief Generate a random Markdown list.
     *
     * @since 0.3.4
     *
     * @xovload
     *
     * @param ordered Whether the list is ordered or unordered. By default
     * false. (unordered)
     * @param minWord The minimum possible number of words in a
     * sentence fragment. By default 4.
     * @param maxWord The maximum possible number of words in a
     * sentence fragment. By default 8.
     * @param minFrag The minimum possible number of sentence fragments
     * in a point. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments
     * in a point. By default 2.
     * @param minPoint The minimum possible number of points in the
     * list. By default 3.
     * @param maxPoint The maximum possible number of points in the
     * list. By default 5.
     *
     * @return std::string The random Markdown list.
     */
    LIPSUM_API std::string GenerateMarkdownListX(bool ordered  = false,
                                                 int  minWord  = 4,
                                                 int  maxWord  = 8,
                                                 int  minFrag  = 1,
                                                 int  maxFrag  = 2,
                                                 int  minPoint = 3,
                                                 int  maxPoint = 5);
} // namespace lipsum

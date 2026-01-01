/**
 * @file lipsum/markdown.hpp
 *
 * @brief Markdown functions of lipsum-cpp
 *
 * This declares functions in lipsum-cpp around generation of Markdown text.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
namespace lipsum
{
    /**
     * @brief Generate a random Markdown header.
     *
     * @since 0.3.0
     *
     * Generate a random Markdown header. This function is not exposed in the C
     * wrapper.
     *
     * @param level The level of the heading. By default 1.
     * @param word The minimum and maximum possible number of words in the
     * heading. By default 2 to 5.
     *
     * @return std::string The random heading.
     */
    LIPSUM_API std::string
    GenerateMarkdownHeader(int level = 1, const ArgVec2& word = ArgVec2(2, 5));

    /**
     * @brief Generate a random emphasized sentence.
     *
     * @since 0.3.0
     *
     * Generate a random sentence in Markdown format that is either bold or
     * italic. This function is not exposed in the C wrapper.
     *
     * @param isBold Whether the sentence is bold or italic. By default true.
     * (bold)
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 2.
     *
     * @return std::string The random emphasized sentence.
     */
    LIPSUM_API std::string
               GenerateMarkdownEmphasis(bool           isBold = true,
                                        const ArgVec2& word   = ArgVec2(4, 8),
                                        const ArgVec2& frag   = ArgVec2(1, 2));

    /**
     * @brief Generate a random Markdown link.
     *
     * @since 0.3.0
     *
     * Generate a random link in Markdown format. This function is not exposed
     * in the C wrapper.
     *
     * @param url The URL to base the link off of. By default
     * https://example.com/.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 2.
     * @param wordURL The minimum and maximum possible number of words at the
     * end of the URL. By default 2 to 5.
     *
     * @return std::string The random link.
     */
    LIPSUM_API std::string GenerateMarkdownLink(
            const std::string& url     = std::string("https://example.com/"),
            const ArgVec2&     word    = ArgVec2(4, 8),
            const ArgVec2&     frag    = ArgVec2(1, 2),
            const ArgVec2&     wordURL = ArgVec2(2, 5));

    /**
     * @brief Generate a random Markdown list.
     *
     * @since 0.3.0
     *
     * Generate a random ordered or unordered list in Markdown format. This
     * function is not exposed in the C wrapper.
     *
     * @param ordered Whether the list is ordered or unordered. By default
     * false. (unordered)
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a point. By default 1 to 2.
     * @param point The minimum and maximum possible number of points in the
     * list. By default 3 to 5.
     *
     * @return std::string The random Markdown list.
     */
    LIPSUM_API std::string
               GenerateMarkdownList(bool           ordered = false,
                                    const ArgVec2& word    = ArgVec2(4, 8),
                                    const ArgVec2& frag    = ArgVec2(1, 2),
                                    const ArgVec2& point   = ArgVec2(3, 5));

    /**
     * @brief Generate a random formatted paragraph.
     *
     * @since 0.3.0
     *
     * Generate a paragraph in Markdown format with bold, italic, and links.
     * This function is not exposed in the C wrapper.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph. By default 5 to 8.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence. By default 4 to 8.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence. By default 1 to 2.
     * @param wordLink The minimum and maximum possible number of words in a
     * link URL. By default 2 to 5.
     * @param linkURL The URL to base links off of. By default
     * https://example.com/.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return std::string The random paragraph.
     */
    LIPSUM_API std::string GenerateMarkdownParagraph(
            const ArgVec2&     word      = ArgVec2(4, 9),
            const ArgVec2&     frag      = ArgVec2(1, 3),
            const ArgVec2&     sent      = ArgVec2(5, 8),
            const ArgVec2&     wordFmt   = ArgVec2(4, 8),
            const ArgVec2&     fragFmt   = ArgVec2(1, 2),
            const ArgVec2&     wordLink  = ArgVec2(2, 5),
            const std::string& linkURL   = std::string("https://example.com/"),
            bool               useLipsum = true);
    /**
     * @brief Generate multiple random formatted paragraphs.
     *
     * @since 0.3.2
     *
     * Generate multiple paragraphs in Markdown format with bold, italic, and
     * links. This function is not exposed in the C wrapper.
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph. By default 5 to 8.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence. By default 4 to 8.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence. By default 1 to 2.
     * @param wordLink The minimum and maximum possible number of words in a
     * link URL. By default 2 to 5.
     * @param linkURL The URL to base links off of. By default
     * https://example.com/.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return std::string The random paragraph.
     */
    LIPSUM_API std::string GenerateMarkdownParagraphs(
            int                paraCount = 5,
            const ArgVec2&     word      = ArgVec2(4, 9),
            const ArgVec2&     frag      = ArgVec2(1, 3),
            const ArgVec2&     sent      = ArgVec2(5, 8),
            const ArgVec2&     wordFmt   = ArgVec2(4, 8),
            const ArgVec2&     fragFmt   = ArgVec2(1, 2),
            const ArgVec2&     wordLink  = ArgVec2(2, 5),
            const std::string& linkURL   = std::string("https://example.com/"),
            bool               useLipsum = true);

    /**
     * @brief Generate a random Markdown document.
     *
     * @since 0.3.0
     *
     * Generate a random document in Markdown format.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in a
     * paragraph. By default 5 to 8.
     * @param point The minimum and maximum possible number of points in a list.
     * By default 3 to 5.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence. By default 4 to 8.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence. By default 1 to 2.
     * @param wordHead The minimum and maximum possible number of words in a
     * link URL or heading. By default 2 to 5.
     * @param level The minimum and maximum possible heading levels, excluding
     * the main heading. By default 2 to 4.
     * @param linkURL The URL to base links off of. By default
     * https://example.com/.
     * @param numElements The number of paragraphs, headings, and lists total.
     * By default 15.
     *
     * @return std::string The random Markdown document.
     */
    LIPSUM_API std::string GenerateMarkdownText(
            const ArgVec2&     word     = ArgVec2(4, 9),
            const ArgVec2&     frag     = ArgVec2(1, 3),
            const ArgVec2&     sent     = ArgVec2(5, 8),
            const ArgVec2&     point    = ArgVec2(3, 5),
            const ArgVec2&     wordFmt  = ArgVec2(4, 8),
            const ArgVec2&     fragFmt  = ArgVec2(1, 2),
            const ArgVec2&     wordHead = ArgVec2(2, 5),
            const ArgVec2&     level    = ArgVec2(2, 4),
            const std::string& linkURL  = std::string("https://example.com/"),
            int                numElements = 15);
} // namespace lipsum

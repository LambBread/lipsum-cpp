
/**
 * @file lipsum/misc.hpp
 *
 * @brief Miscellaneous functions of lipsum-cpp
 *
 * This declares miscellaneous functions in lipsum-cpp,
 * such as CountSentences() and deprecated HTMLify(). This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
namespace lipsum
{

    /**
     * @brief Turn a string into HTML paragraph tags.
     *
     * @deprecated Use a Markdown parser instead.
     *
     * @since 0.0.6
     *
     * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
     * handle HTML entities like &amp;, &lt;, &gt;, etc. This function is
     * deprecated.
     *
     * @return std::string The HTML-ified string.
     *
     * @param str The string inputted.
     */
    LIPSUM_API [[deprecated("Use a Markdown parser")]] std::string
    HTMLify(const std::string& str);

    /**
     * @overload
     *
     * @deprecated Use a Markdown parser instead.
     *
     * Turn a string into HTML paragraph tags specified by a C-style string.
     * This function is deprecated.
     *
     * @since 0.0.6
     *
     * @param str The string inputted.
     *
     * @return std::string The HTML-ified string.
     */
    LIPSUM_API [[deprecated("Use a Markdown parser")]] std::string
    HTMLify(const char* str);

    /**
     * @brief Count the number of sentences in a string.
     *
     * Count the number of periods in a string, ignoring usage in Markdown URLs.
     *
     * @since 0.3.0
     *
     * @param str The string inputted.
     *
     * @return int The number of sentences.
     */
    LIPSUM_API int CountSentences(const std::string& str);

    /**
     * @brief Return the current version of lipsum-cpp.
     *
     * Return the macro LIPSUM_CPP_VERSION.
     *
     * @since 0.3.2
     *
     * @return std::string The current version of lipsum-cpp.
     */
    LIPSUM_API std::string LipsumVersion();
} // namespace lipsum

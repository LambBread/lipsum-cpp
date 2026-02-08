
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
namespace lipsum
{

    /**
     * @brief Count the number of sentences in a string.
     *
     * Count the number of periods in a string, ignoring usage in Markdown URLs.
     * (i.e. in parentheses)
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

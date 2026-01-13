/**
 * @file lipsum/internal.hpp
 *
 * @brief lipsum::internal
 *
 * This declares members in lipsum::internal. This file is under the BSD
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
     * @namespace lipsum::internal
     *
     * @brief This namespace contains functions only used internally by other
     * functions.
     *
     * This namespace's functions are not intended for public use and are
     * not exposed in the C wrapper.
     */
    namespace internal
    {
        LIPSUM_API std::string HandleHTMLEntity(const std::string& str);
        LIPSUM_API int         RandomNumber(int min, int max);

        template <typename T> std::string ToString(const T& x)
        {
            std::stringstream ss;
            ss << x;
            return ss.str();
        }
    } // namespace internal
} // namespace lipsum

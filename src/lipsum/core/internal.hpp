/**
 * @file lipsum/core/internal.hpp
 *
 * @brief Declaration of lipsum::internal
 *
 * This declares members in lipsum::internal. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_INTERNAL_HPP
#    define LIPSUM_CORE_INTERNAL_HPP

#    include "core.hpp"

/**
 * @brief Choose between true or false
 */
#    define LPSM_FLIP_COIN lpsm::internal::RandomNumber<bool>(false, true)

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
        LIPSUM_API std::string GenerateTLD();
        LIPSUM_API std::string HandleHTMLEntity(const std::string& str);

        /**
         * @brief Log a warning.
         *
         * @since 0.4.2
         *
         * Log a warning to the console coloured yellow, starting with
         * "lipsum-cpp WARNING -- " and the message, ending in a newline. If in
         * Emscripten environment, use JavaScript console.warn() instead.
         *
         * @warning This function uses ANSI escape codes. The default Windows
         * terminal on older versions of Windows (< Windows 10 1511) does not
         * support ANSI escape codes. The default Windows terminal on newer
         * versions of Windows (>= Windows 10 1511) has support for ANSI escape
         * codes, but one may have to manually enable them with
         * SetConsoleMode(..., ENABLE_VIRTUAL_TERMINAL_PROCESSING).
         *
         * @param msg The message to print.
         */
        LIPSUM_API void LogWarn(const std::string& msg);

        template <typename T> T RandomNumber(T min, T max)
        {
            static thread_local std::mt19937 gen(std::random_device{}());
            if constexpr (std::is_integral_v<T>)
            {
                std::uniform_int_distribution<T> dist(min, max);
                return dist(gen);
            }
            else
            {
                std::uniform_real_distribution<T> dist(min, max);
                return dist(gen);
            }
        }
        template <> char RandomNumber(char min, char max);
        template <> bool RandomNumber(bool min, bool max);

        template <typename T> std::string ToString(const T& x)
        {
            std::stringstream ss;
            ss << x;
            return ss.str();
        }
    } // namespace internal
} // namespace lipsum
#endif

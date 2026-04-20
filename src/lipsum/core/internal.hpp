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

/**
 * @namespace lipsum::internal
 *
 * @brief This namespace contains functions only used internally by other
 * functions.
 *
 * This namespace's functions are not intended for public use and are
 * not exposed in the C wrapper.
 */
namespace lipsum::internal
{
    /**
     * @brief Pick a random TLD.
     *
     * @since 0.3.7
     *
     * This function picks a random TLD out of .com, .org, .net, .edu, .io, .ca,
     * and .co.uk, each with chances of 70%, 10%, 7%, 5%, 5%, 2%, and 1%
     * respectively.
     *
     * @return std::string The random TLD.
     */
    LIPSUM_API std::string GenerateTLD();

    /**
     * @brief Handle HTML entities.
     *
     * @since 0.0.6
     *
     * This function handles HTML entities by converting quotation marks,
     * apostrophes, less-than signs, greater-than signs, and ampersands to their
     * corresponding HTML entities.
     *
     * @param str The string to handle.
     *
     * @return The handled string.
     */
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
     * @note This function uses ANSI escape codes. The default Windows
     * terminal on older versions of Windows (< Windows 10 1511) does not
     * support ANSI escape codes. The default Windows terminal on newer
     * versions of Windows (>= Windows 10 1511) has support for ANSI escape
     * codes, but one may have to manually enable them with
     * SetConsoleMode(..., ENABLE_VIRTUAL_TERMINAL_PROCESSING).
     *
     * @tparam Args The arguments' types. All must be printable with
     * std::ostream, or else the code will fail to compile.
     *
     * @param args The arguments to print.
     */
    template <typename... Args> void LogWarn(const Args&... args)
    {
        std::ostringstream oss;
        oss << "lipsum-cpp WARNING -- ";
        ((oss << args), ...);
        oss << '\n';
        std::string message = oss.str();
#    ifndef __EMSCRIPTEN__
        std::cerr << "\033[33m" << message << "\033[0m";
#    else
        emscripten_console_warn(message.c_str());
#    endif
    }

    /**
     * @brief Generate a random number.
     *
     * @since 0.2.0
     *
     * Generate a random number between min and max, inclusive. If T is an
     * integer, use std::uniform_int_distribution. Else, use
     * std::uniform_real_distribution.
     *
     * @tparam T The type of the random number. Must be an integer or
     * floating-point type, else compilation will likely fail.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return T The random number.
     */
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

    /**
     * @brief Specialization of RandomNumber() for char
     *
     * @since 0.3.9
     *
     * This is a specialization of RandomNumber() for char.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return char The random character.
     */
    template <> LIPSUM_API char RandomNumber(char min, char max);

    /**
     * @brief Specialization of RandomNumber() for bool
     *
     * @since 0.3.9
     *
     * This is a specialization of RandomNumber() for bool.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return bool The random character.
     */
    template <> LIPSUM_API bool RandomNumber(bool min, bool max);

    /**
     * @brief Choose a random index based off weights
     *
     * @since 0.4.3
     *
     * This function chooses a random index of weights, with higher valued
     * weights being more likely. To do this, it passes the weights into an
     * std::discrete_distribution.
     *
     * @param weights The weights.
     *
     * @return int The random index.
     */
    LIPSUM_API int WeightedRandomIdx(const std::vector<int>& weights);

    /**
     * @brief Convert an object to a string.
     *
     * @since 0.3.0
     *
     * This function converts the parameter passed into a string using
     * std::stringstream.
     *
     * @param param The parameter being converted.
     *
     * @return std::string The parameter as a string.
     */
    template <typename T> std::string ToString(const T& param)
    {
        std::ostringstream oss;
        oss << param;
        return oss.str();
    }
} // namespace lipsum::internal
#endif

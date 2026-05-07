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
#    include "stdincludes.hpp"

/**
 * @brief Choose between true or false
 */
#    define LPSM_FLIP_COIN lpsm::internal::RandomNumber(false, true)

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
     * @brief Can std::to_string() be called with T?
     *
     * @since 0.4.6
     */
    template <typename T>
    concept ToStringable = requires(const T& value) {
        { std::to_string(value) } -> std::convertible_to<std::string>;
    };

    /**
     * @brief Can std::ostream take T?
     *
     * @since 0.4.6
     *
     * Can std::ostream take T and not by std::to_string()?
     */
    template <typename T>
    concept Streamable = requires(std::ostream& outs, const T& value) {
        { outs << value } -> std::same_as<std::ostream&>;
    } && (!ToStringable<T>);

    /**
     * @brief Is T an int?
     *
     * @since 0.4.6
     *
     * Is T an integer type, excluding chars and bool?
     */
    template <typename T>
    concept IsInt =
            (std::integral<T> || std::unsigned_integral<T>) &&
            !(std::same_as<T, char>) && !(std::same_as<T, signed char>) &&
            !(std::same_as<T, unsigned char>) && !(std::same_as<T, bool>);

    /**
     * @brief Can std::uniform_int_distribution or
     * std::uniform_real_distribution be constructed with T?
     *
     * @since 0.4.6
     */
    template <typename T>
    concept UniformDistributionType = (IsInt<T> || std::floating_point<T>);

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
     * Log a warning to the console coloured yellow using ANSI escape codes,
     * starting with "lipsum-cpp WARNING -- " and the message, ending in a
     * newline. If in Emscripten environment, use JavaScript console.warn()
     * instead. If in Windows environment, use SetConsoleTextAttribute()
     * instead.
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
#    ifdef __EMSCRIPTEN__
        // emscripten

        emscripten_console_warn(message.c_str());
#    elif defined(_WIN32)
        // windows

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // yellow
        SetConsoleTextAttribute(hConsole, 6);

        std::cerr << message;

        // default
        SetConsoleTextAttribute(hConsole, 7);
#    else
        // assumed unix-like

        std::cerr << "\033[33m" << message << "\033[0m";
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
     * @tparam T The type of the random number. Must be a uniform-distribution
     * type, i.e. ints (excluding chars and bool) and floats.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return T The random number.
     */
    template <UniformDistributionType T> T RandomNumber(T min, T max)
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
     * @brief Overload of RandomNumber() for char
     *
     * @since 0.3.9
     *
     * @overload
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return char The random character.
     */
    LIPSUM_API char RandomNumber(char min, char max);

    /**
     * @brief Overload of RandomNumber() for bool
     *
     * @since 0.3.9
     *
     * @overload
     *
     * @param min The minimum value.
     * @param max The maximum value.
     *
     * @return bool The random character.
     */
    LIPSUM_API bool RandomNumber(bool min, bool max);

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
     * std::stringstream or std::to_string().
     *
     * @tparam T The type being converted. Must be printable using
     * std::stringstream or convertable using std::to_string().
     *
     * @param param The parameter being converted.
     *
     * @return std::string The parameter as a string.
     */
    template <Streamable T> std::string ToString(const T& param)
    {
        // std::cout << "Using streamable\n";
        std::ostringstream oss;
        oss << param;
        return oss.str();
    }

    template <ToStringable T> std::string ToString(const T& param)
    {
        // std::cout << "Using to_string-able\n";
        return std::to_string(param);
    }

    /**
     * @brief Convert a string to an object.
     *
     * @since 0.4.6
     *
     * This function converts the string passed into the specified type. If T is
     * std::string, return input. If T is bool, return based on if input is
     * true/1 or false/0. If T is char, get first character of the string or a
     * null character if the string is empty. If T is an integer type, convert
     * using std::from_chars(). Else, convert using std::stringstream.
     *
     * @tparam T The type being converted to.
     *
     * @param input The string being converted.
     *
     * @return T The string as the type.
     */
    template <typename T> T ToType(const std::string& input)
    {
        T res{};

        if constexpr (std::same_as<T, std::string>)
        {
            return input;
        }
        else if constexpr (std::same_as<T, bool>)
        {
            // std::cout << "bool ToType\n";
            return (input == "true" || input == "1");
        }
        else if constexpr (std::same_as<T, char>)
        {
            // std::cout << "char ToType\n";
            return input.empty() ? '\0' : input.at(0);
        }
        else if constexpr (IsInt<T>)
        {
            // std::cout << "integer ToType\n";
            auto [ptr, ec] = std::from_chars(input.data(),
                                             input.data() + input.size(),
                                             res);
            if (ec != std::errc{})
            {
                LogWarn("lpsm::internal::ToType: std::from_chars() failed; "
                        "invalidly formatted integer? Returning default T.");
                return T{};
            }
            return res;
        }
        else
        // assume streamable
        {
            // std::cout << "generic ToType\n";
            std::istringstream iss(input);
            iss >> res;
            return res;
        }
    }
} // namespace lipsum::internal
#endif

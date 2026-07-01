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

#include "core.hpp"
#include "stdincludes.hpp"

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
     * @brief Log types for lipsum::internal::LogWarn()
     *
     * @since 0.5.2
     */
    enum class LogType : int
    {
        Trace = 0,
        Info,
        Warn,
        Error,
        Critical
    };

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
     * @brief Handle HTML entities.
     *
     * @since 0.0.6
     *
     * Handle HTML entities by converting quotation marks,
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
     * Log to the console coloured using ANSI escape codes with a message,
     * ending in a newline. If in Emscripten environment, use JavaScript console
     * functions instead. If in Windows environment, use
     * SetConsoleTextAttribute() instead. If doing a minimum build, skip
     * colouring text or logging in JS console. If doing a quiet build, do not
     * print.
     *
     * @tparam Args The arguments' types. All must be printable with
     * std::ostream, or else the code will fail to compile.
     *
     * @param type The log type of the message.
     * @param args The arguments to print.
     */
    template <typename... Args>
    void LogWarn([[maybe_unused]] LogType type,
                 [[maybe_unused]] const Args&... args)
    {
#ifndef LIPSUM_QUIET
        std::ostringstream oss;
        oss << "lipsum-cpp ";
        switch (type)
        {
            case LogType::Trace:
            {
                oss << "TRACE";
                break;
            }
            case LogType::Info:
            {
                oss << "INFO";
                break;
            }
            case LogType::Warn:
            {
                oss << "WARNING";
                break;
            }
            case LogType::Error:
            {
                oss << "ERROR";
                break;
            }
            case LogType::Critical:
            {
                oss << "CRITICAL";
                break;
            }
        }
        oss << " -- ";
        ((oss << args), ...);
        oss << '\n';
        std::string message = oss.str();
#    ifndef LIPSUM_MIN_BUILD
#        ifdef __EMSCRIPTEN__
        auto funcCalling = emscripten_console_warn;
        if (type == LogType::Trace || type == LogType::Info)
        {
            funcCalling = emscripten_console_log;
        }
        if (type == LogType::Error || type == LogType::Critical)
        {
            funcCalling = emscripten_console_error;
        }
        funcCalling(message.c_str());
#        elif defined(_WIN32)
        HANDLE hConsole   = GetStdHandle(STD_OUTPUT_HANDLE);
        int    colorUsing = 6; // yellow
        if (type == LogType::Trace)
        {
            colorUsing = 8; // gray
        }
        if (type == LogType::Info)
        {
            colorUsing = 2; // green
        }
        if (type == LogType::Error)
        {
            colorUsing = 12; // light red
        }
        if (type == LogType::Critical)
        {
            colorUsing = 4; // red
        }
        // yellow
        SetConsoleTextAttribute(hConsole, colorUsing);
        std::cerr << message;
        // default
        SetConsoleTextAttribute(hConsole, 7);
#        else
        int colorUsing = 33; // yellow
        if (type == LogType::Trace)
        {
            colorUsing = 90; // gray
        }
        if (type == LogType::Info)
        {
            colorUsing = 32; // green
        }
        if (type == LogType::Error)
        {
            colorUsing = 91; // light red
        }
        if (type == LogType::Critical)
        {
            colorUsing = 31; // red
        }
        std::cerr << "\033[" << colorUsing << "m" << message << "\033[0m";
#        endif
#    else
        std::cerr << message;
#    endif
#endif
    }

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
                LogWarn(internal::LogType::Error,
                        "lpsm::internal::ToType: std::from_chars() failed; "
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

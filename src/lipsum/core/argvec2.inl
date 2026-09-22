/**
 * @file lipsum/core/argvec2.inl
 *
 * @brief Definition of lipsum::ArgVec2 and internal functions
 *
 * This defines functions in struct lipsum::ArgVec2 and namespace
 * lipsum::internal. This file is under the BSD Zero Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#include "internal.hpp"

namespace lipsum
{

    ArgVec2::ArgVec2(int min, int max)
    {
        if (min < 0 || max < 0)
        {
            internal::LogWarn(internal::LogType::Warn,
                              "lpsm::ArgVec2::ArgVec2(): min and max set to (",
                              min,
                              ", ",
                              max,
                              "), expected both >= 0. If "
                              "this is intentional,"
                              "use another method to generate random numbers "
                              "instead.");
        }

        this->min = min;
        this->max = max;
    }

    int ArgVec2::roll(std::mt19937& gen, bool lazy) const
    {
        if (lazy)
        {
            return (min + max) / 2;
        }

        if (min <= max)
        {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(gen);
        }
        std::uniform_int_distribution<int> dist(max, min);
        return dist(gen);
    }

#ifndef LIPSUM_MIN_BUILD
    std::string internal::HandleHTMLEntity(char letter, Format format)
    {
        if (format == Format::Plain)
        {
            return std::string(1, letter); // NOLINT
        }
        std::string result;

        auto xmlLogic = [&]() -> std::string
        {
            switch (letter)
            {
                case '&':
                {
                    return "&amp;";
                }
                case '<':
                {
                    return "&lt;";
                }
                case '>':
                {
                    return "&gt;";
                }
                case '"':
                {
                    return "&quot;";
                }
                case '\'':
                {
                    return "&apos;";
                }
                default:
                {
                    return std::string(1, letter); // NOLINT
                }
            }
        };

        auto jsonLogic = [&]() -> std::string
        {
            switch (letter)
            {
                case '\\':
                {
                    return "\\\\";
                }
                case '\"':
                {
                    return "\\\"";
                }
                case '\n':
                {
                    return "\\n";
                }
                case '\t':
                {
                    return "\\t";
                }
                default:
                {
                    return std::string(1, letter); // NOLINT
                }
            }
        };

        auto mdLogic = [&]() -> std::string
        {
            static const std::vector<char> chars = {'\\',
                                                    '`',
                                                    '*',
                                                    '_',
                                                    '{',
                                                    '}',
                                                    '[',
                                                    ']',
                                                    '(',
                                                    ')',
                                                    '#',
                                                    '+',
                                                    '-',
                                                    '.',
                                                    '!'};
            for (const auto& let : chars)
            {
                if (let == letter)
                {
                    return std::string("\\") + std::string(1, let);
                }
            }
            return std::string(1, letter); // NOLINT
        };

        switch (format)
        {
            case Format::HTML:
            case Format::XML:
            {
                return xmlLogic();
            }
            case Format::JSON:
            {
                return jsonLogic();
            }
            case Format::Markdown:
            {
                return mdLogic();
            }
            default:
            {
                internal::LogWarn(internal::LogType::Error,
                                  "lpsm::internal::HandleHTMLEntity(): Format "
                                  "option ",
                                  static_cast<int>(format),
                                  " is out of range.");
                return "";
            }
        }

        // -> RESERVE_NUMER / RESERVE_DENOM times size of string
        // constexpr int RESERVE_NUMER = 7;
        // constexpr int RESERVE_DENOM = 5;
        // plus RESERVE_PLUS for small strings
        // constexpr int RESERVE_PLUS = 8;

        // result.reserve((str.length() * RESERVE_NUMER / RESERVE_DENOM) +
        //                RESERVE_PLUS);
    }
#else
    std::string internal::HandleHTMLEntity(const std::string& str)
    {
        return str;
    }
#endif

} // namespace lipsum

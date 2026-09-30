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
            std::unordered_map<char, std::string> xmlMap = {{'&', "&amp;"},
                                                            {'<', "&lt;"},
                                                            {'>', "&gt;"},
                                                            {'"', "&quot;"},
                                                            {'\'', "&apos;"}};

            if (xmlMap.contains(letter))
            {
                return xmlMap.at(letter);
            }
            return std::string(1, letter); // NOLINT
        };

        auto jsonLogic = [&]() -> std::string
        {
            std::unordered_map<char, std::string> jsonMap = {{'\\', "\\\\"},
                                                             {'"', "\\\""},
                                                             {'\n', "\\n"},
                                                             {'\t', "\\t"}};

            if (jsonMap.contains(letter))
            {
                return jsonMap.at(letter);
            }
            return std::string(1, letter); // NOLINT
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
    }

    static char LipsumArgvec2InlEscapeStr(const std::string& str, Format format)
    {
            if (!str.empty() && str.at(0) == '\\' &&
                (format == Format::Markdown || format == Format::JSON))
            {
                if (str.size() >= 2)
                {
                    if (str.at(1) == 'n' && format == Format::JSON)
                    {
                        return '\n';
                    }
                    if (str.at(1) == 't' && format == Format::JSON)
                    {
                        return '\t';
                    }
                    return str.at(1);
                }
            }

            if (!str.empty() && str.at(0) == '&' &&
                (format == Format::XML || format == Format::HTML))
            {
                // std::string                           escaped;
                std::unordered_map<std::string, char> htmlMap = {{"amp", '&'},
                                                                 {"lt", '<'},
                                                                 {"gt", '>'},
                                                                 {"quot", '"'},
                                                                 {"apos",
                                                                  '\''}};

                // int iter = 1;
                std::string escaped = str.substr(1, str.size() - 2);
                // while (str.at(iter) != ';')
                //{
                //     escaped += std::string(1, str.at(iter));
                //     ++iter;
                // }
                if (htmlMap.contains(escaped))
                {
                    return htmlMap.at(escaped);
                }
                // std::cout << escaped << '\n';
            }

            internal::
                    LogWarn(internal::LogType::Error,
                            "LipsumArgvec2InlEscapeStr(): An unknown or "
                            "invalid string was provided.");
            return ' ';

    }

    std::string internal::StripHTMLEntity(const std::string& str, Format format)
    {
        if (format == Format::Plain)
        {
            return str;
        }

        //auto escapeStr = [](const std::string& str, Format format) -> char
        //{
        //};

        std::string ret;
        std::string toEscape;
        bool        isEscaping = false;
        for (const auto& letter : str)
        {
            if (letter == '\\' && !isEscaping &&
                (format == Format::Markdown || format == Format::JSON))
            {
                isEscaping = true;
                toEscape.push_back(letter);
                continue;
            }

            if (letter == '&' && !isEscaping &&
                (format == Format::XML || format == Format::HTML))
            {
                isEscaping = true;
                toEscape.push_back(letter);
                continue;
            }

            if (isEscaping && (format == Format::HTML || format == Format::XML))
            {
                toEscape.push_back(letter);
                if (letter == ';')
                {
                    isEscaping = false;
                    ret.push_back(LipsumArgvec2InlEscapeStr(toEscape, format));
                    toEscape.clear();
                }
                continue;
            }

            if (isEscaping &&
                (format == Format::Markdown || format == Format::JSON))
            {
                toEscape.push_back(letter);
                isEscaping = false;
                ret.push_back(LipsumArgvec2InlEscapeStr(toEscape, format));
                toEscape.clear();
                continue;
            }
            ret.push_back(letter);
        }

        return ret;

        // error:

        // return ' ';
    }
#else
    std::string internal::HandleHTMLEntity(char letter, Format)
    {
        LPSM_VERBOSE_MINLOG;
        return std::string(1, letter); // NOLINT
    }

    std::string internal::StripHTMLEntity(const std::string& str, Format)
    {
        LPSM_VERBOSE_MINLOG;
        return str;
    }
#endif

} // namespace lipsum

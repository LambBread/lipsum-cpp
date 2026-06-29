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

#ifndef LIPSUM_CORE_ARGVEC2_INL
#    define LIPSUM_CORE_ARGVEC2_INL

#    include "internal.hpp"

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

    int ArgVec2::roll(std::mt19937& gen) const
    {
        if (min <= max)
        {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(gen);
        }
        std::uniform_int_distribution<int> dist(max, min);
        return dist(gen);
    }

    std::string internal::HandleHTMLEntity(const std::string& str)
    {
        std::string result;

        // -> RESERVE_NUMER / RESERVE_DENOM times size of string
        constexpr int RESERVE_NUMER = 7;
        constexpr int RESERVE_DENOM = 5;
        // plus RESERVE_PLUS for small strings
        constexpr int RESERVE_PLUS = 8;

        result.reserve((str.length() * RESERVE_NUMER / RESERVE_DENOM) +
                       RESERVE_PLUS);
        for (const auto& letter : str)
        {
            switch (letter)
            {
                case '&':
                {
                    result.append("&amp;");
                    break;
                }
                case '<':
                {
                    result.append("&lt;");
                    break;
                }
                case '>':
                {
                    result.append("&gt;");
                    break;
                }
                case '"':
                {
                    result.append("&quot;");
                    break;
                }
                case '\'':
                {
                    result.append("&apos;");
                    break;
                }
                default:
                {
                    result.push_back(letter);
                }
            }
        }
        return result;
    }

} // namespace lipsum
#endif

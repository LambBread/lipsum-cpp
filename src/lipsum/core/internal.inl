/**
 * @file lipsum/core/internal.inl
 *
 * @brief Definition of lipsum::internal
 *
 * This defines members in lipsum::internal. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_INTERNAL_INL
#    define LIPSUM_CORE_INTERNAL_INL

namespace lipsum
{

    template <> char internal::RandomNumber(char min, char max)
    {
        return static_cast<char>(internal::RandomNumber(static_cast<int>(min),
                                                        static_cast<int>(max)));
    }

    template <> bool internal::RandomNumber(bool min, bool max)
    {
        int choice = internal::RandomNumber(0, 1);
        return choice == 0 ? min : max;
    }

    // TODO: remove hardcoded values
    std::string internal::GenerateTLD()
    {
        constexpr int CHANCE_COM = 70;
        constexpr int CHANCE_ORG = 10;
        constexpr int CHANCE_NET = 7;
        constexpr int CHANCE_EDU = 5;
        constexpr int CHANCE_IO  = 5;
        constexpr int CHANCE_CA  = 2;
        int           rand       = internal::RandomNumber(0, 99);
        if (rand < CHANCE_COM)
        {
            return {".com"};
        }
        if (rand < CHANCE_COM + CHANCE_ORG)
        {
            return {".org"};
        }
        if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET)
        {
            return {".net"};
        }
        if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU)
        {
            return {".edu"};
        }
        if (rand <
            CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU + CHANCE_IO)
        {
            return {".io"};
        }
        if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU +
                           CHANCE_IO + CHANCE_CA)
        {
            return {".ca"};
        }
        return {".co.uk"};
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

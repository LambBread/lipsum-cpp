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

    void internal::LogWarn(const std::string& str)
    {
#    ifndef __EMSCRIPTEN__
        std::cerr << "\033[33mlipsum-cpp WARNING -- " << str << "\033[0m\n";
#    else
        // clang-format off

// use javascript console instead
        EM_ASM({
            const strText = UTF8ToString($0);
            console.warn("lipsum-cpp WARNING --", strText);
        }, str.c_str());

// clang-format on
#    endif
    }

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
            return std::string(".com");
        }
        else if (rand < CHANCE_COM + CHANCE_ORG)
        {
            return std::string(".org");
        }
        else if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET)
        {
            return std::string(".net");
        }
        else if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU)
        {
            return std::string(".edu");
        }
        else if (rand <
                 CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU + CHANCE_IO)
        {
            return std::string(".io");
        }
        else if (rand < CHANCE_COM + CHANCE_ORG + CHANCE_NET + CHANCE_EDU +
                                CHANCE_IO + CHANCE_CA)
        {
            return std::string(".ca");
        }
        else
        {
            return std::string(".co.uk");
        }
    }

    std::string internal::HandleHTMLEntity(const std::string& str)
    {
        std::string result;
        for (const auto& c : str)
        {
            switch (c)
            {
                case '&':
                {
                    result += "&amp;";
                    break;
                }
                case '<':
                {
                    result += "&lt;";
                    break;
                }
                case '>':
                {
                    result += "&gt;";
                    break;
                }
                case '"':
                {
                    result += "&quot;";
                    break;
                }
                case '\'':
                {
                    result += "&apos;";
                    break;
                }
                default:
                {
                    result.push_back(c);
                }
            }
        }
        return result;
    }
} // namespace lipsum
#endif

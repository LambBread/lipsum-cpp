
/**
 * @file lipsum/internal.inl
 *
 * @brief lipsum::internal
 *
 * This defines members in lipsum::internal. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

int lpsm::internal::RandomNumber(int min, int max)
{
    static std::random_device       rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

std::string lpsm::internal::HandleHTMLEntity(const std::string& str)
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

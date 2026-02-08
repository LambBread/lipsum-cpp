
/**
 * @file lipsum/internal.inl
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

std::string lpsm::internal::GenerateTLD()
{
    constexpr int CHANCE_COM = 70;
    constexpr int CHANCE_ORG = 10;
    constexpr int CHANCE_NET = 7;
    constexpr int CHANCE_EDU = 5;
    constexpr int CHANCE_IO  = 5;
    constexpr int CHANCE_CA  = 2;
    int           rand       = lpsm::internal::RandomNumber(0, 99);
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

/**
 * @file lipsum/core/source.inl
 *
 * @brief Mutli-source generation for lipsum-cpp
 *
 * This defines lipsum::Source. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_SOURCE_INL
#    define LIPSUM_CORE_SOURCE_INL

#    include "internal.hpp"
#    include "sample.inl"

namespace lipsum
{
    Source::Source(const std::string& path)
    {
        Load(path);
    }

    std::string Source::RandomWord() const
    {
        int idx;
        if (m_Words.empty())
        {
            idx = internal::RandomNumber<int>(0, LIPSUM_VEC.size() - 1);
            return std::string(LIPSUM_VEC.at(idx));
        }
        else
        {
            idx = internal::RandomNumber<int>(0, m_Words.size() - 1);
            return m_Words.at(idx);
        }
    }

    void Source::Load(const std::string& path)
    {
        m_Words.clear();
        std::ifstream                   f(path);
        std::unordered_set<std::string> unique;
        std::string                     word;
        char                            c;
        if (!f.is_open())
        {
            std::cerr << "lipsum-cpp error: Could not open file " << path
                      << '\n';
            return;
        }
        while (f.get(c))
        {
            if (std::isalnum(static_cast<unsigned char>(c)) || c == '_')
            {
                word += static_cast<char>(
                        std::tolower(static_cast<unsigned char>(c)));
            }
            else if (!word.empty())
            {
                unique.insert(word);
                word.clear();
            }
        }
        if (!word.empty())
        {
            unique.insert(word);
        }
        std::copy(unique.begin(), unique.end(), std::back_inserter(m_Words));
    }
} // namespace lipsum
#endif

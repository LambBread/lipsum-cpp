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
        load(path);
    }

    std::string Source::random_word() const
    {
        int idx;
        if (m_Words.empty())
        {
            idx = internal::RandomNumber<int>(0, LIPSUM_VEC.size() - 1);
            return {LIPSUM_VEC.at(idx)};
        }

        idx = internal::RandomNumber<int>(0, m_Words.size() - 1);
        return m_Words.at(idx);
    }

    void Source::load(const std::string& path)
    {
        m_Words.clear();
        std::ifstream                   file(path);
        std::unordered_set<std::string> unique;
        std::string                     word;
        char                            letter;
        if (!file.is_open())
        {
            internal::LogWarn("lpsm::Source::load(): Could not open file ",
                              path,
                              "; falling back to standard lorem-ipsum source");
            return;
        }
        while (file.get(letter))
        {
            if (static_cast<bool>(
                        std::isalnum(static_cast<unsigned char>(letter))) ||
                letter == '_')
            {
                word += static_cast<char>(
                        std::tolower(static_cast<unsigned char>(letter)));
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

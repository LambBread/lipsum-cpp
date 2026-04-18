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

#    define LPSM_SOURCE_CUSTOM_IPSUM(ipsum, name)                              \
        if (currentLoaded == name)                                             \
        {                                                                      \
            idx = internal::RandomNumber<int>(0, ipsum.size() - 1);            \
            return {ipsum.at(idx)};                                            \
        }

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
            LPSM_SOURCE_CUSTOM_IPSUM(CAT_IPSUM, "cat")
            LPSM_SOURCE_CUSTOM_IPSUM(DOG_IPSUM, "dog")
            LPSM_SOURCE_CUSTOM_IPSUM(CORPO_IPSUM, "corpo")
            idx = internal::RandomNumber<int>(0, LIPSUM_VEC.size() - 1);
            return {LIPSUM_VEC.at(idx)};
        }

        idx = internal::RandomNumber<int>(0, m_Words.size() - 1);
        return m_Words.at(idx);
    }

    void Source::load(const std::string& path)
    {
        m_Words.clear();
        if (path == "default" || path == "lorem")
        {
            currentLoaded = "default";
            return;
        }
        if (path == "cat")
        {
            currentLoaded = "cat";
            return;
        }
        if (path == "dog" || path == "doggo")
        {
            currentLoaded = "dog";
            return;
        }
        if (path == "corpo" || path == "corporate")
        {
            currentLoaded = "corpo";
            return;
        }

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

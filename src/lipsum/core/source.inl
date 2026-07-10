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

#include "internal.hpp"
#include "sample.inl"

#define LPSM_SOURCE_CUSTOM_IPSUM(ipsum, name)                                  \
    if (currentLoaded == name)                                                 \
    {                                                                          \
        std::uniform_int_distribution<size_t> dist(0, ipsum.size() - 1);       \
        return {ipsum.at(dist(gen))};                                          \
    }

namespace lipsum
{
    Source::Source(const std::string& path)
    {
        load(path);
    }

    std::string Source::random_word(std::mt19937& gen) const
    {
#ifndef LIPSUM_MIN_BUILD
        if (m_Words.empty())
        {
            LPSM_SOURCE_CUSTOM_IPSUM(CAT_IPSUM, "cat")
            LPSM_SOURCE_CUSTOM_IPSUM(DOG_IPSUM, "dog")
            LPSM_SOURCE_CUSTOM_IPSUM(CORPO_IPSUM, "corpo")
            std::uniform_int_distribution<size_t> dist(0,
                                                       LIPSUM_VEC.size() - 1);
            return {LIPSUM_VEC.at(dist(gen))};
        }

        std::uniform_int_distribution<size_t> dist(0, m_Words.size() - 1);
        return m_Words.at(dist(gen));
#else
        std::uniform_int_distribution<size_t> dist(0, LIPSUM_VEC.size() - 1);
        return {LIPSUM_VEC.at(dist(gen))};
#endif
    }

    void Source::load([[maybe_unused]] const std::string& path)
    {
        LPSM_VERBOSE_LOG(Info, "Loading source ", path);
        m_Words.clear();
#ifndef LIPSUM_MIN_BUILD
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
            internal::LogWarn(internal::LogType::Warn,
                              "lpsm::Source::load(): Could not open file ",
                              path,
                              "; falling back to standard lorem-ipsum source");
            return;
        }
        while (file.get(letter))
        {
            if (LPSM_SAFE_CCTYPE(bool, std::isalnum, letter) || letter == '_' ||
                letter == '-' || letter == '\'')
            {
                word += LPSM_SAFE_CCTYPE(char, std::tolower, letter);
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
#else
        currentLoaded = "default";
#endif
    }
} // namespace lipsum

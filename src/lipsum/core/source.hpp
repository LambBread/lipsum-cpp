/**
 * @file lipsum/core/source.hpp
 *
 * @brief Mutli-source generation for lipsum-cpp
 *
 * This declares lipsum::Source. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_SOURCE_HPP
#    define LIPSUM_CORE_SOURCE_HPP

#    include "core.hpp"

namespace lipsum
{
    /**
     * @brief Class for multi-source generation
     *
     * @since 0.4.0
     *
     * This class is for multi-source generation which exposes a function to
     * generate a random word.
     */
    class LIPSUM_API Source
    {
    public:
        /**
         * @brief Default constructor
         *
         * @since 0.4.0
         *
         * Default constructor which leaves the m_Words object empty and using
         * global LIPSUM_VEC from sample.inl instead.
         */
        Source() = default;

        /**
         * @brief Constructor with a path
         *
         * @since 0.4.0
         *
         * Constructor which reads from the file specified and fills object
         * m_Words with unique words.
         *
         * @param path A path to the source file.
         */
        Source(const std::string& path);

        /**
         * @brief Load a source and fill the vector.
         *
         * @since 0.4.1
         *
         * Read from the file specified and fill object m_Words with the unique
         * words from it. Formerly known as lpsm::Source::Load().
         *
         * @param path A path to the source file.
         */
        void load(const std::string& path);

        /**
         * @brief Select a random word.
         *
         * @since 0.4.0
         *
         * Select a random word from m_Words unless m_Words is empty, in which
         * it uses LIPSUM_VEC from sample.inl as a fallback. Formerly known as
         * lpsm::Source::RandomWord().
         *
         * @return std::string The random word.
         */
        std::string random_word() const;

    private:
        std::vector<std::string>
                m_Words; ///< The internal list of words stored.
    };
} // namespace lipsum
#endif

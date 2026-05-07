/**
 * @file lipsum/generatorsettings.hpp
 *
 * @brief Struct lipsum::GeneratorSettings
 *
 * This declares the struct lipsum::GeneratorSettings. This file is under the
 * BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_GENERATORSETTINGS_HPP
#    define LIPSUM_GENERATORSETTINGS_HPP

namespace lipsum
{
    /**
     * @brief Settings for lipsum::Generator
     *
     * @since 0.4.5
     *
     * This is a struct storing settings used in lipsum::Generator.
     */
    struct LIPSUM_API GeneratorSettings
    {
        /**
         * @brief The minimum and maximum possible number of words in a sentence
         * fragment.
         *
         * @since 0.4.5
         */
        ArgVec2 word{4, 9};

        /**
         * @brief The minimum and maximum possible number of sentence fragments
         * in a sentence.
         *
         * @since 0.4.5
         */
        ArgVec2 frag{1, 3};

        /**
         * @brief The minimum and maximum possible number of sentences in a
         * paragraph.
         *
         * @since 0.4.5
         */
        ArgVec2 sent{5, 8};

        /**
         * @brief The minimum and maximum possible number of paragraphs in a
         * text.
         *
         * @since 0.4.5
         */
        ArgVec2 para{1, 4};

        /**
         * @brief The minimum and maximum possible number of points in lists.
         *
         * @since 0.4.5
         */
        ArgVec2 point{3, 5};

        /**
         * @brief The minimum and maximum possible number of words at the end of
         * a URL, in a heading, or in slugs.
         *
         * @since 0.4.5
         */
        ArgVec2 wordURL{2, 5};

        /**
         * @brief The minimum and maximum possible number of words in a sentence
         * fragment in formatted sentences.
         *
         * @since 0.4.5
         */
        ArgVec2 wordFmt{4, 8};

        /**
         * @brief The minimum and maximum possible number of sentence fragments
         * in a formatted sentence.
         *
         * @since 0.4.5
         */
        ArgVec2 fragFmt{1, 2};

        /**
         * @brief The minimum and maximum possible heading levels, excluding
         * the main heading.
         *
         * @since 0.4.5
         */
        ArgVec2 level{2, 4};

        /**
         * @brief The minimum and maximum possible number of items in JSON
         * objects and arrays.
         *
         * @since 0.4.5
         */
        ArgVec2 jsonLength{2, 5};

        /**
         * @brief Change a setting
         *
         * @since 0.4.5
         *
         * Change a setting for generation. Valid setting names include "word",
         * "frag", "sent", "para", "point", "wordFmt", "fragFmt", "wordURL",
         * "level", and "jsonLength". If an invalid setting name is used, raise
         * a warning and ignore.
         *
         * @param setting The name of the setting.
         * @param value The new value for the setting.
         */
        void change_setting(const std::string& setting, const ArgVec2& value);
    };
} // namespace lipsum
#endif

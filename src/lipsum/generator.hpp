/**
 * @file lipsum/generator.hpp
 *
 * @brief Declaration of lipsum::Generator
 *
 * This declares the functions in lipsum::Generator. This file is under the
 * BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUM_GENERATOR_HPP
#    define LIPSUM_GENERATOR_HPP

#    include "core/core.hpp"
#    include "core/argvec2.hpp"
#    include "core/source.hpp"

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
         * a URL or in a heading.
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

    /**
     * @brief OOP layer over lipsum-cpp
     *
     * @since 0.2.0
     *
     * This provides a more user-friendly object-oriented layer over lipsum-cpp.
     */
    class LIPSUM_API Generator
    {
    public:
        /**
         * @brief Default constructor for Generator
         *
         * @since 0.2.0
         *
         * This loads the default lorem ipsum source.
         */
        Generator() = default;

        /**
         * @brief Constructor for Generator
         *
         * @since 0.4.1
         *
         * This loads the specified lorem ipsum source into m_Source. If path is
         * invalid, it will print a warning and default to the standard
         * lorem-ipsum source.
         *
         * @param path The filepath or name of the lorem ipsum source.
         *
         * @sa lipsum::Source::load
         */
        Generator(const std::string& path);

        /**
         * @brief Change a setting
         *
         * @since 0.4.4
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

        /**
         * @brief Change a setting
         *
         * @since 0.4.4
         *
         * @overload
         *
         * @param setting The name of the setting.
         * @param minValue The new minimum value of the setting.
         * @param maxValue The new maximum value of the setting.
         */
        void
        change_setting(const std::string& setting, int minValue, int maxValue);

        /**
         * @brief Generate words.
         *
         * @since 0.2.0
         *
         * This function generates multiple words.
         *
         * @param num The number of words. By default 1.
         *
         * @return std::string The random word.
         */
        std::string word(int num = 1);

        /**
         * @brief Generate a sentence fragment.
         *
         * @since 0.2.0
         *
         * This function generates a sentence fragment.
         *
         * @return std::string The random sentence fragment.
         */
        std::string sentence_fragment();

        /**
         * @brief Generate sentences.
         *
         * @since 0.2.0
         *
         * This function generates multiple sentences.
         *
         * @param num The number of sentences. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * sentence(s). By default true.
         *
         * @return std::string The random sentence(s).
         */
        std::string sentence(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate paragraphs.
         *
         * @since 0.2.0
         *
         * This function generates multiple paragraphs.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * paragraph(s). By default true.
         *
         * @return std::string The random paragraph(s).
         */
        std::string paragraph(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a random number of random paragraphs.
         *
         * @since 0.4.4
         *
         * This function generates a random number of random paragraphs.
         *
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * paragraph(s). By default true.
         *
         * @return std::string The random text.
         */
        std::string text(bool useLipsum = true);

        /**
         * @brief Generate a Markdown paragraph.
         *
         * @since 0.3.0
         *
         * This function generates multiple paragraphs in Markdown format.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         * By default true.
         *
         * @return std::string The random Markdown paragraph.
         */
        std::string md_paragraph(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a Markdown document.
         *
         * @since 0.3.0
         *
         * This function generates a document in Markdown format.
         *
         * @param numElements The number of elements (paragraph, list, heading)
         * in the document. By default 15.
         *
         * @return std::string The random Markdown document.
         */
        std::string md_text(int numElements = 15);

        /**
         * @brief Generate an HTML paragraph.
         *
         * @since 0.4.4
         *
         * This function generates multiple paragraphs in HTML format.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         * By default true.
         *
         * @return std::string The random HTML paragraph.
         */
        std::string html_paragraph(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate an HTML document.
         *
         * @since 0.4.4
         *
         * This function generates a document in HTML format.
         *
         * @param numElements The number of elements (paragraph, list, heading)
         * in the document. By default 15.
         *
         * @return std::string The random HTML document.
         */
        std::string html_text(int numElements = 15);

        /**
         * @brief Generate an XML document.
         *
         * @since 0.4.4
         *
         * This function generats a document in XML format.
         *
         * @param choices The number of choices (start element, end element, add
         * data element) that are made. By default 30.
         *
         * @return std::string The random XML document.
         */
        std::string xml(int choices = 30);

        /**
         * @brief Generate a JSON object or array.
         *
         * @since 0.4.4
         *
         * This function generates an object or array in JSON format.
         *
         * @param maxDepth Maximum depth of recursion. By default 3.
         * @param isObject Whether to output an object (true) or an array
         * (false). By default true.
         *
         * @return std::string The random JSON object or array.
         */
        std::string json(int maxDepth = 3, bool isObject = true);

    private:
        GeneratorSettings m_Settings; ///< Settings for generation

        /**
         * @brief Source used for generation.
         *
         * This is the source passed into functions. By default the default
         * lorem-ipsum source from sample.inl.
         *
         * @since 0.4.1
         */
        Source m_Source;
    };
} // namespace lipsum
#endif

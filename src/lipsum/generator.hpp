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

#    include "core/argvec2.hpp"
#    include "core/core.hpp"
#    include "core/source.hpp"
#    include "generatorsettings.hpp"

namespace lipsum
{

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
         * Load the default lorem ipsum source.
         */
        Generator() = default;

        /**
         * @brief Constructor for Generator
         *
         * @since 0.4.1
         *
         * Load the specified lorem ipsum source into m_Source. If path is
         * invalid, it will print a warning and default to the standard
         * lorem-ipsum source.
         *
         * @param path The filepath or name of the lorem ipsum source.
         *
         * @sa lipsum::Source::load
         */
        Generator(const std::string& path);

        /**
         * @brief Reload a source
         *
         * @since 0.4.5
         *
         * Reload the specified lorem ipsum source into m_Source. If path
         * is invalid, it will print a warning and default to the standard
         * lorem-ipsum source.
         *
         * @param path The filepath or name of the lorem ipsum source.
         *
         * @sa lipsum::Source::load
         */
        void load_source(const std::string& path);

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

        /*
         * CORE
         */

        /**
         * @brief Generate words.
         *
         * @since 0.2.0
         *
         * Generates multiple words.
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
         * Generate a sentence fragment. Formerly known as
         * sentence_fragment().
         *
         * @return std::string The random sentence fragment.
         */
        std::string fragment();

        /**
         * @brief Generate sentences.
         *
         * @since 0.2.0
         *
         * Generate multiple sentences.
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
         * Generate multiple paragraphs.
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
         * Generate a random number of random paragraphs.
         *
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * paragraph(s). By default true.
         *
         * @return std::string The random text.
         */
        std::string text(bool useLipsum = true);

        /*
         * MISC
         */

        /**
         * @brief Generate a random character scramble.
         *
         * @since 0.4.5
         *
         * Generate a random string of text with random characters.
         *
         * @param length The number of characters. By default 16.
         * @param minChar The lowest-valued ASCII character that can appear. By
         * default a space.
         * @param maxChar The highest-valued ASCII character than can appear. By
         * default a tilde.
         *
         * @return std::string The character scramble.
         */
        std::string
        scramble(int length = 16, char minChar = ' ', char maxChar = '~');

        /**
         * @brief Generate a URL.
         *
         * @since 0.4.5
         *
         * Generate a URL starting in https://, followed by a random word,
         * followed by a random TLD, followed by a slash and a random HTML id as
         * a slug separated by hyphens.
         *
         * @return std::string The URL.
         */
        std::string url();

        /**
         * @brief Generate a plain URL.
         *
         * @since 0.4.5
         *
         * Generate a URL with a random word followed by a random TLD.
         *
         * @return std::string The plain URL.
         */
        std::string plain_url();

        /**
         * @brief Generate a slug.
         *
         * @since 0.4.5
         *
         * Generate a sentence fragment with the spaces replaced
         * with the specified separator character.
         *
         * @param separator The separator character. By default a hyphen.
         *
         * @return std::string The slug.
         */
        std::string slug(char separator = '-');

        /*
         * FORMATS
         */

        /**
         * @brief Generate a Markdown paragraph.
         *
         * @since 0.3.0
         *
         * Generate multiple paragraphs in Markdown or HTML format.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         * By default true.
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random Markdown paragraph.
         */
        std::string
        md_paragraph(int num = 1, bool useLipsum = true, bool useHtml = false);

        /**
         * @brief Generate a Markdown document.
         *
         * @since 0.3.0
         *
         * Generate a document in Markdown or HTML format.
         *
         * @param numElements The number of elements (paragraph, list, heading)
         * in the document. By default 15.
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random Markdown document.
         */
        std::string md_text(int numElements = 15, bool useHtml = false);

        /**
         * @brief Generate a Markdown header.
         *
         * @since 0.4.6
         *
         * Generate a header in Markdown or HTML format.
         *
         * @param level The level of the heading. By default 1.
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random Markdown header.
         */
        std::string md_header(int level = 1, bool useHtml = false);

        /**
         * @brief Generate an emphasized Markdown sentence.
         *
         * @since 0.4.6
         *
         * Generate a bold or italic sentence in Markdown or HTML format that is
         * either bold or italic.
         *
         * @param isBold Whether the sentence is bold or italic. By default
         * true. (bold)
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random emphasized Markdown sentence.
         */
        std::string md_emphasis(bool isBold = true, bool useHtml = false);

        /**
         * @brief Generate a Markdown link.
         *
         * @since 0.4.6
         *
         * Generate a link in Markdown or HTML format.
         *
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random Markdown link.
         */
        std::string md_link(bool useHtml = false);

        /**
         * @brief Generate a Markdown list.
         *
         * @since 0.4.6
         *
         * Generate an ordered or unordered list in Markdown or HTML format.
         *
         * @param ordered Whether the list is ordered. By default false.
         * @param useHtml Whether HTML should be outputted instead of Markdown.
         * By default false.
         *
         * @return std::string The random Markdown list.
         */
        std::string md_list(bool ordered = false, bool useHtml = false);

        /**
         * @brief Generate an XML document.
         *
         * @since 0.4.4
         *
         * Generate a document in XML format.
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
         * Generate an object or array in JSON format.
         *
         * @param maxDepth The maximum level of recursion. By default 3.
         * @param isObject Whether to output an object (true) or an array
         * (false). By default true.
         *
         * @return std::string The random JSON object or array.
         */
        std::string json(int maxDepth = 3, bool isObject = true);

    private:
        /**
         * @brief Generate a single sentence.
         *
         * @since 0.5.0
         *
         * Generate a single sentence. This function is private.
         *
         * @return std::string The sentence.
         */
        std::string single_sentence();

        /**
         * @brief Generate a single paragraph.
         *
         * @since 0.5.0
         *
         * Generate a single paragraph. This function is private.
         *
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         *
         * @return std::string The paragraph.
         */
        std::string single_paragraph(bool useLipsum);

        GeneratorSettings m_Settings; ///< Settings for generation

        /**
         * @brief Source used for generation.
         *
         * The source passed into functions. By default the
         * lorem-ipsum source "lorem" from sample.inl.
         *
         * @since 0.4.1
         */
        Source m_Source;
    };
} // namespace lipsum
#endif

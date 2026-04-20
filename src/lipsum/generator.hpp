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
#    include "core/source.hpp"

namespace lipsum
{
    /**
     * @brief OOP layer over lipsum-cpp
     *
     * @since 0.2.0
     *
     * This provides a more user-friendly object-oriented layer over lipsum-cpp.
     * It uses mainly default arguments.
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
         * @param path The filepath of the lorem ipsum source.
         */
        Generator(const std::string& path);

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
         * @brief Generate sentences.
         *
         * @since 0.2.0
         *
         * This function generates multiple sentences with default arguments.
         *
         * @param num The number of sentences. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * sentence(s). By default true.
         *
         * @return std::string The random sentence(s).
         */
        std::string sentence(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a sentence fragment.
         *
         * @since 0.2.0
         *
         * This function generates a sentence fragment with default arguments.
         *
         * @return std::string The random sentence fragment.
         */
        std::string sentence_fragment();

        /**
         * @brief Generate paragraphs.
         *
         * @since 0.2.0
         *
         * This function generates multiple paragraphs with default arguments.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * paragraph(s). By default true.
         *
         * @return std::string The random paragraph(s).
         */
        std::string paragraph(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a Markdown paragraph.
         *
         * @since 0.3.0
         *
         * This function generates multiple paragraphs in Markdown format with
         * default arguments.
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
         * This function generates a document in Markdown format with default
         * arguments.
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
         * This function generates multiple paragraphs in HTML format with
         * default arguments.
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
         * This function generates a document in HTML format with default
         * arguments.
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
         * This function generats a document in XML format with default
         * arguments.
         *
         * @param choices The number of choices (start element, end element, add
         * data element) that are made. By default 30.
         *
         * @return std::string The random XML document.
         */
        std::string xml(int choices = 30);

    private:
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

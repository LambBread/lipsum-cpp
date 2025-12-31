/**
 * @file lipsum/generator.hpp
 *
 * @brief lpsm::Generator
 *
 * This declares the functions in lpsm::Generator. This file is under the
 * BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once
namespace lipsum
{
    /**
     * @brief OOP layer over lipsum-cpp
     *
     * This provides a more user-friendly object-oriented layer over lipsum-cpp.
     * It uses mainly default arguments. Unlike most of the codebase which uses
     * PascalCase, the functions in this class use snake_case.
     */
    class LIPSUM_API Generator
    {
    public:
        /**
         * @brief Generate words.
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
         * This function generates a sentence fragment with default arguments.
         *
         * @return std::string The random sentence fragment.
         */
        std::string sentence_fragment();

        /**
         * @brief Generate paragraphs.
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
         * This function generates a paragraph in Markdown format with default
         * arguments.
         *
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         * By default true.
         *
         * @return std::string The random Markdown paragraph.
         */
        std::string md_paragraph(bool useLipsum = true);

        /**
         * @brief Generate a Markdown document.
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
    };
} // namespace lipsum

/**
 * @file lipsum/core_funcs.hpp
 *
 * @brief Core functions of lipsum-cpp
 *
 * This declares core functions in lipsum-cpp around generation of words,
 * sentences, paragraphs, etc. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once
// #include "argvec2.hpp"
namespace lipsum
{
    /**
     * @brief Generate a slug joined by a specified character.
     *
     * @since 0.3.6
     *
     * Generates a sentence fragment with spaces replaced with the specified
     * separator character.
     *
     * @param word The minimum and maximum possible number of words in the slug.
     * By default 2 to 5.
     * @param separator The separator character. By default a hyphen.
     *
     * @return std::string The slug.
     */
    LIPSUM_API std::string GenerateSlug(const ArgVec2& word = ArgVec2(2, 5),
                                        char           separator = '-');

    /**
     * @brief Generate a random word.
     *
     * @since 0.0.3
     *
     * This function generates a random word from a predefined list.
     *
     * @return std::string The random word.
     */
    LIPSUM_API std::string GenerateWord();

    /**
     * @brief Generate a specified number of random words.
     *
     * @since 0.2.1
     *
     * This function generates a sentence fragment with exactly wordCount words.
     *
     * @param wordCount The number of words. By default 6.
     *
     * @return std::string The random words.
     */
    LIPSUM_API std::string GenerateWords(int wordCount = 6);

    /**
     * @brief Generate a fragment of a sentence without punctuation.
     *
     * @since 0.1.0
     *
     * This function generates a fragment of a sentence, without punctuation
     * inside.
     *
     * @param word The minimum and maximum possible number of words in a
     * fragment. By default 4 to 9.
     *
     * @return std::string The random sentence fragment.
     */
    LIPSUM_API std::string
               GenerateSentenceFragment(const ArgVec2& word = ArgVec2(4, 9));

    /**
     * @brief Generate a random sentence.
     *
     * @since 0.0.1
     *
     * This function generates a sentence starting with a capital letter
     * and ending with a period, often containing commas, semicolons, and
     * dashes.
     *
     * @return std::string The random sentence.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 3.
     */
    LIPSUM_API std::string GenerateSentence(const ArgVec2& word = ArgVec2(4, 9),
                                            const ArgVec2& frag = ArgVec2(1,
                                                                          3));

    /**
     * @brief Generate a random paragraph.
     *
     * @since 0.0.1
     *
     * This function generates a random paragraph starting with a tab character
     * and ending in a line break, with each sentence separated by a space.
     *
     * @return std::string The random paragraph.
     *
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph. By default 5 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph. By default true.
     */
    LIPSUM_API std::string
               GenerateParagraph(const ArgVec2& word      = ArgVec2(4, 9),
                                 const ArgVec2& frag      = ArgVec2(1, 3),
                                 const ArgVec2& sent      = ArgVec2(5, 8),
                                 bool           useLipsum = true);

    /**
     * @brief Generate several random paragraphs at once.
     *
     * @since 0.0.2
     *
     * This function generates several random paragraphs, each separated by a
     * line break. Formerly known as GenerateParagraphList().
     *
     * @return std::string The random paragraphs.
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param word The minimum and maximum total number of words in a sentence
     * fragment. By default 4 to 9.
     * @param frag The minimum and maximum total number of sentence fragments in
     * a sentence. By default 1 to 3.
     * @param sent The minimum and maximum total number of sentences in a
     * paragraph. By default 5 to 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph. By default true.
     */
    LIPSUM_API std::string
               GenerateParagraphs(int            paraCount = 5,
                                  const ArgVec2& word      = ArgVec2(4, 9),
                                  const ArgVec2& frag      = ArgVec2(1, 3),
                                  const ArgVec2& sent      = ArgVec2(5, 8),
                                  bool           useLipsum = true);

    /**
     * @brief Generate the beginning Lorem Ipsum sentence.
     *
     * @since 0.0.5
     *
     * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing
     * elit."
     *
     * @return std::string The default Lorem Ipsum sentence.
     */
    LIPSUM_API std::string GenerateDefaultLipsumSentence();

    /**
     * @brief Generate multiple random sentences at once.
     *
     * @since 0.0.5
     *
     * Generate multiple random sentences separated with spaces. Does not add a
     * tab character before the sentences nor a line break after.
     *
     * @return std::string The random sentences.
     *
     * @param sentCount The number of sentences. By default 6.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence. By default true.
     */
    LIPSUM_API std::string
               GenerateSentences(int            sentCount = 6,
                                 const ArgVec2& word      = ArgVec2(4, 9),
                                 const ArgVec2& frag      = ArgVec2(1, 3),
                                 bool           useLipsum = true);

    /**
     * @brief Generate a random number of random paragraphs.
     *
     * @since 0.3.2
     *
     * Generate a random number of random paragraphs separated by line breaks.
     *
     * @return std::string The random text.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in a
     * paragraph. By default 5 to 8.
     * @param para The minimum and maximum possible number of paragraphs in the
     * text. By default 1 to 4.
     * @param useLipsum Whether "Lorem ipsum..." should start the first
     * paragraph. By default true.
     */
    LIPSUM_API std::string GenerateText(const ArgVec2& word = ArgVec2(4, 9),
                                        const ArgVec2& frag = ArgVec2(1, 3),
                                        const ArgVec2& sent = ArgVec2(5, 8),
                                        const ArgVec2& para = ArgVec2(1, 4),
                                        bool           useLipsum = true);
} // namespace lipsum

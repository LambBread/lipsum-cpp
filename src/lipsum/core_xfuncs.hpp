/**
 * @file lipsum/core_xfuncs.hpp
 *
 * @brief Core "X" functions of lipsum-cpp
 *
 * This declares the &quot;X&quot; variants of core functions in lipsum-cpp
 * around generation of words, sentences, paragraphs, etc. This file is under
 * the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
#include "core/core.hpp"
#include "core/source.hpp"
namespace lipsum
{

    /**
     * @brief Generate a random URL.
     *
     * @since 0.3.7
     *
     * @xovload
     *
     * @param minWord The minimum possible number of words at the end
     * of the URL. By default 2.
     * @param maxWord The maximum possible number of words at the end of the
     * URL. By default 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The URL.
     */
    LIPSUM_API std::string GenerateURLX(int           minWord = 2,
                                        int           maxWord = 5,
                                        const Source& source  = Source());

    /**
     * @brief Generate a slug joined by a specified character.
     *
     * @since 0.3.6
     *
     * @xovload
     *
     * @param minWord The minimum possible number of words in the slug. By
     * default 2.
     * @param maxWord The maximum possible number of words in the slug. By
     * default 5.
     * @param separator The separator character. By default a hyphen.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The slug.
     */
    LIPSUM_API std::string GenerateSlugX(int           minWord   = 2,
                                         int           maxWord   = 5,
                                         char          separator = '-',
                                         const Source& source    = Source());

    /**
     * @brief Generate a fragment of a sentence without punctuation.
     *
     * @since 0.1.1
     *
     * @xovload
     *
     * @param minWord Minimum possible number of words in a sentence fragment.
     * By default 4.
     * @param maxWord Maximum possible number of words in a sentence fragment.
     * By default 9.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random sentence fragment.
     */
    LIPSUM_API std::string GenerateSentenceFragmentX(
            int minWord = 4, int maxWord = 9, const Source& source = Source());

    /**
     * @brief Generate a random sentence.
     *
     * @since 0.1.1
     *
     * @xovload
     *
     * @param minWord Minimum possible number of words in a sentence fragment.
     * By default 4.
     * @param maxWord Maximum possible number of words in a sentence fragment.
     * By default 9.
     * @param minFrag Minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag Maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random sentence.
     */
    LIPSUM_API std::string GenerateSentenceX(int           minWord = 4,
                                             int           maxWord = 9,
                                             int           minFrag = 1,
                                             int           maxFrag = 3,
                                             const Source& source  = Source());

    /**
     * @brief Generate a random paragraph.
     *
     * @since 0.1.1
     *
     * @xovload
     *
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param minSent The minimum possible number of sentences in the paragraph.
     * By default 5.
     * @param maxSent The maximum possible number of sentences in the paragraph.
     * By default 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph. By default true.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random paragraph.
     */
    LIPSUM_API std::string GenerateParagraphX(int           minWord   = 4,
                                              int           maxWord   = 9,
                                              int           minFrag   = 1,
                                              int           maxFrag   = 3,
                                              int           minSent   = 5,
                                              int           maxSent   = 8,
                                              bool          useLipsum = true,
                                              const Source& source = Source());

    /**
     * @brief Generate several random paragraphs at once.
     *
     * @since 0.1.1
     *
     * @xovload
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param minSent The minimum possible number of sentences in a paragraph.
     * By default 5.
     * @param maxSent The maximum possible number of sentences in a paragraph.
     * By default 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph. By default true.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random paragraphs.
     */
    LIPSUM_API std::string GenerateParagraphsX(int           paraCount = 5,
                                               int           minWord   = 4,
                                               int           maxWord   = 9,
                                               int           minFrag   = 1,
                                               int           maxFrag   = 3,
                                               int           minSent   = 5,
                                               int           maxSent   = 8,
                                               bool          useLipsum = true,
                                               const Source& source = Source());

    /**
     * @brief Generate multiple random sentences at once.
     *
     * @since 0.1.1
     *
     * @xovload
     *
     * @param sentCount The number of sentences. By default 6.
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence. By default true.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     */
    LIPSUM_API std::string GenerateSentencesX(int           sentCount = 6,
                                              int           minWord   = 4,
                                              int           maxWord   = 9,
                                              int           minFrag   = 1,
                                              int           maxFrag   = 3,
                                              bool          useLipsum = true,
                                              const Source& source = Source());

    /**
     * @brief Generate a random number of random paragraphs.
     *
     * @since 0.3.2
     *
     * @xovload
     *
     * @return std::string The random text.
     *
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param minSent The minimum possible number of sentences in a paragraph.
     * By default 5.
     * @param maxSent The maximum possible number of sentences in a paragraph.
     * By default 8.
     * @param minPara The minimum possible number of paragraphs in the text. By
     * default 1.
     * @param maxPara The maximum possible number of paragraphs in the text. By
     * default 4.
     * @param useLipsum Whether "Lorem ipsum..." should start the first
     * paragraph. By default true.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     */
    LIPSUM_API std::string GenerateTextX(int           minWord   = 4,
                                         int           maxWord   = 9,
                                         int           minFrag   = 1,
                                         int           maxFrag   = 3,
                                         int           minSent   = 5,
                                         int           maxSent   = 8,
                                         int           minPara   = 1,
                                         int           maxPara   = 4,
                                         bool          useLipsum = true,
                                         const Source& source    = Source());
} // namespace lipsum

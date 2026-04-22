/**
 * @file lipsum/formats.hpp
 *
 * @brief JSON/XML functions of lipsum-cpp
 *
 * This declares functions in lipsum-cpp around generation of XML/JSON
 * documents. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUM_FORMATS_HPP
#    define LIPSUM_FORMATS_HPP

#    include "core/core.hpp"
#    include "core/argvec2.hpp"
#    include "core/source.hpp"

namespace lipsum
{
    /**
     * @brief Generate a random XML document.
     *
     * @since 0.4.4
     *
     * Generate a random document in XML format starting with an XML metadata
     * tag. Create a root element and make a number of choices to create a new
     * tag, fill a tag, or close a tag. Afterwards, close all remaining tags.
     *
     * @param choices The number of choices to make. By default 30.
     * @param word The minimum and maximum total number of words in a sentence
     * fragment. By default 4 to 9.
     * @param frag The minimum and maximum total number of sentence fragments in
     * a sentence. By default 1 to 3.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The XML document.
     */
    LIPSUM_API std::string
               GenerateXMLDocument(int            choices = 30,
                                   const ArgVec2& word    = ArgVec2(4, 9),
                                   const ArgVec2& frag    = ArgVec2(1, 3),
                                   const Source&  source  = Source());

    /**
     * @brief Generate a random JSON string.
     *
     * @since 0.4.4
     *
     * Generate a word with quotes surrounding it.
     *
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON string.
     */
    LIPSUM_API std::string GenerateJSONString(const Source& source = Source());

    /**
     * @brief Generate a random JSON number.
     *
     * @since 0.4.4
     *
     * Generate a random number from -1000 to 1000 and convert it to a string.
     *
     * @return std::string The random JSON number.
     */
    LIPSUM_API std::string GenerateJSONNumber();

    /**
     * @brief Generate a random JSON object.
     *
     * @since 0.4.4
     *
     * Generate a random JSON object recursively.
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param jsonLength The minimum and maximum possible number of items in the
     * object. By default 2 to 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON object.
     */
    LIPSUM_API std::string
               GenerateJSONObject(int            depth      = 0,
                                  int            maxDepth   = 3,
                                  const ArgVec2& jsonLength = ArgVec2(2, 5),
                                  const Source&  source     = Source());

    /**
     * @brief Generate a random JSON array.
     *
     * @since 0.4.4
     *
     * Generate a random JSON array recursively.
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param jsonLength The minimum and maximum possible number of items in the
     * array. By default 2 to 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON array.
     */
    LIPSUM_API std::string
               GenerateJSONArray(int            depth      = 0,
                                 int            maxDepth   = 3,
                                 const ArgVec2& jsonLength = ArgVec2(2, 5),
                                 const Source&  source     = Source());

    /**
     * @brief Generate a random JSON value.
     *
     * @since 0.4.4
     *
     * Generate a random JSON value, which can be a string, a number, a bool,
     * null, and if depth <= maxDepth, an object or array.
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param jsonLength The minimum and maximum possible number of items in
     * arrays and objects. By default 2 to 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON value.
     */
    LIPSUM_API std::string
               GenerateJSONValue(int            depth      = 0,
                                 int            maxDepth   = 3,
                                 const ArgVec2& jsonLength = ArgVec2(2, 5),
                                 const Source&  source     = Source());

    /**
     * @brief Generate a random XML document.
     *
     * @since 0.4.4
     *
     * @xovload
     *
     * @param choices The number of choices to make. By default 30.
     * @param minWord The minimum total number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum total number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum total number of sentence fragments in
     * a sentence. By default 1.
     * @param maxFrag The maximum total number of sentence fragments in
     * a sentence. By default 3.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The XML document.
     */
    LIPSUM_API std::string
               GenerateXMLDocumentX(int           choices = 30,
                                    int           minWord = 4,
                                    int           maxWord = 9,
                                    int           minFrag = 1,
                                    int           maxFrag = 3,
                                    const Source& source  = Source());

    /**
     * @brief Generate a random JSON object.
     *
     * @since 0.4.4
     *
     * @xovload
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param minJsonLength The minimum possible number of items in the
     * object. By default 2.
     * @param maxJsonLength The maximum possible number of items in the
     * object. By default 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON object.
     */
    LIPSUM_API std::string GenerateJSONObjectX(int           depth         = 0,
                                               int           maxDepth      = 3,
                                               int           minJsonLength = 2,
                                               int           maxJsonLength = 5,
                                               const Source& source = Source());

    /**
     * @brief Generate a random JSON array.
     *
     * @since 0.4.4
     *
     * @xovload
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param minJsonLength The minimum possible number of items in the
     * array. By default 2.
     * @param maxJsonLength The maximum possible number of items in the
     * array. By default 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON array.
     */
    LIPSUM_API std::string GenerateJSONArrayX(int           depth         = 0,
                                              int           maxDepth      = 3,
                                              int           minJsonLength = 2,
                                              int           maxJsonLength = 5,
                                              const Source& source = Source());

    /**
     * @brief Generate a random JSON value.
     *
     * @since 0.4.4
     *
     * @xovload
     *
     * @param depth The current level of recursion. By default 0.
     * @param maxDepth The maximum level of recursion. By default 3.
     * @param minJsonLength The minimum possible number of items in
     * arrays and objects. By default 2.
     * @param maxJsonLength The maximum possible number of items in
     * arrays and objects. By default 5.
     * @param source The source for words. By default the standard "Lorem
     * ipsum..." sample.
     *
     * @return std::string The random JSON value.
     */
    LIPSUM_API std::string GenerateJSONValueX(int           depth         = 0,
                                              int           maxDepth      = 3,
                                              int           minJsonLength = 2,
                                              int           maxJsonLength = 5,
                                              const Source& source = Source());

} // namespace lipsum

#endif

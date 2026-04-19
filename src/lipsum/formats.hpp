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
     * Generate a random document in XML format starting with an XML metadata
     * tag. Create a root element and make a number of choices to create a new
     * tag, fill a tag, or close a tag. Afterwards, close all remaining tags.
     *
     * @param choices The number of choices to make. By default 70.
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
} // namespace lipsum

#endif

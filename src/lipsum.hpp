/**
 * @file lipsum.hpp
 *
 * @brief Main header of lipsum-cpp
 *
 * This contains the declarations of functions as well as definitions
 * if LIPSUM_IMPLEMENTATION is defined. This file is under the BSD Zero-Clause
 * License.
 *
 * @author LambBread from github.com
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @example Advanced.cpp
 * @example Basic.cpp
 * @example Formats.cpp
 * @example GenerateParagraph.cpp
 * @example GenerateParagraphs.cpp
 * @example GenerateSentence.cpp
 * @example GenerateSentenceFragment.cpp
 * @example GenerateSentences.cpp
 * @example GenerateText.cpp
 * @example GenerateWord.cpp
 * @example GenerateWords.cpp
 * @example Markdown.cpp
 * @example Misc.cpp
 * @example Source.cpp
 */

#pragma once

#ifndef LIPSUM_HPP
#    define LIPSUM_HPP

#    include "lipsum/core/stdincludes.hpp"
#    include "lipsum/core/internal.hpp"

#    include "lipsum/generator.hpp"
#    include "lipsum/core_funcs.hpp"
#    include "lipsum/markdown.hpp"
#    include "lipsum/core_xfuncs.hpp"
#    include "lipsum/formats.hpp"
#    include "lipsum/md_xfuncs.hpp"
#    include "lipsum/misc.hpp"

/**
 * @namespace lipsum
 *
 * @brief This is the main namespace of lipsum-cpp.
 *
 * This namespace contains all the code for the C++ usage of lipsum-cpp.
 */
namespace lipsum
{
}

namespace lpsm = lipsum; ///< Alias for namespace lipsum

#    ifdef LIPSUM_IMPLEMENTATION

#        include "lipsum/core/argvec2.inl"
#        include "lipsum/core/internal.inl"
#        include "lipsum/core/source.inl"

#        include "lipsum/core_funcs.inl"
#        include "lipsum/generator.inl"
#        include "lipsum/markdown.inl"
#        include "lipsum/formats.inl"
#        include "lipsum/misc.inl"
#        include "lipsum/xfuncs.inl"

#    endif
#endif

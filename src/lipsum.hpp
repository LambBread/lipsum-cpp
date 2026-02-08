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
 * @example GenerateDefaultLipsumSentence.cpp
 * @example GenerateMarkdownEmphasis.cpp
 * @example GenerateMarkdownHeader.cpp
 * @example GenerateMarkdownLink.cpp
 * @example GenerateMarkdownList.cpp
 * @example GenerateMarkdownParagraph.cpp
 * @example GenerateMarkdownParagraphs.cpp
 * @example GenerateMarkdownText.cpp
 * @example GenerateParagraph.cpp
 * @example GenerateParagraphs.cpp
 * @example GenerateSentence.cpp
 * @example GenerateSentenceFragment.cpp
 * @example GenerateSentences.cpp
 * @example GenerateSlug.cpp
 * @example GenerateText.cpp
 * @example GenerateURL.cpp
 * @example GenerateWord.cpp
 * @example GenerateWords.cpp
 * @example Markdown.cpp
 * @example Misc.cpp
 */

#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "lipsum/core.hpp"

#include "lipsum/argvec2.hpp"
#include "lipsum/generator.hpp"
#include "lipsum/internal.hpp"

#include "lipsum/core_funcs.hpp"
#include "lipsum/markdown.hpp"
#include "lipsum/core_xfuncs.hpp"
#include "lipsum/md_xfuncs.hpp"
#include "lipsum/misc.hpp"

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

/// Alias for namespace lipsum
namespace lpsm = lipsum;

#ifdef LIPSUM_IMPLEMENTATION

#    include "lipsum/argvec2.inl"
#    include "lipsum/generator.inl"
#    include "lipsum/internal.inl"

#    include "lipsum/core_funcs.inl"
#    include "lipsum/markdown.inl"
#    include "lipsum/xfuncs.inl"
#    include "lipsum/misc.inl"

#endif

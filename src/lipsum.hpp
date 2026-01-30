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
 */

#pragma once

#include <cctype>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "lipsum/core.hpp"
#include "lipsum/internal.hpp"
#include "lipsum/argvec2.hpp"
#include "lipsum/generator.hpp"
#include "lipsum/core_funcs.hpp"
#include "lipsum/core_xfuncs.hpp"
#include "lipsum/misc.hpp"
#include "lipsum/markdown.hpp"
#include "lipsum/md_xfuncs.hpp"

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

#    include "lipsum/generator.inl"
#    include "lipsum/markdown.inl"
#    include "lipsum/misc.inl"
#    include "lipsum/core_funcs.inl"
#    include "lipsum/internal.inl"
#    include "lipsum/xfuncs.inl"
#    include "lipsum/argvec2.inl"

#endif

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
 * @example Generator.cpp
 * @example GeneratorFormats.cpp
 * @example Markdown.cpp
 * @example Misc.cpp
 * @example Source.cpp
 */

#pragma once

#ifndef LIPSUM_HPP
#    define LIPSUM_HPP

#    include "lipsum/core/internal.hpp"
#    include "lipsum/core/stdincludes.hpp"
#    include "lipsum/generator.hpp"
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
#        include "lipsum/core/source.inl"
#        include "lipsum/generator.inl"
#        include "lipsum/misc.inl"

#    endif
#endif

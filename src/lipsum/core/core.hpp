/**
 * @file lipsum/core/core.hpp
 *
 * @brief Core macros for lipsum-cpp
 *
 * This defines the
 * shared library macro and some utility macros. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUM_CORE_CORE_HPP
#    define LIPSUM_CORE_CORE_HPP

#    include "version.hpp"

#    ifndef __cplusplus
#        error lipsum.hpp only supports C++, did you mean lipsum.h?
#    endif

/**
 * @brief Choose between true or false
 */
#    define LPSM_FLIP_COIN random_number(false, true)

/**
 * @brief Simplify safe cctype usage
 */
#    define LPSM_SAFE_CCTYPE(type, func, arg)                                  \
        (static_cast<type>(func(static_cast<unsigned char>((arg)))))

/**
 * @brief Macro for shared libraries
 *
 * @since 0.1.2
 *
 * This macro helps with shared libraries on Windows by exporting
 * or importing functions.
 */
#    ifdef LIPSUM_BUILD_SHARED
#        ifdef _WIN32
#            ifdef LIPSUM_EXPORT_SHARED
#                define LIPSUM_API __declspec(dllexport)
#            else
#                define LIPSUM_API __declspec(dllimport)
#            endif
#        else
#            define LIPSUM_API
#        endif
#    else
#        define LIPSUM_API
#    endif
#endif

/**
 * @file lipsum/core.hpp
 *
 * @brief Core macros for lipsum-cpp
 *
 * This defines the macros for the current lipsum-cpp version as well as the
 * shared library macro. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once
/**
 * @brief The current version of lipsum-cpp.
 *
 * @since 0.2.1
 *
 * This macro stores the current version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION "0.3.2"

#ifndef __cplusplus
#    error lipsum.hpp only supports C++, did you mean lipsum.h?
#endif

/**
 * @brief Macro for shared libraries
 *
 * @since 0.1.2
 *
 * This macro helps with shared libraries on Windows by exporting
 * or importing functions.
 */
#ifdef LIPSUM_BUILD_SHARED
#    ifdef _WIN32
#        ifdef LIPSUM_EXPORT_SHARED
#            define LIPSUM_API __declspec(dllexport)
#        else
#            define LIPSUM_API __declspec(dllimport)
#        endif
#    else
#        define LIPSUM_API
#    endif
#else
#    define LIPSUM_API
#endif

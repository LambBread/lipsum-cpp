/**
 * @file lipsumc/core.h
 *
 * @brief Core macros for lipsum-cpp C wrapper
 *
 * This defines macros for the current lipsum-cpp version as well as the
 * shared library macro. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUMC_CORE_H
#    define LIPSUMC_CORE_H

#    include "version.h"

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
#                define LIPSUMC_API __declspec(dllexport)
#            else
#                define LIPSUMC_API __declspec(dllimport)
#            endif
#        else
#            define LIPSUMC_API
#        endif
#    else
#        define LIPSUMC_API
#    endif

#    ifndef LIPSUM_BUILD_STATIC
#        error Cannot use C wrapper without building a static or shared library.
#    endif

#endif

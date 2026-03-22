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
#ifndef LIPSUM_CORE_H
#define LIPSUM_CORE_H

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
#            define LIPSUMC_API __declspec(dllexport)
#        else
#            define LIPSUMC_API __declspec(dllimport)
#        endif
#    else
#        define LIPSUMC_API
#    endif
#else
#    define LIPSUMC_API
#endif
#ifndef LIPSUM_BUILD_STATIC
#    error Cannot use C wrapper without building a static or shared library.
#endif

/**
 * @brief The current version of lipsum-cpp.
 *
 * @since 0.2.1
 *
 * This macro stores the current version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION_C "0.4.1"

/**
 * @brief The major version of lipsum-cpp.
 *
 * @since 0.4.0
 *
 * This macro stores the current major version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION_MAJOR_C 0

/**
 * @brief The minor version of lipsum-cpp.
 *
 * @since 0.4.0
 *
 * This macro stores the current minor version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION_MINOR_C 4

/**
 * @brief The patch version of lipsum-cpp.
 *
 * @since 0.4.0
 *
 * This macro stores the current patch version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION_PATCH_C 1

#endif

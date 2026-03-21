/**
 * @file lipsum/core.hpp
 *
 * @brief Core macros for lipsum-cpp
 *
 * This defines the macros for the current lipsum-cpp version as well as the
 * shared library macro. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

/**
 * @brief The current version of lipsum-cpp.
 *
 * @since 0.2.1
 *
 * This macro stores the current version of lipsum-cpp, stored as a string.
 */
inline constexpr const char* LIPSUM_CPP_VERSION = "0.4.0";
        // #define LIPSUM_CPP_VERSION "0.4.0"

        /**
         * @brief The major version of lipsum-cpp.
         *
         * @since 0.4.0
         *
         * This macro stores the current major version of lipsum-cpp.
         */
        inline constexpr int LIPSUM_CPP_VERSION_MAJOR = 0;
        // #define LIPSUM_CPP_VERSION_MAJOR 0

        /**
         * @brief The minor version of lipsum-cpp.
         *
         * @since 0.4.0
         *
         * This macro stores the current minor version of lipsum-cpp.
         */
        inline constexpr int LIPSUM_CPP_VERSION_MINOR = 4;
        // #define LIPSUM_CPP_VERSION_MINOR 4

        /**
         * @brief The patch version of lipsum-cpp.
         *
         * @since 0.4.0
         *
         * This macro stores the current patch version of lipsum-cpp.
         */
        inline constexpr int LIPSUM_CPP_VERSION_PATCH = 0;
// #define LIPSUM_CPP_VERSION_PATCH 0

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

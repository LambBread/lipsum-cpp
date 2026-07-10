/**
 * @file lipsum/core/stdincludes.hpp
 *
 * @brief Standard library includes of lipsum-cpp
 *
 * This file includes various standard library headers into lipsum-cpp.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#include <algorithm>
#include <array>
#include <cctype>
#include <concepts>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#ifndef LIPSUM_MIN_BUILD
#    include <charconv>
#    include <fstream>
#    include <type_traits>
#    include <unordered_set>
#    ifdef __EMSCRIPTEN__
#        include <emscripten/console.h>
#    endif
#    ifdef _WIN32
#        ifndef WIN32_LEAN_AND_MEAN
#            define WIN32_LEAN_AND_MEAN
#        endif
#        ifndef NOMINMAX
#            define NOMINMAX
#        endif
#        include <windows.h>
#    endif
#endif

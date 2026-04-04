/**
 * @file lipsum/core/argvec2.inl
 *
 * @brief Definition of lipsum::ArgVec2
 *
 * This defines functions in struct ArgVec2. This file is under the BSD Zero
 * Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_CORE_ARGVEC2_INL
#    define LIPSUM_CORE_ARGVEC2_INL

#    include "internal.hpp"

namespace lipsum
{

    ArgVec2::ArgVec2(int min, int max)
    {
        this->min = min;
        this->max = max;
    }

    int ArgVec2::Roll() const
    {
        return internal::RandomNumber<int>(min, max);
    }

} // namespace lipsum
#endif

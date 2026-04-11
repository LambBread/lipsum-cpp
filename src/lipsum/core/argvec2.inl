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
        if (min < 0 || max < 0)
        {
            internal::LogWarn("lpsm::ArgVec2::ArgVec2(): min and max set to (",
                              min,
                              ", ",
                              max,
                              "), expected both >= 0. If "
                              "this is intentional,"
                              "use another method to generate random numbers "
                              "instead.");
        }

        this->min = min;
        this->max = max;
    }

    int ArgVec2::roll() const
    {
        return internal::RandomNumber<int>(min, max);
    }

} // namespace lipsum
#endif

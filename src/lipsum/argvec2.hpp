
/**
 * @file lipsum/argvec2.hpp
 *
 * @brief lipsum::ArgVec2
 *
 * This declares struct ArgVec2. This file is under the BSD Zero Clause License.
 *
 * @copyright Copyright (c) 2025 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once
// #include "core.hpp"
namespace lipsum
{
    /**
     * @brief Store data for inputting into functions.
     *
     * This struct stores values min and max, which
     * are intended to be inputted into functions as arguments.
     * Not exposed in the C wrapper.
     */
    struct LIPSUM_API ArgVec2
    {
        /**
         * @brief Constructor for ArgVec2
         *
         * @param min Value to enter into this->min
         * @param max Value to enter into this->max
         */
        ArgVec2(int min, int max);

        /**
         * @brief Return a number between min and max.
         *
         * This function returns a random value between min and max.
         *
         * @return int The random number.
         */
        int Roll() const;

        int min; ///< The minimum value
        int max; ///< The maximum value
    };
} // namespace lipsum

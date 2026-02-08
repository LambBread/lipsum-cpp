
/**
 * @file lipsum/argvec2.inl
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

lpsm::ArgVec2::ArgVec2(int min, int max)
{
    this->min = min;
    this->max = max;
}

int lpsm::ArgVec2::Roll() const
{
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(min, max);
    return lpsm::internal::RandomNumber(min, max);
}

/**
 * @file lipsum/internal.hpp
 *
 * @brief Declaration of lipsum::internal
 *
 * This declares members in lipsum::internal. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

/**
 * @brief Choose between true or false
 */
#define LPSM_FLIP_COIN lpsm::internal::RandomNumber<bool>(false, true)

namespace lipsum
{
    /**
     * @namespace lipsum::internal
     *
     * @brief This namespace contains functions only used internally by other
     * functions.
     *
     * This namespace's functions are not intended for public use and are
     * not exposed in the C wrapper.
     */
    namespace internal
    {
        LIPSUM_API std::string GenerateTLD();
        LIPSUM_API std::string HandleHTMLEntity(const std::string& str);
        // LIPSUM_API int         RandomNumber(int min, int max);

        template <typename T> T RandomNumber(T min, T max)
        {
            // static thread_local std::random_device rd;
            // std::mt19937                           gen(rd());
            // std::uniform_int_distribution<T>       dist(min, max);
            // return dist(gen);
            static thread_local std::mt19937 gen(std::random_device{}());
            if constexpr (std::is_integral_v<T>)
            {
                std::uniform_int_distribution<T> dist(min, max);
                return dist(gen);
            }
            else
            {
                std::uniform_real_distribution<T> dist(min, max);
                return dist(gen);
            }
        }
        template <> char RandomNumber(char min, char max);
        template <> bool RandomNumber(bool min, bool max);

        template <typename T> std::string ToString(const T& x)
        {
            std::stringstream ss;
            ss << x;
            return ss.str();
        }
    } // namespace internal
} // namespace lipsum

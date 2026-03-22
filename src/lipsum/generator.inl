/**
 * @file lipsum/generator.inl
 *
 * @brief Definition of lipsum::Generator
 *
 * This defines the functions in lipsum::Generator. This file is under the BSD
 * Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once
#include "core/argvec2.hpp"
#include "core_funcs.hpp"
#include "markdown.hpp"

namespace lipsum
{

    std::string Generator::md_paragraph(int num, bool useLipsum)
    {
        return GenerateMarkdownParagraphs(num,
                                          ArgVec2(4, 9),
                                          ArgVec2(1, 3),
                                          ArgVec2(5, 8),
                                          ArgVec2(4, 8),
                                          ArgVec2(1, 2),
                                          ArgVec2(2, 5),
                                          useLipsum,
                                          false);
    }

    std::string Generator::md_text(int numElements)
    {
        return GenerateMarkdownText(ArgVec2(4, 9),
                                    ArgVec2(1, 3),
                                    ArgVec2(5, 8),
                                    ArgVec2(3, 5),
                                    ArgVec2(4, 8),
                                    ArgVec2(1, 2),
                                    ArgVec2(2, 5),
                                    ArgVec2(2, 4),
                                    numElements,
                                    false);
    }
    std::string Generator::word(int num)
    {
        return GenerateWords(num);
    }
    std::string Generator::sentence(int num, bool useLipsum)
    {
        return GenerateSentences(num, ArgVec2(4, 9), ArgVec2(1, 3), useLipsum);
    }
    std::string Generator::sentence_fragment()
    {
        return GenerateSentenceFragment();
    }
    std::string Generator::paragraph(int num, bool useLipsum)
    {
        return GenerateParagraphs(num,
                                  ArgVec2(4, 9),
                                  ArgVec2(1, 3),
                                  ArgVec2(5, 8),
                                  useLipsum);
    }
} // namespace lipsum

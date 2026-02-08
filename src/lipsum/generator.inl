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

std::string lpsm::Generator::md_paragraph(int num, bool useLipsum)
{
    return lpsm::GenerateMarkdownParagraphs(num,
                                            lpsm::ArgVec2(4, 9),
                                            lpsm::ArgVec2(1, 3),
                                            lpsm::ArgVec2(5, 8),
                                            lpsm::ArgVec2(4, 8),
                                            lpsm::ArgVec2(1, 2),
                                            lpsm::ArgVec2(2, 5),
                                            useLipsum,
                                            false);
}

std::string lpsm::Generator::md_text(int numElements)
{
    return lpsm::GenerateMarkdownText(lpsm::ArgVec2(4, 9),
                                      lpsm::ArgVec2(1, 3),
                                      lpsm::ArgVec2(5, 8),
                                      lpsm::ArgVec2(3, 5),
                                      lpsm::ArgVec2(4, 8),
                                      lpsm::ArgVec2(1, 2),
                                      lpsm::ArgVec2(2, 5),
                                      lpsm::ArgVec2(2, 4),
                                      numElements,
                                      false);
}
std::string lpsm::Generator::word(int num)
{
    return lpsm::GenerateWords(num);
}
std::string lpsm::Generator::sentence(int num, bool useLipsum)
{
    return lpsm::GenerateSentences(num,
                                   lpsm::ArgVec2(4, 9),
                                   lpsm::ArgVec2(1, 3),
                                   useLipsum);
}
std::string lpsm::Generator::sentence_fragment()
{
    return lpsm::GenerateSentenceFragment();
}
std::string lpsm::Generator::paragraph(int num, bool useLipsum)
{
    return lpsm::GenerateParagraphs(num,
                                    lpsm::ArgVec2(4, 9),
                                    lpsm::ArgVec2(1, 3),
                                    lpsm::ArgVec2(5, 8),
                                    useLipsum);
}

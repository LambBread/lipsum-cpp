/**
 * @file lipsum/generator.inl
 *
 * @brief lpsm::Generator
 *
 * This defines the functions in lpsm::Generator. This file is under the BSD
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
                                            ArgVec2(4, 9),
                                            ArgVec2(1, 3),
                                            ArgVec2(5, 8),
                                            ArgVec2(4, 8),
                                            ArgVec2(1, 2),
                                            ArgVec2(2, 5),
                                            std::string("https://example.com/"),
                                            useLipsum);
}

std::string lpsm::Generator::md_text(int numElements)
{
    return lpsm::GenerateMarkdownText(ArgVec2(4, 9),
                                      ArgVec2(1, 3),
                                      ArgVec2(5, 8),
                                      ArgVec2(3, 5),
                                      ArgVec2(4, 8),
                                      ArgVec2(1, 2),
                                      ArgVec2(2, 5),
                                      ArgVec2(2, 4),
                                      std::string("https://example.com/"),
                                      numElements);
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

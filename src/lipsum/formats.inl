/**
 * @file lipsum/formats.inl
 *
 * @brief JSON/XML functions of lipsum-cpp
 *
 * This defines functions in lipsum-cpp around generation of XML/JSON documents.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUM_FORMATS_INL
#    define LIPSUM_FORMATS_INL

#    include "core_funcs.hpp"

namespace lipsum
{
    std::string GenerateXMLDocument(int            choices,
                                    const ArgVec2& word,
                                    const ArgVec2& frag,
                                    const Source&  source)
    {
        std::string ret = R"(<?xml version="1.0" encoding="UTF-8"?>)";
        std::vector<std::string> tagStack;
        std::string              root = GenerateWord(source);
        ret += std::string("<") + root + ">";

        int choice;

        for (int i = 0; i < choices; ++i)
        {
            choice = internal::RandomNumber<int>(0, 2);
            switch (choice)
            {
                case 0:
                {
                    std::string toAdd = GenerateWord(source);
                    ret += std::string("<") + toAdd + ">";
                    tagStack.push_back(toAdd);
                    break;
                }

                case 1:
                {
                    std::string toAdd = GenerateWord(source);
                    ret += std::string("<") + toAdd + std::string(">") +
                           GenerateSentence(word, frag, source) +
                           std::string("</") + toAdd + ">";
                    // ret += toAdd += "";
                    break;
                }

                case 2:
                {
                    if (!tagStack.empty())
                    {
                        ret += std::string("</") + tagStack.back() + ">";
                        tagStack.pop_back();
                    }
                    break;
                }

                default:
                {
                    internal::LogWarn(
                            "lpsm::GenerateXMLDocument(): choice chosen "
                            "somehow < 0 or > 2. If you are reading this, "
                            "something went seriously wrong.");
                }
            }
        }

        while (!tagStack.empty())
        {
            ret += std::string("</") + tagStack.back() + ">";
            tagStack.pop_back();
        }

        ret += std::string("</") + root + ">";

        return ret;
    }
} // namespace lipsum

#endif

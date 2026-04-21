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

                default:
                {
                    if (!tagStack.empty())
                    {
                        ret += std::string("</") + tagStack.back() + ">";
                        tagStack.pop_back();
                    }
                    break;
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

    std::string GenerateJSONString(const Source& source)
    {
        return std::string("\"") + GenerateWord(source) + "\"";
    }

    std::string GenerateJSONNumber()
    {
        constexpr int JSON_NUMBER_MIN = -1000;
        constexpr int JSON_NUMBER_MAX = 1000;
        return internal::ToString(
                internal::RandomNumber(JSON_NUMBER_MIN, JSON_NUMBER_MAX));
    }

    std::string GenerateJSONArray(int            depth,
                                  int            maxDepth,
                                  const ArgVec2& jsonLength,
                                  const Source&  source)
    {
        int         count = jsonLength.roll();
        std::string ret   = "[";
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                ret += ",";
            }
            ret += GenerateJSONValue(depth + 1, maxDepth, jsonLength, source);
        }
        ret += "]";
        return ret;
    }

    std::string GenerateJSONObject(int            depth,
                                   int            maxDepth,
                                   const ArgVec2& jsonLength,
                                   const Source&  source)
    {
        int         count = jsonLength.roll();
        std::string ret   = "{";
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                ret += ",";
            }
            std::string key = GenerateJSONString(source);
            ret += key + std::string(":") +
                   GenerateJSONValue(depth + 1, maxDepth, jsonLength, source);
        }
        ret += "}";
        return ret;
    }

    std::string GenerateJSONValue(int            depth,
                                  int            maxDepth,
                                  const ArgVec2& jsonLength,
                                  const Source&  source)
    {
        int choice;
        if (depth > maxDepth)
        {
            choice = internal::RandomNumber(0, 3);
            switch (choice)
            {
                case 0:
                {
                    return GenerateJSONString(source);
                }
                case 1:
                {
                    return GenerateJSONNumber();
                }
                case 2:
                {
                    return LPSM_FLIP_COIN ? "true" : "false";
                }
                default:
                {
                    return "null";
                }
            }
        }

        choice = internal::RandomNumber(0, 5);
        switch (choice)
        {

            case 0:
            {
                return GenerateJSONString(source);
            }
            case 1:
            {
                return GenerateJSONNumber();
            }
            case 2:
            {
                return LPSM_FLIP_COIN ? "true" : "false";
            }
            case 3:
            {
                return "null";
            }
            case 4:
            {
                return GenerateJSONArray(depth, maxDepth, jsonLength, source);
            }
            default:
            {
                return GenerateJSONObject(depth, maxDepth, jsonLength, source);
            }
        }
    }
} // namespace lipsum

#endif

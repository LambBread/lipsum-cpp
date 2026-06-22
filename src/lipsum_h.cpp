/**
 * @file lipsum_h.cpp
 *
 * @brief Contains the definitions of all the C wrapper's functions.
 *
 * This file defines all the functions declared in lipsum.h. This file is under
 * the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#include <cstring>

// angle brackets to stop quom inserting headers here
#include <lipsum.h>
#include <lipsum.hpp>

#define LPSM_CPPIFY(x, type) (reinterpret_cast<type*>((x)))

static char* ConvertToCstr(std::string&& str)
{
    std::string result = std::move(str);
    char*       cstr   = new char[result.size() + 1];
    std::memcpy(cstr, result.c_str(), result.size());
    cstr[result.size()] = '\0';
    // #ifndef _WIN32
    //     strlcpy(cstr, result.c_str(), result.size() + 1);
    // #else
    //     strcpy_s(cstr, result.size() + 1, result.c_str());
    // #endif
    return cstr;
}

#include "lipsumc/binded.inl"

/*
 * MISC
 * ----------------
 */

extern "C" char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return ConvertToCstr(lpsm::GenerateDefaultLipsumSentence());
}

extern "C" int lpsm_CountWords(const char* str)
{
    return lpsm::CountWords(std::string(str));
}

extern "C" int lpsm_CountSentenceFragments(const char* str)
{
    return lpsm::CountSentenceFragments(std::string(str));
}

extern "C" int lpsm_CountSentences(const char* str)
{
    return lpsm::CountSentences(std::string(str));
}

extern "C" int lpsm_CountParagraphs(const char*          str,
                                    lpsm_CountParaMethod format)
{
    return lpsm::CountParagraphs(std::string(str),
                                 static_cast<lpsm::CountParaMethod>(format));
}

extern "C" void lpsm_DeleteString(char* str) // NOLINT
{
    delete[] str;
}

/**
 * @file lipsumc/binded.inl
 *
 * @brief Binded classes of lipsum-cpp C wrapper
 *
 * This defines functions in binded classes in the C wrapper.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUMC_BINDED_INL
#    define LIPSUMC_BINDED_INL

/*
 * BINDED
 * ----------------
 */

extern "C" lpsm_GeneratorHandle lpsm_Generator(const char* path)
{
    return (reinterpret_cast<lpsm_GeneratorHandle>(new lpsm::Generator(path)));
}

extern "C" void lpsm_GeneratorDestroy(lpsm_GeneratorHandle handle)
{
    auto* realSource = LPSM_CPPIFY(handle, lpsm::Generator);
    delete realSource;
}

extern "C" void lpsm_Generator_load_source(lpsm_GeneratorHandle handle,
                                           const char*          path)
{
    LPSM_CPPIFY(handle, lpsm::Generator)->load_source(path);
}

extern "C" void lpsm_Generator_change_setting(lpsm_GeneratorHandle handle,
                                              const char*          setting,
                                              int                  minValue,
                                              int                  maxValue)
{
    LPSM_CPPIFY(handle, lpsm::Generator)
            ->change_setting(setting, minValue, maxValue);
}

extern "C" char* lpsm_Generator_word(lpsm_GeneratorHandle handle, int num)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->word(num);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_fragment(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->fragment();
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_sentence(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->sentence(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_paragraph(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->paragraph(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_text(lpsm_GeneratorHandle handle,
                                     bool                 useLipsum)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->text(useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_scramble(lpsm_GeneratorHandle handle,
                                         int                  length,
                                         char                 minChar,
                                         char                 maxChar)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)
                       ->scramble(length, minChar, maxChar);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_url(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->url();
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_plain_url(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->plain_url();
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_slug(lpsm_GeneratorHandle handle,
                                     char                 separator)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->slug(separator);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_paragraph(lpsm_GeneratorHandle handle,
                                             int                  num,
                                             bool                 useLipsum,
                                             bool                 useHtml)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)
                       ->md_paragraph(num, useLipsum, useHtml);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_text(lpsm_GeneratorHandle handle,
                                        int                  numElements,
                                        bool                 useHtml)
{
    auto ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->md_text(numElements, useHtml);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_md_header(lpsm_GeneratorHandle handle, int level, bool useHtml)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->md_header(level, useHtml);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_emphasis(lpsm_GeneratorHandle handle,
                                            bool                 isBold,
                                            bool                 useHtml)
{
    auto ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->md_emphasis(isBold, useHtml);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_link(lpsm_GeneratorHandle handle,
                                        bool                 useHtml)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->md_link(useHtml);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_md_list(lpsm_GeneratorHandle handle, bool ordered, bool useHtml)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->md_list(ordered, useHtml);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_xml(lpsm_GeneratorHandle handle, int choices)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)->xml(choices);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_json(lpsm_GeneratorHandle handle,
                                     int                  depth,
                                     int                  maxDepth,
                                     bool                 isObject)
{
    auto ret = LPSM_CPPIFY(handle, lpsm::Generator)
                       ->json(depth, maxDepth, isObject);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_json_value(lpsm_GeneratorHandle handle, int depth, int maxDepth)
{
    auto ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->json_value(depth, maxDepth);
    return ConvertToCstr(ret);
}

#endif

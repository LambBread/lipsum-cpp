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

extern "C" lpsm_SourceHandle lpsm_Source(const char* path)
{
    lpsm_SourceHandle ret;
    ret = reinterpret_cast<lpsm_SourceHandle>(new lpsm::Source(path));
    return ret;
}

extern "C" void lpsm_SourceDestroy(lpsm_SourceHandle handle)
{
    auto* realSource = reinterpret_cast<lpsm::Source*>(handle);
    delete realSource;
}

extern "C" lpsm_ArgVec2Handle lpsm_ArgVec2(int min, int max)
{
    return reinterpret_cast<lpsm_ArgVec2Handle>(new lpsm::ArgVec2(min, max));
}

extern "C" void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle av2)
{
    auto* realAv2 = reinterpret_cast<lpsm::ArgVec2*>(av2);
    delete realAv2;
}

extern "C" int lpsm_ArgVec2_roll(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->roll();
}

extern "C" int lpsm_ArgVec2_min(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->min;
}

extern "C" int lpsm_ArgVec2_max(lpsm_ArgVec2Handle av2)
{
    return (reinterpret_cast<lpsm::ArgVec2*>(av2))->max;
}

extern "C" lpsm_GeneratorHandle lpsm_Generator(const char* path)
{
    return (reinterpret_cast<lpsm_GeneratorHandle>(new lpsm::Generator(path)));
}

extern "C" void lpsm_GeneratorDestroy(lpsm_GeneratorHandle handle)
{
    auto* realSource = LPSM_GEN_CPPIFY(handle);
    delete realSource;
}

extern "C" void lpsm_Generator_change_setting(lpsm_GeneratorHandle handle,
                                              const char*          setting,
                                              int                  minValue,
                                              int                  maxValue)
{
    LPSM_GEN_CPPIFY(handle)->change_setting(setting, minValue, maxValue);
}

extern "C" char* lpsm_Generator_word(lpsm_GeneratorHandle handle, int num)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->word(num);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_sentence_fragment(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->sentence_fragment();
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_sentence(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->sentence(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_paragraph(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->paragraph(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_text(lpsm_GeneratorHandle handle,
                                     bool                 useLipsum)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->text(useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_scramble(lpsm_GeneratorHandle handle,
                                         int                  length,
                                         char                 minChar,
                                         char                 maxChar)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->scramble(length, minChar, maxChar);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_url(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->url();
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_plain_url(lpsm_GeneratorHandle handle)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->plain_url();
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_slug(lpsm_GeneratorHandle handle,
                                     char                 separator)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->slug(separator);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_paragraph(lpsm_GeneratorHandle handle,
                                             int                  num,
                                             bool                 useLipsum)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->md_paragraph(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_md_text(lpsm_GeneratorHandle handle,
                                        int                  numElements)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->md_text(numElements);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_html_paragraph(lpsm_GeneratorHandle handle,
                                               int                  num,
                                               bool                 useLipsum)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->html_paragraph(num, useLipsum);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_html_text(lpsm_GeneratorHandle handle,
                                          int                  numElements)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->html_text(numElements);
    return ConvertToCstr(ret);
}

extern "C" char* lpsm_Generator_xml(lpsm_GeneratorHandle handle, int choices)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->xml(choices);
    return ConvertToCstr(ret);
}

extern "C" char*
lpsm_Generator_json(lpsm_GeneratorHandle handle, int maxDepth, bool isObject)
{
    auto ret = LPSM_GEN_CPPIFY(handle)->json(maxDepth, isObject);
    return ConvertToCstr(ret);
}

#endif

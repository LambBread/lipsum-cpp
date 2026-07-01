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

/*
 * BINDED
 * ----------------
 */

extern "C" lpsm_GeneratorHandle lpsm_Generator(const char* path)
{
    auto* gen = new lpsm::Generator(path, 0);
    gen->load_seed(std::random_device{}());
    return (reinterpret_cast<lpsm_GeneratorHandle>(gen));
}

extern "C" lpsm_GeneratorHandle lpsm_GeneratorSeeded(const char* path, int seed)
{
    auto* gen = new lpsm::Generator(path, seed);
    return reinterpret_cast<lpsm_GeneratorHandle>(gen);
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

extern "C" void lpsm_Generator_load_seed(lpsm_GeneratorHandle handle, int seed)
{
    LPSM_CPPIFY(handle, lpsm::Generator)->load_seed(seed);
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
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->word(num);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_fragment(lpsm_GeneratorHandle handle)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->fragment();
    return ConvertToCstr(std::move(ret));
}

extern "C" char*
lpsm_Generator_sentence(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->sentence(num, useLipsum);
    return ConvertToCstr(std::move(ret));
}

extern "C" char*
lpsm_Generator_paragraph(lpsm_GeneratorHandle handle, int num, bool useLipsum)
{
    auto&& ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->paragraph(num, useLipsum);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_text(lpsm_GeneratorHandle handle,
                                     bool                 useLipsum)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->text(useLipsum);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_scramble(lpsm_GeneratorHandle handle,
                                         int                  length,
                                         char                 minChar,
                                         char                 maxChar)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)
                         ->scramble(length, minChar, maxChar);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_url(lpsm_GeneratorHandle handle)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->url();
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_plain_url(lpsm_GeneratorHandle handle)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->plain_url();
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_email(lpsm_GeneratorHandle handle)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->email();
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_slug(lpsm_GeneratorHandle handle,
                                     char                 separator)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->slug(separator);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_case_slug(lpsm_GeneratorHandle handle,
                                          lpsm_CaseSlugCase    case_)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)
                         ->case_slug(static_cast<lpsm::CaseSlugCase>(case_));
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_code(lpsm_GeneratorHandle handle,
                                     lpsm_CodeLanguage    lang)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)
                         ->code(static_cast<lpsm::CodeLanguage>(lang));
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_fmt_paragraph(lpsm_GeneratorHandle handle,
                                              int                  num,
                                              bool                 useLipsum,
                                              bool                 useHtml)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)
                         ->fmt_paragraph(num, useLipsum, useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_fmt_text(lpsm_GeneratorHandle handle,
                                         int                  numElements,
                                         bool                 useHtml)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)
                         ->fmt_text(numElements, useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char*
lpsm_Generator_fmt_header(lpsm_GeneratorHandle handle, int level, bool useHtml)
{
    auto&& ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->fmt_header(level, useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_fmt_emphasis(lpsm_GeneratorHandle handle,
                                             bool                 isBold,
                                             bool                 useHtml)
{
    auto&& ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->fmt_emphasis(isBold, useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_fmt_link(lpsm_GeneratorHandle handle,
                                         bool                 useHtml)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->fmt_link(useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char*
lpsm_Generator_fmt_list(lpsm_GeneratorHandle handle, bool ordered, bool useHtml)
{
    auto&& ret =
            LPSM_CPPIFY(handle, lpsm::Generator)->fmt_list(ordered, useHtml);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_xml(lpsm_GeneratorHandle handle, int choices)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->xml(choices);
    return ConvertToCstr(std::move(ret));
}

extern "C" char*
lpsm_Generator_json(lpsm_GeneratorHandle handle, int maxDepth, bool isObject)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->json(maxDepth, isObject);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_json_value(lpsm_GeneratorHandle handle,
                                           int                  maxDepth)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->json_value(maxDepth);
    return ConvertToCstr(std::move(ret));
}

extern "C" char* lpsm_Generator_csv(lpsm_GeneratorHandle handle)
{
    auto&& ret = LPSM_CPPIFY(handle, lpsm::Generator)->csv();
    return ConvertToCstr(std::move(ret));
}

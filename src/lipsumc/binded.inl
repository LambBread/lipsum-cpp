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
    if (strcmp(path, "default") == 0)
    {
        ret = reinterpret_cast<lpsm_SourceHandle>(new lpsm::Source);
    }
    else
    {
        ret = reinterpret_cast<lpsm_SourceHandle>(new lpsm::Source(path));
    }
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

extern "C" char* lpsm_gen_word(int num)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.word(num));
}

extern "C" char* lpsm_gen_sentence(int num, bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.sentence(num, useLipsum));
}

extern "C" char* lpsm_gen_sentence_fragment(void)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.sentence_fragment());
}

extern "C" char* lpsm_gen_paragraph(int num, bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.paragraph(num, useLipsum));
}

extern "C" char* lpsm_gen_md_paragraph(int num, bool useLipsum)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.md_paragraph(num, useLipsum));
}

extern "C" char* lpsm_gen_md_text(int numElements)
{
    lpsm::Generator gen;
    return ConvertToCstr(gen.md_text(numElements));
}
#endif

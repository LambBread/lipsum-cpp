/**
 * @file jsbind/lipsum_binding_js.cpp
 *
 * @brief JS binding over lipsum-cpp
 *
 * This contains a JS binding over lipsum-cpp. It requires to be built with
 * Emscripten. This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 *
 * @example JSBinding.html
 */

#ifdef __EMSCRIPTEN__
#    include <emscripten/bind.h>
#else
#    error Must build JS wrapper with Emscripten
#endif

#include <string>
#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include "lipsum.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(lipsumcpp)
{
    class_<lpsm::ArgVec2>("lpsm_ArgVec2")
            .constructor<int, int>()
            .function("Roll", &lpsm::ArgVec2::Roll)
            .property("min", &lpsm::ArgVec2::min)
            .property("max", &lpsm::ArgVec2::max);
    class_<lpsm::Generator>("lpsm_Generator")
            .constructor<>()
            .function("word", &lpsm::Generator::word)
            .function("sentence", &lpsm::Generator::sentence)
            .function("sentence_fragment", &lpsm::Generator::sentence_fragment)
            .function("paragraph", &lpsm::Generator::paragraph)
            .function("md_paragraph", &lpsm::Generator::md_paragraph)
            .function("md_text", &lpsm::Generator::md_text);
    function("lpsm_GenerateWord", &lpsm::GenerateWord);
    function("lpsm_GenerateSentence", &lpsm::GenerateSentence);
    function("lpsm_GenerateSentenceFragment", &lpsm::GenerateSentenceFragment);
    function("lpsm_GenerateParagraph", &lpsm::GenerateParagraph);
    function("lpsm_GenerateWords", &lpsm::GenerateWords);
    function("lpsm_GenerateSentences", &lpsm::GenerateSentences);
    function("lpsm_GenerateParagraphs", &lpsm::GenerateParagraphs);
    function("lpsm_GenerateDefaultLipsumSentence",
             &lpsm::GenerateDefaultLipsumSentence);
    function("lpsm_GenerateMarkdownHeader", &lpsm::GenerateMarkdownHeader);
    function("lpsm_GenerateMarkdownEmphasis", &lpsm::GenerateMarkdownEmphasis);
    function("lpsm_GenerateMarkdownLink", &lpsm::GenerateMarkdownLink);
    function("lpsm_GenerateMarkdownList", &lpsm::GenerateMarkdownList);
    function("lpsm_GenerateMarkdownParagraph",
             &lpsm::GenerateMarkdownParagraph);
    function("lpsm_GenerateMarkdownText", &lpsm::GenerateMarkdownText);
    function("lpsm_GenerateSentenceFragmentX",
             &lpsm::GenerateSentenceFragmentX);
    function("lpsm_GenerateSentenceX", &lpsm::GenerateSentenceX);
    function("lpsm_GenerateParagraphX", &lpsm::GenerateParagraphX);
    function("lpsm_GenerateParagraphsX", &lpsm::GenerateParagraphsX);
    function("lpsm_GenerateSentencesX", &lpsm::GenerateSentencesX);
    function("lpsm_CountSentences", &lpsm::CountSentences);
    function("lpsm_LipsumVersion", &lpsm::LipsumVersion);
    function("lpsm_GenerateText", &lpsm::GenerateText);
    function("lpsm_GenerateTextX", &lpsm::GenerateTextX);
    function("lpsm_GenerateMarkdownParagraphs",
             &lpsm::GenerateMarkdownParagraphs);
}

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

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include "lipsum.hpp"
// std::string LIP_VERSION = std::string(LIPSUM_CPP_VERSION);

using namespace emscripten;

EMSCRIPTEN_BINDINGS(lipsumcpp)
{
    class_<lpsm::ArgVec2>("lpsm_ArgVec2")
            .constructor<int, int>()
            .function("roll", &lpsm::ArgVec2::roll)
            .property("min", &lpsm::ArgVec2::min)
            .property("max", &lpsm::ArgVec2::max);
    class_<lpsm::Generator>("lpsm_Generator")
            .constructor<>()
            .constructor<std::string>()
            .function("word", &lpsm::Generator::word)
            .function("sentence", &lpsm::Generator::sentence)
            .function("sentence_fragment", &lpsm::Generator::sentence_fragment)
            .function("paragraph", &lpsm::Generator::paragraph)
            .function("md_paragraph", &lpsm::Generator::md_paragraph)
            .function("md_text", &lpsm::Generator::md_text)
            .function("html_paragraph", &lpsm::Generator::html_paragraph)
            .function("html_text", &lpsm::Generator::html_text)
            .function("xml", &lpsm::Generator::xml)
            .function("json", &lpsm::Generator::json);
    class_<lpsm::Source>("lpsm_Source")
            .constructor<>()
            .constructor<std::string>()
            .function("random_word", &lpsm::Source::random_word)
            .function("load", &lpsm::Source::load);
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
    constant("LIPSUM_CPP_VERSION", std::string(LIPSUM_CPP_VERSION));
    constant("LIPSUM_CPP_VERSION_MAJOR", LIPSUM_CPP_VERSION_MAJOR);
    constant("LIPSUM_CPP_VERSION_MINOR", LIPSUM_CPP_VERSION_MINOR);
    constant("LIPSUM_CPP_VERSION_PATCH", LIPSUM_CPP_VERSION_PATCH);
    function("lpsm_GenerateText", &lpsm::GenerateText);
    function("lpsm_GenerateTextX", &lpsm::GenerateTextX);
    function("lpsm_GenerateMarkdownParagraphs",
             &lpsm::GenerateMarkdownParagraphs);
    function("lpsm_GenerateMarkdownHeaderX", &lpsm::GenerateMarkdownHeaderX);
    function("lpsm_GenerateMarkdownEmphasisX",
             &lpsm::GenerateMarkdownEmphasisX);
    function("lpsm_GenerateMarkdownLinkX", &lpsm::GenerateMarkdownLinkX);
    function("lpsm_GenerateMarkdownListX", &lpsm::GenerateMarkdownListX);
    function("lpsm_GenerateSlug", &lpsm::GenerateSlug);
    function("lpsm_GenerateSlugX", &lpsm::GenerateSlugX);
    function("lpsm_GenerateURL", &lpsm::GenerateURL);
    function("lpsm_GenerateURLX", &lpsm::GenerateURLX);
    function("lpsm_CountWords", &lpsm::CountWords);
    function("lpsm_GeneratePlainURL", &lpsm::GeneratePlainURL);
    function("lpsm_GenerateScramble", &lpsm::GenerateScramble);
    function("lpsm_GenerateXMLDocument", &lpsm::GenerateXMLDocument);
    function("lpsm_GenerateXMLDocumentX", &lpsm::GenerateXMLDocumentX);
    function("lpsm_GenerateJSONString", &lpsm::GenerateJSONString);
    function("lpsm_GenerateJSONNumber", &lpsm::GenerateJSONNumber);
    function("lpsm_GenerateJSONObject", &lpsm::GenerateJSONObject);
    function("lpsm_GenerateJSONObjectX", &lpsm::GenerateJSONObjectX);
    function("lpsm_GenerateJSONArray", &lpsm::GenerateJSONArray);
    function("lpsm_GenerateJSONArrayX", &lpsm::GenerateJSONArrayX);
    function("lpsm_GenerateJSONValue", &lpsm::GenerateJSONValue);
    function("lpsm_GenerateJSONValueX", &lpsm::GenerateJSONValueX);
}

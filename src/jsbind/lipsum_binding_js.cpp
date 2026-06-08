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
 * @example WebInterface.js
 * @example FontViewer.html
 */

#ifdef __EMSCRIPTEN__
#    include <emscripten/bind.h>
#else
#    error Must build JS wrapper with Emscripten
#endif

#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif
#include <lipsum.hpp>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(lipsumcpp)
{
    class_<lpsm::Generator>("lpsm_Generator")
            .constructor<>()
            .constructor<std::string>()
            .constructor<std::string, int>()
            .function("load_source", &lpsm::Generator::load_source)
            .function("load_seed", &lpsm::Generator::load_seed)
            .function("change_setting",
                      select_overload<void(const std::string&, int, int)>(
                              &lpsm::Generator::change_setting))
            .function("word", &lpsm::Generator::word)
            .function("sentence", &lpsm::Generator::sentence)
            .function("fragment", &lpsm::Generator::fragment)
            .function("paragraph", &lpsm::Generator::paragraph)
            .function("text", &lpsm::Generator::text)
            .function("scramble", &lpsm::Generator::scramble)
            .function("plain_url", &lpsm::Generator::plain_url)
            .function("email", &lpsm::Generator::email)
            .function("url", &lpsm::Generator::url)
            .function("slug", &lpsm::Generator::slug)
            .function("md_paragraph", &lpsm::Generator::md_paragraph)
            .function("md_text", &lpsm::Generator::md_text)
            .function("md_header", &lpsm::Generator::md_header)
            .function("md_emphasis", &lpsm::Generator::md_emphasis)
            .function("md_link", &lpsm::Generator::md_link)
            .function("md_list", &lpsm::Generator::md_list)
            .function("xml", &lpsm::Generator::xml)
            .function("json", &lpsm::Generator::json)
            .function("json_value", &lpsm::Generator::json_value);
    enum_<lpsm::GeneratorFlags>("lpsm_GeneratorFlags")
            .value("USELIPSUM", lpsm::USELIPSUM)
            .value("NO_USELIPSUM", lpsm::NO_USELIPSUM)
            .value("HTML", lpsm::HTML)
            .value("MARKDOWN", lpsm::MARKDOWN)
            .value("OBJECT", lpsm::OBJECT)
            .value("ARRAY", lpsm::ARRAY)
            .value("BOLD", lpsm::BOLD)
            .value("ITALIC", lpsm::ITALIC)
            .value("ORDERED", lpsm::ORDERED)
            .value("UNORDERED", lpsm::UNORDERED);
    enum_<lpsm::CountParaMethod>("lpsm_CountParaMethod")
            .value("Plain", lpsm::CountParaMethod::Plain)
            .value("Markdown", lpsm::CountParaMethod::Markdown)
            .value("HTML", lpsm::CountParaMethod::HTML);

    constant("LIPSUM_CPP_VERSION", std::string(LIPSUM_CPP_VERSION));
    constant("LIPSUM_CPP_VERSION_MAJOR", LIPSUM_CPP_VERSION_MAJOR);
    constant("LIPSUM_CPP_VERSION_MINOR", LIPSUM_CPP_VERSION_MINOR);
    constant("LIPSUM_CPP_VERSION_PATCH", LIPSUM_CPP_VERSION_PATCH);
    constant("LIPSUM_CPP_VERSION_COMMIT",
             std::string(LIPSUM_CPP_VERSION_COMMIT));
    constant("LIPSUM_CPP_VERSION_FULL", std::string(LIPSUM_CPP_VERSION_FULL));
    constant("LIPSUM_CPP_VERSION_TIME", std::string(LIPSUM_CPP_VERSION_TIME));
    constant("LIPSUM_CPP_VERSION_DATE", std::string(LIPSUM_CPP_VERSION_DATE));
    constant("LIPSUM_CPP_VERSION_ISDEV", LIPSUM_CPP_VERSION_ISDEV);
    function("lpsm_GenerateDefaultLipsumSentence",
             &lpsm::GenerateDefaultLipsumSentence);
    function("lpsm_CountWords", &lpsm::CountWords);
    function("lpsm_CountSentenceFragments", &lpsm::CountSentenceFragments);
    function("lpsm_CountSentences", &lpsm::CountSentences);
    function("lpsm_CountParagraphs", &lpsm::CountParagraphs);
}

/**
 * @file lipsumc/binded.h
 *
 * @brief Binded classes of lipsum-cpp C wrapper
 *
 * This declares binded classes as typedefs and their functions.
 * This file is under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */
#pragma once

#ifndef LIPSUMC_BINDED_H
#    define LIPSUMC_BINDED_H

// NOLINTBEGIN
#    define LPSM_USELIPSUM true
#    define LPSM_NO_USELIPSUM false
#    define LPSM_HTML true
#    define LPSM_MARKDOWN false
#    define LPSM_OBJECT true
#    define LPSM_ARRAY false
#    define LPSM_BOLD true
#    define LPSM_ITALIC false
#    define LPSM_ORDERED true
#    define LPSM_UNORDERED false
#    define LPSM_IPV4 false
#    define LPSM_IPV6 true
#    define LPSM_NOPORT false
#    define LPSM_PORT true
// NOLINTEND

#    include "core.h"

// NOLINTBEGIN(modernize-use-using)

/**
 * @brief A handle to a lipsum::Generator
 *
 * @since 0.4.4
 *
 * This is a typedef of a pointer to a lipsum::Generator.
 */
typedef void* lpsm_GeneratorHandle;

/**
 * @brief Cases used by lpsm_Generator_case_slug()
 *
 * @since 0.5.1
 *
 * Types of cases used by lpsm_Generator_case_slug(). Includes various types
 * such as camel case, snake case, etc.
 */
typedef enum lpsm_CaseSlugCase
{
    LPSM_CSC_CAMEL_CASE = 0,
    LPSM_CSC_PASCAL_CASE,
    LPSM_CSC_SNAKE_CASE,
    LPSM_CSC_SHOUTY_CASE,
    LPSM_CSC_KEBAB_CASE,
    LPSM_CSC_TRAIN_CASE
} lpsm_CaseSlugCase;

/**
 * @brief Languages used by lpsm_Generator_code()
 *
 * @since 0.5.1
 *
 * Programming languages that lpsm_Generator_code() can generate, such as C++
 * and Python.
 */
typedef enum lpsm_CodeLanguage
{
    LPSM_CODEL_CPP = 0,
    LPSM_CODEL_PYTHON,
    LPSM_CODEL_RUST,
    LPSM_CODEL_C,
    LPSM_CODEL_JAVASCRIPT
} lpsm_CodeLanguage;

// NOLINTEND(modernize-use-using)

#    ifdef __cplusplus
extern "C"
{
#    endif

    /**
     * @brief Create a lipsum::Generator
     *
     * @since 0.4.4
     *
     * This function creates a pointer pointing to a lipsum::Generator.
     *
     * @note The lpsm_GeneratorHandle should be manually deleted with
     * lpsm_GeneratorDestroy().
     *
     * @param path The filepath or name of the lorem ipsum source.
     *
     * @return lpsm_GeneratorHandle The lipsum::Generator.
     *
     * @sa lipsum::Source::load
     */
    LIPSUMC_API lpsm_GeneratorHandle lpsm_Generator(const char* path);

    /**
     * @brief Create a lipsum::Generator
     *
     * @since 0.5.0
     *
     * This function creates a pointer pointing to a lipsum::Generator.
     *
     * @note The lpsm_GeneratorHandle should be manually deleted with
     * lpsm_GeneratorDestroy().
     *
     * @param path The filepath or name of the lorem ipsum source.
     * @param seed The seed specified.
     *
     * @return lpsm_GeneratorHandle The lipsum::Generator.
     *
     * @sa lipsum::Source::load
     */
    LIPSUMC_API lpsm_GeneratorHandle lpsm_GeneratorSeeded(const char* path,
                                                          int         seed);

    /**
     * @brief Delete a lipsum::Generator
     *
     * @since 0.4.4
     *
     * This function deletes a lpsm_GeneratorHandle allocated with
     * lpsm_Generator().
     *
     * @warning Do not call lpsm_GeneratorDestroy on the same handle twice or
     * use the handle after deleting it, as that would be a double-free or
     * use-after-free and would potentially crash the program.
     *
     * @param handle The lpsm_GeneratorHandle to delete.
     */
    LIPSUMC_API void lpsm_GeneratorDestroy(lpsm_GeneratorHandle handle);

    /**
     * @brief Reload a source
     *
     * @since 0.4.5
     *
     * Reload the specified lorem ipsum source into m_Source. If path is
     * invalid, it will print a warning and default to the standard
     * lorem-ipsum source.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param path The filepath or name of the lorem ipsum source.
     *
     * @sa lipsum::Source::load
     */
    LIPSUMC_API void lpsm_Generator_load_source(lpsm_GeneratorHandle handle,
                                                const char*          path);
    /**
     * @brief Reload a seed
     *
     * @since 0.5.0
     *
     * Reload the seed of m_Gen.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param seed The seed specified.
     */
    LIPSUMC_API void lpsm_Generator_load_seed(lpsm_GeneratorHandle handle,
                                              int                  seed);

    /**
     * @brief Change a setting
     *
     * @since 0.4.5
     *
     * Change a setting for generation. Valid setting names include "word",
     * "frag", "sent", "para", "point", "wordFmt", "fragFmt", "wordURL",
     * "level", and "jsonLength". If an invalid setting name is used, raise
     * a warning and ignore.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param setting The name of the setting.
     * @param minValue The new minimum value of the setting.
     * @param maxValue The new maximum value of the setting.
     */
    LIPSUMC_API void lpsm_Generator_change_setting(lpsm_GeneratorHandle handle,
                                                   const char*          setting,
                                                   int minValue,
                                                   int maxValue);
    /**
     * @brief Generate words.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::word() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param num The number of words.
     *
     * @return char* The random word.
     */
    LIPSUMC_API char* lpsm_Generator_word(lpsm_GeneratorHandle handle, int num);

    /**
     * @brief Generate a sentence fragment.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::fragment() on the specified handle. Formerly
     * lpsm_Generator_sentence_fragment().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The random sentence fragment.
     */
    LIPSUMC_API char* lpsm_Generator_fragment(lpsm_GeneratorHandle handle);

    /**
     * @brief Generate sentences.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::sentence() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param num The number of sentences.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * sentence(s).
     *
     * @return char* The random sentence(s).
     */
    LIPSUMC_API char* lpsm_Generator_sentence(lpsm_GeneratorHandle handle,
                                              int                  num,
                                              bool                 useLipsum);

    /**
     * @brief Generate paragraphs.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::paragraph() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * paragraph(s).
     *
     * @return char* The random paragraph(s).
     */
    LIPSUMC_API char* lpsm_Generator_paragraph(lpsm_GeneratorHandle handle,
                                               int                  num,
                                               bool                 useLipsum);

    /**
     * @brief Generate a random number of random paragraphs.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::text() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * paragraph(s).
     *
     * @return char* The random text.
     */
    LIPSUMC_API char* lpsm_Generator_text(lpsm_GeneratorHandle handle,
                                          bool                 useLipsum);

    /**
     * @brief Generate a random character scramble.
     *
     * @since 0.4.5
     *
     * Call lipsum::Generator::scramble() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param length The number of characters.
     * @param minChar The lowest-valued ASCII character that can appear.
     * @param maxChar The highest-valued ASCII character than can appear.
     *
     * @return char* The character scramble.
     */
    LIPSUMC_API char* lpsm_Generator_scramble(lpsm_GeneratorHandle handle,
                                              int                  length,
                                              char                 minChar,
                                              char                 maxChar);

    /**
     * @brief Generate a URL.
     *
     * @since 0.4.5
     *
     * Call lipsum::Generator::url() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The URL.
     */
    LIPSUMC_API char* lpsm_Generator_url(lpsm_GeneratorHandle handle);

    /**
     * @brief Generate a plain URL.
     *
     * @since 0.4.5
     *
     * Call lipsum::Generator::plain_url() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The plain URL.
     */
    LIPSUMC_API char* lpsm_Generator_plain_url(lpsm_GeneratorHandle handle);

    /**
     * @brief Generate an email.
     *
     * @since 0.5.1
     *
     * Call lipsum::Generator::email() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The email.
     */
    LIPSUMC_API char* lpsm_Generator_email(lpsm_GeneratorHandle handle);

    /**
     * @brief Generate a slug.
     *
     * @since 0.4.5
     *
     * Call lipsum::Generator::slug() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param separator The separator character.
     *
     * @return char* The slug.
     */
    LIPSUMC_API char* lpsm_Generator_slug(lpsm_GeneratorHandle handle,
                                          char                 separator);

    /**
     * @brief Generate a case slug.
     *
     * @since 0.5.1
     *
     * Call lipsum::Generator::case_slug() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param case_ The case.
     *
     * @return char* The case slug.
     */
    LIPSUMC_API char* lpsm_Generator_case_slug(lpsm_GeneratorHandle handle,
                                               lpsm_CaseSlugCase    case_);

    /**
     * @brief Generate a code block.
     *
     * @since 0.5.1
     *
     * Call lipsum::Generator::code() on the specified handle.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param lang The language chosen.
     *
     * @return char* The code block.
     */
    LIPSUMC_API char* lpsm_Generator_code(lpsm_GeneratorHandle handle,
                                          lpsm_CodeLanguage    lang);

    /**
     * @brief Generate an IP address.
     *
     * @since 0.5.3
     *
     * Call lipsum::Generator::ip_addr() on the specified handle.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param useIpv6 Whether to use IPv6.
     * @param usePort Whether to add a port.
     *
     * @return char* The IP address.
     */
    LIPSUMC_API char* lpsm_Generator_ip_addr(lpsm_GeneratorHandle handle,
                                             bool                 useIpv6,
                                             bool                 usePort);

    /**
     * @brief Generate a phone number.
     *
     * @since 0.5.3
     *
     * Call lipsum::Generator::phone_number() on the specified handle.
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The phone number.
     */
    LIPSUMC_API char* lpsm_Generator_phone_number(lpsm_GeneratorHandle handle);

    /**
     * @brief Generate Markdown or HTML paragraphs.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::fmt_paragraph() on the specified handle.
     * Formerly known
     * as lpsm_Generator_md_paragraph().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown paragraph.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_paragraph(lpsm_GeneratorHandle handle,
                                                   int                  num,
                                                   bool useLipsum,
                                                   bool useHtml);

    /**
     * @brief Generate a Markdown or HTML document.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::fmt_text() on the specified handle.
     * Formerly known as
     * lpsm_Generator_md_text().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param numElements The number of elements (paragraph, list, heading)
     * in the document.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown document.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_text(lpsm_GeneratorHandle handle,
                                              int                  numElements,
                                              bool                 useHtml);
    /**
     * @brief Generate a Markdown or HTML header.
     *
     * @since 0.4.6
     *
     * Call lipsum::Generator::fmt_header() on the specified handle.
     * Formerly known as
     * lpsm_Generator_md_header().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param level The level of the heading.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown header.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_header(lpsm_GeneratorHandle handle,
                                                int                  level,
                                                bool                 useHtml);

    /**
     * @brief Generate an emphasized Markdown or HTML sentence.
     *
     * @since 0.4.6
     *
     * Call lipsum::Generator::fmt_emphasis() on the specified handle.
     * Formerly known as lpsm_Generator_md_emphasis().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param isBold Whether the sentence is bold or italic.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random emphasized Markdown sentence.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_emphasis(lpsm_GeneratorHandle handle,
                                                  bool                 isBold,
                                                  bool                 useHtml);

    /**
     * @brief Generate a Markdown or HTML link.
     *
     * @since 0.4.6
     *
     * Call lipsum::Generator::fmt_link() on the specified handle.
     * Formerly known as
     * lpsm_Generator_md_link().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown link.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_link(lpsm_GeneratorHandle handle,
                                              bool                 useHtml);

    /**
     * @brief Generate a Markdown or HTML list.
     *
     * @since 0.4.6
     *
     * Call lipsum::Generator::fmt_list() on the specified handle.
     * Formerly known as lpsm_Generator_md_list().
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param ordered Whether the list is ordered.
     * @param useHtml Whether HTML should be outputted instead of Markdown.
     *
     * @return char* The random Markdown list.
     */
    LIPSUMC_API char* lpsm_Generator_fmt_list(lpsm_GeneratorHandle handle,
                                              bool                 ordered,
                                              bool                 useHtml);

    /**
     * @brief Generate an XML document.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::xml() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param choices The number of choices (start element, end element, add
     * data element) that are made.
     *
     * @return char* The random XML document.
     */
    LIPSUMC_API char* lpsm_Generator_xml(lpsm_GeneratorHandle handle,
                                         int                  choices);

    /**
     * @brief Generate a JSON object or array.
     *
     * @since 0.4.4
     *
     * Call lipsum::Generator::json() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param maxDepth Maximum depth of recursion.
     * @param isObject Whether to output an object (true) or an array
     * (false).
     *
     * @return char* The random JSON object or array.
     */
    LIPSUMC_API char* lpsm_Generator_json(lpsm_GeneratorHandle handle,
                                          int                  maxDepth,
                                          bool                 isObject);

    /**
     * @brief Generate a JSON value.
     *
     * @since 0.5.0
     *
     * Call lipsum::Generator::json_value() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     * @param maxDepth The maximum level of recursion.
     *
     * @return char* The random JSON value.
     */
    LIPSUMC_API char* lpsm_Generator_json_value(lpsm_GeneratorHandle handle,
                                                int                  maxDepth);

    /**
     * @brief Generate a CSV document.
     *
     * @since 0.5.2
     *
     * Call lipsum::Generator::csv() on the specified handle.
     *
     * @cstrnote
     *
     * @param handle The lpsm_GeneratorHandle to use.
     *
     * @return char* The CSV document.
     */
    LIPSUMC_API char* lpsm_Generator_csv(lpsm_GeneratorHandle handle);

#    ifdef __cplusplus
}
#    endif

#endif

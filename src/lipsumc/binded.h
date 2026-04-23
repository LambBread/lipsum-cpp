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

#    include "core.h"

// NOLINTBEGIN(modernize-use-using)

/**
 * @brief A handle to a lipsum::ArgVec2
 *
 * @since 0.3.3
 *
 * This is a typedef of a pointer to a lipsum::ArgVec2.
 */
typedef void* lpsm_ArgVec2Handle;

/**
 * @brief A handle to a lipsum::Source
 *
 * @since 0.4.0
 *
 * This is a typedef of a pointer to a lipsum::ArgVec2.
 */
typedef void* lpsm_SourceHandle;

// NOLINTEND(modernize-use-using)

#    ifdef __cplusplus
extern "C"
{
#    endif

    /**
     * @brief Constructor of lipsum::Source
     *
     * @since 0.4.0
     *
     * This is a wrapper over the constructor of lipsum::Source.
     *
     * @param path The path entered into lipsum::Source::Source. If path is set
     * to any of the built-in sources by lipsum::Source::Source(const
     * std::string&), it will use the specified built-in source.
     *
     * @warning The lpsm_SourceHandle must be manually deleted with
     * lpsm_SourceDestroy().
     *
     * @return lpsm_SourceHandle A handle to the object.
     */
    LIPSUMC_API lpsm_SourceHandle lpsm_Source(const char* path);

    /**
     * @brief Delete a lipsum::Source
     *
     * @since 0.4.0
     *
     * This function handles deletion of a lpsm_SourceHandle.
     *
     * @warning Do not call lpsm_SourceDestroy on the same handle twice or use
     * the handle after deleting it, as that would be a double-free or
     * use-after-free.
     *
     * @param handle A lpsm_SourceHandle to delete.
     */
    LIPSUMC_API void lpsm_SourceDestroy(lpsm_SourceHandle handle);

    /**
     * @brief Create a lpsm::ArgVec2.
     *
     * @since 0.3.3
     *
     * This function creates a pointer pointing to a lpsm::ArgVec2.
     *
     * @warning The lpsm_ArgVec2Handle must be manually deleted with
     * lpsm_ArgVec2Destroy(), except for objects created in the "S" functions
     * when argument "del" is set to true.
     *
     * @param min Value to enter into the minimum value
     * @param max Value to enter into the maximum value
     *
     * @return lpsm_ArgVec2Handle The lpsm::ArgVec2.
     */
    LIPSUMC_API lpsm_ArgVec2Handle lpsm_ArgVec2(int min, int max);

    /**
     * @brief Delete a lpsm::ArgVec2.
     *
     * @since 0.3.3
     *
     * This function deletes a lpsm::ArgVec2 allocated with
     * lpsm_ArgVec2.
     *
     * @warning Do not call lpsm_ArgVec2Destroy on the same handle twice or use
     * the handle after deleting it, as that would be a double-free or
     * use-after-free.
     *
     * @param av2 The lpsm::ArgVec2.
     */
    LIPSUMC_API void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle av2);

    /**
     * @brief Run lpsm::ArgVec2::roll.
     *
     * @since 0.3.3
     *
     * This function calls lpsm::ArgVec2::Roll(). Formerly known as
     * lpsm_ArgVec2Roll().
     *
     * @param av2 The lpsm::ArgVec2.
     *
     * @return int The random number.
     */
    LIPSUMC_API int lpsm_ArgVec2_roll(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::min
     *
     * @since 0.3.3
     *
     * This function retrieves the min property of a lpsm::ArgVec2. Formerly
     * known a lpsm_ArgVec2GetMin().
     *
     * @param av2 The lpsm::ArgVec2.
     *
     * @return int The min value.
     */
    LIPSUMC_API int lpsm_ArgVec2_min(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::max
     *
     * @since 0.3.3
     *
     * This function retrieves the max property of a lpsm::ArgVec2. Formerly
     * known as lpsm_ArgVec2GetMax().
     *
     * @param av2 The lpsm::ArgVec2.
     *
     * @return int The max value.
     */
    LIPSUMC_API int lpsm_ArgVec2_max(lpsm_ArgVec2Handle av2);

    /**
     * @brief Generate words.
     *
     * @since 0.2.3
     *
     * This function generates multiple words.
     *
     * @param num The number of words.
     *
     * @return char* The random word.
     */
    LIPSUMC_API char* lpsm_gen_word(int num);

    /**
     * @brief Generate sentences.
     *
     * @since 0.2.3
     *
     * This function generates multiple sentences with default arguments.
     *
     * @param num The number of sentences.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * sentence(s).
     *
     * @return char* The random sentence(s).
     */
    LIPSUMC_API char* lpsm_gen_sentence(int num, bool useLipsum);

    /**
     * @brief Generate a sentence fragment.
     *
     * @since 0.2.3
     *
     * This function generates a sentence fragment with default arguments.
     *
     * @return char* The random sentence fragment.
     */
    LIPSUMC_API char* lpsm_gen_sentence_fragment(void);

    /**
     * @brief Generate paragraphs.
     *
     * @since 0.2.3
     *
     * This function generates multiple paragraphs with default arguments.
     *
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the
     * paragraph(s).
     *
     * @return char* The random paragraph(s).
     */
    LIPSUMC_API char* lpsm_gen_paragraph(int num, bool useLipsum);

    /**
     * @brief Generate a Markdown paragraph.
     *
     * @since 0.3.0
     *
     * This function generates multiple paragraphs in Markdown format with
     * default arguments.
     *
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return char* The random Markdown paragraph.
     */
    LIPSUMC_API char* lpsm_gen_md_paragraph(int num, bool useLipsum);

    /**
     * @brief Generate a Markdown document.
     *
     * @since 0.3.0
     *
     * This function generates a document in Markdown format with default
     * arguments.
     *
     * @param numElements The number of elements (paragraph, list, heading) in
     * the document.
     *
     * @return char* The random Markdown document.
     */
    LIPSUMC_API char* lpsm_gen_md_text(int numElements);

    /**
     * @brief Generate an HTML paragraph.
     *
     * @since 0.4.4
     *
     * This function generates multiple paragraphs in HTML format with
     * default arguments.
     *
     * @param num The number of paragraphs.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return char* The random HTML paragraph.
     */
    LIPSUMC_API char* lpsm_gen_html_paragraph(int num, bool useLipsum);

    /**
     * @brief Generate an HTML document.
     *
     * @since 0.4.4
     *
     * This function generates a document in HTML format with default
     * arguments.
     *
     * @param numElements The number of elements (paragraph, list, heading)
     * in the document.
     *
     * @return char* The random HTML document.
     */
    LIPSUMC_API char* lpsm_gen_html_text(int numElements);

    /**
     * @brief Generate an XML document.
     *
     * @since 0.4.4
     *
     * This function generats a document in XML format with default arguments.
     *
     * @param choices The number of choices (start element, end element, add
     * data element) that are made.
     *
     * @return char* The random XML document.
     */
    LIPSUMC_API char* lpsm_gen_xml(int choices);

    /**
     * @brief Generate a JSON object or array.
     *
     * @since 0.4.4
     *
     * This function generates an object or array in JSON format with
     * default arguments.
     *
     * @param maxDepth Maximum depth of recursion.
     * @param isObject Whether to output an object (true) or an array
     * (false).
     *
     * @return char* The random JSON object or array.
     */
    LIPSUMC_API char* lpsm_gen_json(int maxDepth, bool isObject);

#    ifdef __cplusplus
}
#    endif

#endif

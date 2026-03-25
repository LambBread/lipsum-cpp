
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
#ifndef LIPSUM_BINDED_H
#define LIPSUM_BINDED_H

#include "core.h"

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

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Constructor of lipsum::Source
     *
     * @since 0.4.0
     *
     * This is a wrapper over the constructor of lipsum::Source.
     *
     * @param path The path entered into lipsum::Source::Source. If path is set
     * to "default", use the default sample.
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
     * @param av2 The lpsm::ArgVec2.
     */
    LIPSUMC_API void lpsm_ArgVec2Destroy(lpsm_ArgVec2Handle av2);

    /**
     * @brief Run lpsm::ArgVec2::Roll.
     *
     * @since 0.3.3
     *
     * This function calls lpsm::ArgVec2::Roll().
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The random number.
     */
    LIPSUMC_API int lpsm_ArgVec2Roll(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::min
     *
     * @since 0.3.3
     *
     * This function retrieves the min property of a lpsm::ArgVec2.
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The min value
     */
    LIPSUMC_API int lpsm_ArgVec2GetMin(lpsm_ArgVec2Handle av2);

    /**
     * @brief Get lpsm::ArgVec2::max
     *
     * @since 0.3.3
     *
     * This function retrieves the max property of a lpsm::ArgVec2.
     *
     * @param av2 The lpsm::ArgVec2
     *
     * @return int The max value
     */
    LIPSUMC_API int lpsm_ArgVec2GetMax(lpsm_ArgVec2Handle av2);

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
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return char* The random Markdown paragraph.
     */
    LIPSUMC_API char* lpsm_gen_md_paragraph(bool useLipsum);

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
#ifdef __cplusplus
}
#endif

#endif

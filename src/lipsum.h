/** @file lipsum.h
 * @brief C wrapper over lipsum.hpp
 * 
 * This contains the C wrapper over lipsum-cpp. It requires being built
 * as a static library in order to function.
 *
 * @author LambBread from github.com
 */
#ifndef LIPSUM_H
#define LIPSUM_H
#ifndef LIPSUM_BUILD_STATIC
#error Cannot use C wrapper without building a static library.
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>

/**
 * @brief Generate a random sentence.
 *
 * This function generates a sentence starting with a capital letter
 * and ending with a period, sometimes containing a comma.
 *
 * @return char* Returns the random sentence.
 *
 * @param minWord Minimum number of words in the sentence.
 * 
 * @param maxWord Maximum number of words in the sentence.
 * 
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence.
 */
char* lpsm_GenerateSentence(int minWord, int maxWord, float ratio);
/**
 * @brief Generate a random paragraph.
 *
 * This function generates a random paragraph starting with a tab character and ending in a
 * line break, with each sentence separated by a space.
 *
 * @return char* Returns the random paragraph.
 *
 * @param minSent Minimum number of sentences in the paragraph.
 * 
 * @param maxSent Maximum number of sentences in the paragraph.
 *
 * @param minWord Minimum number of words in each sentence.
 *
 * @param maxWord Maximum number of words in each sentence.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the paragraph.
 *
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence.
 */
char* lpsm_GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio);

/**
 * @brief Generate several random paragraphs at once.
 *
 * This function generates several random paragraphs, each separated by a line break. Formerly known as lpsm_GenerateParagraphList().
 * 
 * @return char* Returns the random paragraphs.
 *
 * @param paraCount The number of paragraphs.
 *
 * @param minSent The minimum number of sentences per paragraph.
 *
 * @param maxSent The maximum number of sentences per paragraph.
 *
 * @param minWord The minimum number of words per sentence.
 *
 * @param maxWord The maximum number of words per sentence.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the first paragraph.
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence.
 */
char* lpsm_GenerateParagraphs(int paraCount, int minSent, int maxSent, int minWord, int maxWord, bool useLipsum, float ratio);

/**
 * @brief Generate a random word.
 *
 * This function generates a random word from a predefined list.
 *
 * @return char* Returns the random word.
 */
char* lpsm_GenerateWord(void);
/**
 * @brief Generate the beginning Lorem Ipsum sentence.
 * 
 * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
 *
 * @return char* Returns the default Lorem Ipsum sentence.
 */
char* lpsm_GenerateDefaultLipsumSentence(void);
/**
 * @brief Generate multiple random sentences at once.
 *
 * Generate multiple random sentences separated with spaces. Does not add a tab character before the sentences
 * nor a line break after.
 *
 * @return char* Returns the random sentences.
 *
 * @param sentCount The number of sentences.
 *
 * @param minWord The minimum number of words per sentence.
 *
 * @param maxWord The maximum number of words per sentence.
 *
 * @param useLipsum Whether the default "Lorem ipsum..." sentence should be the first sentence.
 *
 * @param ratio How large the random number generated between minWord and maxWord should be compared to maxWord before a comma is added to a sentence.
 */
char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, bool useLipsum, float ratio);
/**
 * @brief Turn a string into HTML paragraph tags.
 * 
 * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
 * handle HTML entities like &, <, >, etc.
 *
 * @return char* The HTML-ified string.
 *
 * @param str The string inputted.
 */
char* lpsm_HTMLify(char* str);
/**
 * @brief Delete a string returned by a function.
 *
 * Since pointers allocated with new[] cannot be deallocated with free(),
 * this handles the deallocation.
 *
 * @return void This function does not return a value.
 *
 * @param str The string to delete.
 */
void lpsm_DeleteString(char* str);

#ifdef __cplusplus
}
#endif
#endif

/** 
 * @file lipsum.h
 * 
 * @brief C wrapper over lipsum.hpp
 * 
 * This contains the C wrapper over lipsum-cpp. It requires being built
 * as a static library in order to function.
 * 
 * @author LambBread from github.com
 * 
 * @example CWrapper.c
 */

#ifndef LIPSUM_H
#define LIPSUM_H

#ifdef LIPSUM_BUILD_SHARED
    #ifdef _WIN32
        #ifdef LIPSUM_EXPORT_SHARED
            #define LIPSUMC_API __declspec(dllexport)
        #else
            #define LIPSUMC_API __declspec(dllimport)
        #endif
    #else
        #define LIPSUMC_API
    #endif
#else
    #define LIPSUMC_API
#endif
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
 * @return char* The random sentence.
 * 
 * @param minWord Minimum number of words in the sentence fragment.
 * @param maxWord Maximum number of words in the sentence fragment.
 * @param minFrag Minimum number of sentence fragments in the sentence.
 * @param maxFrag Maximum number of sentence fragments in the sentence.
 */
LIPSUMC_API char* lpsm_GenerateSentence(int minWord, int maxWord, int minFrag, int maxFrag);
 
/** 
 * @brief Generate a random paragraph.
 *  
 * This function generates a random paragraph starting with a tab character and ending in a
 * line break, with each sentence separated by a space.
 *  
 * @return char* The random paragraph.
 *  
 * @param minSent Minimum number of sentences in the paragraph.
 * @param maxSent Maximum number of sentences in the paragraph.
 * @param minWord Minimum number of words in each sentence fragment.
 * @param maxWord Maximum number of words in each sentence fragment.
 * @param minFrag Minimum number of sentence fragments in each sentence.
 * @param maxFrag Maximum number of sentence fragments in each sentence.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the paragraph.
 */ 
LIPSUMC_API char* lpsm_GenerateParagraph(int minWord, int maxWord, int minFrag, int maxFrag, int minSent, int maxSent, bool useLipsum);
  
/**  
 * @brief Generate several random paragraphs at once.
 *   
 * This function generates several random paragraphs, each separated by a line break. Formerly known as lpsm_GenerateParagraphList().
 *   
 * @return char* The random paragraphs.
 *   
 * @param paraCount The number of paragraphs.
 * @param minSent Minimum number of sentences in each paragraph.
 * @param maxSent Maximum number of sentences in each paragraph.
 * @param minWord Minimum number of words in each sentence fragment.
 * @param maxWord Maximum number of words in each sentence fragment.
 * @param minFrag Minimum number of sentence fragments in each sentence.
 * @param maxFrag Maximum number of sentence fragments in each sentence.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the first paragraph.
 */ 
LIPSUMC_API char* lpsm_GenerateParagraphs(int paraCount, int minWord, int maxWord, int minFrag, int maxFrag, int minSent, int maxSent, bool useLipsum);
  
/**  
 * @brief Generate a random word.
 *   
 * This function generates a random word from a predefined list.
 *   
 * @return char* The random word.
 */  
LIPSUMC_API char* lpsm_GenerateWord(void);
   
/**   
 * @brief Generate the beginning Lorem Ipsum sentence.
 *   
 * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
 *   
 * @return char* The default Lorem Ipsum sentence.
 */  
LIPSUMC_API char* lpsm_GenerateDefaultLipsumSentence(void);
   
/**   
 * @brief Generate multiple random sentences at once.
 *    
 * Generate multiple random sentences separated with spaces. Does not add a tab character before the sentences
 * nor a line break after.
 *    
 * @return char* The random sentences.
 *    
 * @param sentCount The number of sentences.
 * @param minWord Minimum number of words in each sentence fragment.
 * @param maxWord Maximum number of words in each sentence fragment.
 * @param minFrag Minimum number of sentence fragments in each sentence.
 * @param maxFrag Maximum number of sentence fragments in each sentence.
 * @param useLipsum Whether the default "Lorem ipsum..." sentence should be the first sentence.
 */  
LIPSUMC_API char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, int minFrag, int maxFrag, bool useLipsum);
   
/**   
 * @brief Turn a string into HTML paragraph tags.
 *    
 * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
 * handle HTML entities like &amp;, &lt;, &gt;, etc.
 *   
 * @return char* The HTML-ified string.
 *   
 * @param str The string inputted.
 */  
LIPSUMC_API char* lpsm_HTMLify(const char* str);
   
/**  
 * @brief Delete a string returned by a function.
 *   
 * Since pointers allocated with new[] cannot be deallocated with free(),
 * this function handles the deallocation.
 *   
 * @param str The string to delete.
 */  
LIPSUMC_API void lpsm_DeleteString(char* str);
   
/**   
 * @brief Generate a random sentence fragment.
 *    
 * @return char* The random sentence fragment.
 *    
 * @param minWord Minimum number of words in the fragment.
 * @param maxWord Maximum number of words in the fragment.
 */  
LIPSUMC_API char* lpsm_GenerateSentenceFragment(int minWord, int maxWord);
   
#ifdef __cplusplus
}   
#endif   
   
#endif       

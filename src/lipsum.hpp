/** 
 * @file lipsum.hpp
 *
 * @brief Main header of lipsum-cpp
 *
 * This contains the declarations of functions as well as definitions
 * if LIPSUM_IMPLEMENTATION is defined
 * 
 * @author LambBread from github.com
 * 
 * @example GenerateDefaultLipsumSentence.cpp
 * @example GenerateParagraph.cpp
 * @example GenerateParagraphs.cpp
 * @example GenerateSentence.cpp
 * @example GenerateSentenceFragment.cpp
 * @example GenerateSentences.cpp
 * @example GenerateWord.cpp
 * @example HTMLify.cpp
 * @example FuncsX.cpp
 */
#pragma once
#ifndef __cplusplus
#error lipsum.hpp only supports C++, did you mean lipsum.h?
#endif
#include <vector>
#include <sstream>
#include <string>
#include <random>
#include <cctype>
/**
 * @namespace lipsum
 * 
 * @brief This is the main namespace of lipsum-cpp.
 * 
 * This namespace contains all the code for the C++ usage of lipsum-cpp.
 */
namespace lipsum
{
    /**
     * @namespace lipsum::internal
     *
     * @brief This namespace contains functions only used internally by other functions.
     * 
     * This namespace's functions are not intended for public use and are
     * not exposed in the C wrapper.
     */
    namespace internal
    {
        //! \{
        std::string HandleHTMLEntity(const std::string& str);
        //! \}
    }

    /** 
     * @brief Store data for inputting into functions.
     * 
     * This struct stores values min and max, which
     * are intended to be inputted into functions as arguments.
     * Not exposed in the C wrapper.
     */
    struct ArgVec2
    {
        /** 
         * @brief Constructor for ArgVec2
         * 
         * @param min Value to enter into this->min
         * @param max Value to enter into this->max
         */
        ArgVec2(int min, int max);

        /** 
         * @brief Return a number between min and max.
         * 
         * This function returns a random value between min and max.
         * 
         * @return int The random number.
         */
        int Roll() const;
        
        int min; ///<The minimum value
        int max; ///<The maximum value
    };

/**
 * @brief Generate a random word.
 * 
 * This function generates a random word from a predefined list.
 * 
 * @return std::string The random word.
 */
std::string GenerateWord();

/**
 * @brief Generate a fragment of a sentence without punctuation.
 * 
 * This function generates a fragment of a sentence, without punctuation inside.
 * 
 * @param word The minimum and maximum possible number of words in a fragment. By default 4 to 9.
 * 
 * @return std::string The random sentence fragment.
 */
std::string GenerateSentenceFragment(const ArgVec2& word = ArgVec2(4, 9));

/**
 * @brief Generate a fragment of a sentence without punctuation.
 * 
 * @psovload
 * 
 * @param minWord Minimum possible number of words in a sentence fragment. By default 4.
 * @param maxWord Maximum possible number of words in a sentence fragment. By default 9.
 * 
 * @return std::string The random sentence fragment.
 */
std::string GenerateSentenceFragmentX(int minWord = 4, int maxWord = 9);

/**
 * @brief Generate a random sentence.
 * 
 * This function generates a sentence starting with a capital letter
 * and ending with a period, often containing commas, semicolons, and dashes.
 * 
 * @return std::string The random sentence.
 * 
 * @param word The minimum and maximum possible number of words in a sentence fragment. By default 4 to 9.
 * @param frag The minimum and maximum possible number of sentence fragments in the sentence. By default 1 to 3.
 */
std::string GenerateSentence(const ArgVec2& word = ArgVec2(4, 9), const ArgVec2& frag = ArgVec2(1, 3));

/**
 * @brief Generate a random sentence.
 * 
 * @psovload
 * 
 * @param minWord Minimum possible number of words in a sentence fragment. By default 4.
 * @param maxWord Maximum possible number of words in a sentence fragment. By default 9.
 * @param minFrag Minimum possible number of sentence fragments in a sentence. By default 1.
 * @param maxFrag Maximum possible number of sentence fragments in a sentence. By default 3.
 * 
 * @return std::string The random sentence.
 */
std::string GenerateSentenceX(int minWord = 4, int maxWord = 9, int minFrag = 1, int maxFrag = 3);

/**
 * @brief Generate a random paragraph.
 * 
 * This function generates a random paragraph starting with a tab character and ending in a
 * line break, with each sentence separated by a space.
 * 
 * @return std::string The random paragraph.
 * 
 * @param sent The minimum and maximum possible number of sentences in the paragraph. By default 5 to 8.
 * @param frag The minimum and maximum possible number of sentence fragments in a sentence. By default 1 to 3.
 * @param word The minimum and maximum possible number of words in a sentence fragment. By default 4 to 9.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the paragraph. By default true.
 */
std::string GenerateParagraph(const ArgVec2& word = ArgVec2(4, 9), const ArgVec2& frag = ArgVec2(1, 3), 
        const ArgVec2& sent = ArgVec2(5, 8), bool useLipsum = true);

/**
 * @brief Generate a random paragraph.
 * 
 * @psovload
 * 
 * @param minWord The minimum possible number of words in a sentence fragment. By default 4.
 * @param maxWord The maximum possible number of words in a sentence fragment. By default 9.
 * @param minFrag The minimum possible number of sentence fragments in a sentence. By default 1.
 * @param maxFrag The maximum possible number of sentence fragments in a sentence. By default 3.
 * @param minSent The minimum possible number of sentences in the paragraph. By default 5.
 * @param maxSent The maximum possible number of sentences in the paragraph. By default 8.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the paragraph. By default true.
 * 
 * @return std::string The random paragraph.
 */
std::string GenerateParagraphX(int minWord = 4, int maxWord = 9, int minFrag = 1, int maxFrag = 3, 
        int minSent = 5, int maxSent = 8, bool useLipsum = true);

/**
 * @brief Generate several random paragraphs at once.
 * 
 * This function generates several random paragraphs, each separated by a line break. Formerly known as lipsum::GenerateParagraphList().
 * 
 * @return std::string The random paragraphs.
 * 
 * @param paraCount The number of paragraphs. By default 5.
 * @param word The minimum and maximum total number of words in a sentence fragment. By default 4 to 9.
 * @param frag The minimum and maximum total number of sentence fragments in a sentence. By default 1 to 3.
 * @param sent The minimum and maximum total number of sentences in a paragraph. By default 5 to 8.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the first paragraph. By default true.
 */
std::string GenerateParagraphs(int paraCount = 5, const ArgVec2& word = ArgVec2(4, 9), const ArgVec2& frag = ArgVec2(1, 3),
        const ArgVec2& sent = ArgVec2(5, 8), bool useLipsum = true);

/**
 * @brief Generate several random paragraphs at once.
 * 
 * @psovload
 * 
 * @param paraCount The number of paragraphs. By default 5.
 * @param minWord The minimum possible number of words in a sentence fragment. By default 4.
 * @param maxWord The maximum possible number of words in a sentence fragment. By default 9.
 * @param minFrag The minimum possible number of sentence fragments in a sentence. By default 1.
 * @param maxFrag The maximum possible number of sentence fragments in a sentence. By default 3.
 * @param minSent The minimum possible number of sentences in a paragraph. By default 5.
 * @param maxSent The maximum possible number of sentences in a paragraph. By default 8.
 * @param useLipsum Whether the default "Lorem ipsum..." text should start the first paragraph. By default true.
 * 
 * @return std::string The random paragraphs.
 */
std::string GenerateParagraphsX(int paraCount = 5, int minWord = 4, int maxWord = 9, int minFrag = 1, int maxFrag = 3, 
        int minSent = 5, int maxSent = 8, bool useLipsum = true);

/**
 * @brief Generate the beginning Lorem Ipsum sentence.
 * 
 * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
 * 
 * @return std::string The default Lorem Ipsum sentence.
 */
std::string GenerateDefaultLipsumSentence();

/**
 * @brief Generate multiple random sentences at once.
 * 
 * Generate multiple random sentences separated with spaces. Does not add a tab character before the sentences
 * nor a line break after.
 * 
 * @return std::string Returns the random sentences.
 * 
 * @param sentCount The number of sentences. By default 6.
 * @param word The minimum and maximum possible number of words in a sentence fragment. By default 4 to 9.
 * @param frag The minimum and maximum possible number of sentence fragments in a sentence. By default 1 to 3.
 * @param useLipsum Whether the default "Lorem ipsum..." sentence should be the first sentence. By default true.
 */
std::string GenerateSentences(int sentCount = 6, const ArgVec2& word = ArgVec2(4, 9), 
        const ArgVec2& frag = ArgVec2(1, 3), bool useLipsum = true);

/**
 * @brief Generate multiple random sentences at once.
 * 
 * @psovload
 * 
 * @param sentCount The number of sentences. By default 6.
 * @param minWord The minimum possible number of words in a sentence fragment. By default 4.
 * @param maxWord The maximum possible number of words in a sentence fragment. By default 9.
 * @param minFrag The minimum possible number of sentence fragments in a sentence. By default 1.
 * @param maxFrag The maximum possible number of sentence fragments in a sentence. By default 3.
 * @param useLipsum Whether the default "Lorem ipsum..." sentence should be the first sentence. By default true.
 */
std::string GenerateSentencesX(int sentCount = 6, int minWord = 4, int maxWord = 9, int minFrag = 1, int maxFrag = 3,
        bool useLipsum = true);

/**
 * @brief Turn a string into HTML paragraph tags.
 * 
 * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
 * handle HTML entities like &amp;, &lt;, &gt;, etc.
 * 
 * @return std::string The HTML-ified string.
 * 
 * @param str The string inputted.
 */
std::string HTMLify(const std::string& str);

/**
 * @overload
 * 
 * Turn a string into HTML paragraph tags specified by a C-style string.
 * 
 * @param str The string inputted.
 * 
 * @return std::string The HTML-ified string.
 */
std::string HTMLify(const char* str);
}

///Alias for namespace lipsum
namespace lpsm = lipsum;

#ifdef LIPSUM_IMPLEMENTATION
std::string lipsum::HTMLify(const char* str)
{
    return lipsum::HTMLify(std::string(str));
}

std::string lipsum::GenerateSentencesX(int sentCount, int minWord, int maxWord, int minFrag, int maxFrag, bool useLipsum)
{
    return lipsum::GenerateSentences(sentCount, lipsum::ArgVec2(minWord, maxWord), lipsum::ArgVec2(minFrag, maxFrag), useLipsum);
}

std::string lipsum::GenerateParagraphsX(int paraCount, int minWord, int maxWord, int minFrag, int maxFrag, int minSent, int maxSent, bool useLipsum)
{
    return lipsum::GenerateParagraphs(paraCount, lipsum::ArgVec2(minWord, maxWord),
            lipsum::ArgVec2(minFrag, maxFrag), lipsum::ArgVec2(minSent, maxSent), useLipsum);
}

std::string lipsum::GenerateParagraphX(int minWord, int maxWord, int minFrag, int maxFrag, int minSent, int maxSent, bool useLipsum)
{
    return lipsum::GenerateParagraph(lipsum::ArgVec2(minWord, maxWord), 
            lipsum::ArgVec2(minFrag, maxFrag), lipsum::ArgVec2(minSent, maxSent), useLipsum);
}

std::string lipsum::GenerateSentenceX(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return lipsum::GenerateSentence(lipsum::ArgVec2(minWord, maxWord), lipsum::ArgVec2(minFrag, maxFrag));
}

std::string lipsum::GenerateSentenceFragmentX(int minWord, int maxWord)
{
    return lipsum::GenerateSentenceFragment(lipsum::ArgVec2(minWord, maxWord));
}

std::string lipsum::internal::HandleHTMLEntity(const std::string& str)
{
    std::string result;
    for(const auto& c : str)
    {
        switch(c)
        {
            case '&':
            {
                result += "&amp;";
                break;
            }
            case '<':
            {
                result += "&lt;";
                break;
            }
            case '>':
            {
                result += "&gt;";
                break;
            }
            case '"':
            {
                result += "&quot;";
                break;
            }
            case '\'':
            {
                result += "&apos;";
                break;
            }
            default:
            {
                result.push_back(c);
            }
        }
    }
    return result;
}

lipsum::ArgVec2::ArgVec2(int min, int max)
{
    this->min = min;
    this->max = max;
}

int lipsum::ArgVec2::Roll() const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

std::string lipsum::HTMLify(const std::string& str)
{
    std::stringstream ss(str);
    std::string line;
    std::string result;
    while(std::getline(ss, line))
    {
        if(!line.empty())
        {
            result += std::string("<p>") += lipsum::internal::HandleHTMLEntity(line) += std::string("</p>\n");
        }
    }
    return result;
}

std::string lipsum::GenerateSentences(int sentCount, const lipsum::ArgVec2& word, const lipsum::ArgVec2& frag, bool useLipsum)
{
    std::string result;
    if(useLipsum)
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for(int i = 0; i < sentCount - 1; ++i)
        {
            result += lipsum::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        for(int i = 0; i < sentCount; ++i)
        {
            result += lipsum::GenerateSentence(word, frag) += " ";
        }
    }
    return result;
}

std::string lipsum::GenerateDefaultLipsumSentence()
{
    return "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
}

std::string lipsum::GenerateWord()
{
#include "lipsum.inl"
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, lipsumVec.size() - 1);
    return lipsumVec.at(dist(gen));
}

std::string lipsum::GenerateSentenceFragment(const lipsum::ArgVec2& word)
{
    std::string result;
    int numWords = word.Roll();
    for(int i = 0; i < numWords; ++i)
    {
        result += lipsum::GenerateWord() += " ";
    }
    result.pop_back(); //remove trailing space
    return result;

}

std::string lipsum::GenerateSentence(const lipsum::ArgVec2& word, const lipsum::ArgVec2& frag)
{
    constexpr int CHANCE_COMMA = 97;
    constexpr int CHANCE_SEMI = 9;
    std::string result;
    int words = word.Roll();
    int frags = frag.Roll();
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for(int i = 0; i < frags; ++i)
    {
        result += lipsum::GenerateSentenceFragment();
        int check = dist(gen);
        if(i != frags - 1)
        {
            if(dist(gen) < CHANCE_SEMI)
            {
                result += "; ";
            }
            else if(dist(gen) < CHANCE_COMMA)
            {
                result += ", ";
            }
            else
            {
                result += " - ";
            }
        }
    }
    result += ".";
    result.at(0) = std::toupper(result.at(0));
    return result;
}

std::string lipsum::GenerateParagraph(const lipsum::ArgVec2& word, const lipsum::ArgVec2& frag, 
        const lipsum::ArgVec2& sent, bool useLipsum)
{
    std::string result = "\t";
    int sents = sent.Roll();
    if(!useLipsum)
    {
        for(int i = 0; i < sents; ++i)
        {
            result += lipsum::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for(int i = 0; i < sents - 1; ++i)
        {
            result += lipsum::GenerateSentence(word, frag) += " ";
        }
    }
    result += "\n";
    return result;
}

std::string lipsum::GenerateParagraphs(int paraCount, const lipsum::ArgVec2& word, const lipsum::ArgVec2& frag, const lipsum::ArgVec2& sent, bool useLipsum)
{
    std::string result;
    if(!useLipsum)
    {

        for(int i = 0; i < paraCount; ++i)
        {
            result += lipsum::GenerateParagraph(word, frag, sent, false);
        }
    }
    else
    {
        result += lipsum::GenerateParagraph(word, frag, sent, true);
        for(int i = 0; i < paraCount - 1; ++i)
        {
            result += lipsum::GenerateParagraph(word, frag, sent, false);
        }
    }
    return result;
}

#endif
